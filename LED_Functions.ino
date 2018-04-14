// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////// CODE BY RENE FRANK ////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int colors[6][4] =
{
	{
		255, 0, 255, 0
	}, // purple
	{
		255, 255, 0, 0
	}, // yellow
	{
		0, 0, 255, 0
	}, // blue
	{
		255, 0, 0, 0
	}, // red
	{
		127, 127, 127, 127
	}, // full white 50%
	{
		0, 255, 0, 0
	}
	// green
};

// ripple variables
int color;
int center = 0;
int step = -1;
int maxSteps = 16;
float fadeRate = 0.8;
int diff;
uint32_t currentBg = random(256);
uint32_t nextBg = currentBg;

// Fill the dots one after another with first 20 alten red, then 20 alten yellow,
// then 20 alten blue, then turn them off in reverse order
void colorDutchStrip(uint8_t wait)
{
	for (int i = 0; i < 20; i++)
	{
		strip.setPixelColor(i, 255, 0, 0, 0);
		strip.show();
		delay(wait);
	}
	for (int i = 20; i < 40; i++)
	{
		strip.setPixelColor(i, 0, 0, 0, 255);
		strip.show();
		delay(wait);
	}
	for (int i = 40; i < NUM_LEDS; i++)
	{
		strip.setPixelColor(i, 0, 0, 255, 0);
		strip.show();
		delay(wait);
	}
	delay(200);
	for (int i = NUM_LEDS; i >= 0; i--)
	{
		strip.setPixelColor(i, 0);
		strip.show();
		delay(wait);
	}
}

// Turns on the LEDS only at the TV area
void setTV(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
	for (int i = 20; i < NUM_LEDS; i++)
	{
		strip.setPixelColor(i, 0);
	}

	for (int i = 0; i < 20; i++)
	{
		strip.setPixelColor(i, red, green, blue, white);
	}

	strip.show();
}

// Turns on the LEDS only at the PC area
void setPC(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
	for (int i = 0; i < 20; i++)
	{
		strip.setPixelColor(i, 0);
	}

	for (int i = 20; i < 40; i++)
	{
		strip.setPixelColor(i, red, green, blue, white);

	}

	for (int i = 40; i < NUM_LEDS; i++)
	{
		strip.setPixelColor(i, 0);
	}

	strip.show();
}

// Turns on the LEDS only at the Dinner area
void setDinner(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
	for (int i = 0; i < 40; i++)
	{
		strip.setPixelColor(i, 0);
	}

	for (int i = 40; i < NUM_LEDS; i++)
	{
		strip.setPixelColor(i, red, green, blue, white);
	}

	strip.show();
}

// Fill the strip with one color
void colorFill(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int i = 0; i < NUM_LEDS; i++)
	{
		strip.setPixelColor(i, red, green, blue, white);
		strip.show();
		delay(wait);
	}
}

// Fill the dots one after the other in reverse order
void colorFillReverse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int i = NUM_LEDS; i >= 0; i--)
	{
		strip.setPixelColor(i, red, green, blue, white);
		strip.show();
		delay(wait);
	}
}

// Go through all possible intensities of a color
void colorIntensityWipe(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
	for (int c = 0; c < 256; c++)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i,(red * c) /255,(green * c) /255,(blue * c) /255,(white * c) /255);
		}
		strip.show();
	}
	for (int c = 255; c > 0; c--)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i,(red * c) /255,(green * c) /255,(blue * c) /255,(white * c) /255);
		}
		strip.show();
	}
}

// Fill the strip by running one light from front to back, adding to the line
void stripFill(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int j = NUM_LEDS; j >= 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		strip.setPixelColor(j - 1, red, green, blue, white);
	}
}

// Empties a full strip in the same way stripFill fills a strip (left to right)
void stripEmpty(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	setAll(red, green, blue, white);
	for (int j = 0; j < NUM_LEDS; j++)
	{
		for (uint8_t i = j; i < NUM_LEDS; i--)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		strip.setPixelColor(j - 1, 0);
	}
}

