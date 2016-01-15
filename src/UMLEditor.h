#ifndef UMLEDITOR
#define UMLEDITOR
#include <QMainWindow>
#include <vector>
#include <QGridLayout>
class Canvas;
class View;
class QButtonGroup;
class Button;
class UMLEditor : public QMainWindow
{
  Q_OBJECT
public:
  UMLEditor (QWidget *parent = 0);
  virtual ~UMLEditor ();

private:
  Canvas* canvas;
  View* view;

  QButtonGroup* btnGroup;
  std::vector<Button*> buttons;

  QMenuBar *menubar;
  QMenu *file;
  QMenu *edit;
  QAction *exit;
  QAction *group;
  QAction *ungroup;
  QAction *named;

  QGridLayout *toolPanelLayout;
  QHBoxLayout *mainLayout;
  QWidget *toolPanel;
  QWidget *mainPanel;

  void layout();
};
#endif
/* vim: set ft=cpp.qt: */
