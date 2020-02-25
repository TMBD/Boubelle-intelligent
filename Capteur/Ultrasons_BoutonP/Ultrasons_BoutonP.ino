#define ULTRASON_TRIG_PIN  7
#define ULTRASON_ECHO_PIN  8


///////////ULTRASON////////////////////////////
//#define SECURITY_DISTANCE_MM 200
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~08m à 340m/s
float tab[]={100,500,1000,2000};
int s;
int pinBouton, pinLed, SECURITY_DISTANCE_MM;
boolean etatAllumage;
/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

const int LED = 5;
void setup() {
  Serial.begin(9600); // Debugging only
  // put your setup code here, to run once:
  ////////////ULTRASON////////////////////
  pinMode(ULTRASON_TRIG_PIN, OUTPUT);
  digitalWrite(ULTRASON_TRIG_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ULTRASON_ECHO_PIN, INPUT);
  pinMode(LED, OUTPUT);
  pinBouton =2;
pinLed = 3;
etatAllumage=0;
SECURITY_DISTANCE_MM=100;
s=0;
pinMode(pinBouton, INPUT_PULLUP);
pinMode(pinLed, OUTPUT);

}

void loop() {
  if(etatAllumage)
{
  digitalWrite(pinLed, HIGH);

}
else
{
  digitalWrite(pinLed, LOW);
  
}
  boolean etatPinBouton = digitalRead(pinBouton);
    Serial.println(SECURITY_DISTANCE_MM);

  //Serial.println(etatPinBouton);
  if (!etatPinBouton){
    if (s<4){
      SECURITY_DISTANCE_MM = tab[s];;
      s+=1;
    }
    else{
      s=0;
      SECURITY_DISTANCE_MM = tab[s];
    }
    if(etatAllumage){
      etatAllumage=0;
    }
    else
    {
      etatAllumage=1;
     
    }
  }

  // put your main code here, to run repeatedly:
  
  if(obstacle()){
    Serial.println("obstacle detecté");
    digitalWrite(LED,HIGH);
  }
  else {
    Serial.println("aucun obstacle detecté");
        digitalWrite(LED,LOW);

  }
    delay(200);

}






bool obstacle(){
  digitalWrite(ULTRASON_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASON_TRIG_PIN, LOW);

  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ULTRASON_ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  int distance_mm = measure / 2.0 * SOUND_SPEED;
  //Serial.println("-----------obstacle----------");
  Serial.println(distance_mm);
  if(distance_mm < SECURITY_DISTANCE_MM) return true;
  else return false;
}
