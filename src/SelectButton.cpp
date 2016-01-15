#include "Button.h"
#include "SelectButton.h"
#include "SelectMode.h"
#include "Canvas.h"
#include <iostream>

SelectButton::SelectButton(Canvas* canvas) : Button(canvas)
{
    this->mode = new SelectMode(canvas);
    this->setText("Select");
}

SelectButton::~SelectButton()
{
  std::cout<<"SelectButton delete"<<std::endl;
}
