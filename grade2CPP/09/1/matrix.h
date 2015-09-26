#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class matrix
{
    friend std::ostream &operator<< (std::ostream &out, const matrix &c);
    friend std::istream &operator>> (std::istream &in, matrix &c);

public:
    matrix();
    void setData(vector<vector<int> > &data);

    matrix operator +(const matrix& m) const;
    matrix operator *(const matrix& m) const;
private:
    vector<vector<int> > data;
};

#endif // MATRIX_H
