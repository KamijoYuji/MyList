#include<iostream>

using namespace std;

template <typename T>
class MyList{
private:
    struct Node{
        T* value;
        T val;
        Node* next;
        Node(T* _value){
            value = _value;
            next = nullptr;
        }
        Node(T _value){
            val = _value;
            next = nullptr;
            value = &val;
        }
    };

    Node* f;
    Node* l;

    int length = 0;

public:

    MyList& operator = (MyList other){
        f = other.f;
        l = other.l;
        length = other.length;
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
            }
            if(!c)node = node->next;

            if(node != nullptr and c){
                Node* _node = node->next;
                node->next = node->next->next;
                delete _node;
            }
            c = 0;
            length--;
        }
    }

    T pop_front(){
        if(f != nullptr){
            Node* node = f;
            f = node->next;
            T n = *node->value;
            delete node;
            length--;
            return n;
        }
    }

    T pop_back(){
        if(f != nullptr){
            if(f == l)
                pop_front();
            else{
                T n;
                Node* node = f;

                while(node->next != l)
                    node = node->next;

                node->next = nullptr;
                n = *l->value;
                delete l;
                l = node;
                return n;
            }
            length--;
        }
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

int main()
{
    MyList<int> c;
    c.push_back(2);
    c.push_back(1);
    c.push_back(2);
    c.push_back(2);
    c.push_back(3);
    c.push_back(2);
    c.push_back(5);
    c.delete_element(2);
    cout<<c;
    return 0;
}
