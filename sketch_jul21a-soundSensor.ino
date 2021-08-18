const int pinAdc = A0;
/*
 * count = 0
 * if lightSensor > 200 and soundSensor >= 800
 *    ++count;
 *    recordedTimestamp = getTimestamp()
 * if count % 2 != 0 and (currentTime - recordedTimestamp) >= 5 minutes:
 *    lcdDisplay(Garage Door OPEN)
 * 
 * 
 */


void setup()
{
    Serial.begin(115200);
    //Serial.println("Grove - Sound Sensor Test...");
}
 
void loop()
{
    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pinAdc);
    }
 
    sum >>= 5;
 
    Serial.println(sum); //sum >= 800 = garage door open/close
    delay(10);
}
