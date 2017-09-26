#include "ejemplo1.h"



ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
	connect(&cont, SIGNAL(timeout()), this, SLOT(signal()) );
	cont.start();
	
	
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
    
    
    
	if(cont.isActive()){
        
	  cont.stop();
      button->setText("START");
      
	 }else{
        
	    cont.start();
        button->setText("STOP");
        
	 }
	 
	
}

void ejemplo1::signal()
{
    //int y=0;
    qDebug() << "Timeout";
        //y=lcdNumber->intValue();
        lcdNumber->display(lcdNumber->intValue()+1);
}



