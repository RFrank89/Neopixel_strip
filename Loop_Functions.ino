void demoLoop()
{
	setAll(0, 0, 0, 0);
	delay(2500); // sanity delay
	colorDutchStrip(25);
	colorFill(255, 0, 0, 0, 25); // Red
	colorFillReverse(0, 255, 0, 0, 25); // Green
	colorFill(0, 0, 255, 0, 25); // Blue
	colorFillReverse(255, 0, 0, 0, 25); // Red
	colorFill(0, 0, 0, 255, 25); // White
	colorFillReverse(0, 0, 255, 0, 25); // Blue
	colorFill(255, 153, 0, 0, 25); // Orange
	colorFillReverse(0, 0, 0, 0, 25); // Off
	delay(500);
	colorIntensityWipe(255, 0, 0, 0); // r, g, b, w
	colorIntensityWipe(0, 255, 0, 0);
	colorIntensityWipe(0, 0, 255, 0);
	colorIntensityWipe(255, 255, 255, 255);
	delay(500);
	stripFill(0, 0, 255, 0, 5); // r, g, b, w, delay
	stripEmpty(0, 0, 255, 0, 5);
	stripFillReverse(0, 255, 0, 0, 5);
	stripEmptyReverse(0, 255, 0, 0, 5);
	delay(500);
	brightnessPulse(255, 0, 0, 0, 5); // r, g, b, w, delay
	brightnessPulse(0, 0, 255, 0, 5);
	brightnessPulse(0, 0, 0, 255, 5);
	delay(500);
	randomStripFill(5); // delay
	randomStripFill2(5); // delay
	delay(500);
	KITTPulse(255, 0, 0, 0, 5, 10, 25); // r, g, b, w, movelenght, speed, delay
	KITTPulse(0, 255, 0, 0, 5, 10, 25);
	KITTPulse(0, 0, 255, 0, 5, 10, 25);
	KITTPulse(0, 0, 0, 255, 5, 10, 25);
	delay(500);
	newKITT(255, 0, 0, 0, 5, 10, 25);
	delay(500);
	strobe(0, 0, 0, 255, 10, 10, 200, 64); // r, g, b, w, flashes, flashdelay, delay, brightness
	strobe(255, 0, 0, 0, 10, 10, 200, 64);
	strobe(0, 0, 255, 0, 10, 10, 200, 64);
	delay(500);
	sineWaveLights(255, 0, 0, 0, 50); // r, g, b, w, delay
	delay(500);
	sineWaveLightsReverse(255, 0, 0, 0, 50);
	delay(500);
	displayBitsAdder(255, 255, 0, 0, 256); // r, g, b, w, digit
	delay(500);
	rainbowLoops(3, 10); // loops, delay
	delay(500);
	crawlingLights(255, 0, 255, 0, 10, 6, 50); // red, green, blue, white, loops, crawl, delay
	delay(500);
	crawlingLightsReverse(0, 255, 0, 32, 10, 6, 50);
	delay(500);
	racingLights(0, 255, 255, 0, 20, 0.75, 250); // r, g, b, w, loops, speed decrease, initial delay
	delay(500);
	racingLightsReverse(0, 255, 255, 0, 20, 0.75, 250);
	delay(500);
	shuttleRun(255, 0, 0, 0, 20, 0.75, 250); // r, g, b, w, loops, speed decrease, initial delay
	delay(500);
	randomPositionLights(0, 0, 255, 0, 50); // r, g, b, w, delay
	delay(500);
	xmasLights(100); // delay
	delay(500);
	growingSnake(0, 255, 0, 0, 10); // r, g, b, w, delay
	delay(500);
	middleToOutside(0, 0, 255, 0, 5, 10, 25); // r, g, b, w, movesize, speeddelay, returndelay
	delay(500);
	outsideToMiddle(0, 0, 255, 0, 5, 10, 25); // r, g, b, w, movesize, speeddelay, returndelay
	delay(500);
	LightUpOutsideIn(255, 0, 0, 0, 25); // r, g, b, w, delay
	LightOffOutsideIn(255, 0, 0, 0, 25);
	delay(500);
	LightUpInsideOut(255, 0, 0, 0, 25);
	LightOffInsideOut(255, 0, 0, 0, 25);
	delay(500);
	RandomPositionRandomColor(25); // delay
	delay(500);
	Fire(50, 120, 50); // cooling, sparkling delay
	Fire(50, 120, 50);
	Fire(50, 120, 50);
	delay(500);
	ripple(false); // background
	ripple(false);
	ripple(false);
	delay(500);
	meteorRain(0, 0, 255, 0, 1, 48, true, 50); // r, g, b, w, size, trail decay speed, trail random decay, delay
	meteorRain(0, 0, 255, 0, 1, 48, true, 50);
	meteorRain(0, 0, 255, 0, 1, 48, true, 50);
	delay(500);
	meteorRainbow(8, 64, true, 25); // size, trail decay speed, trail random decay, delay
	meteorRainbow(8, 64, true, 25);
	meteorRainbow(8, 64, true, 25);
	delay(500);
}

