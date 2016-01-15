#include "Canvas.h"
#include "Shape.h"
#include "Line.h"
#include "AssLine.h"
#include "Port.h"
#include "BasicBox.h"
#include "UseCaseBox.h"
#include "AssLineMode.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

AssLineMode::AssLineMode(Canvas* canvas) : Mode(canvas){
    
}
AssLineMode::~AssLineMode(){
    
}
void AssLineMode::mousePressEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"assline pressed"<<std::endl;
}
void AssLineMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"assline moved"<<std::endl;
}
void AssLineMode::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
  QTransform transform;
  BasicBox* begin = dynamic_cast<BasicBox*>(canvas->itemAt(event->scenePos(), transform));
  BasicBox* end = dynamic_cast<BasicBox*>(canvas->itemAt(event->buttonDownScenePos(Qt::LeftButton), transform));
  if(begin && end){
    Line* line = new AssLine();
    line->setPorts(begin->getPort(event->scenePos()), end->getPort(event->buttonDownScenePos(Qt::LeftButton)));
    canvas->addItem(line);
  }
  std::cout<<"assline released"<<std::endl;
}
