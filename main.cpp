#include<iostream>
#include"mylist.h"

using namespace std;

int main()
{
    MyList<int> c;
    c.push_back(1);
    c.push_back(2);
    int b = 123;
    c.insert(1,&b);
    int e = 321;
    int h = 44;
    c.push_front(e);
    c.push_front(&h);
    cout<<c<<"\n";
    c.delete_element(1);
    cout<<c<<"| "<<c.find(&h)<<" "<<c.find(2)<<"\n";
    cin>>c;
    cout<<c<<"\n";
    MyList<MyList<int>> a;
    a.push_back(&c);
    MyList<int> q;
    q.push_back(12);
    q.push_back(5);
    a.push_back(&q);
    cout<<a<<"\n";
    c.copy(q);
    cout<<a<<"\n";
    q[0] = 1;
    cout<<a<<"\n";
    MyList<MyList<int>> a1 = a;
    cout<<"\na1 = "<<a1<<"\n";
    a[0][1] = 888;
    cout<<"\na1 = "<<a1<<" "<<a[0][1];
    return 0;
}
