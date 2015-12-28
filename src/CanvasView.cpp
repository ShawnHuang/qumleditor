#include "CanvasView.h"
#include "CanvasScene.h"
#include <QDebug>
CanvasView::CanvasView():rubberBand(NULL),rubber(false) {
}

CanvasView::~CanvasView(){
}
void CanvasView::setScene(CanvasScene *scene)
{
  this->cscene = scene;
  QGraphicsView::setScene(scene);
}
void CanvasView::mousePressEvent(QMouseEvent *e)
{
    origin = e->pos();
    if (this->cscene->mode == CanvasScene::Select)
    {
      //qDebug()<<this->scene()->items(mapToScene(origin));
      //this->setDragMode(QGraphicsView::RubberBandDrag);
      //if(this->scene()->items(mapToScene(origin)).empty())
      //{
      //  if (!rubberBand)
      //      rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
      //  this->rubber = true;
      //  rubberBand->setGeometry(QRect(origin, QSize()));
      //  rubberBand->show();
      //}
    }
    if (this->cscene->mode == CanvasScene::ClassDiagram)
    {
      //this->setDragMode(QGraphicsView::NoDrag);
    }
    //else{
    //  //this->setDragMode(QGraphicsView::ScrollHandDrag);
    //  this->setDragMode(QGraphicsView::RubberBandDrag);
    //}
    QGraphicsView::mousePressEvent(e);
}

void CanvasView::mouseMoveEvent(QMouseEvent *e)
{
    //if (rubberBand&&rubber)
    //  rubberBand->setGeometry(QRect(rubberBand->pos(), e->pos()).normalized());
    //else
    QGraphicsView::mouseMoveEvent(e);
}

void CanvasView::mouseReleaseEvent(QMouseEvent *e)
{
    //qDebug()<<rubberBand->rect();
    //qDebug()<<this->items(mapToScene(rubberBand->rect()));
    //if (rubberBand&&rubber)
    //{
    //  //this->setDragMode(QGraphicsView::NoDrag);
      qDebug()<<scene()->selectedItems();
    //  rubberBand->hide();
    //  delete rubberBand;
    //  rubberBand = NULL;
    //  rubber=false;
    //}
    QGraphicsView::mouseReleaseEvent(e);
}
/* vim: set ft=cpp.qt: */