// Fill the strip by running one light from front to back, adding to the line. In reverse.
void stripFillReverse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int j = 0; j <= NUM_LEDS; j++)
	{
		for (int i = NUM_LEDS; i > j; i--)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		strip.setPixelColor(j, red, green, blue, white);
	}
}

// Empties a full strip in the same way stripFill fills a strip, in reverse (right to left)
void stripEmptyReverse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	setAll(red, green, blue, white);
	for (int j = NUM_LEDS; j >= 0; j--)
	{
		for (uint8_t i = j; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		strip.setPixelColor(j - 1, 0);
	}
}

// Change brightness in a pulse like motion
void brightnessPulse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int b = 1; b < 255; b++)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.setBrightness(b);
		}
		delay(wait);
		strip.show();
	}
	for (int b = 255; b >= 0; b--)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.setBrightness(b);
		}
		delay(wait);
		strip.show();
	}
	strip.setBrightness(BRIGHTNESS);
}

// Fill the strip by running one light from front to back, adding to the line, every run a random color
void randomStripFill(uint8_t wait)
{
	int red;
	int blue;
	int green;
	for (int nl = NUM_LEDS; nl >= 0; nl--)
	{
		red = random(1, 255);
		blue = random(1, 255);
		green = random(1, 255);
		for (int i = 0; i < nl; i++)
		{
			strip.setPixelColor(i, red, green, blue);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		strip.setPixelColor(nl - 1, red, green, blue);
	}
}

// Fill the strip, but with different randomness
void randomStripFill2(uint8_t wait)
{
	int dimension;
	for (int nl = NUM_LEDS; nl >= 0; nl--)
	{
		dimension = random(0, 6);
		for (int i = 0; i < nl; i++)
		{
			strip.setPixelColor(i, colors[dimension][0], colors[dimension][1], colors[dimension][2], colors[dimension][3]);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		strip.setPixelColor(nl - 1, colors[dimension][0], colors[dimension][1], colors[dimension][2], colors[dimension][3]);
	}
}

// KITT like pulse through the strip
void KITTPulse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t moveSize, uint8_t speedDelay, uint8_t returnDelay)
{
	for (int i = 0; i < NUM_LEDS - moveSize - 1; i++)
	{
		setAll(0, 0, 0, 0);
		strip.setPixelColor(i, red / 10, green / 10, blue / 10, white / 10);
		for (int j = 1; j <= moveSize; j++)
		{
			strip.setPixelColor(i + j, red, green, blue, white);
		}
		strip.setPixelColor(i + moveSize + 1, red / 10, green / 10, blue / 10, white / 10);
		strip.show();
		delay(speedDelay);
	}
	delay(returnDelay);
	for (int i = NUM_LEDS - moveSize - 1; i >= 0; i--)
	{
		setAll(0, 0, 0, 0);
		strip.setPixelColor(i, red / 10, green / 10, blue / 10, white / 10);
		for (int j = 1; j <= moveSize; j++)
		{
			strip.setPixelColor(i + j, red, green, blue, white);
		}
		strip.setPixelColor(i + moveSize + 1, red / 10, green / 10, blue / 10, white / 10);
		strip.show();
		delay(speedDelay);
	}
	delay(returnDelay);
}

// Strobe effect
void strobe(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, int strobeCount, int strobeDelay, int wait, uint8_t bright)
{
	strip.setBrightness(bright);
	for (int i = 0; i < strobeCount; i++)
	{
		setAll(red, green, blue, white);
		strip.show();
		delay(strobeDelay);
		setAll(0, 0, 0, 0);
		strip.show();
		delay(strobeDelay);
	}
	delay(wait);
	strip.setBrightness(BRIGHTNESS);
}

// Moving leds in groups across the ledstrip
void sineWaveLights(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, int sinDelay)
{
	int pos = 0;
	for (int i = 0; i < NUM_LEDS; i++)
	{
		pos++;
		for (int j = 0; j < NUM_LEDS; j++)
		{
			strip.setPixelColor(j,((sin(j + pos) * 128 + 128) / 255) * red,
			((sin(j + pos) * 128 + 128) / 255) * green,
			((sin(j + pos) * 128 + 128) / 255) * blue,
			((sin(j + pos) * 128 + 128) / 255) * white);
		}
		strip.show();
		delay(sinDelay);
	}
}

void sineWaveLightsReverse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, int sinDelay)
{
	int pos = 60;
	for (int i = 0; i < NUM_LEDS; i++)
	{
		pos--;
		for (int j = 0; j < NUM_LEDS; j++)
		{
			strip.setPixelColor(j,((sin(j + pos) * 128 + 128) / 255) * red,
			((sin(j + pos) * 128 + 128) / 255) * green,
			((sin(j + pos) * 128 + 128) / 255) * blue,
			((sin(j + pos) * 128 + 128) / 255) * white);
		}
		strip.show();
		delay(sinDelay);
	}
}

