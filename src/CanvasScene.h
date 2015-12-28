#ifndef CANVASSCENE
#define CANVASSCENE
#include <QGraphicsScene>
#include <QRubberBand>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
class CanvasScene: public QGraphicsScene
{
  Q_OBJECT
public:
  enum Mode { Select, AssoLine, GenLine, ComLine, ClassDiagram, UseCaseDiagram};
  CanvasScene ();
  virtual ~CanvasScene ();
  void setMode(Mode mode);
  QGraphicsLineItem * line;
  Mode mode;
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
private:
};
#endif
