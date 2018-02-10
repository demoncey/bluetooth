#ifndef blueTooth_h
#define blueTooth_h
#include "Arduino.h"
#include <SoftwareSerial.h> 
class Bluetooth
{
  public:
    Bluetooth(uint8_t rx,uint8_t tx,uint8_t read_led,uint8_t write_led,uint8_t delay_time);
	Bluetooth(uint8_t rx,uint8_t tx,uint8_t delay_time);
    void init();
    void send(String msg);
	String recv();
  private:
	SoftwareSerial bluetooth;
	uint8_t interval;
	uint8_t read_led;
	uint8_t write_led;
};

#endif
