#include "Canvas.h"
#include "ClassBoxMode.h"
#include "Shape.h"
#include "BasicBox.h"
#include "ClassBox.h"
#include <iostream>

ClassBoxMode::ClassBoxMode(Canvas* canvas) : Mode(canvas){
    
}
ClassBoxMode::~ClassBoxMode(){
    
}
void ClassBoxMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"classbox moved"<<std::endl;
}
void ClassBoxMode::mousePressEvent(QGraphicsSceneMouseEvent * event){
  ClassBox *item = new ClassBox();
  item->setPos(event->scenePos());
  Mode::canvas->addItem(item);
  std::cout<<"classbox pressed"<<std::endl;
}
void ClassBoxMode::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"classbox released"<<std::endl;
}
