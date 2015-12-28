#ifndef CANVASVIEW
#define CANVASVIEW
#include <QGraphicsView>
#include <QRubberBand>
#include <QMouseEvent>
class CanvasScene;
class CanvasView: public QGraphicsView
{
public:
  CanvasView ();
  virtual ~CanvasView ();
  void setScene(CanvasScene *scene);
private:
  CanvasScene *cscene;
  QRubberBand *rubberBand;
  bool rubber;
  QPoint origin;
  void mousePressEvent(QMouseEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);
};
#endif
