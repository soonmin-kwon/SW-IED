#define PIN_LED 7
unsigned int count, toggle;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  
  count = 0;
  toggle = 0;
  
  digitalWrite(PIN_LED, toggle);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  toggle = toggle_state(toggle);
  digitalWrite(PIN_LED, toggle);
  
  while(count <= 11){
    toggle = toggle_state(toggle);
    digitalWrite(PIN_LED, toggle);
  
    delay(83);    //loop 12 times -> 1000ms / 12 = 83
    count++;
  }

  //infinite loop
  while(1){
    ;
  }  
}

unsigned int toggle_state(unsigned int toggle){
  return (toggle == 0) ? 1 : 0;
}
