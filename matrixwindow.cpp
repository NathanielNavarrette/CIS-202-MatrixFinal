#include "matrixwindow.h"

matrixWindow::matrixWindow(QWidget *parent) : QWidget(parent)
{
    connect(parent, SIGNAL(addingMatrix(bool)), this, SLOT(addingMatrix(bool)));
    connect(this, SIGNAL(matrixWindowSignal()), this, SLOT(addMatrixAccept()));
}

void matrixWindow::addMatrixAccept()
{
    addMatrixDialog();
}

void matrixWindow::addMatrixDialog()
{
    std::vector<int> c_tmp;
    qDebug() << "Rows:" << this->rows << " Columns: " << this->collums;
    //int totalValues = rows * collums;

    QDialog dialog(this);
    dialog.setMinimumHeight(225);
    dialog.setMinimumWidth(225);

    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Values in Matrix:"));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    QString label[collums];
    QLineEdit *lineEdit = NULL;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < collums; j++)
        {
            qDebug() << "Test -- R" << i << "C" << j;
            label[j] = QString("Row:").arg(i + 1);
            lineEdit = new QLineEdit(QString::number(j+i), &dialog);
            form.addRow("Row" + QString::number(i+1) + " ,Column" + QString::number(j+1), lineEdit);
            fields << lineEdit;
        }
        //form.addRow(label, lineEdit);
    }


    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    //QObject::connect(&buttonBox, SIGNAL(accepted()), parent())        //connect the accpted signal to previous dialog to close both windows at once

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        foreach(QLineEdit * lineEdit, fields)
        {
            c_tmp.push_back(lineEdit->text().toInt());
            //qDebug() << lineEdit->text().toInt();
        }
    }

    std::vector<int> row_tmp;
    std::vector<int> empty_vector;
    for(int i=0;i<c_tmp.size();i++)
    {

        if(i % rows != 0)
        {
            row_tmp.push_back(c_tmp.at(i));
        }else{
            m_data.push_back(row_tmp);
            row_tmp = empty_vector;
        }

        qDebug() << c_tmp.at(i);
    }
    qDebug() << "Output from the vector:";
    qDebug() << "m_data size: " << m_data.size();
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < collums; j++)
        {
           //qDebug() << m_data.at(i).at(j);
        }
        qDebug() << "Size at " << i << " : " << m_data.at(i).size();
    }
    /*
    if(fields.constFirst()->text().toInt() == 0 || fields.constLast()->text().toInt() == 0 )
    {
        QMessageBox::critical(this, tr("Invalid Data"), tr("You entered invalid data"));
    }else{
        this->m_objectHeight = fields.constFirst()->text().toInt();
        this->m_objectWidth = fields.constLast()->text().toInt();
    }
*/
}


void matrixWindow::addingMatrix(bool clicked)
{
    qDebug() << "Display box Image";
    int rows = 0;
    int collums = 0;
    int totalValues;

    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Size of Matrix:"));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;

    for(int i = 0; i < 2; ++i) {
        QLineEdit *lineEdit = NULL;
        QString label;
        if(i==0)
        {
            label = QString("Rows:").arg(i + 1);
            lineEdit = new QLineEdit(QString::number(1), &dialog);
        }else if(i == 1){
            label = QString("Collums:").arg(i + 1);
            lineEdit = new QLineEdit(QString::number(1), &dialog);
        }

        form.addRow(label, lineEdit);

        fields << lineEdit;
    }

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    qDebug() << "Before Connect";

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    qDebug() << "after Connect";

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted)
    {
        qDebug() << "into if dialog::accepted";
        // If the user didn't dismiss the dialog, do something with the fields
        foreach(QLineEdit * lineEdit, fields) {
            if(fields.constFirst()->text().toInt() == 0 || fields.constLast()->text().toInt() == 0 )
            {
                QMessageBox::critical(this, tr("Invalid Data"), tr("You entered invalid data"));
            }else{
                qDebug() << "Into else statement";
                this->rows = fields.constFirst()->text().toInt();
                this->collums = fields.constLast()->text().toInt();
            }
        }
        emit matrixWindowSignal();
    }


    //emit buttonBox.accepted();
}