#include <KApplication>
#include <KAboutData>
#include <KCmdLineArgs>
#include <KLocale>

#include "mainwindow.h"

int main (int argc, char *argv[])

{
   KAboutData aboutData("kiphone", 0,
                        ki18n("kiphone"), "0.1",
                        ki18n("A simple ipod and iphone manager"),
                        KAboutData::License_GPL_V3,
                        ki18n("Copyright (c) 2009"));

   aboutData.addAuthor(ki18n("Francesco Grieco"),
                       ki18n("Main Developer"),
                       "fgrieco@gmail.com");


   KCmdLineArgs::init( argc, argv, &aboutData );

   KApplication app;

   MainWindow* window = new MainWindow();

   window->show();

   return app.exec();
}
