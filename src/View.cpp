#include "View.h"
#include <iostream>

View::View(QWidget *parent) : QGraphicsView(parent)
{
    
}

View::~View()
{
  std::cout<<"View delete"<<std::endl; 
}
