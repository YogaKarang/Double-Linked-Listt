// #include <iostream>
// using namespace std;

// int main(){
//     int nilai[5] = {80,90,75,100,85};

//     for (int i = 0; i < 5; i++){
//         cout<<nilai[i]<<" ";
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// struct Node{
//     float value;
//     Node* next; 
// };

// int main(){
//     Node* head = NULL;
//     Node* node1 = new Node;
//     node1 -> value = 65;
//     node1 -> next = NULL;
//     head = node1;

//     Node* node2 = new Node;
//     node2 -> value = 75;
//     node2 -> next = NULL;
//     node1 -> next = node2;

//     Node* node3 = new Node;
//     node3 -> value = 95;
//     node3 -> next = NULL;
//     node2 -> next = node3;

//     Node* temp = head;

//     while (temp != NULL){
//         cout << temp->value << "->";
//         temp = temp->next;
//     }

// }


// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
// };
// void insertFirst(Node*& head, int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }
// int main(){
//     Node* head = NULL;
    
//     insertFirst(head, 50);
//     insertFirst(head, 70);

//     Node* temp = head; 

//     while (temp != NULL) {
//         cout << temp ->data;
//         if (temp-> !=)
//     }
// }

// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
// }; // <-- harus ada titik koma

// void insertFirst(Node*& head, int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }

// int main(){
//     Node* head = NULL; // awalnya kosong

//     // isi data
//     insertFirst(head, 50);
//     insertFirst(head, 70);

//     Node* temp = head;

//     while (temp != NULL) {
//         cout << temp->data;
//         if (temp->next != NULL) {
//             cout << " -> ";
//         }
//         temp = temp->next;
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };

// Node* head = NULL;

// void insertFirst(int data){
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->prev = NULL;
//     newNode->next = head;

//     if(head != NULL){
//         head->prev = newNode;
//     }

//     head = newNode;
// }

// void insertLast(int data){
//     Node* newNode = new Node();
//     Node* temp = head;

//     newNode->data = data;
//     newNode->next = NULL;

//     if(head == NULL){
//         newNode->prev = NULL;
//         head = newNode;
//         return;
//     }

//     while(temp->next != NULL){
//         temp = temp->next;
//     }

//     temp->next = newNode;
//     newNode->prev = temp;
// }

// void deleteFirst(){
//     if(head == NULL){
//         cout << "List kosong\n";
//         return;
//     }

//     Node* temp = head;
//     head = head->next;

//     if(head != NULL){
//         head->prev = NULL;
//     }

//     delete temp;
// }

// void display(){
//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main(){
//     insertFirst(10);
//     insertFirst(5);
//     insertLast(20);

//     display();

//     deleteFirst();

//     display();
// }


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