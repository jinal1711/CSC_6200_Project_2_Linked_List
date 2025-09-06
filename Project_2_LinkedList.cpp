#include <iostream>
using namespace std;

struct Node {
    int row;
    int col;
    int value;
    Node* next;
};


class SparseMatrix {
private:
    Node* head;

public:
    SparseMatrix() {
        head = nullptr;
    }

    // Function to insert a new non-zero element
    void insert(int r, int c, int val) {
        if (val == 0) return; 

        Node* newNode = new Node();
        newNode->row = r;
        newNode->col = c;
        newNode->value = val;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display sparse matrix in triplet form
    void display() {
        Node* temp = head;
        cout << "Row  Col  Value" << endl;
        while (temp) {
            cout << temp->row << "    " << temp->col << "    " << temp->value << endl;
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~SparseMatrix() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    int rows, cols, nonZero;
    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    SparseMatrix sm;

    cout << "Enter row, column and value for each non-zero element:\n";
    for (int i = 0; i < nonZero; i++) {
        int r, c, val;
        cin >> r >> c >> val;
        sm.insert(r, c, val);
    }

    cout << "\nSparse Matrix Representation (Linked List):\n";
    sm.display();

    return 0;
}
