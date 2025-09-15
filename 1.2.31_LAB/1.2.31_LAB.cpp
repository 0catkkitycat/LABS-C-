#include <iostream>

class Node {
public:
    Node(int val);
    int value;
    Node* next;
    Node* previous;
};

Node::Node(int val) : value(val), next(nullptr), previous(nullptr) {}

class List {
public:
    List();
    List(const List& other);
    ~List();
    int size();
    void push_back(int value);
    void push_front(int value);
    bool pop_front(int& value);
    bool pop_back(int& value);
    int at(int index);
    void insert_at(int index, int value);
    void remove_at(int index);

private:
    Node* head;
    Node* tail;
    int listSize;
};

List::List() : head(nullptr), tail(nullptr), listSize(0) {}

List::List(const List& other) : List() {
    Node* n = other.head;
    while (n != nullptr) {
        push_back(n->value);
        n = n->next;
    }
}

List::~List() {
    while (head != nullptr) {
        Node* n = head;
        head = head->next;
        delete n;
    }
}

int List::size() {
    return listSize;
}

void List::push_back(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->previous = tail;
        tail = new_node;
    }
    listSize++;
}

void List::push_front(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else {
        head->previous = new_node;
        new_node->next = head;
        head = new_node;
    }
    listSize++;
}

bool List::pop_front(int& value) {
    if (head == nullptr) {
        return false;
    }
    Node* removed = head;
    value = removed->value;
    head = head->next;
    if (head != nullptr) {
        head->previous = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete removed;
    listSize--;
    return true;
}

bool List::pop_back(int& value) {
    if (tail == nullptr) {
        return false;
    }
    Node* removed = tail;
    value = removed->value;
    tail = tail->previous;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete removed;
    listSize--;
    return true;
}

int List::at(int index) {
    if (index >= listSize || index < 0) {
        std::cout << "Index out of bounds.\n";
        return -1;
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->value;
}

void List::insert_at(int index, int value) {
    if (index < 0 || index > listSize) {
        std::cout << "Index out of bounds.\n";
        return;
    }
    if (index == 0) {
        push_front(value);
    }
    else if (index == listSize) {
        push_back(value);
    }
    else {
        Node* new_node = new Node(value);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next->previous = new_node;
        new_node->previous = current;
        current->next = new_node;
        listSize++;
    }
}

void List::remove_at(int index) {
    if (index < 0 || index >= listSize) {
        std::cout << "Index out of bounds.\n";
        return;
    }
    if (index == 0) {
        int temp;
        pop_front(temp);
    }
    else if (index == listSize - 1) {
        int temp;
        pop_back(temp);
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        listSize--;
    }
}

void printList(List& list) {
    for (int i = 0; i < list.size(); i++) {
        std::cout << "list[" << i << "] == " << list.at(i) << "\n";
    }
}

int main() {
    List list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    std::cout << "list1" << "\n";
    printList(list1);
    std::cout << "\n";

    List list2(list1);
    std::cout << "list2 (copy of list1)" << "\n";
    printList(list2);
    std::cout << "\n";

    list1.insert_at(1, 6);
    list2.remove_at(2);

    std::cout << "list1 (after insertion)" << "\n";
    printList(list1);
    std::cout << "\n";
    std::cout << "list2 (after removal)" << "\n";
    printList(list2);
    std::cout << "\n";

    return 0;
}