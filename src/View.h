#ifndef VIEW_H
#define VIEW_H
#include <QMainWindow>
#include "UMLButton.h"
#include "CanvasScene.h"
#include "CanvasView.h"
class View : public QMainWindow 
{
  Q_OBJECT
public:
  View (QWidget *parent = 0);
  virtual ~View ();
public slots:
  void rename();
  void group();
  void ungroup();
private:
  CanvasScene *cscene;
  CanvasView *cview;
};
#endif // VIEW_H
/* vim: set ft=cpp.qt: */