void officeDemo()
{
	setAll(0, 0, 0, 0);
	delay(2500);
	colorDutchStrip(25);
	delay(1000);
	colorFill(255, 0, 0, 0, 25);
	colorFillReverse(0, 255, 0, 0, 25);
	colorFill(0, 0, 255, 0, 25);
	colorFillReverse(0, 0, 0, 255, 25);
	delay(1000);
	colorIntensityWipe(0, 255, 0, 0);
	delay(1000);
	brightnessPulse(255, 0, 0, 0, 5);
	delay(1000);
	stripFill(0, 0, 255, 0, 5);
	stripEmpty(0, 0, 255, 0, 5);
	stripFillReverse(0, 255, 0, 0, 5);
	stripEmptyReverse(0, 255, 0, 0, 5);
	delay(1000);
	randomStripFill(5);
	delay(1000);
	randomStripFill2(5);
	setAll(0, 0, 0, 0);
	delay(1000);
	randomPositionLights(0, 0, 255, 0, 50);
	delay(1000);
	RandomPositionRandomColor(25);
	delay(1000);
	xmasLights(100);
	delay(1000);
	strobe(255, 0, 0, 0, 50, 10, 200, 64);
	delay(1000);
	KITTPulse(255, 0, 0, 0, 5, 10, 25);
	KITTPulse(255, 0, 0, 0, 5, 10, 25);
	KITTPulse(255, 0, 0, 0, 5, 10, 25);
	delay(1000);
	newKITT(255, 0, 0, 0, 5, 10, 25);
	delay(1000);
	sineWaveLights(255, 0, 0, 0, 50);
	delay(1000);
	displayBitsAdder(255, 255, 0, 0, 512);
	delay(1000);
	crawlingLights(255, 0, 255, 0, 20, 6, 50);
	crawlingLightsReverse(255, 0, 255, 0, 20, 6, 50);
	delay(1000);
	racingLights(0, 255, 255, 0, 20, 0.75, 100);
	delay(1000);
	shuttleRun(255, 0, 0, 0, 20, 0.75, 100);
	delay(1000);
	growingSnake(0, 255, 0, 0, 10);
	delay(1000);
	middleToOutside(0, 0, 255, 0, 5, 10, 25);
	delay(1000);
	outsideToMiddle(0, 0, 255, 0, 5, 10, 25);
	delay(1000);
	LightUpOutsideIn(255, 0, 0, 0, 25);
	LightOffOutsideIn(255, 0, 0, 0, 25);
	delay(200);
	LightUpInsideOut(255, 0, 0, 0, 25);
	LightOffInsideOut(255, 0, 0, 0, 25);
	delay(1000);
	rainbowLoops(5, 10);
	delay(1000);
	Fire(50, 120, 50);
	delay(1000);
	BouncingLightsColors(5);
	delay(1000);
	xmasLights2(strip.Color(255, 0, 0), strip.Color(0, 255, 0), 250);
	delay(1000);
	ripple(false);
	delay(1000);
}
