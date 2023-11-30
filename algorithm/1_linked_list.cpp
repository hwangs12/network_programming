#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    void displayMembers()
    {
        while (next)
        {
            cout << this->data << endl;
            this->next = (this->next)->next;
        }
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

    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}