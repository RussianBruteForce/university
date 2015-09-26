#include <iostream>

using namespace std;

struct node {
    int item;
    node *next;
};

node *add()
{
    node *n = new node;
    n->next = NULL;
    cout << "\nЗначение:\n\t>";
    cin >> n->item;
    return n;
}

void print(node *start)
{
    node *buf = start;
    while (buf) {
        cout << buf->item << ' ';
        buf = buf->next;
    }
    cout << endl;
}

int find_max(node *start){
    int max = start->item;
    node *buf = start->next;
    while (buf) {
        if (max < buf->item)
            max = buf->item;
        buf = buf->next;
    }
    return max;
}

int main()
{
    node* start = NULL;
    cout << "Длина списка: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        node *buf = add();
        buf->next = start;
        start = buf;
    }
    print(start);
    cout << "MAX: " << find_max(start) << endl;

    return 0;
}

