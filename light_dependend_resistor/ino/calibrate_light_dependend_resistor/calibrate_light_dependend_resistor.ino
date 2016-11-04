// light dependent resistor

int LDR_Pin = A0; //analog pin 0
int LED = 9;
int maximum = 0;
int minimum = 1023;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  int LDRReading = analogRead(LDR_Pin);   
  if(maximum < LDRReading){
  
    maximum = LDRReading;
  
  }
  if(minimum > LDRReading){
  minimum = LDRReading;
  }


  analogWrite(9,map(LDRReading, minimum,maximum,0, 255));
  
  
//  delay(10); //just here to slow down the output for easier reading
}
