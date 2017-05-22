int ldrpin = A0;
int ledpin = 9;
int ivmin = 1023;
int ivmax = 0;
int ovmin = 0;
int ovmax = 255;
void setup() {
  // once
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}
void loop() {
  int potivalue = analogRead(ldrpin);
  Serial.println(ldrvalue);
  // calibrate
  if (ldrvalue < ivmin) {
    ivmin = potivalue;
  }
  if (ldrvalue > ivmax) {
    ivmax = potivalue;
  }
  
  int mappedvalue = map(ldrvalue, ivmin, ivmax, ovmin, ovmax);
  analogWrite(ledpin, mappedvalue);

}
