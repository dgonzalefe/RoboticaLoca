#include "ejemplo1.h"




ejemplo1::ejemplo1(): Ui_Counter() {
    
    
    ///*****////

    setupUi(this);
    show();
    valor=0;
    mythread = std::move(std::thread(&myqtimer::run, myqtimer(),std::bind(&ejemplo1::signal,this)));
    connect(buttonStart,SIGNAL(clicked()),this,SLOT(doButton()));
    connect(buttonRestart, SIGNAL(clicked()),this,SLOT(restartCounter()));
    
}

ejemplo1::~ejemplo1(){
    
     mythread.detach();
     
}

void ejemplo1::doButton(){
    
    if(!cont.getStop()){
        cont.setStop(true);
        buttonStart->setText("START");
	qDebug() << "Cronometro parado";
    }
    else{
        cont.setStop(false);
        buttonStart->setText("STOP");
        condition.notify_all();
	qDebug() << "Cronometro reanudado";
    }
  
}


void ejemplo1::restartCounter(){
    
    valor=0;
    lcdNumber->display(valor);
    qDebug() << "Cronometro reiniciado";

}


 void ejemplo1::signal(){
    
   std::unique_lock<std::mutex> lk(condition_mutex); 
   
   while(cont.getStop())
        lcdNumber->display(valor);
        condition.wait(lk);
   
   
   valor++;
   lcdNumber->display(valor);
   //usleep(1000000);
 
    
    
} 


