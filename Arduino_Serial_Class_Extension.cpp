#include "Arduino_Serial_Class_Extension.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>

SerialClassExtension::SerialClassExtension(SoftwareSerial *serial)
{
    hwserial = false;
    port = serial;
}

SerialClassExtension::SerialClassExtension(HardwareSerial *serial)
{
    hwserial = true;
    port = serial;
}

void SerialClassExtension::begin(long baudrate)
{
    if(hwserial) {
        static_cast<HardwareSerial*>(port)->begin(baudrate);
    } else {
        static_cast<SoftwareSerial*>(port)->begin(baudrate);
    }
}

/*uint8_t SerialClassExtension::send(uint8_t arg){
    port->write(arg);
}*/

uint8_t SerialClassExtension::read(){
    port->read();
}

uint8_t SerialClassExtension::write(uint8_t args){
    port->write(args);
}

int SerialClassExtension::available(){
    port->available();
}
