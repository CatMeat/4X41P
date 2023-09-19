//
//
//
char *buffer[20];
int buflen=0;
int prevlen=0;
int thresholds[16] = {2,77,144,202,244,290,331,368,394,424,452,477,496,518,538,556};
char keypad[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};

//char keypad[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','E','0','F','D'};


void setup() {
  Serial.begin(9600);
  Serial.write("Begin");
}

void loop() {
  CheckKeypad();
  if(prevlen != buflen) {
    prevlen++;
    for (int i=0; i <= buflen; i++) {
      Serial.write(buffer[i]);
    }
  }
}

bool CheckKeypad() { //char *buf, int index) 
  int value = analogRead(A0);

  for (int i=0; i < 16; i++)
  {
    if( abs(value - thresholds[i]) < 5)
    {
      Serial.println(keypad[i]);
      buffer[buflen] = keypad[i];
      buflen++;

      while (analogRead(A0) < 1000) {delay(100);}
    }
  }
}
  
