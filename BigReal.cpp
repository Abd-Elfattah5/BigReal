//
// Created by abdel on 10/31/2022.
//
#define new_line '\n'
#include "BigReal.h"

BigReal::BigReal(string BR):Total(BR)
{
    if(!CheckReal()){cout << "this is invalid Real number"<<new_line;}

}

bool BigReal::CheckReal()
{
    regex CH("[-+]?[0-9]+[.]?[0-9]+");
    return regex_match(Total,CH);
}
/*
BigReal::BigReal (BigDecimalInt& bigInteger)
{

    integer_part = bigInteger.getNumber();
    fractional_part = "0";
    Total = bigInteger.getNumber() + fractional_part;
    cout << Total;

};*/