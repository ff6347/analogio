// as simple sketch that shows
// how to use loops and pulse width modulation
int outpin = 9;
void setup(){
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);

}

void loop(){

    for(int val = 0; val < 255; val++){
    
      analogWrite(outpin, val);
      Serial.print("The value is currently at: ");
      Serial.println(val);
      delay(50);
    }

}
