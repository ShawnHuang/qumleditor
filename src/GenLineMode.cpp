#include "Canvas.h"
#include "Shape.h"
#include "Line.h"
#include "GenLine.h"
#include "Port.h"
#include "BasicBox.h"
#include "UseCaseBox.h"
#include "GenLineMode.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

GenLineMode::GenLineMode(Canvas* canvas) : Mode(canvas){
    
}
GenLineMode::~GenLineMode(){
    
}
void GenLineMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"genline moved"<<std::endl;
}
void GenLineMode::mousePressEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"genline pressed"<<std::endl;
}
void GenLineMode::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
  QTransform transform;
  BasicBox* begin = dynamic_cast<BasicBox*>(canvas->itemAt(event->scenePos(), transform));
  BasicBox* end = dynamic_cast<BasicBox*>(canvas->itemAt(event->buttonDownScenePos(Qt::LeftButton), transform));
  if(begin && end){
    GenLine* line = new GenLine();
    line->setPorts(begin->getPort(event->scenePos()), end->getPort(event->buttonDownScenePos(Qt::LeftButton)));
    canvas->addItem(line);
  }
  std::cout<<"genline released"<<std::endl;
}
