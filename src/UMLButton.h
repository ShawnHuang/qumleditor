#ifndef UMLBUTTON
#define UMLBUTTON
#include "CanvasScene.h"
#include <QToolButton>
#include <QEvent>
class UMLButton: public QToolButton
{
public:
  UMLButton (CanvasScene* scene, CanvasScene::Mode mode);
  virtual ~UMLButton ();
private:
  void mousePressEvent(QMouseEvent * e);
  CanvasScene *scene;
  CanvasScene::Mode mode;
};
#endif
/* vim: set ft=cpp.qt: */
