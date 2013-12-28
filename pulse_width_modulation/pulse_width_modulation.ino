// based on analogWrite example
// http://arduino.cc/en/Reference/AnalogWrite
int ledPin = 9;      // LED connected to digital pin 9
int analogPin = A0;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value

void setup(){

  pinMode(ledPin, OUTPUT);   // sets the pin as output
}
void loop(){

  val = analogRead(analogPin);   // read the input pin
  /**
   * analogRead values go from 0 to 1023
   * analogWrite values from 0 to 255
   */
    analogWrite(ledPin, val / 4);  

}


