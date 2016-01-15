#include "Canvas.h"
#include "Shape.h"
#include "Line.h"
#include "ComLine.h"
#include "Port.h"
#include "BasicBox.h"
#include "UseCaseBox.h"
#include "ComLineMode.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

ComLineMode::ComLineMode(Canvas* canvas) : Mode(canvas){
    
}
ComLineMode::~ComLineMode(){
    
}
void ComLineMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"comline moved"<<std::endl;
}
void ComLineMode::mousePressEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"comline pressed"<<std::endl;
}
void ComLineMode::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
  QTransform transform;
  BasicBox* begin = dynamic_cast<BasicBox*>(canvas->itemAt(event->scenePos(), transform));
  BasicBox* end = dynamic_cast<BasicBox*>(canvas->itemAt(event->buttonDownScenePos(Qt::LeftButton), transform));
  if(begin && end){
    ComLine* line = new ComLine();
    line->setPorts(begin->getPort(event->scenePos()), end->getPort(event->buttonDownScenePos(Qt::LeftButton)));
    canvas->addItem(line);
  }
  std::cout<<"comline released"<<std::endl;
}
