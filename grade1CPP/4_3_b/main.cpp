#include <iostream>

using namespace std;


struct data {
    int dd,mm,yy;
};
struct student {
    char name[20];
    data dd[3];
} M[2] = {{"Лаптев",{{1,10,1990},{8,8,1987},{3,2,1988}}},
          {"Романов",{{8,12,1999},{3,2,1986},{6,6,2005}}}};

void f()  {
    int i1, i2;
    i1 = M[0].dd[0].mm;
    i2 = M[1].dd[2].dd;
    cout << "месяц первой даты лаптева " << i1 << endl;
    cout << "день третьей даты романова " << i2 << endl;
}

int main()
{
    cout << M[0].name << ' '
                      << M[0].dd[0].mm <<'.'
                      << M[0].dd[0].dd <<'.'
                      << M[0].dd[0].yy <<' '
                                      << M[0].dd[1].mm <<'.'
                                      << M[0].dd[1].dd <<'.'
                                      << M[0].dd[1].yy <<' '
                                                      << M[0].dd[2].mm <<'.'
                                                      << M[0].dd[2].dd <<'.'
                                                      << M[0].dd[2].yy <<' ' << endl;
    cout << M[1].name << ' '
                      << M[1].dd[0].mm <<'.'
                      << M[1].dd[0].dd <<'.'
                      << M[1].dd[0].yy <<' '
                                      << M[1].dd[1].mm <<'.'
                                      << M[1].dd[1].dd <<'.'
                                      << M[1].dd[1].yy <<' '
                                                      << M[1].dd[2].mm <<'.'
                                                      << M[1].dd[2].dd <<'.'
                                                      << M[1].dd[2].yy <<' ' << endl;

    f();
    return 0;
}

