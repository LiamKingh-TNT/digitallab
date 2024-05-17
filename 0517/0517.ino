void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ss = analogRead(A0);
  Serial.println(ss);
  delay(10);
  if(ss>=700)
  {
    ss = 700;
  }
  else if(ss<=400)
  {
    ss=400;
  }
  int dimming = map(ss,400,700,0,255);
  analogWrite(9,dimming);
  delay(10);
}