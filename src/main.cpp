#include <QApplication>
#include "UMLEditor.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    UMLEditor editor;
    editor.show();
    return app.exec();
}

/* vim: set ft=cpp.qt : */
