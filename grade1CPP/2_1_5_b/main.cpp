#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<double> polynom;

unique_ptr<polynom> multiply_polynoms(polynom &a, polynom &b)
{
    unique_ptr<polynom> c(new polynom);
    c->resize(a.size() + b.size(), 0);
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++)
            (*c)[i+j] += a[i]*b[j];
    return c;
}

void read_file(const string &name, polynom &a, polynom &b)
{
    ifstream f(name, ios::in);
    if (!f) {
        cerr << "Can't open file " << name << '!' << endl;
        exit(0);
    }
    size_t k = 0, l = 0;
    int buf;

    f >> k >> l;

    for (size_t i = 0; i < k; i++)
        if (f >> buf)
            a.push_back(buf);
    if (k != a.size()){
        cerr << "Wrong file (fist polynom) " << name << '!' << endl;
        exit(1);
    }

    for (size_t i = 0; i < l; i++)
        if (f >> buf)
            b.push_back(buf);
    if (l != b.size()){
        cerr << "Wrong file (second polynom) " << name << '!' << endl;
        exit(2);
    }
    f.close();
    cout << "Readed " << a.size() << " and " << b.size() <<
            " coefficients from " << name << endl;
}

void print_polynom(polynom &p)
{
    cout << endl;
    for (const auto x : p)
        cout << "\t" << x;
    cout << endl;
}

int main()
{
    polynom a, b;
    read_file("w", a, b);
    auto c = multiply_polynoms(a, b);
    print_polynom(*c);
    return 0;
}

