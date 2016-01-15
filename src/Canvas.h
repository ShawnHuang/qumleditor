#ifndef CANVAS
#define CANVAS
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class Mode;
class Canvas : public QGraphicsScene
{
  Q_OBJECT
public:
  Canvas ();
  virtual ~Canvas();
  void setMode(Mode* mode);
public slots:
  void group();
  void ungroup();
  void named();
  QGraphicsItem* itemAt(const QPointF & position, const QTransform & deviceTransform) const;
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
private:
  Mode* mode;  
};
#endif
