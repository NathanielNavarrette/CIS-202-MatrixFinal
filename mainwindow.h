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
    QVBoxLayout *m_layout = new QVBoxLayout(this);
    QHBoxLayout *optionsLayout = new QHBoxLayout(optionsMenu);
    QWidget *addMatrix = new QPushButton("Add Matrix", optionsMenu);
    QWidget *clearScreen = new QPushButton("Clear Screen", optionsMenu);
    QWidget *editMatrix = new QPushButton("Edit Matrix", optionsMenu);


    QWidget *matrixView = new matrixWindow(this);
    QHBoxLayout *matrixLayout = new QHBoxLayout(matrixView);

public slots:
    void addMatrixSlot(bool pressed);

signals:
    void addingMatrix(bool);
};

#endif // MAINWINDOW_H
