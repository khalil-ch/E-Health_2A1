#include <dht11.h>
#define DHT11PIN 4 // broche DATA -> broche 4

dht11 DHT11;
 int pinled =7;
 int incomingByte =0; 
void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB (LEONARDO)
  }
  
  
}
 
void loop()
{
  DHT11.read(DHT11PIN);
  Serial.println(DHT11.temperature);
   
    incomingByte=Serial.read();
    if(incomingByte==48 )
    {
      digitalWrite(pinled,LOW);
      
    }
    
    if(DHT11.temperature >=30)
    {
      digitalWrite(pinled,HIGH);
    }
    else 
    digitalWrite(pinled,LOW);
      
  delay(2000);
}
