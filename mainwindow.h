#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLayout>

#include "matrixwindow.h"

enum SizeConstraint { SetDefaultConstraint, SetFixedSize, SetMinimumSize, SetMaximumSize, SetMinAndMaxSize, SetNoConstraint };


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget *optionsMenu = new QWidget(this);
    QWidget *operationMenu = new QWidget(this);
    QVBoxLayout *m_layout = new QVBoxLayout(this);
    QHBoxLayout *optionsLayout = new QHBoxLayout(optionsMenu);
    QHBoxLayout *operationLayout = new QHBoxLayout(operationMenu);
    QWidget *addMatrix = new QPushButton("Add a Matrix", optionsMenu);
    QWidget *clearScreen = new QPushButton("Clear Screen", optionsMenu);
    QWidget *editMatrix = new QPushButton("Edit Matrix", optionsMenu);

    QWidget *addingMats = new QPushButton("Add Two Matricies", operationMenu);
    QWidget *subbingMats = new QPushButton("Subtract Two Matricies", operationMenu);
    QWidget *multiMats = new QPushButton("Multiply Two Matricies", operationMenu);


    QWidget *matrixView = new matrixWindow(this);
    QHBoxLayout *matrixLayout = new QHBoxLayout(matrixView);

public slots:
    void addMatrixSlot(bool pressed);

signals:
    void addingMatrix(bool);
};

#endif // MAINWINDOW_H
