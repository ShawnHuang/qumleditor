#include "UMLButton.h"
#include <QEvent>
#include <QDebug>

UMLButton::UMLButton(CanvasScene *scene, CanvasScene::Mode mode)
{
    this->scene = scene;
    this->mode = mode;
    if(this->mode == CanvasScene::Select)
    {
      this->setText("Select");
      this->setCheckable(true);
    }
    if(this->mode == CanvasScene::AssoLine)
    {
      this->setText("Association Line");
      this->setCheckable(true);
    }
    if(this->mode == CanvasScene::GenLine)
    {
      this->setText("Generalization Line");
      this->setCheckable(true);
    }
    if(this->mode == CanvasScene::ComLine)
    {
      this->setText("Composition Line");
      this->setCheckable(true);
    }
    if(this->mode == CanvasScene::ClassDiagram)
    {
      this->setText("Class");
      this->setCheckable(true);
    }
    if(this->mode == CanvasScene::UseCaseDiagram)
    {
      this->setText("Use Case");
      this->setCheckable(true);
    }
}

UMLButton::~UMLButton()
{
    
}
void UMLButton::mousePressEvent(QMouseEvent * e)
{
    QToolButton::mousePressEvent(e);
    scene->setMode(mode);
}
/* vim: set ft=cpp.qt: */
