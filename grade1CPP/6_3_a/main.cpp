#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node
    *firstNode,
    *lastNode;

void add(int &data)
{
    node *buf = new node;
    buf->data = data;

    if (!firstNode) {
        firstNode = buf;
        lastNode = buf;
        buf->next = NULL;
        buf->prev = NULL;
    } else {
        buf->prev = lastNode;
        buf->next = NULL;
        lastNode->next = buf;
    }
    lastNode = buf;
}
void print()
{
    node *buf = firstNode;
    while (buf) {
        cout << buf->data << " ";
        buf = buf->next;
    }
    cout << endl;
}

void delete_from(int n) {
    int counter = 0;

    node *buf = firstNode, *del = NULL;
    while (buf) {
        if (counter++ == n) {
            del = buf;
            buf->prev->next = NULL;
            break;
        }
        buf = buf->next;
    }
    buf = del;
    while(buf) {
        del = buf;
        buf = buf->next;
        delete del;
    }
}

int main()
{
    for (int i = 0; i < 8; i++){
        cout << "Значение: ";
        int t;
        cin >> t;
        add(t);
        cout << '\n';
    }
    print();
    cout << "удалить с: ";
    int n;
    cin >> n;
    cout << '\n';
    delete_from(n);
    print();
    return 0;
}

