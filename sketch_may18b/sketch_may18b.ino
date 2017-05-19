#include "pitches.h"
#include "ledPitches.h"

// pins
const int buzzer = 2;//the buzzer pin
const int lowestPin = 3;//the lowest led
const int highestPin = 10;//the highest led


// note length
const int eighth = 500;
const int breath = 100;

/*********************
 * Music
 *********************/
 // first and fourth stanza
 int first[] = {
  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_C6, 
  NOTE_D6, NOTE_B5, NOTE_C6, NOTE_A5, NOTE_D6, NOTE_D6, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, 
  NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_B5, NOTE_C6, NOTE_A5,
  NOTE_G5, NOTE_G5
 };



 /**************
  * Lights
  **************/
  int firstLED[] = {
  N_G, N_A, N_B, N_B, N_A, N_B, N_C, N_C, N_B, N_C, 
  N_D, N_B, N_C, N_A, N_D, N_D, N_G, N_A, N_B, N_B, 
  N_A, N_B, N_C, N_C, N_B, N_C, N_D, N_B, N_C, N_A,
  N_G, N_G
 };

void setup() {
  //set pins 0 through 8 as output  
  for(int thisPin = buzzer;thisPin <= (highestPin);thisPin++)
  {
     pinMode(thisPin,OUTPUT); //initialize thisPin as an output
  }

}

void loop() {

  for (int thisNote = 0; thisNote < 32; thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
    tone(buzzer,first[thisNote], eighth); //turn the buzzer on
    digitalWrite(firstLED[thisNote], HIGH);
    delay(eighth);
    digitalWrite(firstLED[thisNote], LOW);
    delay(breath);
  }

}
