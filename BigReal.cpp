//
// Created by abdel on 10/31/2022.
//
#define new_line '\n'
#include "BigReal.h"

BigReal::BigReal(string BR )
{
    Total = new string{BR};

    if(!CheckReal())
    {
        cout << "this is invalid Real number"<<new_line;
    }
    else
    {

        if(BR[0] == '-')
        {
            delete R_sign;
            R_sign = new int {-1};
        }

        string intprt,frcprt;
        int i = 0;
        while(BR[i] != '.' && i != BR.size())
        {
            intprt += BR[i];
            i++;
        }
        i++;
        for (int j = i; j < BR.size(); ++j) {
            frcprt += BR[j];
        }
        fractional_part = new string{frcprt};

        integer_part = new string{intprt};


    }

}

BigReal::BigReal(double BR)
{
    string tmp = to_string(BR);
    Total = new string (tmp);
    if(tmp[0] == '-')
    {
        delete R_sign;
        R_sign = new int {-1};
    }

    string intprt,frcprt;
    int i = 0;
    while(tmp[i] != '.')
    {
        intprt += tmp[i];
        i++;
    }
    i++;
    for (int j = i; j < tmp.size(); ++j) {
        frcprt += tmp[j];
    }
    fractional_part = new string{frcprt};
    integer_part = new string{intprt};

}

bool BigReal::CheckReal()
{
    regex CH("[-+]?[0-9]+[.]?[0-9]+");
    return regex_match(*Total,CH);
}

BigReal::BigReal (BigDecimalInt& bigInteger)
{
    delete R_sign;
    R_sign = new int {bigInteger.sign()};
    integer_part = new string (bigInteger.getNumber());
    fractional_part = new string("0");
    Total = new string (bigInteger.getNumber() + '.' + *fractional_part);

};
BigReal::~BigReal()
{
    delete R_sign;
    delete fractional_part;
    delete integer_part;
    delete Total;
}
BigReal::BigReal(const BigReal &other)
{
    delete R_sign;
    R_sign = new int {*other.R_sign};
    integer_part = new string(*other.integer_part);
    fractional_part = new string (*other.fractional_part);
    Total = new string (*other.Total);

}

BigReal::BigReal(BigReal&& other)
{

    delete integer_part;
    delete fractional_part;
    delete Total;
    delete R_sign;

    integer_part = other.integer_part;
    fractional_part = other.fractional_part;
    Total = other.Total;
    R_sign = other.R_sign;

    other.Total = nullptr;
    other.fractional_part = nullptr;
    other.integer_part = nullptr;
    other.R_sign = nullptr;

};

BigReal& BigReal::operator=(BigReal &other)
        {
            integer_part = new string(*other.integer_part);
            fractional_part = new string (*other.fractional_part);
            Total = new string (*other.Total);
            delete R_sign;
            R_sign = new int (*other.R_sign);
            return *this;


        }

BigReal &BigReal::operator=(BigReal &&other)
        {

            delete R_sign;
            integer_part = other.integer_part;
            fractional_part = other.fractional_part;
            Total = other.Total;
            R_sign = other.R_sign;

            other.Total = nullptr;
            other.fractional_part = nullptr;
            other.integer_part = nullptr;
            return *this;
            cout<<"move assignment"<<new_line;
        }


