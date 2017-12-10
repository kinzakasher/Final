//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

//const int read = A1; //Sensor A1 pin to Arduino pin A1 Water Level 
int value;          //Variable to store the incoming data


int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

//int sensorValue1, sensorValue2, digitalValue; //sensorValue3, sensorValue4;

void setup() {


  Serial.begin(9600); //Begin serial communication

}

void loop() {
 
  sensorValue1 = analogRead(0);  // read sensor in analog input 0 photo cell
  sensorValue2 = analogRead(1);  // read sensor in analog input 1 water sensor
  sensorValue3 = analogRead(2);  // read sensor in analog input 2
  //sensorValue4 = analogRead(3);  // read sensor in analog input 3
  //digitalValue = digitalRead(2);  // temp senses 
  Serial.print(sensorValue1, DEC);  // print sensor 1
  Serial.print(",");                // print ','
  Serial.print(sensorValue2, DEC);  // print sensor 2
  Serial.print(",");                // print ','
  Serial.println(sensorValue3, DEC);  // print sensor 3
  //Serial.print(",");                // print ','
 // Serial.println(sensorValue4, DEC);  // print sensor 4 and newline (println)
  delay(200);   // wait 200ms for next reading
}

