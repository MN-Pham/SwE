#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

string str1 ("Embedded System: ");
string str2 ("Software Engineering");

vector<int> vect1 {4, 3, 7, 2};
vector<int> vect2 {4, 5, 6, 7};

list<double> list1 {1.0, 2.5, 3.5, 7.0};
list<double> list2 {1.0, 3.0, 4.0, 5.0};

vector<string> vdata1;
vector<string> vdata2{"start", "setspeed 2", "stop"};

int main()
{
    //***********a***********************************//
    // Using opearator += to add str2 to str1
    str1 += str2;
    cout<<"str1 + str2 = "<<str1<<endl;
    // Using insert() to change the content of str2
    str2.insert(0, "Embedded System ");
    cout<<"str2: "<<str2<<endl;
    // Compare two string
    if (str1.compare(str2) == 0)
        cout<<"str1 and str2 are the same!"<<endl;
    else
        cout<<"str1 and str2 are different!"<<endl;
    // Delete content of str1
    str1.clear();
    cout<<"Deleting str1."<<endl;
    cout<<"The size of str 1 is: "<<str1.size()<<" bytes."<<endl;
    // Copy a part of str2 to str1
    str1 = str2.substr(0, 15);
    cout<<"New str1: "<<str1<<endl;

    //***********b***********************************//
    cout<<"--------------------------------------"<<endl;
    cout<<"vect1: ";
    for (int i:vect1)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"vect2: ";
    for (int i:vect2)
        cout<<i<<" ";
    cout<<"\n";

    // Relational operators stop at the first mismatch
    if (vect1 == vect2)
        cout<<"vect1 = vect2."<<endl;
    else if (vect1 < vect2)
        cout<<"vect1 < vect2."<<endl;
    else
        cout<<"vect1 > vect2."<<endl;
    // Delete content of vect1
    cout<<"Deleting vect1."<<endl;
    vect1.clear();
    cout<<"Size of vect1: "<<vect1.size()<<endl;
    // Copy vect2 to vect1
    vect1 = vect2;
    // Add elements to vect1
    vect1.push_back(8);
    vect1.push_back(9);
    cout<<"New content of vect1: ";
    for (int i:vect1)
        cout<<i<<" ";
    cout<<"\n";

    //***********c***********************************//
    cout<<"--------------------------------------"<<endl;
    cout<<"list1: ";
    for (double j:list1)
        cout<<j<<" ";
    cout<<"\n";

    cout<<"list2: ";
    for (double j:list2)
        cout<<j<<" ";
    cout<<"\n";

    // Ralational operators stop at the first mismatch
    if (list1 == list2)
        cout<<"list1 = list2."<<endl;
    else if (list1 < list2)
        cout<<"list1 < list2."<<endl;
    else
        cout<<"list1 > list2."<<endl;
    // Delete content of list1
    cout<<"Deleting list1."<<endl;
    list1.clear();
    cout<<"Size of list1: "<<list1.size()<<endl;
    // Copy list2 to list1
    list1 = list2;
    // Add element to the end of list1
    list1.push_back(99.0);
    // Add element to the start of list1
    list1.push_front(22.0);
    cout<<"New content of list1: ";
    for (double j:list1)
        cout<<j<<" ";
    cout<<"\n";

    //***********d***********************************//
    cout<<"--------------------------------------"<<endl;
    vdata1 = vdata2;
    cout<<vdata1.size()<<endl;
    cout<<vdata1[1]<<endl;
    vdata1[0] += (" then " + vdata1[2]);
    cout<<vdata1[0]<<endl;
    vdata1.push_back("reset");
    cout<<"vdata1: ";
    for (string s:vdata1)
        cout<<"\""<<s<<"\""<<" ";
    cout<<"\n";

    return 0;
}