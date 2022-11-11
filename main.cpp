#include <iostream>
#include <vector>
#include "BigReal.h"
//#include "BigReal.cpp"







//BigReal test(){
//    BigReal b;
//    return b;};

int main() {
    BigReal a("-2.99");
    BigReal b("-2.99");
    BigReal z ;
    z = a-b;
    cout << z;
    return 0;
}
