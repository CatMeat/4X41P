//
//
//

int thresholds[16] = {209,152,86,9,373,336,296,250,481,456,429,398,559,541,521,499};
char keypad[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
//char keypad[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','E','0','F','D'};


void setup() {
  Serial.begin(9600);
  Serial.write("Begin");
}

void loop() {
  CheckKeypad();
}

bool CheckKeypad() { //char *buf, int index) 
  int value = analogRead(A0);
  for (int i=0; i < 16; i++)
  {
    if( abs(value - thresholds[i]) < 5)
    {
      Serial.println(keypad[i]);
      while (analogRead(A0) < 1000) {delay(100);}
    }
  }
}
  
