#include "Button.h"
#include "ComLineButton.h"
#include "ComLineMode.h"
#include <iostream>

ComLineButton::ComLineButton(Canvas* canvas) : Button(canvas)
{
    this->mode = new ComLineMode(canvas);
    this->setText("Composite Line");
}

ComLineButton::~ComLineButton()
{
  std::cout<<"ComLineButton delete"<<std::endl;
}

