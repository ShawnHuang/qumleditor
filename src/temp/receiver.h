#include <QObject>
#include <QDebug>
class Receiver : public QObject 
{
    Q_OBJECT
public:
    Receiver()
    {
    }

    // receiver
    void receive(const QString & name) {
         qDebug() << "Receive: " << name;
    }
};
/* vim: set ft=cpp.qt: */
