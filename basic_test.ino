/* TTP229 16 Key Capacitive Touch Keypad (TTP229) [S153] : http://rdiot.tistory.com/134 [RDIoT Demo] */

#define pulse 2
#define data 3

int old  = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pulse, OUTPUT);  
  pinMode(data, INPUT); 
}

void loop()
{
  int Key = getkey();
  
  if (Key!=0&Key!=old)
  {
    Serial.print("PUSH--->");
    Serial.println(Key);

  }
    
  old = Key;
    
}


byte getkey(void)
{
  byte cnt;
  byte num = 0;
  for(cnt = 1; cnt < 17; cnt++)
  {
    digitalWrite(pulse, LOW); 
    
    if (digitalRead(data) == 0)
      num = cnt; 
    
    digitalWrite(pulse, HIGH);
  }  
  
  return num; 
}
