#pragma once
#ifndef SerialClassExtension_H
#define SerialClassExtension_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>

class SerialClassExtension
{
private:
    bool hwserial;
    Stream *port;
public:
    SerialClassExtension::SerialClassExtension(SoftwareSerial *serial);
    SerialClassExtension::SerialClassExtension(HardwareSerial *serial);
    virtual void begin(long baud);
    //virtual uint8_t send(uint8_t arg);
    virtual uint8_t read();
    virtual uint8_t write(uint8_t args);
    virtual int available();
};
#endif