// Displays a number in bits on the strip
void displayBitsAdder(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint32_t number)
{
	for (uint32_t i = 0; i < number; i++)
	{
		// max == 4294967295
		for (int j = 0; j < NUM_LEDS; j++)
		{
			if (bitRead(i, j) == 0)
				strip.setPixelColor(j, 0);
			if (bitRead(i, j) == 1)
				strip.setPixelColor(j, red, green, blue, white);
			strip.show();
		}
	}
	setAll(0, 0, 0, 0);
}

// Equally distributed rainbow that moves across the strip, in a chosen number of loops
void rainbowLoops(uint8_t loops, uint8_t wait)
{
	for (uint32_t j = 0; j < 256 * loops; j++)
	{
		for (uint8_t i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
		}
		strip.show();
		delay(wait);
	}
}

// Crawling lights, like in old style theater
void crawlingLights(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t loops, uint8_t crawl, uint8_t wait)
{
	for (int j = 0; j < loops; j++)
	{
		for (int q = 0; q < crawl; q++)
		{
			for (int i = 0; i < NUM_LEDS; i = i + crawl)
			{
				strip.setPixelColor(i + q, red, green, blue, white); // turn every 'crawl' on
			}
			strip.show();
			delay(wait);
			for (int i = 0; i < NUM_LEDS; i = i + crawl)
			{
				strip.setPixelColor(i + q, 0); // turn every 'crawl' pixel off
			}
		}
	}
}

// Crawling lights, reversed
void crawlingLightsReverse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t loops, uint8_t crawl, uint8_t wait)
{
	for (int j = 0; j < loops; j++)
	{
		for (int q = 0; q < crawl; q++)
		{
			for (int i = 0; i <= NUM_LEDS; i = i + crawl)
			{
				strip.setPixelColor(i - q, red, green, blue, white); // turn every 'crawl' pixel on
			}
			strip.show();
			delay(wait);
			for (int k = 0; k <= NUM_LEDS; k = k + crawl)
			{
				strip.setPixelColor(k - q, 0); // turn every 'crawl' pixel off
			}
		}
	}
}

void crawlingLightsRainbow(uint8_t loops, uint8_t crawl, uint8_t wait)
{
	for (int j = 0; j < loops; j++)
	{
		for (int q = 0; q < crawl; q++)
		{
			for (int i = 0; i < NUM_LEDS; i = i + crawl)
			{
				strip.setPixelColor(i + q, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
			}
			strip.show();
			delay(wait);
			for (int k = 0; k < NUM_LEDS; k = k + crawl)
			{
				strip.setPixelColor(k + q, 0);
			}
		}
	}
}

// Lights racing from left to right, going faster every lap
void racingLights(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t loops, float increase, uint8_t wait)
{
	for (int runs = 1; runs <= loops; runs++)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		if (wait > 5)
		{
			wait = wait * increase;
		}
	}
}

