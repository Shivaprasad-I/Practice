// linkedlist.h
#ifndef LINKEDLIST_H  // Prevents multiple inclusions
#define LINKEDLIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();               // Constructor declaration
    ~LinkedList();              // Destructor declaration

    void insertAtHead(int value);  // Method to insert a value at the head
    void insertAtTail(int value);  // Method to insert a value at the tail
    void deleteNode(int value);    // Method to delete a node
    void printList();              // Method to print the list
    bool search(int value);        // Method to search for a value
};

#endif // LINKEDLIST_H
