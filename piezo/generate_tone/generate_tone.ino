// generate a tone with a piezo
// connect the piezo + to pin 9
// connect the piezo - to GND
void setup(){
  Serial.begin(9600);
}

void loop(){

    for(int i = 0; i < 256;i++){
  // map the sensor values to a wide range of pitches
  int pitch = map(i, 0, 255, 50, 4000);
        Serial.println(pitch);

  // play the tone for 20 ms on pin 12
  tone(12, pitch, 20);
  // wait for a moment
  delay(10);
  }

}