// Light racing from right to left, going faster every lap
void racingLightsReverse(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t loops, float increase, uint8_t wait)
{
	for (int runs = 1; runs <= loops; runs++)
	{
		for (int i = NUM_LEDS; i >= 0; i--)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		if (wait > 5)
		{
			wait = wait * increase;
		}
	}
}

// Lights racing inspired by the shuttle run
// ARDUINO ONLY !!!
void shuttleRun(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t loops, float increase, uint8_t wait)
{
	for (int runs = 1; runs <= loops; runs++)
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		for (int i = NUM_LEDS; i >= 0; i--)
		{
			strip.setPixelColor(i, red, green, blue, white);
			strip.show();
			strip.setPixelColor(i, 0);
			delay(wait);
		}
		if (wait > 5)
		{
			wait = wait * increase;
		}
	}
}

// Lights up the pixels in a random position
void randomPositionLights(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	int pos;
	int positions[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
	};

	setAll(0, 0, 0, 0);
	
	for (int i = 0; i < NUM_LEDS * 2; i++)
	{
		pos = positions[random(0, 60)];
		if (positions[pos] < 60)
		{
			strip.setPixelColor(pos, red, green, blue, white);
		}
		positions[pos] = 73; // arbitrary value, just needs to be >= 60
		strip.show();
		delay(wait);
	}
	
}

// Xmas lighting that shows red, green, gold or white at a random position
void xmasLights(uint8_t wait)
{
	int pos;
	int positions[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
	};
	for (int i = 0; i < NUM_LEDS * 2; i++)
	{
		pos = positions[random(0, 60)];
		int dimension = random(4);
		if (positions[pos] < 60)
		{
			if (dimension == 0)
			{
				strip.setPixelColor(pos, 255, 0, 0, 0);
			}
			if (dimension == 1)
			{
				strip.setPixelColor(pos, 0, 255, 0, 0);
			}
			if (dimension == 2)
			{
				strip.setPixelColor(pos, 255, 215, 0, 0);
			}
			if (dimension == 3)
			{
				strip.setPixelColor(pos, 0, 0, 0, 255);
			}
		}
		positions[pos] = 66;
		strip.show();
		delay(wait);
	}
	setAll(0, 0, 0, 0);
}

// Xmas lights that move through the strip
void xmasLights2(uint32_t color1, uint32_t color2, uint8_t wait)
{
	for (uint16_t i = 0; i < NUM_LEDS; i++)
	{
		if (i % 2 == 0)
		{
			// set even LED to color 1
			strip.setPixelColor(i, color1);
		}
		else
		{
			// set odd LED to color 2
			strip.setPixelColor(i, color2);
		}
	}
	strip.show();
	delay(wait);
	for (uint16_t i = 0; i < NUM_LEDS; i++)
	{
		if (i % 2 == 0)
		{
			// set even LED to color 2
			strip.setPixelColor(i, color2);
		}
		else
		{
			// set odd LED to color 1
			strip.setPixelColor(i, color1);
		}
	}
	strip.show();
	delay(wait);
}

// starting with 1 pixel lit on the left, running to the right, every turnaround adds 1 pixel
void growingSnake(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	int tail = 0;
	for (int k = 0; k < NUM_LEDS; k++)
	{
		for (int i = 0; i < NUM_LEDS - tail; i++)
		{
			setAll(0, 0, 0, 0);
			strip.setPixelColor(NUM_LEDS - 1, 255, 0, 0, 0);
			for (int j = 0; j <= tail; j++)
			{
				strip.setPixelColor(i + j, red, green, blue, white);
			}
			strip.show();
			delay(wait);
		}
		tail++;
		for (int i = NUM_LEDS - tail; i >= 0; i--)
		{
			setAll(0, 0, 0, 0);
			strip.setPixelColor(0, 255, 0, 0, 0);
			for (int j = 0; j <= tail; j++)
			{
				strip.setPixelColor(i + j, red, green, blue, white);
			}
			strip.show();
			delay(wait);
		}
		tail++;
	}
}

