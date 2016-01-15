#include "Mode.h"
class ClassBoxMode : public Mode
{
public:
  ClassBoxMode (Canvas* canvas);
  virtual ~ClassBoxMode ();
protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
  void mousePressEvent(QGraphicsSceneMouseEvent * event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
  
};
