#ifndef XIPHONEREADER_H
#define XIPHONEREADER_H

#include <QDomDocument>

class QTreeWidget;
class QTreeWidgetItem;

class XIPhoneReader
{
public:
     XIPhoneReader(QTreeWidget *treeWidget);

     bool read(QString &output);

 private:
     QDomDocument xml;
     QTreeWidget *treeWidget;

     void parseKeyElement(const QDomElement &element);

};

#endif // XIPHONEREADER_H
