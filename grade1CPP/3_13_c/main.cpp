#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void read_file(string name, vector<string> &v)
{
    ifstream file(name,ios::in);
    if (!file) {
        cerr << "Can't open file " << name << '!' << endl;
        exit(0);
    }

    while (!file.eof()) {
        string buf;
        file >> buf;
        if (!buf.empty() && buf.find(buf[0],1) != string::npos)
            v.push_back(buf);
    }
    file.close();
}

void print (vector<string> &v)
{
    for (auto &x: v) {
        if (x.compare(v.back()) != 0)
            cout << x << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    cout << "Enter filename to open:\n\t>";
    cout.flush();
    string filename;
    cin >> filename;

    vector<string> line;
    read_file(filename, line);
    print(line);

    return 0;
}

