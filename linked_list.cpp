#include "linked_list.h"

linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
}

linked_list &linked_list::operator=(const linked_list& rhs) {
    if (this != &rhs) {
        node* it = rhs.head;

        while (!is_empty()) pop_back();

        while (it != nullptr) {
            push_back(it->value);
            it = it->next;
        }
    }
    return *this;
}

linked_list &linked_list::operator+=(const linked_list& rhs) {
    node* it = rhs.head;

    while (it != nullptr) {
        push_back(it->value);
        it = it->next;
    }

    return *this;
}

linked_list::linked_list(const linked_list& src) {
    head = nullptr;
    tail = nullptr;

    *this = src;
}

linked_list::node::node(double value) {
    this->value = value;
    prev = nullptr;
    next = nullptr;
}

void linked_list::push_back(double value) {
    node* newNode = new node(value);
    if(is_empty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        newNode->next = nullptr;
    }
}

void linked_list::push_front(double value) {
    node* newNode = new node(value);
    if (is_empty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        newNode->prev = nullptr;
    }
}

void linked_list::print() const {
    node* it = head;
    while (it != nullptr) {
        std::cout << it->value << " ";
        it = it->next;
    }
    std::cout << "\n";
}

void linked_list::print_reverse() const {
    node* it = tail;
    while(it != nullptr) {
        std::cout << it->value << " ";
        it = it->prev;
    }
    std::cout << "\n";
}

bool linked_list::is_empty() const {
    if (head == nullptr && tail == nullptr) return true;

    return false;
}

size_t linked_list::size() const {
    node* it = head;
    size_t counter = 0;
    while (it != nullptr) {
        counter++;
        it = it->next;
    }
    return counter;
}

linked_list::~linked_list() {
    node* it = head;
    while(it != nullptr) {
        it = it->next;
        pop_front();
    }
}

double linked_list::at(size_t pos) const {
    node* it = head;
    for (size_t i = 0; i < pos; i++) it = it->next;

    return it->value;
}

double linked_list::front() const {
    double value = head->value;
    return value;
}

double linked_list::back() const {
    double value = tail->value;
    return value;
}

double linked_list::pop_back() {
    node* node = tail;

    double value = 0;

    if (size() == 1) {
        value = node->value;
        head = nullptr;
        tail = nullptr;
        delete node;
    }
    else if (size() > 1) {
        value = node->value;
        node->prev->next = nullptr;
        tail = node->prev;
        delete node;
    }

    return value;
}

double linked_list::pop_front() {
    node* node = head;

    double value = 0;

    if (size() == 1) {
        value = node->value;
        head = nullptr;
        tail = nullptr;
        delete node;
    }
    else if (size() > 1) {
        value = node->value;
        node->next->prev = nullptr;
        head = node->next;
        delete node;
    }

    return value;
}

void linked_list::remove(size_t pos) {
    node* it = head;
    for (size_t i = 0; i < pos; i++) it = it->next;

    if (it->prev == nullptr) pop_front();
    else if (it->next == nullptr) pop_back();
    else {
        it->prev->next = it->next;
        it->next->prev = it->prev;
        delete it;
    }

}

void linked_list::insert(double value, size_t pos) {
    node* it = head;
    node* newNode = new node(value);

    if (size() == 0) push_front(value);
    else if (pos == size() - 1) push_back(value);
    else {
        for (size_t i = 0; i < pos; i++) it = it->next;

        newNode->prev = it->prev;
        it->prev->next = newNode;
        it->prev = newNode;
        newNode->next = it;
    }
}
