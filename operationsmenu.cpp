#include "operationsmenu.h"

operationsMenu::operationsMenu(): QWidget(parent)
{
    connect(parent, SIGNAL(operationButton(bool)), this, SLOT(operationsMenuSlot(bool)));
    //connect(this, SIGNAL(matrixWindowSignal()), this, SLOT(addMatrixAccept()));
}

void operationsMenu::operationsMenuSlot()
{

}
