
int z = 5; // size of array

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()){
    String rd = Serial.readStringUntil('\n');
    stringSplit(rd,','); //parameters String & delimiter
    
  }

}

void stringSplit(String s, char a){
  int l = s.length();
  int c = 0;
  for (int j = 0; j < l; j++){
    if (s.charAt(j) == a){
      c++;
    }
  }
  String split[z];
  if (c != 0){
    for (int k = 0; k < c ; k++){
      if (k >= z){
        break;
      }
      int x = s.indexOf(a);
      l = s.length();
      split[k] = s.substring(0,x);
      s = s.substring(x+1,l);
      if (k == c-1){
        split[k+1] = s;
      }
    }

    for (int s = 0; s < c+1; s++){
      if (s >= z){
        break;
      }
      String p = split[s];
      Serial.print("|");
      Serial.print(p);
      Serial.print("|");
    }
    Serial.println(";");
  } else {
    Serial.println(s);    //no delimiter not found, print original string
  }
  

}
