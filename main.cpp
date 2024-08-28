#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class ForwardList {
    Node<T>* head;

public:
    ForwardList() {
        head = nullptr;
    }

    ~ForwardList(){
        Node<T>* temp = head;
        while(temp != nullptr){
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    T front(){
        if(head == nullptr){
            throw ("Lista vacía");
        }
        return head->data;
    }

    T back(){
        if(head == nullptr){
            throw ("Lista vacía");
        }
        Node<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T data){
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head == nullptr){
            head = newNode;
        } else {
            Node<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T pop_front(){
        if(head == nullptr){
            throw ("Lista vacía");
        }
        Node<T>* temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;
        return data;
    }

    T pop_back(){
        if(head == nullptr){
            throw ("Lista vacía");
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next;
        }
        T data = temp->data;
        if(prev == nullptr){
            head = nullptr;
        } else {
            prev->next = nullptr;
        }
        delete temp;
        return data;
    }

    bool insert(T data, int pos){
        if(pos < 0){
            throw ("Posición inválida");
        }
        Node<T>* newNode = new Node<T>(data);
        if(pos == 0){
            newNode->next = head;
            head = newNode;
            return true;
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        int i = 0;
        while(i < pos && temp != nullptr){
            prev = temp;
            temp = temp->next;
            i++;
        }
        if(i < pos){
            return false;
        }
        prev->next = newNode;
        newNode->next = temp;
        return true;
    }

    bool remove(int pos){
        if(pos < 0){
            throw ("Posición inválida");
        }
        if(head == nullptr){
            return false;
        }
        if(pos == 0){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        int i = 0;
        while(i < pos && temp != nullptr){
            prev = temp;
            temp = temp->next;
            i++;
        }
        if(i < pos || temp == nullptr){
            return false;
        }
        prev->next = temp->next;
        delete temp;
        return true;
    }

    T& operator[](int pos){
        if(pos < 0){
            throw ("Posición inválida");
        }
        Node<T>* temp = head;
        int i = 0;
        while(i < pos && temp != nullptr){
            temp = temp->next;
            i++;
        }
        if(i < pos || temp == nullptr){
            throw ("Posición inválida");
        }
        return temp->data;
    }

    bool is_empty(){
        return head == nullptr;
    }

    int size(){
        Node<T>* temp = head;
        int count = 0;
        while(temp != nullptr){
            temp = temp->next;
            count++;
        }
        return count;
    }

    void clear(){
        Node<T>* temp = head;
        while(temp != nullptr){
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    void sort(){
        if(head == nullptr){
            return;
        }
        Node<T>* temp = head;
        while(temp->next != nullptr){
            Node<T>* temp2 = temp->next;
            while(temp2 != nullptr){
                if(temp->data > temp2->data){
                    T aux = temp->data;
                    temp->data = temp2->data;
                    temp2->data = aux;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    bool is_sorted(){
        if(head == nullptr){
            return true;
        }
        Node<T>* temp = head;
        while(temp->next != nullptr){
            if(temp->data > temp->next->data){
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void reverse(){
        if(head == nullptr){
            return;
        }
        Node<T>* prev = nullptr;
        Node<T>* temp = head;
        Node<T>* next = nullptr;
        while(temp != nullptr){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }

    string name(){
        return "ForwardList";
    }
};

int main() {
    ForwardList<int> list;

    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    cout << "Lista: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Pop front: " << list.pop_front() << endl;
    cout << "Pop back: " << list.pop_back() << endl;

    list.insert(15, 1);

    cout << "Lista después de insertar: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    list.sort();
    cout << "Lista ordenada: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}
