#ifndef MATRIXWINDOW_H
#define MATRIXWINDOW_H

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

#include "matrix.h"
#include "matrixview.h"

class matrixWindow : public QWidget
{
    Q_OBJECT
public:
    explicit matrixWindow(QWidget *parent = nullptr);

private:
    void addMatrixDialog();

    int rows = 1;
    int collums = 1;

signals:
    void matrixWindowSignal();
    void sendMatrix(Matrix add_this);
    void addedMatrixSignal(Matrix viewThis);
    void resultingMatrixSignal(Matrix lhs, Matrix rhs, Matrix result, QString operation);

public slots:
    void addingMatrix(bool clicked);
    void addMatrixAccept();
    void doOpers(std::vector<Matrix> recieved_list);

};

#endif // MATRIXWINDOW_H
