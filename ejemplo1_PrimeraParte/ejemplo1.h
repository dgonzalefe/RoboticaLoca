#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include <QTimer>
#include <QPushButton>

class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT
public:
    
    QTimer *timer=new QTimer(this);
    ejemplo1();
    virtual ~ejemplo1();
    
public slots:
    
    
    void doReset();
    void update();
	void doButton();
};

#endif // ejemplo1_H
