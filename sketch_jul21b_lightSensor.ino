const int LIGHT_SENSOR = A0;
float Rsensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(LIGHT_SENSOR);
  Rsensor = (float)(1023-sensorValue)*10/sensorValue;
  Serial.println("the analog read data is:");
  Serial.println(sensorValue); //sensorValue > 200 = light on
  //Serial.println("the sensor resistance is:");
  //Serial.println(Rsensor, DEC);
}
