#include <iostream>


class Node
{
public:
    Node(int val);
    Node();
    ~Node();
    int value;
    Node* next = nullptr;
};

Node::~Node()
{

}

Node::Node() { this->value = NULL; Node* next = nullptr; }


Node::Node(int val) : value(val), next(nullptr)
{

}

class List
{
public:
    List();
    ~List();
    int size();
    void push_back(int value);
    void push_front(int value);
    bool pop_front(int& value);
    bool pop_back(int& value);


private:
    Node* head;
    Node* tail;
    int listSize;
};




bool List::pop_back(int& value)
{
    if (head == nullptr) {
        return false;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    value = current->value;
    delete current;
    listSize--;

    if (previous != nullptr) {
        previous->next = nullptr;
        tail = previous;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }

    return true;
}

bool List::pop_front(int& value)
{
    if (head != nullptr) {
        Node* popped = head;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        value = popped->value;
        delete popped;
        listSize--;
        return true;
    }

    return false;
}

void List::push_front(int value)
{
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;

    if (tail == nullptr)
    {
        tail = head;
    }
    listSize++;
}

void List::push_back(int value)
{
    Node* new_tail = new Node(value);

    if (head == nullptr)
    {
        head = new_tail;
        tail = new_tail;
    }
    else {
        tail->next = new_tail;
        tail = new_tail;
    }
    listSize++;
}

int List::size()
{
    return listSize;
}


List::~List()
{
    while (head != nullptr) {
        Node* n = head;
        head = head->next;
        delete n;
    }
}

List::List() : head(nullptr), listSize(0), tail(nullptr)
{

}


int main()
{
    List list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    int value = 0;
    while (list.pop_back(value))
    {
        std::cout << value << "\n";
    }

    return 0;
}