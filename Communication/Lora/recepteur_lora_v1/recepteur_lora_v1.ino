#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); //mySerial(10, 11); RX, TX
int SerialValue;
int ledPin = 13;

void setup(){
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
 while (!Serial){}
 mySerial.begin(9600);
}

void loop(){
  //Serial.write("in");
 if (mySerial.available()){
   SerialValue = mySerial.read();
   Serial.write(SerialValue);
   if (SerialValue == '1'){
    digitalWrite(ledPin,HIGH);
   }
   else if (SerialValue == '0'){
    digitalWrite(ledPin,LOW);
   }
 }
 if (Serial.available())
  mySerial.write(Serial.read());
}
