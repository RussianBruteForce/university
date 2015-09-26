#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

vector<int> read_file(string name)
{
    vector<int> array;
    ifstream f;
    f.open(name);
    int buffer;
    for (int i = 0; i < 16; i++) {
        f >> buffer;
        array.push_back(buffer);
    }
    f.close();
    return array;
}

void print_4_x_4(vector<int> array)
{

}

int main()
{
    string filename;
    cout << "Enter file name:\n\t>";
    cin >> filename;
    vector<int> x = read_file(filename);
    print_4_x_4(x);
    return 0;
}
