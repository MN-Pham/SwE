#include<iostream>
#include<array>

using namespace std;

array<int, 3> ar{2, -2, 3};

int main()
{
    //---a--------------------------------------------//
    for (auto& el: ar)
    {
        cout<<el<<" ";
        el*=10;

        //el is a reference to an array element in ar
        //Hence, the value of all elements in ar will be
        //multiplied by 10 after being printed.
    }
    cout<<endl; //{20 -20 30}

    ar[0] = 10*ar[1];
    //Assign new value (10 times ar[1]) to ar[0].

    for (const auto el: ar)
    {
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}
