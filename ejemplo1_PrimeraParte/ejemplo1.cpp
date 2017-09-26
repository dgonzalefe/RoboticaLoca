#include "ejemplo1.h"

static int h=0;

ejemplo1::ejemplo1(): Ui_Counter()
{
    
    //Primer apartado
    
    
	setupUi(this);
	show();
    
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
    connect(button2, SIGNAL(clicked()), this, SLOT(doReset()));
    

 
    
}

ejemplo1::~ejemplo1(){
    
    
}

//Primer apartado



//Update counter
void ejemplo1::update(){
    
    h++;
    lcdNumber->display(h);
    
}

//Reset counter
void ejemplo1::doReset(){
    
    timer->stop();
    h=0;
    timer->start();
    lcdNumber->display(h);
    qDebug() << "Cronometro reiniciado";

    
    
}

//Stop counter
void ejemplo1::doButton()
{
 
    //Check timer state
    if (timer->isActive()){
        timer->stop();
        button->setText("START");
        qDebug() << "Cronometro parado";
        
    }else{
        
        timer->start();
        button->setText("STOP");
        qDebug() << "Cronometro reanudado";

    }
        
}








