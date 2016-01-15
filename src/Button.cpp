#include "Button.h"
#include "Canvas.h"
#include <iostream>
#include <QObject>

Button::Button(Canvas *canvas)
{
    this->canvas = canvas;
    this->setCheckable(true);
    this->connect(this, SIGNAL(pressed()), this, SLOT(action()));
}

Button::~Button()
{
  std::cout<<"Button delete"<<std::endl;
}

void Button::action()
{
  if (!this->isChecked())
  {
    this->setChecked(true);
    this->canvas->setMode(this->mode); 
    std::cout<<"Mouse clicked!"<<std::endl;
  }
}

/* vim: set ft=cpp.qt: */
