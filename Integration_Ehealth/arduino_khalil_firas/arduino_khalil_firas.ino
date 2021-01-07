#include <SPI.h>
#include <MFRC522.h>
String msg;
String a;
int led_rouge =5;
int led_blue =7;
int i;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup() {
  Serial.begin(9600);
  pinMode(led_rouge,OUTPUT);
  pinMode(led_blue,OUTPUT);


  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop() {
if (Serial.available() > 0)
  {
    a = Serial.readString();


    if(a=="yes")
{
digitalWrite(led_blue,HIGH);
delay(2000);
digitalWrite(led_blue,LOW);




}
if(a=="no")
{
digitalWrite(led_rouge,HIGH);
delay(2000);
digitalWrite(led_rouge,LOW);




}

  }







  
 // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
 
String content= "";
String msg = "";
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     /*Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);*/
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }


  content.toUpperCase();
 
msg =content+"#";
 //send data
//delay (5000);
 
 for(i=0;i<msg.length();i++)
    {
        Serial.write(msg[i]);
        delay (100);

    }
     //delay (1500);


}
