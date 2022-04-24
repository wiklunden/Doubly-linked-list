/*
 * Milton Wiklund
 * 14-04-2022
 * Labb 2 - Dubbellänkad lista
 */

#ifndef LABB2_LINKED_LIST_H
#define LABB2_LINKED_LIST_H

#include <iostream>

class linked_list {
public:
    linked_list();
    linked_list(const linked_list& src);

    ~linked_list();

    linked_list& operator=(const linked_list& rhs);

    linked_list& operator+=(const linked_list& rhs);

    void insert(double value, size_t pos);
    void push_front(double value);
    void push_back(double value);

    double front() const;
    double back() const;
    double at(size_t pos) const;

    void remove(size_t pos);
    double pop_front();
    double pop_back();

    size_t size() const;
    bool is_empty() const;

    void print() const;
    void print_reverse() const;

private:
    struct node {
        node(double value);
        double value;
        node* prev;
        node* next;
    };
    node* head;
    node* tail;
};

#endif //LABB2_LINKED_LIST_H
