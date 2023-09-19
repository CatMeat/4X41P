//
//
//

int thresholds[16] = {2,77,144,202,244,290,331,368,394,424,452,477,496,518,538,556};
char keypad[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
//char keypad[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};


void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);

  for (int i=0; 1< 16; i++)
  {
    if( abs(value - thresholds[i]) < 5)
    {
      Serial.println(keypad[i]);
      while (analogRead(A0) < 1000) {delay(100);}
    }
  }
}



  
