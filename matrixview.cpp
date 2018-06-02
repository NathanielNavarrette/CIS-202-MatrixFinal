#include "matrixview.h"

MatrixView::MatrixView(QWidget *parent) : QWidget(parent)
{

}

MatrixView::MatrixView(Matrix displayThis, QWidget *parent) : QWidget(parent)
{
    m_data = displayThis;

    for(int i=0;i<m_data.get_rows();i++)
    {
        for(int j=0;j<m_data.get_cols();j++)
        {
            QWidget *value = new QLabel(QString::number( m_data.get_value_at(i, j)), horzWidget);
            colLayout->addWidget(value);
        }
        m_layout->addWidget(horzWidget);
    }

}
