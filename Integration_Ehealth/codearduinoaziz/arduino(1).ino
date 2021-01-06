#include <SimpleDHT.h>
int pinDHT11 = 4;
int pinled = 7;
int incomingByte =0;
SimpleDHT11 dht11;
int err = SimpleDHTErrSuccess;
// =======================================================================
void setup() {
  Serial.begin(9600);
  pinMode(pinled,OUTPUT);
  // Initialisation de l'écran LCD
}
// =======================================================================
void loop() {
  // Affichage sur le terminal
  
  // Lecture de la température et de l'humidité ------------------
  byte temperature = 0;
  byte humidity = 0;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    // Si on n'arrive pas à lire les données.
    delay(25);
    return;
  }
  Serial.print((int)temperature);
  // Ecran LCD --------------------------------------------------

  if (Serial.available()>0){
    incomingByte=Serial.read();
    if (incomingByte==48){
      digitalWrite(pinled,LOW);
    }
    if (incomingByte==49){
      digitalWrite(pinled,HIGH);
    }
  }
  delay(50);
}
