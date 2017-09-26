#include "ejemplo1.h"

 
ejemplo1::ejemplo1(): Ui_Counter()
{
  setupUi(this);
  num=0;
  tiempo=1000;
  verticalSlider->setMinimum(1);
  verticalSlider->setMaximum(16);
  verticalSlider->setValue(verticalSlider->maximum()/2);
  
  
  show();
  
  mythread = std::move(std::thread(&hebras::run, hebras(),std::bind(&ejemplo1::doLCDnumber,this)));
  
  connect(button, SIGNAL(clicked()),this,SLOT(doButton()));
  connect(restart, SIGNAL(clicked()),this,SLOT(restartContador()));
  connect(verticalSlider, SIGNAL(actionTriggered(int)),this,SLOT(frecuencia()));
  connect(verticalSlider, SIGNAL(sliderPressed()),this,SLOT(frecuencia()));
 
}

ejemplo1::~ejemplo1(){
  mythread.detach();
}

void ejemplo1::doButton()
{
	
  if(!hilo.getparar()){
    hilo.setparar(true);
    button->setText("START");
  }
  else{
   hilo.setparar(false);
  button->setText("STOP");
  cv.notify_all();
  }
  
}

void ejemplo1::restartContador()
{
  
num=0;
lcdNumber->display(num);


}


 void ejemplo1::doLCDnumber()
{
    
   std::unique_lock<std::mutex> lk(cv_m); 
   
   while(hilo.getparar())
      cv.wait(lk);
   
   
   num++;
   lcdNumber->display(num);
   std::this_thread::sleep_for(std::chrono::milliseconds(tiempo));
     
}  

void ejemplo1::frecuencia()
{
   int f;
   f=verticalSlider->value();
   tiempo=4000/f;
   lcdNumber_F->display(f);
  
}




