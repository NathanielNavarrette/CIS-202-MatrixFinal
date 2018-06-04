#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    optionsLayout->addWidget(addMatrix);
    optionsLayout->stretch(1);
    optionsLayout->addWidget(operationButton);
    optionsLayout->stretch(1);
    optionsLayout->addWidget(clearScreen);
    optionsLayout->stretch(1);
    optionsMenu->setFixedHeight(50);

    /*
    operationLayout->addWidget(addingMats);
    operationLayout->stretch(1);
    operationLayout->addWidget(subbingMats);
    operationLayout->stretch(1);
    operationLayout->addWidget(multiMats);
    operationLayout->stretch(1);
    operationMenu->setFixedHeight(50);
*/

    m_layout->addWidget(optionsMenu);
    //m_layout->addWidget(operationMenu);
    m_layout->addWidget(matrixViewArea);

    ui->centralWidget->setLayout(m_layout);
    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);


    connect(addMatrix, SIGNAL(clicked(bool)), this, SLOT(addMatrixSlot(bool)));
    //connect(this, SIGNAL(operationButtonSent(std::vector<Matrix>)), operationMenu, SLOT(operationMenuSlot(std::vector<Matrix>)));
    connect(matrixViewArea, SIGNAL(addedMatrixSignal(Matrix)), this, SLOT(addedMatrixSlot(Matrix)));
    connect(clearScreen, SIGNAL(clicked(bool)), this, SLOT(tempSlotDebug(bool)));
    connect(operationButton, SIGNAL(clicked(bool)), this, SLOT(operationButtonSending(bool)));

    connect(matrixViewArea, SIGNAL(resultingMatrixSignal(Matrix, Matrix, Matrix, QString)) , this, SLOT(viesResultingMatrix(Matrix, Matrix, Matrix, QString)));
    connect(matrixViewArea, SIGNAL(sendMatrix(Matrix)), this, SLOT(finishedAddingMatrix(Matrix)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMatrixSlot(bool pressed)
{
    emit addingMatrix(pressed);
}

void MainWindow::addedMatrixSlot(Matrix viewThis)
{
    //new_matrix = new MatrixView(viewThis, matrixView);
    QWidget *add_this = new QLabel(MatrixView(viewThis, this).get_string());
    m_layout->addWidget(add_this);
}
void MainWindow::viesResultingMatrix(Matrix lhs, Matrix rhs, Matrix result, QString operation)
{
    //QWidget add_this = MatrixView(lhs, rhs, result, operation, this).get_label();
    QWidget *matrixView = new matrixWindow(matrixViewArea);
    QHBoxLayout *matrixLayout = new QHBoxLayout(matrixView);
    QWidget *l1 = new QLabel(MatrixView(lhs, this).get_string());
    QWidget *l2 = new QLabel(operation);
    QWidget *l3 = new QLabel(MatrixView(rhs, this).get_string());
    QWidget *l4 = new QLabel(QString("="));
    QWidget *l5 = new QLabel(MatrixView(result, this).get_string());

    matrixLayout->addWidget(l1);
    matrixLayout->addWidget(l2);
    matrixLayout->addWidget(l3);
    matrixLayout->addWidget(l4);
    matrixLayout->addWidget(l5);

    m_layout->addWidget(matrixView);
}

void MainWindow::finishedAddingMatrix(Matrix add_this)
{
    inputtedMatricies.push_back(add_this);
}

void MainWindow::operationButtonSending(bool)
{
    emit operationButtonSent(inputtedMatricies);
}

void MainWindow::tempSlotDebug(bool pressed)
{
    for(int i=0;i<inputtedMatricies.size();i++)
    {
        qDebug() << "Matrix : " << i+1;
        for(int j=0;j<inputtedMatricies.at(i).get_rows();j++)
        {
            for(int k=0;k<inputtedMatricies.at(i).get_cols();k++)
            {
                qDebug() << inputtedMatricies.at(i).get_value_at(j, k);
            }
        }
    }
}
