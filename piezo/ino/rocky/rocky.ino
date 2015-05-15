// play tunes with a piezo
// based on "drunk rider" by Dejan Milenkovits from https://ioio.mah.se/
// Malmö University at the institution of art, culture and communication.
//
// hook up the piezo with an 220 OHM resitor to pin 12
// piezo red to pin 12
// piezo black to ground
//
// thanks to Olive Christou || http://oliva-uhlig.me/
// for figuring out the melody and pauses
//
// written by fabiantheblind & Olive Christou
// TODO: get the puses in the intro right as weel
//
// the notes are in here
#include "pitches.h"


int notes_intro = 34; // how many notes in intro
int notes_verse = 30; // how many notes in verse
int piezo_pin = 12; // the pin for the piezo
// this is the intro
// still needs some work on the pauses
int melody_intro [] = {

  NOTE_C4,NOTE_C4,NOTE_C4,
  NOTE_C4,NOTE_C4,NOTE_C4,
  NOTE_C4,NOTE_C4,NOTE_E4,
  NOTE_C4,NOTE_C4,NOTE_C4,

  NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_E4,NOTE_G4,
  NOTE_E4,NOTE_E4,NOTE_E4,

  NOTE_D4,NOTE_D4,NOTE_D4,
  NOTE_D4,NOTE_D4,NOTE_D4,
  NOTE_D4,NOTE_D4,
  NOTE_F3,NOTE_E3
};
// the duration of the note in intro
int noteDurations_intro [] = {
  16,16,8,
  16,16,8,
  16,16,8,
  16,16,8,

  16,16,8,
  16,16,8,
  16,16,8,
  16,16,8,

  18,8,16,
  8,16,8,
  16,8,
  4, 1

};

// the notes in the verse
int melody_verse [] = {

  NOTE_E4,NOTE_G4,NOTE_A4,
  NOTE_A4,NOTE_B4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_A4,
  NOTE_A4,NOTE_B4,NOTE_E4,

  NOTE_D4,NOTE_C4,NOTE_D4,
  NOTE_D4,NOTE_C4,NOTE_D4,
  NOTE_C4,NOTE_D4,NOTE_E4,

  NOTE_C4,NOTE_C4,NOTE_B3,
  NOTE_B3,NOTE_A3,NOTE_A3,
  NOTE_G3,NOTE_B3,NOTE_E5
};


// the duration of the notes in the verse
int noteDurations_verse [] = {
  16,8,1,
  16,8,1,
  16,8,1,
  16,8,1,

  16,16,8,
  16,16,6,
  16,16,4,

  16,16,8,
  16,8,18,
  2,1,1
};

// this is nicer than the intro
// we have definite control over the pauses between notes
// before the pauses where based in the note duration
int pause_between_notes_verse [] = {
  187, 375, 1500,
  187, 375, 1500,
  187, 375, 1500,
  187, 375, 1500,

  187,187,375,
  187,187,450,
  187,187,750,

  187,187,375,
  187,375,200,
  1000,1500,3000
};

// once
void setup(){
  pinMode(piezo_pin, OUTPUT);
  play_intro();
}

// all the time
void loop(){
  play_verse();
}

// this is the intro
// TODO make pauses like in the verse
void play_intro(){

  for (int thisNote = 0; thisNote < notes_intro; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations_intro[thisNote];

    // play the according note with the according duration
    tone(piezo_pin, melody_intro[thisNote],noteDuration);
    // The time between each tone defined herein.
    // The time is variable, we use the original note value.
    // If you want to it to go slower so multiply up.
    // For example, note the duration * 1.30 is 30% slower:

    int pauseBetweenNotes = noteDuration * 3;

    delay(pauseBetweenNotes);
  }
  noTone(piezo_pin); // stop the music
}


// this is the same as the intro
// but we have better control over the pauses between notes
void play_verse(){
  for (int i = 0; i < notes_verse; i++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations_verse[i];

    tone(piezo_pin, melody_verse[i], noteDuration);

    // The time between each tone defined in an array.
    int pause = pause_between_notes_verse[i];
    delay(pause);
  }
  noTone(piezo_pin); // stop the music
}








