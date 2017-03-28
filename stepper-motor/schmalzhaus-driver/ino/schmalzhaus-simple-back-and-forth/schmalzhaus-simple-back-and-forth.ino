/**
 * Taken from here
 * http://www.schmalzhaus.com/EasyDriver/Examples/EasyDriverExamples.html
 * 
 */

 int counter = 0;
void setup() {                
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  digitalWrite(9, HIGH);
  delay(1);          
  digitalWrite(9, LOW); 
  delay(1); 
  counter++;
  if(counter == 3600){
    digitalWrite(8, !digitalRead(8));
  counter = 0;
    }         
}
