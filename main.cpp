#include<iostream>

using namespace std;

template <typename T>
class MyList{
private:
    struct Node{
        T* value;
        Node* next;
        Node(T *_value){
            value = _value;
            next = nullptr;
        }
    };

    Node* f;
    Node* l;

    int length = 0;

public:

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

    int find(T v){
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

    Node* operator[](int index){
        int c = 0;
        Node* node = f;

        while(c != index and node != nullptr){
            node = node->next;
            c++;
        }

        if(node == nullptr)
            cout<<"Index out of range!";
        return node;
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

        if(index == 0){
            push_front(value);
            return;
        }

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
private:
    friend ostream& operator << (ostream &os, const MyList<T> &q){
        Node* node = q.f;
        while (node != nullptr) {
            os<<*node->value<<" ";
            node = node->next;
        }
        return os;
    }

    friend ostream& operator << (ostream &os, Node* node){
        return os << *node->value;
    }

    friend istream& operator >> (istream &in, MyList<T> &q){
        T value;
        in>>value;
        q.push_back(value);
        return in;

    }

};

int main()
{
    MyList<MyList<int>> a;

    MyList<int> b;
    MyList<int> c;
    MyList<int> d;
    MyList<int> e;

    int b1 = 3;
    int c1 = 4;
    int d1 = 5;
    int e1 = 6;

    b.push_back(&b1);
    c.push_back(&c1);
    c.push_back(&b1);
    c.push_back(&e1);
    c.push_back(&c1);
    c.push_back(&d1);
    d.push_back(&d1);
    e.push_back(&e1);

    a.push_back(&b);
    a.push_back(&c);
    a.push_back(&d);
    a.push_back(&e);

    a.pop_back();

    cout<<a.getLength()<<endl;

    a.delete_element(&b);

    cout<<a.getLength()<<endl;

    cout<<a[0];
    return 0;
}