// lights running from the middle of the strip to the outside
void middleToOutside(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t moveSize, uint8_t speedDelay, uint8_t returnDelay)
{
	for (int i = ((NUM_LEDS - moveSize) / 2); i >= 0; i--)
	{
		setAll(0, 0, 0, 0);
		strip.setPixelColor(i, red / 10, green / 10, blue / 10, white / 10);
		for (int j = 1; j <= moveSize; j++)
		{
			strip.setPixelColor(i + j, red, green, blue, white);
		}
		strip.setPixelColor(i + moveSize + 1, red / 10, green / 10, blue / 10, white / 10);
		strip.setPixelColor(NUM_LEDS - i, red / 10, green / 10, blue / 10, white / 10);
		for (int j = 1; j <= moveSize; j++)
		{
			strip.setPixelColor(NUM_LEDS - i - j, red, green, blue, white);
		}
		strip.setPixelColor(NUM_LEDS - i - moveSize - 1, red / 10, green / 10, blue / 10, white / 10);
		strip.show();
		delay(speedDelay);
	}
	delay(returnDelay);
}

// lights running from outside to middle
void outsideToMiddle(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t moveSize, uint8_t speedDelay, uint8_t returnDelay)
{
	for (int i = 0; i <= ((NUM_LEDS - moveSize) / 2); i++)
	{
		setAll(0, 0, 0, 0);
		strip.setPixelColor(i, red / 10, green / 10, blue / 10, white / 10);
		for (int j = 1; j <= moveSize; j++)
		{
			strip.setPixelColor(i + j, red, green, blue, white);
		}
		strip.setPixelColor(i + moveSize + 1, red / 10, green / 10, blue / 10, white / 10);
		strip.setPixelColor(NUM_LEDS - i, red / 10, green / 10, blue / 10, white / 10);
		for (int j = 1; j <= moveSize; j++)
		{
			strip.setPixelColor(NUM_LEDS - i - j, red, green, blue, white);
		}
		strip.setPixelColor(NUM_LEDS - i - moveSize - 1, red / 10, green / 10, blue / 10, white / 10);
		strip.show();
		delay(speedDelay);
	}
	delay(returnDelay);
}

// New KITT running lights
void newKITT(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t moveSize, uint8_t speedDelay, uint8_t returnDelay)
{
	KITTPulse(red, green, blue, white, moveSize, speedDelay, returnDelay);
	outsideToMiddle(red, green, blue, white, moveSize, speedDelay, returnDelay);
	middleToOutside(red, green, blue, white, moveSize, speedDelay, returnDelay);
	KITTPulse(red, green, blue, white, moveSize, speedDelay, returnDelay);
	outsideToMiddle(red, green, blue, white, moveSize, speedDelay, returnDelay);
	middleToOutside(red, green, blue, white, moveSize, speedDelay, returnDelay);
}

// lights the strip from the outsides in
void LightUpOutsideIn(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int j = 0; j <= (NUM_LEDS / 2); j++)
	{
		strip.setPixelColor(j, red, green, blue, white);
		strip.setPixelColor(NUM_LEDS - j, red, green, blue, white);
		strip.show();
		delay(wait);
	}
}

// light the strip inside out
void LightUpInsideOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	for (int j = (NUM_LEDS / 2); j >= 0; j--)
	{
		strip.setPixelColor(j, red, green, blue, white);
		strip.setPixelColor(NUM_LEDS - j, red, green, blue, white);
		strip.show();
		delay(wait);
	}
}

// turns strip off outside in
void LightOffOutsideIn(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	setAll(red, green, blue, white);
	for (int j = 0; j <= (NUM_LEDS / 2); j++)
	{
		strip.setPixelColor(j, 0);
		strip.setPixelColor(NUM_LEDS - j, 0);
		strip.show();
		delay(wait);
	}
}

