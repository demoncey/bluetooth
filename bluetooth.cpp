#include "Arduino.h"
#include "bluetooth.h"
#include <SoftwareSerial.h> 
Bluetooth::Bluetooth(uint8_t rx,uint8_t tx,uint8_t read_led,uint8_t write_led,uint8_t delay_time):bluetooth(SoftwareSerial(rx,tx)),interval(delay_time)
{
  
  this->write_led=read_led;
  this->read_led=write_led;
  
}

Bluetooth::Bluetooth(uint8_t rx,uint8_t tx,uint8_t delay_time):bluetooth(SoftwareSerial(rx,tx)),write_led(0),read_led(0),interval(delay_time)
{
  
}

void Bluetooth::init()
{
	bluetooth.begin(38400);
}


void Bluetooth::send(String msg)
{
	digitalWrite(write_led,HIGH);
	bluetooth.println(msg);
	delay(interval);
	digitalWrite(write_led,LOW);
}

String Bluetooth::recv()
{
	String recived="";
	bool switch_on=true;
	while(bluetooth.available()>0){
		if(switch_on){
			digitalWrite(read_led,HIGH);
			switch_on=false;
			delay(interval);
		}
		char c = bluetooth.read();
		recived+=c;
	}
	digitalWrite(read_led,LOW);
	return recived;
}
