
#define buzzer 4//buzzer for all sensors
int flag = 0;
 
void setup () {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
} 

void loop() {
    //code for waterSensor
    Serial.println("Water Sensor");
    int waterVal = analogRead(0); //read the water sensor  
    Serial.println(waterVal); //print the value of the water sensor to the serial monitor
    delay(1000);

    if (waterVal >= 300){
      Serial.println("Water Level above the danger level");
      flag++;
    }

    //code for temperature humidity sensor
    Serial.println("Temperature Humidity Sensor");
    int tempHumVal = analogRead(1);
    //int tempHumVal = 1530;
    if (tempHumVal <1100){
      Serial.print("temperature = ");
      Serial.println(tempHumVal/50); //print the value of the temperature to the serial monitor
      Serial.print("humidity = ");
      Serial.print(tempHumVal/11); //print the value of the humidity to the serial monitor
      Serial.println("%");
    }
    else if (tempHumVal >1100 && tempHumVal <1200){
      Serial.print("temperature = ");
      Serial.println(tempHumVal/50); //print the value of the temperature to the serial monitor
      Serial.println("Humidity level reached its peak");
      Serial.print("humidity = ");
      Serial.println("100%");
    }
    else if (tempHumVal >=1500){
      Serial.println("Temperature and Humidity crossed the danger level");
      Serial.print("temperature = ");
      Serial.println(tempHumVal/50); //print the value of the temperature to the serial monitor
      Serial.println("Humidity level reached its peak");
      Serial.print("humidity = ");
      Serial.println("100%");
      flag++;
    }
    delay(1000);

    //code for air quality sensor
    Serial.println("Air Quality Measurement");
    int airQualityVal = analogRead(2);
    //int airQualityVal = 630;
    Serial.println(airQualityVal); //print the value of the air quality sensor to the serial monitor
    if (airQualityVal >=600){
      Serial.println("Air quality fallen");
      flag++;
    }
    delay(1000);

    //code for Carbon Gas Sensor
    Serial.println("Carbon in Air Measurement");
    int carbonGasVal = analogRead(3);
    //int carbonGasVal = 830;
    Serial.println(carbonGasVal); //print the value of the air quality sensor to the serial monitor
    if (carbonGasVal >=800){
      Serial.println("Carbon gas crossed the danger level");
      flag++;
    }
    delay(1000);
    Serial.println(flag);
    if(flag==0){
      Serial.println("Your System is normal!!");
      }
    if(flag==1){
      Serial.println("Abnormal environment detected!!");
      digitalWrite(buzzer, HIGH);
      Serial.println("Alarm: 1");
      delay(200);
      digitalWrite(buzzer, LOW);
      }
    else if(flag==2){
      Serial.println("Abnormal environment detected!!");
      digitalWrite(buzzer, HIGH);
      Serial.println("Alarm: 2");
      delay(600);
      digitalWrite(buzzer, LOW);
    }
    else if(flag==3){
      Serial.println("Abnormal environment detected!!");
      digitalWrite(buzzer, HIGH);
      Serial.println("Alarm: 3");
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
    else if(flag==4){
      Serial.println("Abnormal environment detected!!");
      digitalWrite(buzzer, HIGH);
      Serial.println("Alarm: 4");
      delay(2000);
      digitalWrite(buzzer, LOW);
    }

    flag = 0;
    Serial.println(flag);
}
