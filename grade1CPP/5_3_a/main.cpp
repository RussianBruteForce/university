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

void delete_from(node *start, int n){
    int counter = 0;
    node *buf = start, *delete_from_this = NULL;

    while (buf) {
        if (counter++ == n-1) {
            delete_from_this = buf->next;
            buf->next = NULL;
            break;
        }
        buf = buf->next;
    }
    while (delete_from_this) {
        buf = delete_from_this;
        delete_from_this = delete_from_this->next;
        delete buf;
    }
}

int main()
{
    node* start = NULL;
    for (int i = 0; i < 8; i++) {
        node *buf = add();
        buf->next = start;
        start = buf;
    }
    print(start);
    cout << "Удалить с какого? >" << endl;
    int n;
    cin >> n;
    delete_from(start,n);
    print(start);
    return 0;
}

