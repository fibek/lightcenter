#include <FastLED.h>

/* 
 *  if using more than one LED strip define DATA_PINn
 *  and add this to every strip
 *  
 *  Example:
 *  This code uses two LED strips, so there are 2 DATA_PIN macros,
 *  2 CRGB arrays, and 2 FastLED.addLeds();
 *  
 */
 
#define DATA_PIN1 3
#define DATA_PIN2 4   
#define NUM_LEDS1 60
#define NUM_LEDS2 60

CRGB leds1[NUM_LEDS1];
CRGB leds2[NUM_LEDS2];

int num_leds;

CRGB *leds_ptr(int set);
void color(CRGB *leds, int ar_size, int r, int g, int b);

void setup() {
	Serial.begin(115200);
	while( !Serial.available() ) 
	// add loop with FastLED.addLeds<..., DATA_PIN_n, ...>(leds_n, NUM_LEDS_n);
	FastLED.addLeds<WS2811, DATA_PIN1, BRG>(leds1, NUM_LEDS1);
	FastLED.addLeds<WS2811, DATA_PIN2, BRG>(leds2, NUM_LEDS2);
}

void loop() {
	while( !Serial.available() );
	Serial.setTimeout(5);
	int r,g,b,pin;
	CRGB *ptr;
	r = g = b = 255; pin = 0;
	pin = Serial.parseInt();
	r = Serial.parseInt();
	g = Serial.parseInt();
	b = Serial.parseInt();   
  ptr = leds_ptr(pin); 
	color(ptr, num_leds, r, g, b);  
	//Serial.flush();
}

CRGB *leds_ptr(int set) {
/* 
 * sizeof(arr) = size of array (e.g. 32 bytes); 
 * sizeof(*arr) = sizeof(arr[0]) = size of one element (e.g 4 bytes)
 */
switch(set) {
	case 0:
    num_leds = sizeof(leds1)/sizeof(*leds1);
		return leds1;
		break;
	case 1:
    num_leds = sizeof(leds2)/sizeof(*leds2);
		return leds2;
		break;
	default:
		Serial.println("wrong set num");
		break;
}
}

void color(CRGB *leds, int ar_size, int r, int g, int b) {
	for(int i = 0; i <= ar_size; i++) 
		leds[i].setRGB(r,g,b);
	FastLED.show();
}
