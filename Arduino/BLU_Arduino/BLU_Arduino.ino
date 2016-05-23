//servo header
#include <Servo.h> 

// Var
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 0;    // variable to store the servo position 

// BLU
String comdata = "";

// setup method
void setup()
{
 Serial.begin(9600);
 //
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

}

// loop method 
void loop()
{

// BLU Operation  
  while(Serial.available())
   {
     char c=Serial.read();
      if(c=='A')
        {
          Serial.println("Hello I am amarino");
        }
   }

   while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
    if (comdata.length() > 0)
    {
        Serial.println(comdata);
        comdata = "";
    }

// Servo operation
   for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

  
}
