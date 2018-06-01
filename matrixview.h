#ifndef MATRIXVIEW_H
#define MATRIXVIEW_H

#include <QWidget>
#include <QLayout>
#include <QLabel>

#include "matrix.h"

class MatrixView : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixView(QWidget *parent = nullptr);
    MatrixView(QWidget *parent = nullptr, Matrix displayThis);


private:
    Matrix m_data;

    QWidget *displayWindow = new QWidget(this);
    QVBoxLayout *m_layout = new QVBoxLayout(this);

    QWidget *horzWidget = new QWidget(displayWindow);
    QHBoxLayout *colLayout = new QHBoxLayout(horzWidget);


signals:

public slots:

};

#endif // MATRIXVIEW_H
