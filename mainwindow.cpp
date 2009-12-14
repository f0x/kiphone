#include "mainwindow.h"
#include "xiphonereader.h"

extern "C"
{
#include <gpod/itdb.h>
}

#include <QXmlStreamReader>
#include <KProcess>

MainWindow::MainWindow(QWidget *parent) : KXmlGuiWindow(parent)
{
    ui.setupUi(this);

    connect(ui.infoButton, SIGNAL(clicked()), this, SLOT(generalInfo()));
    connect(ui.albumButton, SIGNAL(clicked()), this, SLOT(albumInfo()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::generalInfo()
{
    KProcess *process = new KProcess;
    process->setOutputChannelMode(KProcess::MergedChannels);
    QStringList options;
    options << "-x";
    process->setProgram("iphoneinfo", options);
    process->start();
    process->waitForFinished();

    QString output;
    output = process->readAllStandardOutput();

    ui.treeWidget->clear();

    XIPhoneReader reader(ui.treeWidget);


    //reader.read(output);
    if (!reader.read(output)) {

    }

    // ui.ktextedit->append(output);
}

void MainWindow::albumInfo()
{

}

#include "mainwindow.moc"
