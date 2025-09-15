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
    void push_front(int value);
    bool pop_front(int& value);
private:
    Node* head;
    int listSize;
};

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

List::List() : head(nullptr), listSize(0)
{

}

void List::push_front(int value)
{
    Node* new_head = new Node(value);
    new_head->next = head;
    head = new_head;
    listSize++;
}

bool List::pop_front(int& value)
{
    if (head != nullptr) {
        Node* popped = head;
        head = head->next;
        value = popped->value;
        delete popped;
        listSize--;
        return true;
    }

    return false;
}

int main()
{
    List list;

    for (int i = 0; i <= 5; i++)
    {
        list.push_front(i);
        std::cout << "pushed " << i << " size: " << list.size() << "\n";
    }
    std::cout << "\n";
    for (int i = 5; i > 0; i--)
    {

        list.pop_front(i);
        std::cout << "popped " << i << " size: " << list.size() << "\n";
    }


    return 0;
}