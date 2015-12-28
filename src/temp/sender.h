#include <QObject>
#include <QDebug>
class Sender : public QObject 
{
    Q_OBJECT
public:
    Sender(const QString & name) : obj_name(name)
    {
    }

    // sender
    void action() {
        emit send(obj_name);
    }

signals:
    void send(const QString &name);

private:
    QString obj_name;
};
/* vim: set ft=cpp.qt: */
