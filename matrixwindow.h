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
    void addedMatrixSignal(Matrix viewThis);

public slots:
    void addingMatrix(bool clicked);
    void addMatrixAccept();





};

#endif // MATRIXWINDOW_H
