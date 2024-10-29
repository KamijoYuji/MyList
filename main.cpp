#include<iostream>
#include"MyList.h"

using namespace std;

int main()
{
    MyList<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    for(auto i = c.begin(); i!=c.end(); ++i){
        cout<<*i;
    }
    return 0;
}
