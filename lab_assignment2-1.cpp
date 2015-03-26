// Do not remove the include below
#include "lab_assignment2-1.h"


#define FRONT_LED_PIN 10
#define REAR_LED_PIN 9


//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(FRONT_LED_PIN, OUTPUT);
	pinMode(REAR_LED_PIN, OUTPUT);

	digitalWrite(FRONT_LED_PIN, LOW);
	digitalWrite(REAR_LED_PIN, HIGH);
}

// The loop function is called in an endless loop
void loop()
{
	int front_brightness=0;
	int rear_brightness=255;
	int brightness_change=51;

	int i=0;

	for(i=0;i<5;i++){
		front_brightness=front_brightness+brightness_change;
		rear_brightness=rear_brightness-brightness_change;
		analogWrite(FRONT_LED_PIN, front_brightness);
		analogWrite(REAR_LED_PIN, rear_brightness);
		delay(1000);

	}

	for(i=0;i<5;i++){
		front_brightness=front_brightness-brightness_change;
		rear_brightness=rear_brightness+brightness_change;
		analogWrite(FRONT_LED_PIN, front_brightness);
		analogWrite(REAR_LED_PIN, rear_brightness);
		delay(1000);
	}

}
