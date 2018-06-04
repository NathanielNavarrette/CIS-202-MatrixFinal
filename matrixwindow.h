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

//typedef std::vector<std::vector<int>> Matrix;

class matrixWindow : public QWidget
{
    Q_OBJECT
public:
    explicit matrixWindow(QWidget *parent = nullptr);

private:
    //Matrix m_data;
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





};

#endif // MATRIXWINDOW_H
