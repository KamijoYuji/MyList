#ifndef MYLIST_H
#define MYLIST_H
#include<iostream>

using namespace std;

template <typename T>
class MyList
{
    struct Node{
        T* value;
        T val;
        Node* next;
        Node(T* _value){
            value = _value;
            next = nullptr;
        }
        Node(T& _value){
            val = _value;
            next = nullptr;
            value = &val;
        }
    };

    Node* f;
    Node* l;
    int length = 0;

public:

    class Iterator{
        Node* node;
    public:
        Iterator(){
            node = nullptr;
        }

        Iterator(Node* _){
            node = _;
        }

        Iterator operator++(){
            if(node){
                node = node->next;
                return Iterator(node);
            }
            return *this;
        }

        bool operator ==(Iterator a){
            return node == a.node;
    }

        bool operator !=(Iterator a){
            return node != a.node;
    }

        T& operator *(){
            return *node->value;
        }

    };

    Iterator begin(){
        return Iterator(f);
    }

    Iterator end(){
        return Iterator(l->next);
    }


    MyList& operator = (const MyList& other){
        if(this != &other){
            f = other.f;
            l = other.l;
            length = other.length;
        }
        return *this;
    }

    int getLength(){
        return length;
    }

    MyList(){
        f = nullptr;
        l = nullptr;
    }

    void push_back(T* value){
        Node* new_node = new Node(value);

        if(f == nullptr){
            f = new_node;
            l = new_node;
        }
        else{
            l->next = new_node;
            l = new_node;
        }

        length++;
    }

    void push_back(T value){
        Node* new_node = new Node(value);

        if(f == nullptr){
            f = new_node;
            l = new_node;
        }
        else{
            l->next = new_node;
            l = new_node;
        }

        length++;
    }

    int find(T* v){
        if(f != nullptr){
            Node* node = f;
            int c = 0;

            while(node != nullptr){
                if(node->value == v)
                    return c;
                node = node->next;
                c++;
            }
        }
        cout<<"Nothing.\n";
        return -1;
    }


    int find(T v){
        if(f != nullptr){
            Node* node = f;
            int c = 0;

            while(node != nullptr){
                if(*node->value == v)
                    return c;
                node = node->next;
                c++;
            }
        }
        cout<<"Nothing.\n";
        return -1;
    }


    void delete_element(T* v){
        if(f == nullptr)
            return;

        if(f->value == v)
            pop_front();

        bool c = 0;
        Node* node = f;

        while(node != nullptr){
            if(node->next == nullptr){
                break;
            }
            if(node->next->value == v){
                c = 1;
                break;
            }
            node = node->next;
        }

        if(!c)
            return;

        if(node != nullptr){
            c = 1;
            Node* _node = node->next;
            node->next = node->next->next;
            delete _node;
        }

        length--;

        if(c)
            delete_element(v);
    }

    void delete_element(T v){
        if(f == nullptr)
            return;

        if(*f->value == v)
            pop_front();

        bool c = 0;
        Node* node = f;

        while(node != nullptr){
            if(node->next == nullptr){
                break;
            }
            if(*node->next->value == v){
                c = 1;
                break;
            }
            node = node->next;
        }

        if(!c)
            return;

        if(node != nullptr){
            c = 1;
            Node* _node = node->next;
            node->next = node->next->next;
            delete _node;
        }

        length--;

        if(c)
            delete_element(v);
    }

    void pop_front(){
        if(f == nullptr)
            return;
        Node* node = f;
        f = node->next;
        delete node;
        length--;
    }

    void pop_back(){
        if(f == nullptr)
            return;

        if(f == l)
            pop_front();

        else{
            Node* node = f;

            while(node->next != l)
                node = node->next;

            node->next = nullptr;
            delete l;
            l = node;
        }
        length--;
    }

    T& operator[](int index){
        int c = 0;
        Node* node = f;

        while(c != index and node != nullptr){
            node = node->next;
            c++;
        }

        if(node == nullptr)
            cout<<"Index out of range!";
        return *node->value;
    }

    void clear(){
        while(f != nullptr){
            pop_front();
        }
        length = 0;
    }

    void insert(int index, T value){
        if(index >= length or index < 0)
            return;


        if(index == length-1){
            push_back(value);
            return;
        }

        Node* new_node = new Node(value);
        Node* node = f;
        int c = 0;

        while (c < index) {
            node = f->next;
            c++;
        }

        Node* _node = node->next;
        new_node->next = _node;
        node->next = new_node;

        length++;
    }

    void insert(int index, T* value){
        if(index >= length or index < 0)
            return;

        if(index == length-1){
            push_back(value);
            return;
        }

        Node* new_node = new Node(value);
        Node* node = f;
        int c = 0;

        while (c < index) {
            node = f->next;
            c++;
        }

        Node* _node = node->next;
        new_node->next = _node;
        node->next = new_node;

        length++;
    }

    void push_front(T value){
        Node* new_node = new Node(value);
        new_node->next = f;
        f = new_node;

        length++;
    }

    void push_front(T* value){
        Node* new_node = new Node(value);
        new_node->next = f;
        f = new_node;

        length++;
    }

    void copy(MyList b){
        if(this == &b)
            return;
        clear();
        for(int i = 0; i < b.length; i++)
            push_back(b[i]);
    }

private:
    friend ostream& operator << (ostream &os, const MyList<T> &q){
        Node* node = q.f;
        while (node != nullptr) {
            os<<*node->value<<" ";
            node = node->next;
        }
        return os;
    }

    friend ostream& operator << (ostream &os, T* value){
        return os << *value;
    }

    friend istream& operator >> (istream &in, MyList<T> &q){
        T value;
        in>>value;
        q.push_back(value);
        return in;

    }
};

#endif // MYLIST_H
