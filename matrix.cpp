#include "matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(m_Matrix complete_set)
{
    m_data = complete_set;
    m_rows = complete_set.size();
    m_cols = complete_set.at(0).size();
}

Matrix::Matrix(std::vector<int> in_values, int rows, int cols)
{
    qDebug() << "Matrix Constructor called";
    m_rows = rows;
    m_cols = cols;
    std::vector<int> these_rows;
    std::vector<int> empty_vector;
    int thisSize = (rows*cols);

    for(int i=0;i<thisSize;i)
    {
        if(i != thisSize -1)
        {
            int secondLoopMax = i+cols;
            for(int j=i; j < secondLoopMax; j++)
            {
                these_rows.push_back(in_values.at(j));
                i=0;
                i+=(j+1);
            }
            m_data.push_back(these_rows);
            these_rows = empty_vector;
        }else{
            i++;
        }
    }
}

m_Matrix Matrix::get_matrix() const
{
    return m_data;
}

int Matrix::get_rows() const
{
    return m_rows;
}

int Matrix::get_cols() const
{
    return m_cols;
}

int Matrix::get_value_at(int this_row, int this_col)
{
    return m_data.at(this_row, this_col);
}

void Matrix::m_debug_this(QString s_name)
{
    qDebug() << s_name;
    qDebug() << "\nRows: " << m_rows;
    qDebug() << "Cols: " << m_cols;

    qDebug() << "\nValues in Matrix:";
    qDebug() << "m_data size: " << m_data.size();

    for(int i = 0; i < m_data.size(); i++)
    {
        qDebug() << "Size at " << i << " : " << m_data.at(i).size();
        for(int j = 0; j < m_data.at(i).size(); j++)
        {
            qDebug() << m_data.at(i).at(j);
        }
    }
}

bool check_if_possible(const Matrix &lhs, const Matrix &rhs, int operation_case)
{
    switch(operation_case){
    case 1:
        //addition case:
        if((lhs.get_cols() != rhs.get_cols()) || (lhs.get_rows() != rhs.get_rows()))
            return false;
        else
            return true;
        break;
    case 2:

        //subtraction case:
        if((lhs.get_cols() != rhs.get_cols()) || (lhs.get_rows() != rhs.get_rows()))
            return false;
        else
            return true;
        break;

    case 3:
        //multiplication
        if(lhs.get_cols() != rhs.get_rows())
            return false;
        else
            return true;
        break;
    }
    //if all else false:
    return false;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
    m_Matrix result;
    Matrix empty_result;

    if(check_if_possible(lhs, rhs, 1))
    {
        //only create and use this memory if its possible
        std::vector<int> values_tmp;
        std::vector<int> empty_vec;
        m_Matrix m_lhs = lhs.get_matrix();
        m_Matrix m_rhs = rhs.get_matrix();

        for(int i = 0; i < m_lhs.size(); i++)
        {
            for(int j = 0; j < m_lhs.at(i).size(); j++)
            {
                values_tmp.push_back( (m_lhs.at(i).at(j)) + (m_rhs.at(i).at(j)) );
                //qDebug() << m_lhs.at(i).at(j) << " + " << m_rhs.at(i).at(j);
            }
            result.push_back(values_tmp);
            values_tmp = empty_vec;
        }
        Matrix return_this(result);
        return return_this;
    }else{
        return empty_result;
    }
}

Matrix operator-(const Matrix &lhs, const Matrix &rhs)
{
    m_Matrix result;
    Matrix empty_result;

    if(check_if_possible(lhs, rhs, 2))
    {
        //only create and use this memory if its possible
        std::vector<int> values_tmp;
        std::vector<int> empty_vec;
        m_Matrix m_lhs = lhs.get_matrix();
        m_Matrix m_rhs = rhs.get_matrix();

        for(int i = 0; i < m_lhs.size(); i++)
        {
            for(int j = 0; j < m_lhs.at(i).size(); j++)
            {
                values_tmp.push_back( (m_lhs.at(i).at(j)) - (m_rhs.at(i).at(j)) );
                //qDebug() << m_lhs.at(i).at(j) << " - " << m_rhs.at(i).at(j);
            }
            result.push_back(values_tmp);
            values_tmp = empty_vec;
        }
        Matrix return_this(result);
        return return_this;
    }else{
        return empty_result;
    }
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs)
{
    Matrix empty_result;

    if(check_if_possible(lhs, rhs, 3))
    {
        std::vector<int> result_tmp;
        std::vector<int> add_row_tmp;
        std::vector<int> row_tmp;
        std::vector<int> empty_vec;
        m_Matrix m_value;
        m_Matrix m_lhs = lhs.get_matrix();
        m_Matrix m_rhs = rhs.get_matrix();

        for(int i=0; i < lhs.get_rows(); i++)
        {
            for(int j=0; j < rhs.get_cols(); j++)
            {
                for(int k = 0; k < lhs.get_cols(); k++)
                {
                    result_tmp.push_back( (m_lhs.at(i).at(k) * m_rhs.at(k).at(j) ) );
                    //qDebug() << "Value Pushed Back: " << (m_lhs.at(i).at(k) * m_rhs.at(k).at(j) );
                }
            }
        }

        //take the values that are in result_tmp and rearrange them into the proper matrix
        for(int i=0;i<result_tmp.size();i)
        {
            if(i != result_tmp.size()-1)
            {
                int add_tmp = 0;
                int secondLoopMax = i+lhs.get_cols();
                for(int j=i; j < secondLoopMax; j++)
                {
                    add_tmp += result_tmp.at(j);
                    i=(j+1);
                }
                add_row_tmp.push_back(add_tmp);
            }
        }

        for(int i=0;i<add_row_tmp.size();i)
        {
            if(i != (lhs.get_rows()*rhs.get_cols()) -1)
            {
                int secondLoopMax = i+rhs.get_cols();
                for(int j=i; j < secondLoopMax; j++)
                {
                    row_tmp.push_back(add_row_tmp.at(j));
                    i=0;
                    i+=(j+1);
                }
                m_value.push_back(row_tmp);
                row_tmp = empty_vec;
            }else{
                i++;
            }
        }
        //end the rearranging
        Matrix return_this(m_value);
        return return_this;
    }else{
        return empty_result;
    }
}
