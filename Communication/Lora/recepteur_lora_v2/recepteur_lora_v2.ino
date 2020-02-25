#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); //mySerial(RX, TX); 
int SerialValue;
int ledPin = 13;
String receivedData;

void setup(){
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
 while (!Serial){}
 mySerial.begin(9600);
}

void loop(){
  //Serial.write("in");
 if (mySerial.available()){
  digitalWrite(ledPin,HIGH);
   receivedData = mySerial.readString();
   Serial.println(receivedData);
 }else digitalWrite(ledPin,LOW);
 
 if (Serial.available())
  mySerial.write(Serial.read());
}
