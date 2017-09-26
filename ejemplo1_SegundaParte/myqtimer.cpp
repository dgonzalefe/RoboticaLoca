

#include "myqtimer.h"

myqtimer::myqtimer()
{
  parar=true;
}

bool myqtimer::isActive()
{
  if(parar==true){
    return false;
  }else{
    return true;
  }
}

void myqtimer::run()
{
  while(1){
    if(!parar){
      emit timeout();
      msleep(1000);
    }
  }
}

void myqtimer::start()
{
  parar = false;
  QThread::start();
}

void myqtimer::stop()
{
  parar=true;
}
