//
// Created by abdel on 10/31/2022.
//

#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H
#include "BigDecimalIntClass.h"


#include <bits/stdc++.h>
using namespace std;
class BigReal
{
private:

    string Total,fractional_part,integer_part;
    bool CheckReal();
public:

    BigReal (string BR="0.0"); // Default constructor
    BigReal (BigDecimalInt& bigInteger);
//    BigReal (const BigReal& other); // Copy constructor
//    BigReal (BigReal&& other); // Move constructor
//    BigReal& operator= (BigReal& other); // Assignment operator
//    BigReal& operator= (BigReal&& other); // Move assignment
//    BigReal operator+ (BigReal& other);
//    BigReal operator- (BigReal& other);
//    bool operator< (BigReal anotherReal);
//    bool operator> (BigReal anotherReal);
//    bool operator== (BigReal anotherReal);
//    int size();
//    int sign();
//    friend ostream& operator << (ostream& out, BigReal num);
//    friend istream& operator >> (istream& out, BigReal num);

};
#endif //BIGREAL_BIGREAL_H