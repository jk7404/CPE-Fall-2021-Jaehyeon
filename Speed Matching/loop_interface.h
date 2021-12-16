
#ifndef loop_interface

class loop_interface{

private: ScreenEffect* screen;
         bool quit =false;
         String menu_arr[4] = {"Play", "Option", "About", "Quit"};
         String game_arr[4] = {"SpeedMatch", "game1", "game2", "Quit"};         
         colorPolygon* game0;

public: 

loop_interface(ScreenEffect in_screen, colorPolygon in_game)
{
  screen =& in_screen;
  game0 =& in_game;
}

  void buttonCheck ()
  {
     M5.Lcd.setTextSize(1.5);
     bool checker = false;
     M5.Lcd.setTextSize(1.5);
  
  while (checker ==false) {
    M5.update();
    M5.Lcd.drawCentreString("Press the left button on the device",(int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-30, 2);
    //these lines  chceks whether the left button works correctly or not
    if (M5.BtnA.wasReleased())
    {
      M5.Lcd.setTextSize(2);
      screen->setDefault();
      M5.Lcd.drawCentreString("GoodJob!",(int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)+30, 2);
      checker = true;
      screen->fading(20,140);
      screen->setDefault();
       M5.Lcd.clear(BLACK);
    }  

  }

  checker = false;
  while (checker == false)
  {
    M5.update();
    M5.Lcd.setTextSize(1.5);
    M5.Lcd.drawCentreString("Press the middle button on the device", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-30, 2);

     if (M5.BtnB.wasReleased())
    {
      M5.Lcd.setTextSize(2);
      screen->setDefault();
      M5.Lcd.drawCentreString("GoodJob!",(int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)+30, 2);
      checker = true;
      screen->fading(20,140);
      screen->setDefault();
      M5.Lcd.clear(BLACK);
    }  
  }
  checker = false;
  while (checker ==false)
  {
    M5.update();
    M5.Lcd.setTextSize(1.5);
    M5.Lcd.drawCentreString("Press the right button on the device", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-30, 2);
     if (M5.BtnC.wasReleased())
    {
      M5.Lcd.setTextSize(2);
      M5.Lcd.drawCentreString("GoodJob!",(int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)+30, 2);
      screen->setDefault();
      checker = true;
      screen->fading(20,140);
      screen->setDefault();
      M5.Lcd.clear(BLACK);
    }  
  }

    
    checker = false;
    M5.Lcd.setTextSize(2);
    M5.Lcd.drawCentreString("Done! Enjoy!", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2);
    screen->fading(20,140);
    screen->setDefault();
}

void menu()
{   
  //initialize menu
    M5.Lcd.clear(BLACK);
   screen->rev_fading(20,140);
    M5.Lcd.setTextSize(3);
    M5.Lcd.drawCentreString(menu_arr[0], (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-50, 2);
    M5.Lcd.setTextSize(1);
    M5.Lcd.drawCentreString(menu_arr[1], 80, 180, 2);
    M5.Lcd.drawCentreString(menu_arr[2], 160, 180, 2);
    M5.Lcd.drawCentreString(menu_arr[3], 240, 180, 2);
  int choice = -1;
  while (quit ==false)
  {
      M5.update();
   if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200))
   {
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    M5.Lcd.drawCentreString(menu_arr[0], (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-50, 2);
    M5.Lcd.setTextSize(1);
    M5.Lcd.drawCentreString(menu_arr[1], 80, 180, 2);
    M5.Lcd.drawCentreString(menu_arr[2], 160, 180, 2);
    M5.Lcd.drawCentreString(menu_arr[3], 240, 180, 2);
    choice++;
    M5.Lcd.setTextColor(RED);
    if (choice ==0)
    {
    M5.Lcd.setTextSize(3);
    M5.Lcd.drawCentreString(menu_arr[choice], (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-50, 2);
    }
    M5.Lcd.setTextSize(1);
    if (choice ==1)
    {
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }
    if (choice ==2){
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }
    if (choice ==3)
    {
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }
    if (choice ==4)
    {
    M5.Lcd.setTextSize(3);
    choice = 0;
    M5.Lcd.drawCentreString(menu_arr[choice], (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-50, 2);
    }
     
    }
    else if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200))
   {
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    M5.Lcd.drawCentreString(menu_arr[0], (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-50, 2);
    M5.Lcd.setTextSize(1);
    M5.Lcd.drawCentreString(menu_arr[1], 80, 180, 2);
    M5.Lcd.drawCentreString(menu_arr[2], 160, 180, 2);
    M5.Lcd.drawCentreString(menu_arr[3], 240, 180, 2);
    choice--;
    
    M5.Lcd.setTextColor(RED);
    if (choice==0)
    {
    M5.Lcd.setTextSize(3);
    M5.Lcd.drawCentreString(menu_arr[choice], (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2)-50, 2);
    }
    M5.Lcd.setTextSize(1);
    if (choice ==1){
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }
    if (choice ==2)
    {
    M5.Lcd.setTextSize(1);
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }
    if (choice ==-2 ||choice ==-1)
    {
    M5.Lcd.setTextSize(1);
    choice = 3;   
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }

     
    }
      else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200))
    {
        if (choice ==0)
        {
          M5.Lcd.clear(BLACK);
          gameMenu();
        }
        if (choice ==1)
        {
          M5.Lcd.clear(BLACK);
        }
        if (choice ==2)
        {
          M5.Lcd.clear(BLACK);          
        }  
        if (choice ==3)
        
          M5.Lcd.drawCentreString(menu_arr[2], 2*80, 180, 2);
          {
             M5.Axp.PowerOff();
          }
    }


}
}

void gameMenu ()
{
   M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(WHITE);
  bool go_back = false;
  int choice = -1;
    M5.Lcd.drawString("Choose your game", 1, 1,2);
    M5.Lcd.drawString(game_arr[0], 1, 40, 2);
    M5.Lcd.drawString(game_arr[1], 1, 80, 2);
    M5.Lcd.drawString(game_arr[2], 1, 120, 2);
    M5.Lcd.drawRightString(game_arr[3], 299, 200, 2);
  while (go_back == false)
  {
    M5.update();
   if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200))
   {
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.drawCentreString(game_arr[0], 1, 40, 2);
    M5.Lcd.drawCentreString(game_arr[1], 1, 80, 2);
    M5.Lcd.drawCentreString(game_arr[2], 1, 120, 2);
    M5.Lcd.drawRightString(game_arr[3], 299, 200, 2);
    choice++;
    M5.Lcd.setTextColor(RED);
    if (choice ==0)
    {
    M5.Lcd.drawCentreString(game_arr[0], 1, 40, 2);
    }
    if (choice ==1)
    {
    M5.Lcd.drawCentreString(game_arr[1], 1, 80, 2);
    }
    if (choice ==2){
    M5.Lcd.drawCentreString(game_arr[2], 1, 120, 2);
    }
    if (choice ==3)
    {
    M5.Lcd.drawRightString(game_arr[3], 299, 200, 2);
    }
    if (choice ==4)
    {
    choice = 0;
    M5.Lcd.drawCentreString(game_arr[0], 1, 40, 2);
    }
    }
    else if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200))
   {
        M5.Lcd.setTextColor(WHITE);
    M5.Lcd.drawCentreString(game_arr[0], 1, 40, 2);
    M5.Lcd.drawCentreString(game_arr[1], 1, 80, 2);
    M5.Lcd.drawCentreString(game_arr[2], 1, 120, 2);
    M5.Lcd.drawRightString(game_arr[3], 299, 200, 2);
    M5.Lcd.setTextColor(RED);
    choice --;
    if (choice==0)
    {
    M5.Lcd.drawCentreString(game_arr[0], 1, 40, 2);
    }
    if (choice ==1){
    M5.Lcd.drawCentreString(game_arr[1], 1, 80, 2);
    }
    if (choice ==2)
    {
    M5.Lcd.drawCentreString(menu_arr[choice], choice*80, 180, 2);
    }
    if (choice ==-2 ||choice ==-1)
    {
    choice = 3;   
    M5.Lcd.drawRightString(game_arr[3], 299, 200, 2);
    }
    }
      else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200))
    {
        if (choice ==0)
        {
          M5.Lcd.clear(BLACK);
          game0->play();
        }
        if (choice ==1)
        {
          M5.Lcd.clear(BLACK);
        }
        if (choice ==2)
        {
          M5.Lcd.clear(BLACK);          
        }  
        if (choice ==3)
        {
          M5.Lcd.clear(BLACK);
          M5.Lcd.setTextSize(1.5);
          M5.Lcd.setTextColor(WHITE);
          M5.Lcd.drawCentreString("Returning to the menu", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2);
          screen->fading(20,140);
          M5.Lcd.clear(BLACK);
          screen->rev_fading(20,140);
          bool go_back =true;
        }
    }
        
}
}


};




#endif
