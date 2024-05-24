/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"
int buttonState = 0;
const int buttonPin = 6;
int songs = 0;
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int melody2[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
int noteDurations2[] = {
  1, 1, 1, 1, 1, 1, 1, 1
};
void setup() {
  // iterate over the notes of the melody:
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
  // no need to repeat the melody.
  buttonState = digitalRead(buttonPin);
  songs = playSong(songs);
}

int playSong(int songs)
{
  switch(songs)
  {
    case 0:
      for (int thisNote = 0; thisNote < 8; thisNote++) 
      {
        if(thisNote>1) buttonState = digitalRead(buttonPin);
        if(buttonState == LOW)
        {
          return 1;
        }
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(8);
        
      }
      return 0;
      break;
    case 1:
      for (int thisNote = 0; thisNote < 8; thisNote++) 
      {
        if(thisNote>1) buttonState = digitalRead(buttonPin);
        if(buttonState == LOW)
        {
          return 0;
        }
        int noteDuration = 1000 / noteDurations2[thisNote];
        tone(8, melody2[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(8);
      }
      return 1;
      break;
  }
}
