//**********************************************************************************//
//** Author: Jaehyeon Kim                                                         **//
//** Date Created: December 8, 2021                                               **//
//** Term Project mini game: find the number of the shape                         **//
//** UH-1000 Computer Programming for Engineers, NYUAD                            **//
//**********************************************************************************//

#include <M5Core2.h>

//Declare variables.
int boxX = 15;
int boxY = 15;
int boxWidth = 180;
int boxHeight = 155;
int score = 0;
int answer;
int answerButton;
int answerShape;
int option1;
int option2;
int option3;
const int shapeCount = 9;
RTC_TimeTypeDef TimeStruct;

//Class of shape for objects that will move around inside the box
class Shape {
  private:
    int x = boxX + boxWidth / 2;                  //x coordinate
    int y = boxY + boxHeight / 2;                 //y coordinate
    int vx;                                       //x vector
    int vy;                                       //y vector
    int shape;                                    //shape id
  public:
    Shape() {}
    Shape(int num) {
      shape = num;
      vx = int(random(-15, 15));                  //Set random x vector.
      vy = int(random(-15, 15));                  //Set random y vector.
      checkSpeed();                               //Check if the velocity is valid.
    }
    int getShape(){
      return shape;
    }
    void checkSpeed() {
      bool check = false;
      if (vx == 0 && vy == 0){                    //Reset vectors if velocity is 0.
        check = true;                             //Check the velocity again.
        vx = int(random(-15, 15));
        vy = int(random(-15, 15));  
      }
      if (vx*vx + vy*vy < score*score or vx*vx + vy*vy > (score+5)*(score+5)) {
        check = true;                             //Reset vectors if velocity is less than score
        vx = int(random(-15, 15));                //or is greater than score + 5.
        vy = int(random(-15, 15));                //This makes sure that the velocity increases with the score.
      }
      if (check){
        checkSpeed();                             //Check the velocity again if it has been resetted.
      }
    }
    void moveShape() {                            //Update the coordinates and draw the shape.
      x += vx;                                    //Add the vectors to coordinates.
      y += vy;
      if (x<boxX+19 or x>boxX + boxWidth-29) {    //If the shape hits the left/right edge of the box
        vx *= -1;                                 //reverse the x direction.
        x += vx;
      }
      if (y<boxY+19 or y>boxY + boxHeight-29){    //If the shape hits the top/bottom edge of the box
        vy *= -1;                                 //reverse the y direction.
        y += vy;
      }
      switch (shape) {                            //Draw the shape at the new coordinates according to the shape id (Paint it black to hide colors).  
        case 0:                                   //Shape id 0 : Circle
          M5.Lcd.fillCircle(x, y, 20, BLACK);
          break;
        case 1:                                   //Shape id 1 : Square
          M5.Lcd.fillRect(x-20, y-20, 40, 40, BLACK);
          break;
        default:                                  //Shape id 2 : Triangle
          M5.Lcd.fillTriangle(x-20, y+20, x+20, y+20, x, y-17.5, BLACK);
      }
    }
    void reveal() {                               //Reveal the color of the shape.
      switch (shape) {                            //Draw the colored shape on the same position so that it covers the original black shape.
        case 0:                                   //Shape id 0 : Circle
          M5.Lcd.fillCircle(x, y, 20, RED);
          break;
        case 1:                                   //Shape id 1 : Square
          M5.Lcd.fillRect(x-20, y-20, 40, 40, GREEN);
          break;
        default:                                  //Shape id 2 : Triangle
          M5.Lcd.fillTriangle(x-20, y+20, x+20, y+20, x, y-17.5, BLUE);
      }
    }
};

Shape shapes[shapeCount];

//Set a new answer.
void setAnswer() {
  answer = int(random(2, 6));                     //Answer: how many shapes are there?
  answerShape = int(random(0, 3));                //What shape should we find?
  answerButton = int(random(0, 3));               //What button is the answer?
  
  if (answerButton == 0) {                        //If the first button is the answer
    option1 = answer;
    option2 = option1 + 1;                  
    option3 = option2 + 1;
  } else if (answerButton == 1) {                 //If the second button is the answer:
    option2 = answer;
    option1 = option2 - 1;
    option3 = option2 + 1;
  } else {                                        //If the third button is the answer:
    option3 = answer;
    option2 = option3 - 1;
    option1 = option2 - 1;
  }
  for (int i = 0; i < answer; i++) {              //Create the 'answer' amount of answer shapes
    shapes[i] = Shape(answerShape);
  }
  for (int i = 0; i < shapeCount - answer; i++) { //Create other shapes (random, but not the 'answer') so that the number of shapes is 'shapeCount' in total
    int other = int(random(0,3));
    if (other != answerShape) {
      shapes[i + answer] = Shape(other);
    } else {
      i--;
    }
  }
}

