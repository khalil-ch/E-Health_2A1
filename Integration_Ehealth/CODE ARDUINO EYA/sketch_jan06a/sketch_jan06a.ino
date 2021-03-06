#include <LiquidCrystal.h>
LiquidCrystal lcd(2,7,11,10,9,8);
int contraste =70;
int rawValue;

  
bool heartbeatDetected(int IRSensorPin, int delay)
{
 static int maxValue = 0;
 static bool isPeak = false;
  
  
 bool result = false;
  
 rawValue = analogRead(IRSensorPin);
 // La tension au phototransistor est lue et stockée dans la variable rawValue
 rawValue *= (1000/delay);
  
 // Si la valeur de la dernière mesure dévie trop 
 // (par exemple parce que le doigt a été enlevé ou a bougé)
 // maxValue se réinitialise
 if (rawValue * 4L < maxValue) { maxValue = rawValue * 0.8;  }  
 // Detect new peak 
 if (rawValue > maxValue - (1000/delay)) {
 // Détection de l'impulsion. Si la nouvelle rawValue est plus grande
 // que la dernière valeur maximale, elle sera prise en compte en enregistrée
 if (rawValue > maxValue) {
 maxValue = rawValue;
 }
 // Attribution des pulsations
 if (isPeak == false) {
 result = true;
 }
 isPeak = true;
 } else if (rawValue < maxValue - (3000/delay)) {
 isPeak = false;
 // La valeur maximale est légèrement diminuée à chaque passage.
 // Cela peut prendre plusieurs secondes pour détecter de nouveau
 // le signal lorsque le doigt a bougé ou que le capteur est devant
 // une partie osseuse du doigt. On peut aussi vérifier le délai
 // depuis la dernière pulsation et s'il excède 1 seconde, on
 // rénitialise maxValue
 maxValue-=(1000/delay);
 }
 return result;
}
 
  
////////////////////////////////////////////////////////////////////////
// Arduino main code
////////////////////////////////////////////////////////////////////////

int analogPin=0;
  
void setup()
{  
  lcd.begin(16, 2);
  Serial.begin(9600);
 analogWrite(6, contraste);

  
 // Initialisation de la sortie série

Serial.println("la pulsations:");
  
}
  
const int delayMsec = 60; // 100msec per sample
  
// Le programme principal a deux sorties:
// - L'impulsion est calculée et envoyée vers la sortie série.
  
void loop()
{

      lcd.setCursor(2,0);
      lcd.print("BPM");
      lcd.setCursor(1,2);
      lcd.print(rawValue);
      delay(300);

       int heartRateBPM = 0;  
    static int beatMsec = 0;

 if (heartbeatDetected(analogPin, delayMsec)) {
 heartRateBPM = 60000 / beatMsec;

 
 // Envoi des données série
 Serial.print(rawValue);
 Serial.print("BPM, ");

      

 //beatMsec = 0;
 }
 delay(delayMsec);
 beatMsec += delayMsec;
 
 }
