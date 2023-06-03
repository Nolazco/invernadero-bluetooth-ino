#include <SoftwareSerial.h>
SoftwareSerial BT(0,1);

#define TPIN 2
const float analogRes = (float)5000 / 1023;

void setup() {
	BT.begin(9600);
	DDRC = 0b00000000;
}

void loop() {
	int decVolt = analogRead(TPIN);
	float volt = decVolt * analogRes;
	float grados = volt / 10;
	BT.write(grados);
}

