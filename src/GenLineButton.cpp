#include "Button.h"
#include "GenLineButton.h"
#include "GenLineMode.h"
#include "Canvas.h"
#include <iostream>

GenLineButton::GenLineButton(Canvas* canvas) : Button(canvas)
{
    this->mode = new GenLineMode(canvas);
    this->setText("Generation Line");
}

GenLineButton::~GenLineButton()
{
  std::cout<<"GenLineButton delete"<<std::endl;
}

