int pinBouton, pinLed;
boolean etatAllumage;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinBouton =2;
pinLed = 3;
etatAllumage=0;
pinMode(pinBouton, INPUT_PULLUP);
pinMode(pinLed, OUTPUT);
}

void loop() {
Serial.print(etatAllumage);
if(etatAllumage)
{
  digitalWrite(pinLed, HIGH);
}
else
{
  digitalWrite(pinLed, LOW);
}
  boolean etatPinBouton = digitalRead(pinBouton);
  Serial.println(etatPinBouton);
  if (!etatPinBouton){
    if(etatAllumage){
      etatAllumage=0;
    }
    else
    {
      etatAllumage=1;
    }
  }
  delay(200);
}
