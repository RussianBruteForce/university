#include <iostream>

using namespace std;

int F(char *p)
{
    int n;
    if (*p == '\0') return 0; // если по указателю ето NULL возвращаем 0
    if (*p != ' ') n = 1; else n = 0; // если начинается с пробела то n = 1, иначе 0
    for (p++; *p!='\0'; p++) //идем дальше и вообще бежим по цепочке до конца
        if (p[0]!=' ' && p[-1]==' ') n++; // игнорируем лишние пробелы, но после каждой цепочки не пробеллов увеличиваем n
    return n;
}

int main()
{
    char str[] = "ol  erterg     dfgfdg   drd";
    cout << str  << " | Количество слов в строке: "<< F(str) << endl;
    return 0;
}

