#define LED_PIN 12
#define PERIOD 10

String inp="";       // string to take input
int str_length;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);          //9600 bits per second
  Serial.setTimeout(10);       //sets the maximum milliseconds to wait for serial data
  Serial.println("Hello From Transmitter!");
  digitalWrite(LED_PIN, LOW);   //initially O/P of the LED Pin is LOW that is 0 which means we are not sending data initially.
}

void loop() 
{
  inp="";      // input variable which stores the user input data.
  if(Serial.available()){        //it reads the incoming bytes.
    inp = Serial.readString();    
    sendMessage(inp);

    Serial.println(inp);
    Serial.print("Done");
    Serial.println();
    digitalWrite(LED_PIN, LOW);
  }
}

void sendMessage(String str){
  int str_length = str.length();
  Serial.println("Initiated");
  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
  for(int i = 0; i < str_length; i ++)
  {
    send_byte(str[i]);
    if( (i%3==0 and i!=0) or i==2)   wait_time(); 
  }
  digitalWrite(LED_PIN, LOW);
}

void wait_time(){
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD*10);
  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
  return;
}

void send_byte(char my_byte)
{
  String bits = "";
  for (int i = 7; i >= 0; --i) {
        int state = (my_byte & (1 << i))? 1 : 0;
        digitalWrite(LED_PIN, state);
        Serial.print(state);
        delay(PERIOD);
  }
  Serial.print(" -> ");
  Serial.print(my_byte);
  Serial.println();
        
  return;

  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
}