// turns strip off inside out
void LightOffInsideOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t wait)
{
	setAll(red, green, blue, white);
	for (int j = (NUM_LEDS / 2); j >= 0; j--)
	{
		strip.setPixelColor(j, 0);
		strip.setPixelColor(NUM_LEDS - j, 0);
		strip.show();
		delay(wait);
	}
}

// fills the strip at random locations with random colors
void RandomPositionRandomColor(uint8_t wait)
{
	int dimension;
	int pos;
	int positions[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
	};
	for (int i = 0; i < NUM_LEDS * 2; i++)
	{
		pos = positions[random(0, 60)];
		dimension = random(0, 6);
		if (positions[pos] < 60)
		{
			strip.setPixelColor(pos, colors[dimension][0], colors[dimension][1], colors[dimension][2], colors[dimension][3]);
		}
		positions[pos] = 73;
		strip.show();
		delay(wait);
	}
	setAll(0, 0, 0, 0);
}

// bouncing lights
// ARDUINO ONLY !!!
void BouncingLights(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, int balls)
{
	float gravity = -9.81;
	int start = 1;
	float Height[balls];
	float ImpactVelocityStart = sqrt(-2 * gravity * start);
	float ImpactVelocity[balls];
	float TimeSinceLastBounce[balls];
	int Position[balls];
	long ClockTimeSinceLastBounce[balls];
	float Dampening[balls];
	for (int i = 0; i < balls; i++)
	{
		ClockTimeSinceLastBounce[i] = millis();
		Height[i] = start;
		Position[i] = 0;
		ImpactVelocity[i] = ImpactVelocityStart;
		TimeSinceLastBounce[i] = 0;
		Dampening[i] = 0.90 - float(i) / pow(balls, 2);
	}
	while (true)
	{
		for (int i = 0; i < balls; i++)
		{
			TimeSinceLastBounce[i] = millis() - ClockTimeSinceLastBounce[i];
			Height[i] = 0.5 * gravity * pow(TimeSinceLastBounce[i] /1000, 2.0) + ImpactVelocity[i] * TimeSinceLastBounce[i] /1000;
			if (Height[i] < 0)
			{
				Height[i] = 0;
				ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
				ClockTimeSinceLastBounce[i] = millis();
				if (ImpactVelocity[i] < 0.01)
				{
					ImpactVelocity[i] = ImpactVelocityStart;
				}
			}
			Position[i] = round(Height[i] * (NUM_LEDS - 1) / start);
		}
		for (int i = 0; i < balls; i++)
		{
			strip.setPixelColor(Position[i], red, green, blue, white);
		}
		strip.show();
		setAll(0, 0, 0, 0);
	}
}

// bouncing lights with different colors
// ARDUINO ONLY !!!
void BouncingLightsColors(int balls)
{
	float gravity = -9.81;
	int start = 1;
	float Height[balls];
	float ImpactVelocityStart = sqrt(-2 * gravity * start);
	float ImpactVelocity[balls];
	float TimeSinceLastBounce[balls];
	int Position[balls];
	long ClockTimeSinceLastBounce[balls];
	float Dampening[balls];
	for (int i = 0; i < balls; i++)
	{
		ClockTimeSinceLastBounce[i] = millis();
		Height[i] = start;
		Position[i] = 0;
		ImpactVelocity[i] = ImpactVelocityStart;
		TimeSinceLastBounce[i] = 0;
		Dampening[i] = 0.90 - float(i) / pow(balls, 2);
	}
	while (true)
	{
		for (int i = 0; i < balls; i++)
		{
			TimeSinceLastBounce[i] = millis() - ClockTimeSinceLastBounce[i];
			Height[i] = 0.5 * gravity * pow(TimeSinceLastBounce[i] /1000, 2.0) + ImpactVelocity[i] * TimeSinceLastBounce[i] /1000;
			if (Height[i] < 0)
			{
				Height[i] = 0;
				ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
				ClockTimeSinceLastBounce[i] = millis();
				if (ImpactVelocity[i] < 0.01)
				{
					ImpactVelocity[i] = ImpactVelocityStart;
				}
			}
			Position[i] = round(Height[i] * (NUM_LEDS - 1) / start);
		}
		for (int i = 0; i < balls; i++)
		{
			strip.setPixelColor(Position[i], colors[i][0], colors[i][1], colors[i][2], colors[i][3]);
		}
		strip.show();
		setAll(0, 0, 0, 0);
	}
}

