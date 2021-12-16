#include <time.h>
#include <cstdlib>
#define ORANGE_1              0xFC64 //because there is already a predefined color named orange with different rgb value, add "_1" to the name;
#define LIGHTGREY           0xC618 //define color using hexa decimal 
#define DARKGREY            0x7BEF 
#ifndef colorPolygon

class colorPolygon {
  private: int answer_arr [4] = {1, 0, 0, 0}; //only one among 4 is correct. 
           int score =0;; //set score
           String str_arr [4] = {"Rectangle", "Triangle", "Circle", "Ellipse"};
           String color_arr [4] = {"Red", "Blue", "Yellow", "Green"};
           ScreenEffect* screen;
           int tempAnswer;
  public:
 
  colorPolygon(ScreenEffect in_screen)
{
  screen =& in_screen;
}

//the function shuffles the color and polygon and correct answer for the button.
void shuffleArr ()
{  
  srand(time(NULL));
  for(int i=0;i<4 ;i++) //shuffle 4 times
  {
     int j=i+ rand() % (4-i); //remaining positions are only targeted.
     int tmp_ans=answer_arr[i];
     answer_arr[i]=answer_arr[j];
     answer_arr[j] = tmp_ans;
     int a=i+ rand() % (4-i);
     String tmp_color=color_arr[i];
     color_arr[i]=color_arr[a];
     color_arr[a] = tmp_color;
     int b=i+ rand() % (4-i);
     String tmp_str=str_arr[i];
     str_arr[i]=str_arr[b];
     str_arr[b] = tmp_str;
  }
  for (int i =0; i<4; i++) //for randomize button
  {
    if (answer_arr[i] ==1)
        tempAnswer = i;
  }

}
void drawButtons ()
{
 
  M5.Lcd.fillRect (10, 150, 150, 30, LIGHTGREY);
  M5.Lcd.fillRect (10, 190, 150, 30, LIGHTGREY);
  M5.Lcd.fillRect (170, 150,150, 30, LIGHTGREY);
  M5.Lcd.fillRect (170, 190, 150, 30,LIGHTGREY);
  M5.Lcd.fillRect (10, 150, 150, 24, DARKGREY);
  M5.Lcd.fillRect (10, 190, 150, 24, DARKGREY);
  M5.Lcd.fillRect (170, 150, 150, 24,DARKGREY);
  M5.Lcd.fillRect (170, 190, 150, 24,DARKGREY);
  
  srand(time(NULL)); 
   M5.Lcd.setTextSize(0.5);
    for (int i =0; i< tempAnswer; i++)
    {
         int j=rand() % 3+1; //1 to 3//
         if (i <2){
         M5.Lcd.drawCentreString(color_arr[j-1] + str_arr[j], 60+i*190, 155,2); //j-1 to make sure the same answer does not generate
         }
      if (i ==2){
         M5.Lcd.drawCentreString(color_arr[j] + str_arr[j-1], 60, 195,2); //j-1 to make sure the same answer does not generate
      }
    }
    
    for (int i = tempAnswer; i<4; i++)
    {
       int c=rand() % 2+0; //1 to 3//
       if (i<2)
       {
          if (i==tempAnswer)
            M5.Lcd.drawCentreString(color_arr[1] + str_arr[1], 60+i*190, 155,2); //
          else if (i!=tempAnswer)
           M5.Lcd.drawCentreString(color_arr[c+1] + str_arr[c], 60+i*190, 155,2);
       }
       if (i==2){
          if ( i == tempAnswer) 
         M5.Lcd.drawCentreString(color_arr[1] + str_arr[1], 60, 195,2);
         else if (i != tempAnswer)
          M5.Lcd.drawCentreString(color_arr[c] + str_arr[c+1], 60, 195,2); 
       }
       
      if (i ==3){
           if ( i == tempAnswer) 
            M5.Lcd.drawCentreString(color_arr[1] + str_arr[1], 250, 195,2);
           else if (i != tempAnswer)
            M5.Lcd.drawCentreString(color_arr[c] + str_arr[c+1], 250, 195,2);
      }
    }
  
}

void drawBoard ()
{
  uint32_t temp_color; // in m5 stack core, colors are defined as uint32_t and converted to RGB. 
  if (color_arr[1]=="Red")
    temp_color = RED;
  if (color_arr[1]=="Blue")
    temp_color = BLUE;
  if (color_arr[1]=="Yellow")
    temp_color = YELLOW;
  if (color_arr[1]=="Green")
    temp_color = GREEN;
  if (str_arr[1] =="Rectangle") //since array is already shuffled, we can just assign 1 or any other number in between 0 to 3 to generate a random number
      M5.Lcd.fillRect(10,10,120,120, temp_color);
  else if (str_arr[1] == "Triangle")
      M5.Lcd.fillTriangle(65,10,10,130, 130, 130, temp_color);
  else if (str_arr[1] =="Circle")
      M5.Lcd.fillCircle(70,70,60, temp_color);
  else if (str_arr[1] =="Ellipse")
  {
      M5.Lcd.fillEllipse(70,70,60,40, temp_color);
  }
}
void buttons ()
{
    int i=-1;
    bool answered =false;

    for (int t =0; t<2500; t++)
    {
       M5.Lcd.setTextSize(1);
       
       int dis_t = t*0.002;
       M5.Lcd.drawString ("Time remainded: " + ((String) (5-dis_t) ), 190, 60, 2);
      M5.update();
     if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200))
      {
        M5.Lcd.drawRect (9,149,152,32, BLACK);
        M5.Lcd.drawRect (169,149,152,32,BLACK);
        M5.Lcd.drawRect (9,189,152,32, BLACK);
        M5.Lcd.drawRect (169,189,152,32, BLACK);
          i++;        
      if ( i == 0) 
      {
        M5.Lcd.drawRect (9,149,152,32, RED);
      }
      else if ( i ==1)
      {
        M5.Lcd.drawRect (169,149,152,32,RED);
      }
      else if ( i == 2)
      {
        M5.Lcd.drawRect (9,189,152,32, RED);
      }
        
      else if (i == 3)   
      {
        M5.Lcd.drawRect (169,189,152,32, RED);
      }
      else if (i == 4){
          i = 0;
        M5.Lcd.drawRect (9,149,152,32, RED);
        }
    }
      else if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200))
      { 
        M5.Lcd.drawRect (9,149,152,32, BLACK);
        M5.Lcd.drawRect (169,149,152,32,BLACK);
        M5.Lcd.drawRect (9,189,152,32, BLACK);
        M5.Lcd.drawRect (169,189,152,32, BLACK);
        M5.update();
          i--;        
      if ( i==-2 || i ==-1) 
      {
        i =3;
        M5.Lcd.drawRect (169,189,152,32, RED);
      } 
      else if (i ==0)
      {
        M5.Lcd.drawRect (9,149,152,32, RED);
      }
      else if ( i == 1)
      {
        M5.Lcd.drawRect (169,149,152,32,RED);
      }
      else if (i == 2)   
      {
        M5.Lcd.drawRect (9,189,152,32, RED);
      }
      else if (i == 3){
        M5.Lcd.drawRect (169,189,152,32, RED);
        }
    }
    if (M5.BtnB.isPressed() || M5.BtnB.pressedFor(1000, 200))
    {
      M5.update();
      M5.Lcd.setTextSize(2);
      M5.Lcd.setTextColor(WHITE); 
      if (i == tempAnswer)
        {
          
          M5.Lcd.clear(BLACK);
          M5.Lcd.drawCentreString("Correct!", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2);
          score++;
          screen->fading(40,110);
          screen->setDefault();
          M5.Lcd.clear(BLACK);
          break;
          }
     else if (i !=tempAnswer && -1 !=i)
     {    
      
         M5.Lcd.clear(BLACK);
          M5.Lcd.drawCentreString("Wrong", (int)(M5.Lcd.width()/2), (int)(M5.Lcd.height()/2), 2);
          screen->fading(40,110);
          screen->setDefault();
          M5.Lcd.clear(BLACK);
         break;
     }     
    }
    delay(1);
  }
}

  int getScore()
  {
    return score;
  }
  void resetScore()
  {
    score =0;
  }
  void play()
  {
    resetScore();
    for (int r =10; r>=0; r--)
    {
     shuffleArr();
     drawBoard();
     drawButtons();
     M5.Lcd.drawString ("Remaing round : " + ((String)r), 190, 20, 2);
     M5.Lcd.drawString ("Score: " + ((String) getScore()), 190, 40, 2);
     buttons();
    M5.Lcd.clear(BLACK);
  }
  }
};

#endif 
