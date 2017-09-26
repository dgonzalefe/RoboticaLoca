

#ifndef MYQTIMER_H
#define MYQTIMER_H

#include <QThread>

class myqtimer : public QThread
{
  Q_OBJECT
  
public:
myqtimer();
bool isActive();
void stop();
void start();
void run();

private:
    
  int dato;
  bool parar;
  
signals:
  void timeout();
  
};

#endif // MYQTIMER_H
