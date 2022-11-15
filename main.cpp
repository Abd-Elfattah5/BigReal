#include <iostream>
#include "BigReal.h"








//BigReal test(){
//    BigReal b;
//    return b;};

int main() {
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 - n2;
    cout << n3;
    return 0;
}