// Fire simulated
// ARDUINO ONLY !!!
void Fire(int cooling, int sparkling, int wait)
{
	static byte heat[NUM_LEDS];
	int cooldown;
	// Step 1.  Cool down every cell a little
	for (int i = 0; i < NUM_LEDS; i++)
	{
		cooldown = random(0,((cooling * 10) / NUM_LEDS) + 2);
		if (cooldown > heat[i])
		{
			heat[i] = 0;
		}
		else
		{
			heat[i] = heat[i] - cooldown;
		}
	}
	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = NUM_LEDS - 1; k >= 2; k--)
	{
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}
	// Step 3.  Randomly ignite new 'sparks' near the bottom
	if (random(255) < sparkling)
	{
		int y = random(7);
		heat[y] = heat[y] + random(160, 255);
	}
	// Step 4.  Convert heat to LED colors
	for (int j = 0; j < NUM_LEDS; j++)
	{
		setPixelHeatColor(j, heat[j]);
	}
	strip.show();
	delay(wait);
}

void setPixelHeatColor(int Pixel, byte temperature)
{
	// Scale 'heat' down from 0-255 to 0-191
	byte t192 = round((temperature/255.0) * 191);
	// calculate ramp up from
	byte heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2; // scale up to 0..252
	// figure out which third of the spectrum we're in:
	if (t192 > 0x80)
	{
		// hottest
		strip.setPixelColor(Pixel, 255, 255, heatramp);
	}
	else
		if (t192 > 0x40)
		{
			// middle
			strip.setPixelColor(Pixel, 255, heatramp, 0);
		}
	else
	{
		// coolest
		strip.setPixelColor(Pixel, heatramp, 0, 0);
	}
}

// shows a ripple through the strip like a drop of water hitting a pond
void ripple(bool background)
{
	if (background)
	{
		if (currentBg == nextBg)
		{
			nextBg = random(256);
		}
		else
			if (nextBg > currentBg)
			{
				currentBg++;
			}
		else
		{
			currentBg--;
		}
		for (uint16_t l = 0; l < NUM_LEDS; l++)
		{
			strip.setPixelColor(l, Wheel(currentBg, 0.1));
		}
	}
	else
	{
		for (uint16_t l = 0; l < NUM_LEDS; l++)
		{
			strip.setPixelColor(l, 0, 0, 0);
		}
	}
	if (step == -1)
	{
		center = random(NUM_LEDS);
		color = random(256);
		step = 0;
	}
	if (step == 0)
	{
		strip.setPixelColor(center, Wheel(color, 1));
		step++;
	}
	else
	{
		if (step < maxSteps)
		{
			strip.setPixelColor(wrap(center + step), Wheel(color, pow(fadeRate, step)));
			strip.setPixelColor(wrap(center - step), Wheel(color, pow(fadeRate, step)));
			if (step > 3)
			{
				strip.setPixelColor(wrap(center + step - 3), Wheel(color, pow(fadeRate, step - 2)));
				strip.setPixelColor(wrap(center - step + 3), Wheel(color, pow(fadeRate, step - 2)));
			}
			step++;
		}
		else
		{
			step = -1;
		}
	}
	strip.show();
	delay(50);
}

int wrap(int step)
{
	if (step < 0)
		return NUM_LEDS + step;
	if (step > NUM_LEDS - 1)
		return step - NUM_LEDS;
	return step;
}

