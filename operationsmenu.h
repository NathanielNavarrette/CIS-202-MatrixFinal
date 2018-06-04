#ifndef OPERATIONSMENU_H
#define OPERATIONSMENU_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QDebug>
#include <vector>

#include "matrixview.h"

class operationsMenu: public QWidget
{
    Q_OBJECT
public:
    explicit operationsMenu();

private:

public slots:
    void operationsMenuSlot();

signals:


};

#endif // OPERATIONSMENU_H
