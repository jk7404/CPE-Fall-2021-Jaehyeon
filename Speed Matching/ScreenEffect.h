#ifndef ScreenEffect

class ScreenEffect
{

public: ScreenEffect(){}

void fading(int factor, int delayFactor)
{
  for(int cv=3300; cv > 2400; cv = cv -factor) //cv equal to 2400 to set some delay.
  {   
      delay(delayFactor);
      M5.Axp.SetLcdVoltage(cv); //M5Core2 LCD brightness is controlled by AXP192 from 2500 to 3300 mv  
  }
 }
 //reverse fading aka brightning, voltage set initially equal to 2500.
 void rev_fading(int factor, int delayFactor)
{
  for(int cv=2500; cv < 3400; cv = cv +factor)
  {   
      delay(delayFactor);
      M5.Axp.SetLcdVoltage(cv); //M5Core2 LCD brightness is controlled by AXP192 from 2500 to 3300 mv  
  }
 }
//this function decrease the screen brightness exponentially
void accFading(int factor, int delayFactor) 
{
  int currentFactor = factor;
  for(int cv=3300; cv > 2500; cv = cv -factor)   
  {
    delay(delayFactor);
      M5.Axp.SetLcdVoltage(3300-factor); //M5Core2 LCD brightness is controlled by AXP192 from 2500 to 3300 mv  
      
  }
}

 void setDefault()
 {
        M5.Axp.SetLcdVoltage(3300); //M5Core2 LCD brightness is controlled by AXP192 from 2500 to 3300 mv  
 }
};

#endif
