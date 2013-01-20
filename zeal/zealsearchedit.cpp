#include "zealsearchedit.h"
#include <QCoreApplication>
#include <QKeyEvent>
#include <QDebug>

ZealSearchEdit::ZealSearchEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void ZealSearchEdit::setTreeView(QTreeView *view)
{
    treeView = view;
    this->installEventFilter(this);
}

bool ZealSearchEdit::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == this && ev->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(ev);
        if(keyEvent->key() == Qt::Key_Down || keyEvent->key() == Qt::Key_Up ||
                keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            QCoreApplication::instance()->sendEvent(treeView, keyEvent);
            return true;
        }
    }
    return QLineEdit::eventFilter(obj, ev);
}