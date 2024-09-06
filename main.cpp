#include<iostream>

using namespace std;

template <typename T>
class MyList{
private:
    struct Node{
        T value;
        Node* next;
        Node(T _value){
            value = _value;
            next = nullptr;
        }
    };

public:

    Node* f;
    Node* l;

    MyList(){
        f = nullptr;
        l = nullptr;
    }

    int length(){
        if(f==nullptr)
            return 0;
        Node* node = f;
        int c = 0;
        while(node!=nullptr){
            node = node->next;
            c++;
        }
        return c;
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
    }

    Node* find(T v){
        if(f!=nullptr){
            Node* node = f;
            while(node!=nullptr){
                if(node->value == v)
                    return node;
                node = node->next;
            }
        }
        return nullptr;
    }

    void pop_front(){
        if(f!=nullptr){
            f = f->next;
        }
    }

    void pop_back(){
        if(f!=nullptr){
            if(f==l)
                pop_front();
            else{
                Node* node = f;
                while(node->next!=l)
                    node = node->next;
                node->next = nullptr;
                l = node;
            }
        }
    }

    Node* operator[](int index){
        int c = 0;
        Node* node = f;
        while(c!=index and node!=nullptr){
            node = node->next;
            c++;
        }
        if(node==nullptr)
            cout<<"Index out of range!";
        return node;
    }

    void clear(){
        while(f!=nullptr)
            f = f->next;
    }

    void insert(int index, T value){
        if(index>=0 and index<length()){
            MyList<T> e;
            Node* node = f;
            int c = 0;
            while(c!=index){
                e.push_back(node->value);
                node = node->next;
                c++;
            }
            e.push_back(value);
            while(c<length()){
                e.push_back(node->value);
                node = node->next;
                c++;
            }
            clear();
            c = 0;
            while(c<e.length()){
                push_back(e[c]->value);
                c++;
            }
        }
        else{
            cout<<"Index out of range!";
        }
    }

    void push_front(T value){
        MyList<T> e;
        Node* node = f;
        int c = 0;
        e.push_back(value);
        while(c<length()){
            e.push_back(node->value);
            node = node->next;
            c++;
        }
        clear();
        c = 0;
        while(c<e.length()){
            push_back(e[c]->value);
            c++;
        }
    }
private:
    friend ostream& operator << (ostream &os, const MyList<T> &q){
        Node* node = q.f;
        while (node!=nullptr) {
            os<<node->value<<" ";
            node = node->next;
        }
        return os;
    }

    friend ostream& operator << (ostream &os, Node* node){
        return os << node->value;
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
    MyList<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    cout<<a;
    cout<<a[0]<<endl;
    MyList<int> e;
    cin>>e;
    cout<<e;

    return 0;
}
