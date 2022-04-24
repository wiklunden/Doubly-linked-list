/*
 * Milton Wiklund
 * 14-04-2022
 * Labb 2 - Dubbellänkad lista
 */

#include <iostream>
#include <cstdlib>

#include "linked_list.h"

void menu() {
    std::cout << "\n1. push_back\n";
    std::cout << "2. remove_biggest_element\n";
    std::cout << "3. copy_list\n";
    std::cout << "4. remove_every_other_element  +  print_list\n";
    std::cout << "5. merge\n";
    std::cout << "6. insert node\n";
    std::cout << "7. remove node\n";
    std::cout << "8. exit\n";
    std::cout << "> ";
}

void push_back(linked_list&, linked_list&);
void remove_biggest_element(linked_list&, linked_list&);
linked_list copy_list(linked_list&, linked_list&);
linked_list remove_every_other_element(linked_list&);
void print_list(linked_list l);
linked_list merge(linked_list&, linked_list&);
bool list_is_sorted(linked_list);
void insert_node(linked_list&);
void remove_node(linked_list&);

int main() {
    linked_list l, l1, l2, l3, l4, l5;
    size_t choice;

    while(true) {
        menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                push_back(l1, l2);
                break;
            case 2:
                remove_biggest_element(l1, l2);
                break;
            case 3:
                l3 = copy_list(l1, l2);
                std::cout << "\nList 3 in reverse (Size: " << l3.size() << "):\n";
                l3.print_reverse();
                break;
            case 4:
                if(l1.size() == 50) l4 = remove_every_other_element(l1);
                else if(l2.size() == 50) l4 = remove_every_other_element(l2);
                print_list(l4);
                break;
            case 5:
                l = merge(l1, l2);
                list_is_sorted(l);
                break;
            case 6:
                insert_node(l);
                break;
            case 7:
                remove_node(l);
                break;
            case 8:
                std::cout << "\nExiting...\n";
                return 0;
            default:
                break;
        }
    }
}

void push_back(linked_list& l1, linked_list& l2) {
    srand(time(nullptr));
    size_t node_limit = 50;
    for (size_t it = 0; it < node_limit; it++) {
        if (it == 0) {
            l1.push_back(0);
            l2.push_back(0);
        }
        else {
            l1.push_back(l1.back() + (rand() % 5));
            l2.push_back(l2.back() + (rand() % 5));
        }
    }

    std::cout << "List 1 and List 2 have been pushed back with 50 elements.\n";
    std::cout << "List 1: "; l1.print();
    std::cout << "List 2: "; l2.print();
}

void remove_biggest_element(linked_list& l1, linked_list& l2) {
    int index = 24;
    double l1_pos = l1.at(index);
    double l2_pos = l2.at(index);

    if (l1_pos > l2_pos) {
        l1.remove(index);
        std::cout << "\nElement was removed from List 1.\n";
        std::cout << "New size: " << l1.size() << "\n";
    }
    else if (l2_pos > l1_pos) {
        l2.remove(index);
        std::cout << "\nElement was removed from List 2.\n";
        std::cout << "New size: " << l2.size() << "\n";
    }
    else if (l2_pos == l1_pos) {
        int choice;
        std::cout << "\nBoth elements are equal.\n";
        std::cout << "From which list would you like to remove? (1/2): ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            l1.remove(index);
            std::cout << "\nElement was removed from List 1.\n";
            std::cout << "New size: " << l1.size() << "\n";
        }
        else if (choice == 2) {
            l2.remove(index);
            std::cout << "\nElement was removed from List 2.\n";
            std::cout << "New size: " << l2.size() << "\n";
        }
        else std::cout << "\nIncorrect input!\n";
    }
}

linked_list copy_list(linked_list& l1, linked_list& l2) {
    std::cout << "\nList was copied!\n";
    return l1.size() > l2.size() ? l2 : l1;
}

linked_list remove_every_other_element(linked_list& l) {
    for (int i = 0; i < 25; i++) {
        l.pop_back();
        l.push_front(l.pop_back());
    }
    std::cout << "\nEvery other element was removed!\n";

    return l;
}

void print_list(linked_list l) {
    std::cout << "Split list (Size: " << l.size() << "):\n";
    l.print();
}

linked_list merge(linked_list& l1, linked_list& l2) {
    linked_list l;

    while (!l1.is_empty()) {
        if (l1.front() < l2.front()) {
            l.push_back(l1.pop_front());
        }
        else if (l2.front() < l1.front()) {
            l.push_back(l2.pop_front());
        }
        else if (l1.front() == l2.front()) {
            l.push_back(l1.pop_front());
            l.push_back(l2.pop_front());
        }
        if (l1.is_empty() || l2.is_empty()) break;
    }

    if (l1.is_empty()) {
        while (!l2.is_empty()) {
            l.push_back(l2.pop_front());
            if (l2.is_empty()) break;
        }
    }
    else if (l2.is_empty()) {
        while (!l1.is_empty()) {
            l.push_back(l1.pop_front());
            if (l1.is_empty()) break;
        }
    }

    std::cout << "\nList successfully merged!\n";

    return l;
}

bool list_is_sorted(linked_list l) {
    bool is_sorted = true;

    std::cout << "\nList: ";
    l.print();

    double check_node = l.pop_front();

    while (!l.is_empty()) {
        if (l.is_empty()) break;

        if (check_node < l.front() || check_node == l.front()) {
            check_node = l.front();
            l.pop_front();
        }
        else {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) std::cout << "List is sorted!\n";
    else std::cout << "List is not sorted!\n";

    return is_sorted;
}

void insert_node(linked_list& l) {
    double value;
    size_t pos;

    std::cout << "Enter value: ";
    std::cin >> value;
    std::cin.ignore();

    std::cout << "Enter position: ";
    std::cin >> pos;
    std::cin.ignore();

    l.insert(value, pos);
    list_is_sorted(l);
}

void remove_node(linked_list& l) {
    size_t pos;

    std::cout << "Enter position: ";
    std::cin >> pos;
    std::cin.ignore();

    l.remove(pos);

    std::cout << "\nElement successfully removed from position " << pos << ".\n";
    list_is_sorted(l);
}