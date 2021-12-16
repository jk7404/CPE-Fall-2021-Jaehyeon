
#ifndef IntroSetup
class IntroSetup

{
private: ScreenEffect* screen;
public: IntroSetup(ScreenEffect in_screen){
    screen = &in_screen; // just so we don't have to include additional an additional argument
  }
    void logoIntro (uint16_t* logoBitmap) 
    {
      M5.Lcd.drawBitmap(0, 0, 320, 240,logoBitmap); // draw a logo
      delay(1300);
    }
    void coolIntro () {
     M5.begin();
     M5.Lcd.setTextSize(1.5); // set the text size to 1.5 pixels.
     M5.Lcd.setCursor(150, 100); //Set the location of the cursor to the coordinates X and Y
     M5.Lcd.clear(BLACK); // clear the screen to black
     M5.Lcd.setTextColor(WHITE); // set the color of the text to white
     M5.Lcd.setTextFont(4);
     M5.Lcd.drawCentreString("Hello, welcome to Brainy", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2); //print in the center
     screen->fading(20,140); // call a function fading to fade the screen 
     screen->setDefault(); // set to a default brightness
     M5.Lcd.clear(BLACK);
     M5.Lcd.drawCentreString("Before we start, let's", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2); //print in the center
     M5.Lcd.drawCentreString("check if all functions work correctly", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2+20), 2);
     screen->fading(20,140);
     screen->setDefault();
     M5.update();
     M5.Lcd.clear(BLACK);   
    }

  
};




#endif
