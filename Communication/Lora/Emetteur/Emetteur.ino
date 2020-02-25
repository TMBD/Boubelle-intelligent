
String texte = "je suis adil";

void setup(){
 Serial.begin(9600);
}

void loop(){
 Serial.print(texte);
 delay(1000);
 Serial.print(1, BIN);
 delay(1000);


  
 //Serial.print(0, BIN);
 //delay(1000);
 //Serial.print(1, BIN);
 //delay(1000);
 
}
