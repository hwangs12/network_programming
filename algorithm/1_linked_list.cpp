#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    void displayMembers()
    {
        node *t = this;
        while (t)
        {
            cout << t->data << endl;
            t = t->next;
        }
    }

    void push()
    {
    }

    void insert()
    {
    }

    void append()
    {
    }
};

int main()
{
    node *head = NULL;
    node *n1 = NULL;
    node *n2 = NULL;
    node *tail = NULL;

    head = new node();
    n1 = new node();
    n2 = new node();
    tail = new node();

    head->data = 1;
    head->next = n1;

    n1->data = 2;
    n1->next = n2;

    n2->data = 3;
    n2->next = tail;

    tail->data = 4;
    tail->next = NULL;

    head->displayMembers();

    return 0;
}