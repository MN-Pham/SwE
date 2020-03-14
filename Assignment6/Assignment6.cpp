#include <iostream>
#include "CartVec2D.h"

int main() {
    
    CartVec2D vect1;
    CartVec2D vect2(2.2, 3.3);
    CartVec2D vect3(vect2);
    CartVec2D vect4 = vect1;
    std::cout<<"Initial vectors:"<<std::endl;
    std::cout<<"\tvect1 = "<<vect1<<std::endl;
    std::cout<<"\tvect2 = "<<vect2<<std::endl;
    std::cout<<"\tvect3 = "<<vect3<<std::endl;
    std::cout<<"\tvect4 = "<<vect4<<std::endl;
    vect1 = vect2 + vect3;
    std::cout<<std::endl;
    std::cout<<"vect1  = vect2 + vect3 = "<<vect1<<std::endl;
    vect4 = 3.0 * vect2;
    std::cout<<"vect4  = 3.0 * vect2 = "<<vect4<<std::endl;
    std::cout<<"-vect4 = "<<-vect4<<std::endl;
    std::cout<<"vect1 - vect2   = "<<vect1 - vect2<<std::endl;
    std::cout<<"Length of vect2 = "<<vect2.length()<<std::endl;
    std::cout<<std::endl;
    return 0;
}