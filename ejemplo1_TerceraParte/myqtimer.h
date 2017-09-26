

#ifndef MYQTIMER_H
#define MYQTIMER_H
#include <QThread>
#include <unistd.h>
#include <functional>


class myqtimer{
  
  
public:
    
myqtimer();
bool getStop();
void setStop(bool stop);
void run(std::function<void()> signal);
~myqtimer();


private:

  bool parar;
  

  
};

#endif // MYQTIMER_H
