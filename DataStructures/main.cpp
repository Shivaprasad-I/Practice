// main.cpp for testing
#include <iostream>
#include "linkedlist.hpp"  // Including the header file to use LinkedList
using namespace std;

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);

    list.printList();  // Expected: 5 -> 10 -> 20 -> nullptr

    list.deleteNode(10);
    list.printList();  // Expected: 5 -> 20 -> nullptr

    std::cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;  // Expected: Found

    return 0;
}
