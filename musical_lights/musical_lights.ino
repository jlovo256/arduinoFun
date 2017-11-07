#include "pitches.h"
#include "ledPitches.h"

// pins
const int buzzer = 4;//the buzzer pin
const int lowestPin = 5;//the lowest led
const int highestPin = 12;//the highest led


// note duration in milliseconds
// based on 60 beats per minute
const int sixteenth = 250;
const int eighth = 500;
const int breath = 100;
const int quarter = 1000;
const int dotted_quarter = 1500;
const int half = 2000;
const int dotted_half = 3000;
const int whole = 4000;



/*******************
 * Perpetual Motion
 *******************/


// first and fourth stanzas
// Music
int PM_first[] = 
{
    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6,
    NOTE_B5, NOTE_C6, NOTE_D6, NOTE_B5, NOTE_C6, NOTE_A5, NOTE_D6, NOTE_D6,
    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6,
    NOTE_B5, NOTE_C6, NOTE_D6, NOTE_B5, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_G5
};

// first and fourth stanzas
// lights
int PM_firstLED[] = 
{
    N_G, N_A, N_B, N_B, N_A, N_B, N_C, N_C, N_B, N_C, 
    N_D, N_B, N_C, N_A, N_D, N_D, N_G, N_A, N_B, N_B, 
    N_A, N_B, N_C, N_C, N_B, N_C, N_D, N_B, N_C, N_A,
    N_G, N_G
};

// second stanza
// Music
int PM_second[] =
{
    NOTE_G6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_D6,
    NOTE_E6, NOTE_D6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_D6, NOTE_D6,
    NOTE_G6, NOTE_FS6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_E6, NOTE_D6, NOTE_D6,
    NOTE_E6, NOTE_D6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_G5
};

// second stanza
// lights
int PM_secondLED[] =
{
    N_HG, N_FS, N_E, N_E, N_FS, N_E, N_D, N_D, 
    N_E, N_D, N_C, N_C, N_B, N_A, N_D, N_D, 
    N_HG, N_FS, N_E, N_E, N_FS, N_E, N_D, N_D,
    N_E, N_D, N_C, N_C, N_B, N_A, N_G, N_G
};

// third stanza
// repeat twice
int PM_third[] =
{
    NOTE_B5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_C6, NOTE_A5, NOTE_B5, NOTE_B5,
    NOTE_D6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_FS6, NOTE_G6, NOTE_G6
};

// third stanza
// repeat twice
int PM_thirdLED[] =
{
    N_B, N_G, N_A, N_A, N_C, N_A, N_B, N_B,
    N_D, N_B, N_C, N_D, N_E, N_FS, N_HG, N_HG
};




/*
 * initialize the pins
 */
void setup()
{
    //set pins 0 through 8 as output  
    for(int thisPin = buzzer;thisPin <= (highestPin);thisPin++)
    {
    pinMode(thisPin,OUTPUT); //initialize thisPin as an output
    }
}// end setup

/*
 * arduino's main
 */
void loop() {

    for (int thisNote = 0; thisNote < 32; thisNote++) 
    {
        tone(buzzer,PM_first[thisNote], eighth); //turn the buzzer on
        digitalWrite(PM_firstLED[thisNote], HIGH);
        delay(eighth);
        digitalWrite(PM_firstLED[thisNote], LOW);
        delay(breath);
    }// end for

    for (int thisNote = 0; thisNote < 32; thisNote++) 
    {
        tone(buzzer,PM_second[thisNote], eighth); //turn the buzzer on
        digitalWrite(PM_secondLED[thisNote], HIGH);
        delay(eighth);
        digitalWrite(PM_secondLED[thisNote], LOW);
        delay(breath);
    }// end for

    int twice = 2;
    while (twice > 0)
    {
        for (int thisNote = 0; thisNote < 16; thisNote++) 
        {
            tone(buzzer,PM_third[thisNote], eighth); //turn the buzzer on
            digitalWrite(PM_thirdLED[thisNote], HIGH);
            delay(eighth);
            digitalWrite(PM_thirdLED[thisNote], LOW);
            delay(breath);
        }// end for

        twice--;
    }//end while

    for (int thisNote = 0; thisNote < 32; thisNote++) 
    {
        tone(buzzer,PM_first[thisNote], eighth); //turn the buzzer on
        digitalWrite(PM_firstLED[thisNote], HIGH);
        delay(eighth);
        digitalWrite(PM_firstLED[thisNote], LOW);
        delay(breath);
    }// end for

}// end loop
