// as simple sketch that shows
// how to use loops and pulse width modulation
int outpin = 9;
void setup() {
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);

}

void loop() {

  for (int val = 0; val < 256; val++) {
    analogWrite(outpin, val);
    Serial.println(val);
    delay(10);
  }
  for (int val = 255; val >= 0; val--) {
    analogWrite(outpin, val);
    Serial.println(val);
    delay(10);
  }

}
