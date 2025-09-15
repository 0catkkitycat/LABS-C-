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
    int  at(int index);
    void insert_at(int index, int value);
    void remove_at(int index);

private:
    Node* head;
    Node* tail;
    int listSize;

};

int List::at(int index)
{
    int i = 0;
    Node* n = head;
    while (i < index) {
        n = n->next;
        i++;
    }
    return n->value;
}

void List::insert_at(int index, int value)
{
    if (index == 0)
    {
        push_front(value);
    }
    else if (index == listSize)
    {
        push_back(value);
    }
    else
    {
        Node* n = new Node(value);

        Node* before = head;

        for (int i = 1; i < index; i++) {
            before = before->next;
        }
        n->next = before->next;
        before->next = n;
        if (n->next == nullptr)
        {
            tail = n;
        }
        listSize++;
    }
}

void List::remove_at(int index)
{
    if (index == 0)
    {
        int temp;
        pop_front(temp);
    }
    else if (index == listSize)
    {
        int temp;
        pop_back(temp);
    }
    else
    {
        Node* before = head;

        for (int i = 1; i < index; i++) {
            before = before->next;
        }

        Node* removed = before->next;
        before->next = removed->next;
        delete removed;
        listSize--;
    }
}


void printList(List& list)
{
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << "list[" << i << "] == " << list.at(i) << "\n";
    }
}


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

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    printList(list);
    std::cout << "\n";

    list.remove_at(2);
    printList(list);
    std::cout << "\n";

    list.insert_at(1, 6);
    printList(list);

    return 0;
}