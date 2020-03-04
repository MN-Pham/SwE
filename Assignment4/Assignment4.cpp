#include<iostream>
#include"Dataframe.h"

int main()
{
    Dataframe Dummy;
    Dataframe Duplicate;
    Dummy.showAll(); //All elements should be 0
    Dummy.setData({29, 2, 25, 13, 0}, 5);
    Dummy.show(); //[19] [5] [29] [2] [25] [13] [0] [182]
    Duplicate.setDataframe(Dummy.getDataframe());
    Duplicate.showAll(); //Same content with Dummy
    if (Duplicate.checksumIsCorrect())
        std::cout<<"Checksum is correct"<<std::endl;
    else
        std::cout<<"Checksum is incorrect"<<std::endl;
    Dummy.clear();
    Dummy.showAll(); 
}
