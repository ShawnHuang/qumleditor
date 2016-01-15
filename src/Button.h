#ifndef BUTTON
#define BUTTON
#include<QToolButton>
class Canvas;
class Mode;
class Button : public QToolButton
{
  Q_OBJECT
public:
  Button (Canvas* canvas);
  virtual ~Button ();
public slots:
  void action();
protected:
  Mode* mode;
private:
  Canvas* canvas;
};

#endif
