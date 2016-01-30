// Function: If the sound sensor senses a sound that is up to the threshold you set in using
// the rotary angle sensor, switch the relay on.
// Hardware: Grove - Sound Sensor, Grove - Rotation, Grove - Relay

/*macro definitions of the sound sensor and the LED*/
#define SOUND_SENSOR A0
#define ROTARY_ANGLE_SENSOR A1

#define RELAY 2      // the number of the LED pin



#define ADC_REF 5//reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
				 //board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5//VCC of the grove interface is normally 5v
#define FULL_ANGLE 300//full value of the rotary angle is 300 degrees


void setup() 
{
  Serial.begin(9600);
	
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  pinMode(SOUND_SENSOR, INPUT); 
  pinMode(RELAY,OUTPUT);

}

void loop() 
{
  int soundValue = analogRead(SOUND_SENSOR);//use A0 to read the electrical signal
  int refValue = analogRead(ROTARY_ANGLE_SENSOR);//use A0 to read the electrical signal
  Serial.print("soundValue ");
  Serial.println(soundValue);
  Serial.print("refValue ");
  Serial.println(refValue);
  if(soundValue > refValue)
  {
    digitalWrite(RELAY,HIGH);//if the value read from A0 is larger than 400,then light the LED
    delay(200);
  }
  else
  {
    digitalWrite(RELAY,LOW);
  }
  delay(200);
}



