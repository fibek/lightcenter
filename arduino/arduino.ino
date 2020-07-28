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
 
#define DATA_PIN1 13
#define DATA_PIN2 12  
#define NUM_LEDS1 60
#define NUM_LEDS2 60

CRGB leds1[NUM_LEDS1];
CRGB leds2[NUM_LEDS2];

int num_leds;

CRGB *leds_ptr(int set);
void color(CRGB *leds, int ar_size, int r, int g, int b);

void setup() {
	Serial.begin(115200);
	while( !Serial ) { ; }
	// add loop with FastLED.addLeds<..., DATA_PIN_n, ...>(leds_n, NUM_LEDS_n);
	FastLED.addLeds<WS2811, DATA_PIN1, BRG>(leds1, NUM_LEDS1);
	FastLED.addLeds<WS2811, DATA_PIN2, BRG>(leds2, NUM_LEDS2);
}

int dot_counter = -1;  //every incoming data start with "."
String r,g,b;
CRGB *ptr;

void loop() {

  Serial.setTimeout(0);
  if( Serial.available() > 0 ) {
    char ch = (char)Serial.read();
    if( ch == '.' ) {
      dot_counter++;
//      Serial.print("\ndot_counter: ");
//      Serial.print(dot_counter, DEC);
//      Serial.println();      
      if(dot_counter >= 4 ) {
        color(ptr, r.toInt(), g.toInt(), b.toInt());
        r = g = b = "";
        dot_counter = -1;
      }
    } else {
      if(dot_counter == 0 ) 
        ptr = leds_ptr(ch);
      if(dot_counter == 1 )
        r += ch;
      if(dot_counter == 2 )
        g += ch;
      if(dot_counter == 3 )
        b += ch;
//      Serial.print(ch);
    }
  }
}

CRGB *leds_ptr(char set) {
/* 
 * sizeof(arr) = size of array (e.g. 32 bytes); 
 * sizeof(*arr) = sizeof(arr[0]) = size of one element (e.g 4 bytes)
 */
switch(set) {
	case '0':
    num_leds = sizeof(leds1)/sizeof(*leds1);
		return leds1;
		break;
	case '1':
    num_leds = sizeof(leds2)/sizeof(*leds2);
		return leds2;
		break;
	default:
		break;
  }
}

void color(CRGB *leds, int r, int g, int b) {
//  Serial.print("\n r: ");
//  Serial.print(r, DEC); 
//  Serial.print("\n g: ");
//  Serial.print(g, DEC); 
//  Serial.print("\n b: ");
//  Serial.print(b, DEC);
//  Serial.println();
	for(int i = 0; i <= num_leds; i++) 
		leds[i].setRGB(r,g,b);
	FastLED.show();
}
