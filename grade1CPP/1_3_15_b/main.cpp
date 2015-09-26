#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include "../in.h"

/*
 * Меня насильно заставили писать в эти лабы Си код, наверняка угрожали расправой.
 */

using namespace std;

void get_int(char *text, int *i)
{
    char str[31];
    int ch;
    do {
        printf("%s", text);
        scanf("%31[^\n]", &str);
        __fpurge(stdin);
	ch = sscanf(str, "%i %c", i, NULL);
    } while (ch != 1);
}

vector<int> read_file() {
    vector<int> ret;
    FILE *f = NULL;
    if ((f = fopen("a.txt","r")) == NULL)
        printf("Can't open a.txt!\n");
    while (true) {
        if (feof(f)) {
            ret.pop_back();
            break;
        } else {
            int buf = 0;
            fscanf(f, "%i", &buf);
            char str[31];
            fscanf(f, "%30[^ ]", str);
            __fpurge(stdin);
            sscanf(str, "%i ", &buf);
            if (buf != 0)
                ret.push_back(buf);
        }
    }
    fclose(f);
    return ret;
}

void print_m(unsigned m, vector<int> &x)
{
    auto str_l = x.size()/m;
    for (size_t i = 0; i < x.size(); i++){
        if (i%str_l == 0)
            printf("\n");
        printf("%i ", x.at(i));
    }
    printf("\n");
}

extern void get_size(char *text, size_t *i);

int main()
{
    auto x = read_file();
    int m;
    get_int((char*)"Enter m:\n\t>", &m);
    if (x.size() < m) // извините
        m = x.size();
    print_m(m, x);
    return 0;
}
