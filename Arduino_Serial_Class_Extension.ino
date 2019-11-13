#include "Arduino_Serial_Class_Extension.h"
#include <SoftwareSerial.h>

static const int RXPin = 10, TXPin = 11;
static const uint32_t Baud = 9600;
SoftwareSerial ss( RXPin, TXPin );
SerialClassExtension ReadFromUno(&ss); // SoftwareSerial

#define SERIAL1
#define SERIAL2

// Uno and Mini
//SerialClassExtension com1(&Serial); // HardwareSerial

//SerialClassExtension ReadFromUno(&Serial1); // HardwareSerial
SerialClassExtension ReadFromMini(&Serial2); // HardwareSerial

void setup() {
  Serial.begin(19200);

  // Uno
  //com1.begin(Baud);
  //com1.write("Uno Serial 1!");

  // Mini
  //com1.begin(Baud);
  //com1.write("Mini Serial 1!");

  #ifdef SERIAL1
    ReadFromUno.begin(Baud);
  #endif
  #ifdef SERIAL2
    ReadFromMini.begin(Baud);
  #endif
}

void loop() {
  char dataFromUno, dataFromMini;
  int numc;
  delay(1000);

  // Uno
  //com1.write("Uno - Serial1!");

  // Mini
  //com1.write("Mini - Serial1!");

#ifdef SERIAL1
  // Read from Uno
  numc = ReadFromUno.available();
  if(numc > 0){
    
    for (int i=0;i<numc;i++){
      dataFromUno = ReadFromUno.read();
      if(dataFromUno == "\n"){
        break;
      }else{
        Serial.print("Data from Uno, received: ");
        Serial.println(dataFromUno);
      }
    }
  }else{
    Serial.println("Not able to read from serial 1 ! ");
  }
#endif

#ifdef SERIAL2
  // Read from Mini
  numc = ReadFromMini.available();
  if(numc > 0){
    
    for (int i=0;i<numc;i++){
      dataFromMini = ReadFromMini.read();
      if(dataFromMini == "\n"){
        break;
      }else{
        Serial.print("Data from Mini, received: ");
        Serial.println(dataFromMini);
      }
    }
  }else{
    Serial.println("Not able to read from serial 2 ! ");
  }
#endif
}
