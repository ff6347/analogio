/**
 * A very simple sketch by Fabian Morón Zirfas
 *
 *
 */
int poti = A0; // the poti pin
void setup(){
Serial.begin(9600);  // init Serial
}
void loop(){
  int potival = analogRead(poti); // read the poti
  Serial.println(potival); // print it
  delay(100);// wait a bit
}
