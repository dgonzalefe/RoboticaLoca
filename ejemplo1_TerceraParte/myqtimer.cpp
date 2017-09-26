#include "myqtimer.h"


myqtimer::myqtimer(){
    
  parar=false;
  
}



void myqtimer::run( std::function <void()> signal){
    
  while(true){
      
    signal();
    
  }
  
}

void myqtimer::setStop(bool stop){

    parar=stop;
    
}

bool myqtimer::getStop(){
    
    return parar;
    
}


myqtimer::~myqtimer(){
    
    
    
}
