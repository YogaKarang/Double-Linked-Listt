#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertFirst(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void insertLast(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertNext(int key, int data){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key){
            Node* newNode = new Node;
            newNode->data = data;

            newNode->next = temp->next;
            newNode->prev = temp;

            if(temp->next != NULL){
                temp->next->prev = newNode;
            }

            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan\n";
}

void deleteFirst(){
    if(head == NULL){
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }

    delete temp;
}

void deleteLast(){
    if(head == NULL){
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;

    if(temp->next == NULL){
        head = NULL;
        delete temp;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void deleteData(int key){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key){

            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }else{
                head = temp->next;
            }

            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }

            delete temp;
            return;
        }

        temp = temp->next;
    }

    cout << "Data tidak ditemukan\n";
}

void display(){
    Node* temp = head;

    if(temp == NULL){
        cout << "List kosong\n";
        return;
    }

    cout << "Data: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    int pilihan, data, key;

    do{
        cout << "\nMENU DOUBLE LINKED LIST\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert Next\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete Data\n";
        cout << "7. Display\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan){

        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            insertFirst(data);
            break;

        case 2:
            cout << "Masukkan data: ";
            cin >> data;
            insertLast(data);
            break;

        case 3:
            cout << "Masukkan data setelah: ";
            cin >> key;
            cout << "Masukkan data baru: ";
            cin >> data;
            insertNext(key,data);
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            cout << "Masukkan data yang dihapus: ";
            cin >> key;
            deleteData(key);
            break;

        case 7:
            display();
            break;

        }

    }while(pilihan != 0);

}