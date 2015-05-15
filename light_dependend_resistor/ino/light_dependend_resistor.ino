//light dependent resistor

int LDR_Pin = A0; //analog pin 0

void setup(){
  Serial.begin(9600);
}

void loop(){
  int LDRReading = analogRead(LDR_Pin); 

  Serial.println(LDRReading);
  delay(10); //just here to slow down the output for easier reading
}
