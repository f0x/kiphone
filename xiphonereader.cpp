#include "xiphonereader.h"

#include <QTreeWidgetItem>

#include <KLocale>
#include <KDebug>

XIPhoneReader::XIPhoneReader(QTreeWidget *treeWidget) : treeWidget(treeWidget)
{
}

bool XIPhoneReader::read(QString &output)
{
    xml.setContent(output);
    QDomElement root = xml.documentElement();
    QDomElement child = root.firstChildElement("dict");
    QDomElement key = child.firstChildElement("key");

    while (!key.isNull()) {
        parseKeyElement(key);
        key = key.nextSiblingElement("key");
    }

    treeWidget->resizeColumnToContents(0);
    treeWidget->resizeColumnToContents(2);
    return true;
}


void XIPhoneReader::parseKeyElement(const QDomElement &element)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
    QDomNode value = element.nextSibling();
    QDomElement e = value.toElement();
    item->setData(0, Qt::DisplayRole, element.text());
    item->setData(1, Qt::DisplayRole, e.text().simplified());

    if (value.nodeName() == "true" || value.nodeName() == "false") {
        item->setData(1, Qt::DisplayRole, value.nodeName());
        item->setData(2, Qt::DisplayRole, i18n("boolean"));
    } else {
        item->setData(2, Qt::DisplayRole, value.nodeName());
    }

}