//Update the screen upon startup or when a button is pressed.
void updateScreen(int choice) {
  M5.Rtc.GetTime(&TimeStruct);                    //Get the current time.
  
  if (choice == answer) {                         //If the user inputs correct answer:
    score++;                                      //Increment the score.
    M5.Lcd.drawString("Correct!", 110, 160, 4);
    for (int i = 0; i < shapeCount; i++) {        //Reveal the answer shapes.
      if (shapes[i].getShape() == answerShape){
        shapes[i].reveal();
      }
    }
    setAnswer();                                  //Set a new answer and start the next quiz after one second.
    delay(1000);
  } else if (choice != 0) {                       //If the user inputs incorrect answer:
    M5.Lcd.drawString("Incorrect: the answer was " + String(answer), 10, 160, 4);
    for (int i = 0; i < shapeCount; i++) {        //Reveal the answer shapes.
      if (shapes[i].getShape() == answerShape){
        shapes[i].reveal();
      }
    }
    setAnswer();                                  //Set a new answer and start the next quiz after one second.
    delay(1000);
  }                                               //If there is no answer input (choice is zero), it means the program is on its startup, so do not execute the code.
  
  if (score == 10){                               //Print the timestamp and end the program when the user reaches the score 10.
    int minutes = TimeStruct.Hours*60 + TimeStruct.Minutes;
    int seconds = TimeStruct.Seconds;
    M5.Lcd.drawString("Finished!", 100, 160, 4);
    delay(1500);
    M5.Lcd.drawString("Elapsed time: " + String(minutes) + ":" + String(seconds), 50, 160, 4);
    delay(3000);
    M5.Axp.PowerOff();
  }

  M5.Lcd.clear(WHITE);                                              //If the program is not ended, start a new quiz.
  M5.Lcd.drawRect(boxX-1, boxY-1, boxWidth+2, boxHeight+2, BLACK);  //Draw the box in which the shapes will move around.
  M5.Lcd.fillRect(boxX, boxY, boxWidth, boxHeight, WHITE);          //Paint the box white.
  M5.Lcd.drawString("Score: " + String(score), 210, 25, 4);         //Print the current score.
  M5.Lcd.drawString("How many", 198, 75, 4);
  switch (answerShape) {                                            //Draw the answer shape.
    case 0:
      M5.Lcd.fillCircle(260, 140, 20, RED);
      break;
    case 1:
      M5.Lcd.fillRect(260 - 20, 140 - 20, 40, 40, GREEN);
      break;
    default:
      M5.Lcd.fillTriangle(260 - 20, 140 + 20, 260 + 20, 140 + 20, 260, 140 - 17.5, BLUE);
  }
  M5.Lcd.drawNumber(option1, 45, 200, 4);                           //Print the answer options above each buttons.
  M5.Lcd.drawNumber(option2, 155, 200, 4);
  M5.Lcd.drawNumber(option3, 260, 200, 4);
}

// Initialize the program.
void setup() {
  M5.begin();                       //Init M5Core2.
  M5.Lcd.fillScreen(WHITE);
  M5.Rtc.begin();
  TimeStruct.Hours   = 0;           //Set the time of the real-time clock structure.
  TimeStruct.Minutes = 0;
  TimeStruct.Seconds = 0;
  M5.Rtc.SetTime(&TimeStruct);
  setAnswer();                      //Setup answer.
  updateScreen(0);                  //Update screen according to answer.
}

// After the program in setup() runs, it runs the program in loop().
// The loop() function is an infinite loop in which the program runs repeatedly.
void loop() {
  M5.update();                      //Read the press state of the key.
  
  delay(50);
  
  M5.Lcd.fillRect(boxX, boxY, boxWidth, boxHeight, WHITE);  //Move the shapes around inside the box
  for (int i = 0; i < shapeCount; i++) {                    //by filling the box white and drawing each shapes at their new coordinates.
    shapes[i].moveShape();
  }
  if (M5.BtnA.wasReleased()) {                              //Update screen with a relative parameter upon a button press input.
    updateScreen(option1);
  } else if (M5.BtnB.wasReleased()) {
    updateScreen(option2);
  } else if (M5.BtnC.wasReleased()) {
    updateScreen(option3);
  }
}
