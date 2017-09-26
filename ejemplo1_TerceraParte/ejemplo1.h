#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include "myqtimer.h"
#include <thread>
#include <functional>
#include <condition_variable>

class ejemplo1 : public QWidget, public Ui_Counter
{
    
Q_OBJECT

public:
    
    int valor;
    ejemplo1();
    virtual ~ejemplo1();
    
public slots:
    
	void doButton();

	void signal();
	
    void restartCounter();
    
private:
    
  myqtimer cont;
  std::thread mythread;
  std::condition_variable condition;
  std::mutex condition_mutex;
  
};



#endif // ejemplo1_H
