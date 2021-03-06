#define SENSOR  8 //soil sensor digital pin connected to pin 8
#define LDR  A0//light dependent resistor is connected to A0
#define PORTNUMBER  9600 // opens serial port, sets data rate to 9600 bps

void setup()
{
   Serial.begin(PORTNUMBER); 
   pinMode(13,OUTPUT); //Set pin 13 as OUTPUT green pin
   pinMode(12,OUTPUT); //Set pin 12 as OUTPUT red pin
   pinMode(SENSOR,INPUT); //Set pin 8 as input pin, to receive data from Soil moisture sensor.
   pinMode(LDR,INPUT);
   digitalWrite(13,LOW);//LED 13 should be off initally
   digitalWrite(12,LOW);//LED 12 should be off initally


}

void loop() 
{ 
  
  int val = digitalRead(SENSOR); //stores the value received from Soil moisture sensor in variable val 
  int LDRValue=analogRead(LDR);//stores the value received from LDR in variable LDRValue 
  
   if(LDRValue <= 400  &&  val==HIGH)
  {
   
     Serial.print("Its dark and soil is dry so pump will be turned on. LDR value is: ");
     Serial.println(LDRValue);//Print LDR value
     Serial.println(val);   	//print soil moisture sensor value
     digitalWrite(12,HIGH);//pump has to be turned on
     digitalWrite(13,LOW);
     return;   
  }

else if(LDRValue <=400 && val==LOW)
{
Serial.print("Its dark and soil is perfect so pump will be turned off. LDR value is: ");
     Serial.println(LDRValue);//Print LDR value
     Serial.println(val);   	//print soil moisture sensor value
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
     return;   
}

  else if(LDRValue > 400 && val == HIGH)
  {
      
     Serial.print("Its not dark and soil is dry so pump should turn on, LDR value is: ");
     Serial.println(LDRValue);		//print LDR value
     Serial.print("\n moisture value is: ");
     Serial.println(val);   	//print soil moisture sensor value
     digitalWrite(13,HIGH); 	//pump has to be turned on
     digitalWrite(12,LOW);
  }
  else
  {
      Serial.print("Its not dark and moisture is perfect so pump will off, LDR value is: ");
      Serial.println(LDRValue);//print LDR value
      digitalWrite(13,LOW);//pump has to be turned off
      digitalWrite(12,HIGH);
  }
  delay(400); //Wait for few second and then continue the loop.

          }
