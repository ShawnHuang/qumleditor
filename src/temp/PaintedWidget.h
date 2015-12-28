#include <QPainter>
#include <QWidget>
//!!! Qt4/Qt5
class PaintedWidget : public QWidget {
    Q_OBJECT
public:
    PaintedWidget(QWidget *parent = 0);
    void test();
protected:
    void paintEvent(QPaintEvent *);
private:
    QPainter painter;
};
/* vim: set ft=cpp.qt: */
