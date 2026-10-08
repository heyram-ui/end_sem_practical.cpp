#include <iostream>
#include <string>
using namespace std;
struct Patient {
    int tokenNo;
    string name;
};
class Queue {
private:
    struct Node {
        Patient data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int nextToken;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        nextToken = 1;
    }
    void addPatient(string name) {
        Node* newNode = new Node();
        newNode->data.tokenNo = nextToken++;
        newNode->data.name = name;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\n[Success] Token generated! Token No: " << newNode->data.tokenNo << " for " << name << "\n";
    }
    void callNextPatient() {
        if (isEmpty()) {
            cout << "\n[Notice] Queue is empty! No patients are currently waiting.\n";
            return;
        }

        Node* temp = front;
        cout << "\n[Calling] Now serving -> Token No: " << temp->data.tokenNo << " | Name: " << temp->data.name << "\n";

        front = front->next;

        // If front becomes null, rear must also be set to null
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }
    void displayWaitingPatients() {
        if (isEmpty()) {
            cout << "\n[Notice] Queue is empty! No patients waiting.\n";
            return;
        }


        cout << "WAITING PATIENTS";

        Node* temp = front;
        while (temp != nullptr) {
            cout << " Token No: " << temp->data.tokenNo << " --> " << temp->data.name << "\n";
            temp = temp->next;
        }

    }
    bool isEmpty() {
        return (front == nullptr);
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue hospitalQueue;
    int choice;
    string name;

    do {
        cout << "\nHospital Token Management System\n";
        cout << "1. Add Patient (Get Token)\n";
        cout << "2. Call Next Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> ws; // clear input buffer
                getline(cin, name);
                hospitalQueue.addPatient(name);
                break;
            case 2:
                hospitalQueue.callNextPatient();
                break;
            case 3:
                hospitalQueue.displayWaitingPatients();
                break;
            case 4:
                cout << "Exiting system. Have a nice day!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option (1-4).\n";
        }
    } while (choice != 4);

    return 0;
}
