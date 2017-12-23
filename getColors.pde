PImage img;
String[][] pixelArray = new String[11][14];

void setup() {
  size(11, 14);
  img = loadImage("js1_small.jpg");
  img.loadPixels();
  for (int i = 0; i<img.width*img.height; i++){
    int col = img.pixels[i];

    int r1 = int(red(col));
    int g1 = int(green(col));
    int b1 = int(blue(col));
    
    // convert each value to 3 integer long value 
    String rr = str(r1);
    String gg = lengthTo3(str(g1));
    String bb = lengthTo3(str(b1));

    pixelArray[i%11][i/11] = ( "'" +rr+gg+bb + "'");
  }

  for(int i=0; i<pixelArray.length; i++){
    println(pixelArray[i]);
  }
  
}

void draw() {
  image(img, 0, 0);  
}

// pad the value to three digits length
String lengthTo3(String str){
  while(str.length() < 3){
    str = "0" + str;
  }
  return str;
}
