int led = 10;// the pin that the LED is attached to. It is a PWM enabled pin 
int brightness;    // how bright the LED is
String fadeAmount;    // The data got from the device. It is to be in the String format as explained later // the setup routine runs once when you press reset: 
void setup() {   // declare pin 9 to be an output:   
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);   //Setup Baud rate 
  Serial.begin(9600);  
  delay(10); } 
  void loop() {   if(Serial.available()>0){
    fadeAmount = Serial.readString();   //.toInt() is a macro to convert fadeAmount which is a String to a integer  
    brightness= fadeAmount.toInt();     
    Serial.println(brightness);   //brightness=(int)fadeAmount;   //Serial.write((int)brightness);   //Serial.write(brightness);   
    analogWrite(led,brightness); //to command the 9 pin to glow with the brightness given       
    //   wait for 30 milliseconds to see the dimming effect 
    delay(300);   //  }   }   }
  }
}

