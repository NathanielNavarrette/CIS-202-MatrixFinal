#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    optionsLayout->addWidget(addMatrix);
    optionsLayout->stretch(1);
    optionsLayout->addWidget(editMatrix);
    optionsLayout->stretch(1);
    optionsLayout->addWidget(clearScreen);
    optionsLayout->stretch(1);
    optionsMenu->setFixedHeight(50);

    operationLayout->addWidget(addingMats);
    operationLayout->stretch(1);
    operationLayout->addWidget(subbingMats);
    operationLayout->stretch(1);
    operationLayout->addWidget(multiMats);
    operationLayout->stretch(1);
    operationMenu->setFixedHeight(50);

    m_layout->addWidget(optionsMenu);
    m_layout->addWidget(operationMenu);
    m_layout->addWidget(matrixView);

    ui->centralWidget->setLayout(m_layout);
    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);


    connect(addMatrix, SIGNAL(clicked(bool)), this, SLOT(addMatrixSlot(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMatrixSlot(bool pressed)
{
    emit addingMatrix(pressed);
}
