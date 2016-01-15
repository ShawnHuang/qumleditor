#include "Button.h"
#include "AssLineButton.h"
#include "AssLineMode.h"
#include "Canvas.h"
#include <iostream>

AssLineButton::AssLineButton(Canvas *canvas) : Button(canvas)
{
    this->mode = new AssLineMode(canvas);
    this->setText("Association Line");
}

AssLineButton::~AssLineButton()
{
  std::cout<<"AssLineButton delete"<<std::endl;
}

