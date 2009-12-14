#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KXmlGuiWindow>

#include "ui_mainwindow.h"

class MainWindow : public KXmlGuiWindow
{
   Q_OBJECT

public:
   MainWindow(QWidget *parent = 0);
   ~MainWindow();

private:
   Ui::MainWindow ui;

private slots:
   void generalInfo();
   void albumInfo();

};

#endif // MAINWINDOW_H