bool BigReal::operator < (BigReal& anotherReal)
{

    BigDecimalInt F1(*integer_part);
    BigDecimalInt F2(*anotherReal.integer_part);
    if(F1 == F2)
    {

        int sign1 = sign() ;
        int sign2 = anotherReal.sign() ;

        deque<int> bdi1;
        deque<int> bdi2;

        for(char& ch : *fractional_part){
            if ( ch == '-' || ch == '+') continue;
            bdi1.push_back(ch - 48);
        }

        for(char& ch : *anotherReal.fractional_part){
            if ( ch == '-' || ch == '+') continue;
            bdi2.push_back(ch - 48);
        }

        int maxLen = max(bdi1.size(), bdi2.size());
        int minLen = min(bdi1.size(), bdi2.size()) ;

        for (int i = minLen; i < maxLen; ++i) {
            (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_back(0);
        }

        for (int i = 0; i < maxLen; ++i) {
            if ( bdi1[i] * sign1  < bdi2[i] * sign2) return true;
            else if ( bdi1[i] * sign1 > bdi2[i] * sign2) return false;

        }
        return false;
    }

    else if(F1 < F2){return true;}
    else{return false;}
}

bool BigReal::operator > (BigReal& anotherReal)
{

    BigDecimalInt F1(*integer_part);
    BigDecimalInt F2(*anotherReal.integer_part);
    if(F1 == F2)
    {

        int sign1 = sign() ;
        int sign2 = anotherReal.sign() ;


        deque<int> bdi1;
        deque<int> bdi2;

        for(char& ch : *fractional_part){
            if ( ch == '-' || ch == '+') continue;
            bdi1.push_back(ch - 48);
        }

        for(char& ch : *anotherReal.fractional_part){
            if ( ch == '-' || ch == '+') continue;
            bdi2.push_back(ch - 48);
        }

        int maxLen = max(bdi1.size(), bdi2.size());
        int minLen = min(bdi1.size(), bdi2.size()) ;

        for (int i = minLen; i < maxLen; ++i) {
            (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_back(0);
        }

        for (int i = 0; i < maxLen; ++i) {
            if ( bdi1[i] * sign1  > bdi2[i] * sign2) return true;
            else if ( bdi1[i] * sign1 < bdi2[i] * sign2) return false;

        }
        return false;
    }

    else if(F1 > F2){return true;}
    else{return false;}
}

bool BigReal::operator==(BigReal anotherReal)
{
    BigDecimalInt F1(*integer_part);
    BigDecimalInt F2(*anotherReal.integer_part);
    if(!(F1 == F2))
    {
        return false;
    }
    else
    {

        int sign1 = sign() ;
        int sign2 = anotherReal.sign() ;


        deque<int> bdi1;
        deque<int> bdi2;

        for(char& ch : *fractional_part){
            if ( ch == '-' || ch == '+') continue;
            bdi1.push_back(ch - 48);
        }

        for(char& ch : *anotherReal.fractional_part){
            if ( ch == '-' || ch == '+') continue;
            bdi2.push_back(ch - 48);
        }

        int maxLen = max(bdi1.size(), bdi2.size());
        int minLen = min(bdi1.size(), bdi2.size()) ;

        for (int i = minLen; i < maxLen; ++i) {
            (bdi1.size() > bdi2.size() ? bdi2 : bdi1).push_back(0);
        }

        for (int i = 0; i < maxLen; ++i) {
            if ( bdi1[i] * sign1  != bdi2[i] * sign2) return false;


        }
        return true;
    }
}

BigReal BigReal::operator+(BigReal &other)
{   BigReal Final;
    BigDecimalInt A(*this->integer_part) , B(*other.integer_part);
    delete Final.integer_part ;

    if((Total[0] == "-") && (other.Total[0] == "-"))
    {}
    if((Total[0] == "-") && (other.Total[0] == "+"))
    {}
    if((Total[0] == "+") && (other.Total[0] == "-"))
    {}
    if((Total[0] == "+") && (other.Total[0] == "+"))
    {
        Final.integer_part = new string{(A + B).getNumber()};
        return Final;
    }
}
int BigReal::sign()
{
    return *R_sign;
}

int BigReal::size()
{
    return Total->size()-1;
}

ostream& operator << (ostream& out, BigReal& b){
    out << *b.Total;
    return out ;
}
istream& operator >> (istream& out, BigReal& b){
    string tmp_str;
    out >> tmp_str;
    BigReal tmp_br(tmp_str);
    b = tmp_br;
    return out;
}

string BigReal::addition(string first, string second)
{   string total;
    int sum = 0;
    int maxlen = max(first.size(),second.size());
    int minlen = min(first.size(),second.size());
    for (int i = minlen; i < maxlen; ++i) {
        (first.size() > second.size() ? second : first)+='0';
    }
    for (int i = 0; i < maxlen; i++) {
        sum += ((first[first.size() - 1 - i] - '0') + (second[second.size() - 1 - i] - '0'));
        if(i == maxlen-1)
        {total += to_string(sum);
        }
        else{int carry = sum % 10;
            sum /= 10;
            total += to_string(carry);}

    }
    return total;
}