#include "Canvas.h"
#include "UseCaseMode.h"
#include "Shape.h"
#include "BasicBox.h"
#include "UseCaseBox.h"
#include <iostream>

UseCaseMode::UseCaseMode(Canvas* canvas) : Mode(canvas){
    
}
UseCaseMode::~UseCaseMode(){
    
}
void UseCaseMode::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"usecase moved"<<std::endl;
}
void UseCaseMode::mousePressEvent(QGraphicsSceneMouseEvent * event){
  UseCaseBox *item = new UseCaseBox();
  item->setPos(event->scenePos());
  Mode::canvas->addItem(item);
  std::cout<<"usecase pressed"<<std::endl;
}
void UseCaseMode::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
  std::cout<<"usecase released"<<std::endl;
}
