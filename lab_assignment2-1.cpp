// Do not remove the include below
#include "lab_assignment2-1.h"


#define FRONT_LED_PIN 10
#define REAR_LED_PIN 9
#define DUTY_CYCLE 20 //20ms

int done = false;

void PWM_Write(int pin, int on_time_perc)
{
	int on_time = DUTY_CYCLE*on_time_perc/100.0;
	int off_time = DUTY_CYCLE - on_time;
	digitalWrite(pin, HIGH);
	delay(on_time);
	digitalWrite(pin, LOW);
	delay(off_time);
}
void myAnalogWrite(int pin, int percent, int time)
{
	int num_loops = time/DUTY_CYCLE;
	int i;
	for (i=0; i<num_loops; i++)
	{
		PWM_Write(pin, percent);
	}
}
//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(REAR_LED_PIN, OUTPUT);
}
// The loop function is called in an endless loop
void loop()
{
	if (done == false)
	{
		int value = 100;
		int value_interval = 5;
		int total_duration = 10000; //10,000ms
		int time_per_step = total_duration/(value/value_interval);
		while (value > 0)
		{
			myAnalogWrite(REAR_LED_PIN, value, time_per_step);
			value -= value_interval;
		}
		done = true;
	}
	else
		digitalWrite(REAR_LED_PIN, LOW);
}
