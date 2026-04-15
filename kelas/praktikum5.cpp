#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void addFirst(Node *&head, Node *&tail, int dataBaru) {
    Node *nodeBaru = new Node;

    nodeBaru->data = dataBaru;
    nodeBaru->next = head;

    head = nodeBaru;

    if (tail == nullptr) {
        tail = nodeBaru;
    }
}

void addLast(Node *&head, Node *&tail, int dataBaru) {
    Node *nodebaru = new Node;

    nodebaru->data = dataBaru;
    nodebaru->next = nullptr;

    if (tail != nullptr)
    {
        tail->next = nodebaru;
    }
    else
    {
        head = nodebaru;
    }
    tail = nodebaru;
}

void addSpesific(Node *&head, Node *&tail, int posisi, int dataBaru) {
    if (posisi < 1)
    {
        cout << "gada woe" << endl;
        return;
    }

    if (posisi == 1) {
        addFirst(head, tail, dataBaru);
        return;
    }

    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi -1)
    {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << "kelebihan wok" << endl;
    }
    else if (temp->next == nullptr) {
        addLast(head, tail, dataBaru);
    }
    else {
        Node *nodeBaru = new Node;
        nodeBaru->data = dataBaru;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void transversal(Node *head) {
    if (head == nullptr) {
        cout << "lah kok kosong" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr) 
    {
        cout << "data" << temp->data << endl;
        temp = temp->next;
    }
    cout << "nullptr"   << endl;

}

void deleteFirst(Node *&head, Node *&tail)
{
    if (head == nullptr) 
    {
        cout << "lah kok kosong" << endl;
        return;
    }

    Node *temp = head;
    head = temp->next;
    delete temp;

    if (head == nullptr) 
    {
        tail = nullptr;
    }
}

void deleteLast(Node *&head, Node *&tail) 
{
    if (head == nullptr) 
    {
        cout << "lah kok kosong" << endl;
        return;
    }

    if (head->next == nullptr) 
    {
        delete head;
        head == nullptr;
        tail == nullptr;
        cout << "kehapus wok" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr) 
    {
        temp = temp->next;
    }
    tail = temp;
    delete temp->next;
    tail->next = nullptr;
    cout << "kehapus wok" << endl;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    addFirst(head, tail, 20);
    addFirst(head, tail, 30);
    addFirst(head, tail, 40);
    addFirst(head, tail, 50);
    addSpesific(head, tail, 2, 99);
    addLast(head, tail, 67);
    deleteFirst(head, tail);
    transversal(head);

    return 0;
}