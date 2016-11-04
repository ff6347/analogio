int ledpin = 9;
int potipin = A0;
int sensormin = 1023;
int sensormax = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potivalue = analogRead(potipin); // 0 <-> 1023
  if(potivalue < sensormin){
      sensormin = potivalue;
    }
   if(potivalue > sensormax){
    sensormax = potivalue;
    }
  int mapped_value = map(potivalue, sensormin, sensormax, 255, 0);
  Serial.println(mapped_value);
  analogWrite(ledpin, mapped_value); // 0 <-> 255
}
