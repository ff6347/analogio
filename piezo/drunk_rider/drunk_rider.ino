// play tunes with a piezo
// based on "drunk rider" by Dejan Milenkovits from https://ioio.mah.se/
// Malmö University at the institution of art, culture and communication.

// the pitches are in that file
#include "pitches.h"

// to transpose the tones just change e.g.
// 4 to 5
// and 5 to 6
int melody[] = {
  NOTE_C4,
  NOTE_CS4,
  NOTE_C4,
  NOTE_F4,
  NOTE_C5,
  NOTE_CS5,
  NOTE_C5,
  NOTE_F4,
  NOTE_C4,
  NOTE_CS4,
  NOTE_C4,
  NOTE_F4,
  NOTE_C5,
  NOTE_AS4};

// how long to play each note
int noteDurations[] = {
  4, 8, 8, 2, 4, 8, 8, 2, 4, 8, 8, 4, 4,2};
void setup(){
  pinMode(12, OUTPUT);

}

void loop(){
  play_melody();
}

// Play the melody
void play_melody(){
// there are 14 notes
// so we need a value from 0 to 14 that increases:
//
  for (int thisNote = 0; thisNote < 14; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(12, melody[thisNote],noteDuration);
    // The time between each tone defined herein.
    // The time is variable, we use the original note value.
    // If you want to it to go slower so multiply up.
    // For example, note the duration * 1.30 is 30% slower:
    // for better control of the pauses see the rocky example
    int pauseBetweenNotes = noteDuration * 0.8;
    delay(pauseBetweenNotes);
    // Stop the musik:
  }
  noTone(12);
}


