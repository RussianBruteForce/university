#include "matrix.h"

ostream &operator<<(ostream &out, const matrix &c)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            out << c.data[i][j] << '\t';
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, matrix &c)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            char buf[256];
            in >> buf;
            c.data[i][j] = atoi(buf);
        }
    return in;
}

matrix::matrix()
{
    data.resize(3);
    for (int i = 0; i < 3; i++)
        data[i].resize(3);
}

void matrix::setData(vector<vector<int> > &data)
{
    this->data = data;
}

matrix matrix::operator +(const matrix &m) const
{
    vector<vector<int> > buf;
    buf.resize(3);
    for (int i = 0; i < 3; i++)
        buf[i].resize(3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            buf[i][j] = data[i][j] + m.data[i][j];
    matrix ret;
    ret.setData(buf);
    return ret;
}

matrix matrix::operator *(const matrix &m) const
{
    vector<vector<int> > buf;
    buf.resize(3);
    for (int i = 0; i < 3; i++)
        buf[i].resize(3);

    for (int i = 0; i < 3; i++)
        for (int l = 0; l < 3; l++)
            for (int j = 0; j < 3; j++)
                buf[i][l] += data[i][j] * m.data[j][l];
    matrix ret;
    ret.setData(buf);
    return ret;
}
