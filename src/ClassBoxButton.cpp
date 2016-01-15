#include "Button.h"
#include "ClassBoxButton.h"
#include "ClassBoxMode.h"
#include "Canvas.h"
#include <iostream>

ClassBoxButton::ClassBoxButton(Canvas* canvas) : Button(canvas)
{
    this->mode = new ClassBoxMode(canvas);
    this->setText("Class");
}

ClassBoxButton::~ClassBoxButton()
{
  std::cout<<"ClassBoxButton delete"<<std::endl;
}

