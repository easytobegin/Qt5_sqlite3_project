#include <QApplication>
#include "qtranslator.h"
//#include "mainform.h"
#include "managementform.h"
int main(int argc, char *argv[])
{
QApplication app(argc, argv);

QTranslator translator(0);
translator.load("qr_zh",".");
app.installTranslator(&translator);

//MainForm *dialog = new MainForm;
ManagementForm *dialog=new ManagementForm;
dialog->show();
return app.exec();

}
