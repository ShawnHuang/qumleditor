#include "Button.h"
#include "UseCaseButton.h"
#include "UseCaseMode.h"
#include "Canvas.h"
#include <iostream>

UseCaseButton::UseCaseButton(Canvas* canvas) : Button(canvas)
{
    this->mode = new UseCaseMode(canvas);
    this->setText("Use Case");
}

UseCaseButton::~UseCaseButton()
{
  std::cout<<"UseCaseButton delete"<<std::endl;
}

