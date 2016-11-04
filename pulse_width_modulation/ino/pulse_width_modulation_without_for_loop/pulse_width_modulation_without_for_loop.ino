int pinled = 9;
int i  = 0;
boolean flag = true;
void setup() {
  pinMode(pinled, OUTPUT);
}

//void loop() {
//  for (int i = 0; i < 256; i++) {
//    analogWrite(pinled, i);
//    delay(15);
//  }
//
//  for (int j = 255; j >= 0; j--) {
//    analogWrite(pinled, j);
//  }
//}
void loop() {

analogWrite(pinled, i);
  if (flag == true) {
    i++;
  } else if (flag == false) {
    i--;
  }
  if (i == 255) {
    flag = true;
  }

  if (i == 0) {
    flag = false;
  }
}
