/*
 * Copyright 2016 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

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
    void start(int valor);
    void run();

private:
    
  int data;
  bool bandera;
  
signals:
    
  void timeout();
  
};

#endif // MYQTIMER_H
