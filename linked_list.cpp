#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;

        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    // Create the list by adding a node at its end.
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Add a node after the first node containing target.
    bool insertAfter(int target, int value) {
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current == nullptr) return false;

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        return true;
    }

    // Delete the first node containing value.
    bool deleteNode(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) return false;

        if (previous == nullptr) {
            head = head->next;
        } else {
            previous->next = current->next;
        }
        delete current;
        return true;
    }

    void display() const {
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->data << " -> ";
        }
        std::cout << "nullptr\n";
    }

    void clear() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
};

int main() {
    LinkedList firstList;
    LinkedList secondList;

    firstList.append(10);
    firstList.append(20);
    firstList.append(30);
    firstList.insertAfter(20, 25); // 10 -> 20 -> 25 -> 30
    firstList.deleteNode(10);      // 20 -> 25 -> 30

    secondList.append(100);
    secondList.append(200);

    std::cout << "First list: ";
    firstList.display();
    std::cout << "Second list: ";
    secondList.display();
}
