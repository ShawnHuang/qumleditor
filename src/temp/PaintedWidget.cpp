#include "PaintedWidget.h"
PaintedWidget::PaintedWidget(QWidget *parent):
  QWidget(parent)
{
  resize(800,600);
  setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
  painter.begin(this);
  this->test();
  //QPainterPath circlePath;
  //circlePath.addEllipse(QRect(0, 0, 100, 100));
  //if(circlePath.contains(QPoint(49,99))) 
  //  painter.setPen(Qt::red);
  //else
  //  painter.setPen(Qt::blue);
  ////painter.setBrush(Qt::blue);
  //painter.drawPath(circlePath);
}

void PaintedWidget::test(){
  painter.setViewport(0, 0, 200, 200);
  painter.fillRect(0, 0, 200, 200, Qt::red);
}

/* vim: set ft=cpp.qt: */