// Shows a meteor with trail in a given color
void meteorRain(uint8_t red, uint8_t green, uint8_t blue, uint8_t white, uint8_t meteorSize, uint8_t meteorTrailDecay, boolean meteorRandomDecay, uint8_t wait)
{
	setAll(0, 0, 0, 0);
	for (int i = 0; i < NUM_LEDS + NUM_LEDS; i++)
	{
		// fade brightness all LEDs one step
		for (int j = 0; j < NUM_LEDS; j++)
		{
			if ((!meteorRandomDecay) || (random(10) > 5))
			{
				fadeToBlack(j, meteorTrailDecay);
			}
		}
		// draw meteor
		for (int j = 0; j < meteorSize; j++)
		{
			if ((i - j < NUM_LEDS) && (i - j >= 0))
			{
				strip.setPixelColor(i - j, red, green, blue, white);
			}
		}
		strip.show();
		delay(wait);
	}
}

// Shows a meteor with trail in rainbow colors
void meteorRainbow(uint8_t meteorSize, uint8_t meteorTrailDecay, boolean meteorRandomDecay, uint8_t wait)
{
	setAll(0, 0, 0, 0);
	for (int i = 0; i < (NUM_LEDS * 2); i++)
	{
		// fade brightness all LEDs one step
		for (int j = 0; j < NUM_LEDS; j++)
		{
			if ((!meteorRandomDecay) || (random(10) > 5))
			{
				fadeToBlack(j, meteorTrailDecay);
			}
		}
		// draw meteor
		for (int j = 0; j < meteorSize; j++)
		{
			if ((i - j < NUM_LEDS) && (i - j >= 0))
			{
				strip.setPixelColor(i - j, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
			}
		}
		strip.show();
		delay(wait);
	}
}

// Lights racing inspired by the shuttle run
// ARDUINO ONLY !!!
void shuttleRunRainbow(uint8_t loops, float increase, uint8_t wait)
{
	for (int j = 0; j < loops; j++)
	{
		for (int runs = 1; runs <= loops; runs++)
		{
			for (int i = 0; i < NUM_LEDS; i++)
			{
				strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
				strip.show();
				strip.setPixelColor(i, 0);
				delay(wait);
			}
			for (int i = NUM_LEDS; i >= 0; i--)
			{
				strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
				strip.show();
				strip.setPixelColor(i, 0);
				delay(wait);
			}
			if (wait > 5)
			{
				wait = wait * increase;
			}
		}
	}
}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fades pixels to black
void fadeToBlack(int ledNo, byte fadeValue)
{
	uint32_t oldColor;
	uint8_t r, g, b;
	int value;
	oldColor = strip.getPixelColor(ledNo);
	r = (oldColor & 0x00ff0000UL) >> 16;
	g = (oldColor & 0x0000ff00UL) >> 8;
	b = (oldColor & 0x000000ffUL);
	r = (r <= 10)? 0:(int) r - (r * fadeValue/256);
	g = (g <= 10)? 0:(int) g - (g * fadeValue/256);
	b = (b <= 10)? 0:(int) b - (b * fadeValue/256);
	strip.setPixelColor(ledNo, r, g, b);
}

// Sets all pixels to one color
void setAll(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
	for (int i = 0; i < NUM_LEDS; i++)
	{
		strip.setPixelColor(i, red, green, blue, white);
	}
	strip.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85)
	{
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
	}
	if (WheelPos < 170)
	{
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
	}
	WheelPos -= 170;
	return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos, float opacity)
{
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85)
	{
		return strip.Color((WheelPos * 3) * opacity,(255 - WheelPos * 3) * opacity, 0);
	}
	if (WheelPos < 170)
	{
		WheelPos -= 85;
		return strip.Color((255 - WheelPos * 3) * opacity, 0,(WheelPos * 3) * opacity);
	}
	WheelPos -= 170;
	return strip.Color(0,(WheelPos * 3) * opacity,(255 - WheelPos * 3) * opacity);
}

uint8_t Red(uint32_t c)
{
	return(c >> 16);
}

uint8_t Green(uint32_t c)
{
	return(c >> 8);
}

uint8_t Blue(uint32_t c)
{
	return(c);
}
