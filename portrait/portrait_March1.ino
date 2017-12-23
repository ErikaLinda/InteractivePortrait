#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 4
#define TOTAL 156
#define sensorRight 7
#define sensorLeft A0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(TOTAL, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
//long js1[154] = {149148144, 163159156, 152150151, 249238234, 249240235, 168167163, 190187180, 178177173, 192187184, 115108100, 107102096, 78072074, 63054059, 44042063,150149145, 161160156, 168155146, 154145136, 148137135, 129120115, 75067065, 125059060, 222209201, 110105099, 85080077, 59053055, 61056060, 34028038,151151143, 202195185, 80071074, 70061062, 109100093, 144131125, 120109105, 194147127, 116068064, 107090082, 186178176, 51053065, 38038048, 33031042,159156149, 138129120, 136116109, 164126113, 178139122, 154122111, 173145134, 181152146, 165129105, 158110096, 145102086, 176182194, 33036045, 32030043,236222209, 190181166, 179146127, 186135116, 191142127, 185133111, 187136117, 180134108, 152104084, 171147135, 154136126, 132094075, 171177191, 147154172,252242233, 134117109, 165122105, 185136122, 184133112, 149109084, 91062044, 191140123, 175127107, 169122102, 166147133, 142129121, 97101126, 97106135,175177166, 173165154, 172126110, 160111097, 180129108, 74057049, 88065059, 149095085, 145091081, 107069060, 101080077, 137127125, 80059058, 89098129,160162157, 242233224, 172134125, 165121112, 159116099, 73048043, 138097077, 128081073, 122086072, 49036030, 123109096, 131121122, 87072077, 88095124,160165159, 154159153, 178171161, 224209202, 156116108, 61041032, 177130120, 189136130, 118104103, 137096100, 142128117, 143133131, 69050054, 30014027,164165160, 153162159, 177181180, 186188187, 192194191, 189177161, 189163150, 112071067, 197189186, 86061054, 138127125, 113103104, 63073085, 41018024,162164159, 158162161, 181185186, 187191192, 191197197, 198200199, 200204203, 205210206, 149153156, 108094093, 174138124, 146118106, 51057073, 39037048};

  Serial.begin(9600);

  pinMode(sensorRight, INPUT);
  pinMode(sensorLeft, INPUT);

  strip.begin(); // start strip
  strip.show(); 

  // set placeholder color
  for(int i=0; i< TOTAL; i++){
    strip.setPixelColor(i, 40,50, 100);
  }
  
  strip.show(); 
  delay(5000);
  
}

void loop() {
  long js2[154] = {236241245, 235240244, 150159176, 70079094, 69078093, 59072089, 88105123, 73088107, 78106084, 34044043, 95121084, 153168201, 140153185, 165170200, 238243246, 235243246, 128127135, 27022019, 48042042, 70047041, 99056049, 117070062, 121125098, 29035035, 100129085, 128138173, 144155187, 171177203, 236241247, 110104106, 28019020, 29023023, 58039033, 66043035, 113075064, 88058047, 103069057, 133109107, 91065066, 111123161, 133143179, 175179208, 214209216, 75062056, 69044037, 120074059, 134083062, 121075059, 130081066, 172094071, 171094066, 186107074, 176128105, 182154151, 144149179, 159168199,147136144, 78061054, 96058045, 164094069, 156086061, 198125092, 124086073, 183100070, 177091064, 95059047, 161097069, 214169148, 179144138, 204202226,115113118, 61048040, 142084062, 197119081, 207125087, 214139100, 82045036, 136074063, 149080064, 189127102, 175091080, 214147118, 225197193, 196191213,233238244, 69062056, 161099074, 222147107, 215146107, 213148116, 192120082, 211134104, 212141111, 139083060, 172089075, 220163134, 233198192, 65040046,237240247, 56052053, 158120109, 216152124, 215147112, 216151113, 65038029, 191104074, 199108079, 156105078, 214176155, 222201198, 216221240, 216222236,235243246, 236241247, 83082087, 40022022, 175119104, 183140124, 199150133, 213153125, 211152118, 197143115, 156163156, 181195221, 204209228, 212215232,237242248, 237242248, 195201217, 95102120, 81093107, 71070076, 138138146, 80097115, 66084072, 33039039, 24026025, 187204224, 200206230, 212214235,235242250, 235240246, 233235247, 119119131, 142141157, 79077082, 142139146, 74091111, 67086064, 26032030, 28032033, 31041040, 194201227, 182194220};
   
  int sensorValueRight = digitalRead(sensorRight);
  int sensorValueLeft = analogRead(sensorLeft);
  Serial.println(sensorValueRight);
  Serial.println(sensorValueLeft);
  Serial.println();

  if(sensorValueRight == 1 || sensorValueLeft > 270){
    Serial.println("here");
     for(int i=0; i< TOTAL; i++){
        long tmp = js2[i];

        // separate r, g, and b values
        long r = tmp/1000000;
        long g = tmp%1000000/1000;
        long b = tmp%1000;
        int rr = (int)r;
        int gg = (int)g;
        int bb = (int)b;

        //determine the correct NeoPixel
        int pos = i/14;
        int j = 0;
        if(pos % 2 == 1){
          j = (13 + 14*pos) - i%14;
         }else{
          j = i;
          }
      
       strip.setPixelColor(j, rr, gg, bb);

    }
  }else{
     for(int i=0; i< TOTAL; i++){
       strip.setPixelColor(i, 40,50, 100);
     }
  }
   strip.show();
   delay(5000);


}


