#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(2,4);

int pinButton = 2; //the pin where we connect the button
int LED = 8; //the pin we connect the LED
int previous = LOW;
int stateLED = LOW;
int stateButton;
int time = 0;

void setup()
{
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  pinMode(pinButton, INPUT); //set the button pin as INPUT
  pinMode(LED, OUTPUT); //set the LED pin as OUTPUT
}

void loop()
{
  long start = millis();
  long total1 = cs_4_2.capacitiveSensor(30);

  Serial.print(millis() - start);
  Serial.print("\t");
 
  Serial.print(total1);
  Serial.println();
  delay(10);

 /* if(LED == LOW){
    if(total1 <= 15) { //if is pressed
     digitalWrite(LED, HIGH); //write 1 or HIGH to led pin
  } else { //if not pressed
     digitalWrite(LED, LOW);  //write 0 or low to led pin
  } 
    
  }*/

  stateButton = digitalRead(pinButton);
  if(stateButton == HIGH && previous == LOW && millis() - time > 200){
    if(stateLED == HIGH){
      stateLED = LOW;
    } else {
        stateLED = HIGH;  
      }
    time = millis();
   }

   digitalWrite(LED,stateLED);
   previous = stateButton;
  
/*  if(total1 <= 15) { //if is pressed
     digitalWrite(LED, HIGH); //write 1 or HIGH to led pin
  } 

  if(total1 >= 15){ // not pressed
    digitalWrite(LED, LOW);
  } */
  

}



 

