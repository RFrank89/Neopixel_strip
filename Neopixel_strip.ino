#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>

// Blynk app auth token
char auth[] = "95abdd251dbb4e519f6782cc89fbc1f2";

// WiFi credentials
char ssid[] = "May_The_Wifi_Be_With_You";
char pass[] = "Luke_Im_Your_Father";

#define PIN 0
#define NUM_LEDS 60
#define BRIGHTNESS 128
#define Scene_MEM 0
#define Brightness_MEM 1
#define Red_MEM 2
#define Green_MEM 3
#define Blue_MEM 4
#define White_MEM 5

int scene = 3; 
int brightness = 128;
int r = 128;
int g = 64; 
int b = 128;
int white = 255;
int area;
int current_scene;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

BLYNK_WRITE(V0)
{
	r = param[0].asInt();
	g = param[1].asInt();
	b = param[2].asInt();
	EEPROM.write(Red_MEM,r);
	EEPROM.write(Green_MEM,g);
	EEPROM.write(Blue_MEM,b);
	EEPROM.commit();
	Serial.println("set red: " + String(r));
	Serial.println("set green: " + String(g));
	Serial.println("set blue: " + String(b));
}

BLYNK_WRITE(V1)
{
	scene = param.asInt();
	EEPROM.write(Scene_MEM,scene);
	EEPROM.commit();
	Serial.println("set scene: " + String(scene));
}

BLYNK_WRITE(V2)
{
	brightness = param.asInt();
	strip.setBrightness(brightness);
	EEPROM.write(Brightness_MEM, brightness);
	EEPROM.commit();
	Serial.println("set brightness: " + String(brightness));
}

BLYNK_WRITE(V3)
{
	area = param.asInt();

	if (area == 1)
	{
		scene = -3;
	}
	else if (area == 2)
	{
		scene = -2;
	}
	else if (area == 3)
	{
		scene = -1;
	}
}

BLYNK_WRITE(V4)
{
	white = param.asInt();
	EEPROM.write(White_MEM, white);
	EEPROM.commit();
	Serial.println("Set white level: "+ String(white));
}

void setup()
{
	// Debug console
	Serial.begin(9600);
	Blynk.begin(auth, ssid, pass);

	EEPROM.begin(512);
	scene = EEPROM.read(Scene_MEM);
	brightness = EEPROM.read(Brightness_MEM);
	r = EEPROM.read(Red_MEM);
	g = EEPROM.read(Green_MEM);
	b = EEPROM.read(Blue_MEM);

	strip.setBrightness(brightness);
	strip.begin();
	strip.show();

	Serial.println("start up scene: " + String(scene));
	Serial.println("start up brightness: " + String(brightness));
}

void loop()
{
	Blynk.run();
	switch (scene)
	{
		case -3:			
			setTV(r, g, b, 0);
			break;
		case -2:
			setPC(r, g, b, 0);
			break;
		case -1:
			setDinner(r, g, b, 0);
			break;
		case 0:
			setAll(r, g, b, 0);
			break;
		case 1:
			KITTPulse(r, g, b, 0, 5, 25, 25); // r, g, b, w, movelenght, speed, delay
			break;
		case 2:
			randomPositionLights(r, g, b, 0, 20); // r, g, b, w, delay
			break;
		case 3:
			rainbowLoops(1, 5); // loops, delay
			break;
		case 4:
			meteorRain(r, g, b, 0, 1, 48, true, 50); // r, g, b, w, meteor size, trail decay speed, random trail decay bool, delay
			break;
		case 5:
			crawlingLightsRainbow(1, 4, 75); // loops, crawl, delay
			break;
		case 6:
			LightUpOutsideIn(r, g, b, 0, 50);
			delay(500);
			LightOffInsideOut(r, g, b, 0, 50);
			break;
		case 7:
			LightUpInsideOut(r, g, b, 0, 50);
			delay(500);
			LightOffOutsideIn(r, g, b, 0, 50);
			break;
		case 8:
			colorDutchStrip(25); // delay
			break;
		case 9:
			xmasLights2(strip.Color(255, 0, 0), strip.Color(0, 255, 0), 250);			
			break;
		case 10:
			RandomPositionRandomColor(25); // delay
			break;
		case 11:
			ripple(false); // background
			break;
		case 12:
			meteorRainbow(5, 64, false, 25); // meteor size, trail decay speed, random trial decay bool, delay
			break;
		default:
			setAll(0,0,0,white);
			break;
	}
}
