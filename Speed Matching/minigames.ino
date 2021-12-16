#include <M5Core2.h>
#include <time.h>
#include <cstdlib>
#include <charconv>
#include "memorizingCard.h"
#include "ScreenEffect.h"
#include "IntroSetup.h"
#include "colorpolygon.h"
#include "loop_interface.h"
#include "Images.h"

ScreenEffect screen;
colorPolygon game0(screen);
IntroSetup intro(screen);
loop_interface interface(screen, game0);
int boxsize = 20;

void setup() 
{
  //put your setup code here, to run once:
  M5.begin();     
// intro.coolIntro(); // when the device is turned on, it will display the intro made by the programmer.
}
void loop() {
    srand (time(NULL));
    M5.update();
    game0.play();
    M5.Lcd.clear(BLACK);
} 
