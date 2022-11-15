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
            R_sign = new int {-1};
        }
        else R_sign = new int {1};


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
        R_sign = new int {-1};
    }
    else R_sign = new int {1};

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
    R_sign = new int {*other.R_sign};
    integer_part = new string(*other.integer_part);
    fractional_part = new string (*other.fractional_part);
    Total = new string (*other.Total);

}

BigReal::BigReal(BigReal&& other)
{
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
            R_sign = new int (*other.R_sign);
            return *this;


        }

BigReal &BigReal::operator=(BigReal &&other)
        {


            integer_part = other.integer_part;
            fractional_part = other.fractional_part;
            Total = other.Total;
            R_sign = other.R_sign;

            other.Total = nullptr;
            other.fractional_part = nullptr;
            other.integer_part = nullptr;
            other.R_sign = nullptr;
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

BigReal BigReal::operator-(BigReal &other)
{

    BigReal Final;
    BigDecimalInt A(*this->integer_part) , B(*other.integer_part);
    string frc1 , frc2;
    frc1 = *this->fractional_part;
    frc2 = *other.fractional_part;
    delete Final.integer_part ;
    delete Final.fractional_part ;
    delete Final.Total;
    delete Final.R_sign;
//    if((this ->sign() == -1) && (other.sign() == -1))
//    {
//            if(*this > other)
//            {
//                Final = substraction(*this,other);
//               delete Final.R_sign;
//               Final.R_sign = new int{1};
//            }
//            else if(*this == other)
//            {
//                Final.Total = new string {"0.0"};
//                Final.fractional_part = new string {"0"};
//                Final.integer_part = new string {"0"};
//                Final.R_sign = new int{1};
//
//            }
//            else
//            {
//                Final = substraction(*this,other);
//                delete Final.R_sign;
//                Final.R_sign = new int{-1};
//            }
//
//    }
//    else if((this ->sign() == -1) && (other.sign() == 1))
//    {
//        Final = addition(*this,other);
//        delete Final.R_sign;
//        Final.R_sign = new int{-1};
//    }
//    else if((this ->sign() == 1) && (other.sign() == -1))
//    {
//        Final.integer_part = new string{(A-B).getNumber()};
//        Final.fractional_part = new string{(addition(frc1,frc2,Final))};
//        Final.Total = new string {(*Final.integer_part) +'.'+ (*Final.fractional_part)};
//        Final.R_sign = new int{1};
//    }
//    else if((this ->sign() == 1) && (other.sign() == 1))
//    {
//        if(*this > other)
//        {
//            Final = substraction(*this,other);
//            delete Final.R_sign;
//            Final.R_sign = new int{1};
//        }
//        else if(*this == other)
//        {
//            Final.Total = new string {"0.0"};
//            Final.fractional_part = new string {"0"};
//            Final.integer_part = new string {"0"};
//            Final.R_sign = new int{1};
//
//        }
//        else
//        {
//            Final = substraction(*this , other);
//            delete Final.R_sign;
//            Final.R_sign = new int{-1};
//        }
//    }
    Final = substraction(*this,other);
    if(*this > other && this->sign() == -1)
    {
      delete  Final.R_sign;
      Final.R_sign = new int {1};
    }
    else if(*this > other && this->sign() == 1)
    {
        delete  Final.R_sign;
        Final.R_sign = new int {1};
    }
    else
    {
        delete  Final.R_sign;
        Final.R_sign = new int {-1};
    }
    return Final;

}
BigReal BigReal::operator+(BigReal &other)
{
//
    BigReal Final;
    BigDecimalInt A(*this->integer_part) , B(*other.integer_part);
    string frc1 , frc2;
    frc1 = *this->fractional_part;
    frc2 = *other.fractional_part;
    delete Final.integer_part ;
    delete Final.fractional_part ;
    delete Final.Total;
    delete Final.R_sign;

//    if((this ->sign() == -1) && (other.sign() == -1))
//    {
//        Final = addition(*this,other);
//        delete Final.R_sign;
//        Final.R_sign = new int{-1};
//    }
//
//    else if((this ->sign() == -1) && (other.sign() == 1))
//    {
//        if(*this > other)
//        {
//            Final = substraction(*this,other);
//            delete Final.R_sign;
//            Final.R_sign = new int{1};
//        }
//        if(*this == other)
//        {
//            Final.Total = new string {"0.0"};
//            Final.fractional_part = new string {"0"};
//            Final.integer_part = new string {"0"};
//            Final.R_sign = new int{1};
//
//        }
//
//         {
//            Final = substraction(other , *this);
//            delete Final.R_sign;
//            Final.R_sign = new int{1};
//        }
//}
//    else if((this ->sign() == 1) && (other.sign() == -1))
//    {
//
//        if(*this > other)
//        {
//            Final = substraction(*this,other);
//            delete Final.R_sign;
//            Final.R_sign = new int{-1};
//        }
//       else  if(*this == other)
//        {
//            Final.Total = new string {"0.0"};
//            Final.fractional_part = new string {"0"};
//            Final.integer_part = new string {"0"};
//            Final.R_sign = new int{1};
//
//        }
//        else
//        {
//            Final = substraction(other , *this);
//            delete Final.R_sign;
//            Final.R_sign = new int{1};
//        }
//    }
//    else if((this ->sign() == 1) && (other.sign() == 1))
//    {
//
//        Final.integer_part = new string{(A+B).getNumber()};
//        Final.fractional_part = new string{(addition(frc1,frc2,Final))};
//        Final.Total = new string {(*Final.integer_part) +'.'+ (*Final.fractional_part)};
//        Final.R_sign = new int{1};
//
//
//    }
//    Final = addition(*this,other);
//
//
//    return Final;
    Final = addition(*this,other);
    if(*this > other && this->sign() == -1)
    {
        delete  Final.R_sign;
        Final.R_sign = new int {-1};
    }
    else if(*this < other && other.sign() == -1)
    {
        delete  Final.R_sign;
        Final.R_sign = new int {-1};
    }
    else
    {
        delete  Final.R_sign;
        Final.R_sign = new int {1};
    }
    return Final;
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
    if(b.sign() == -1){out <<'-'<<*b.Total;}
     else out <<*b.Total;
    return out ;
}

istream& operator >> (istream& out, BigReal& b){
    string tmp_str;
    out >> tmp_str;
    BigReal tmp_br(tmp_str);
    b = tmp_br;
    return out;
}

BigReal BigReal::addition(BigReal& first, BigReal& seccond)
{

//    string total;
//    int sum = 0;
//    int maxlen = max(first.size(),second.size());
//    int minlen = min(first.size(),second.size());
//    for (int i = minlen; i < maxlen; ++i) {
//        (first.size() > second.size() ? second : first)+='0';
//    }
//    for (int i = 0; i < maxlen; i++) {
//        sum += ((first[first.size() - 1 - i] - '0') + (second[second.size() - 1 - i] - '0'));
//        if(i == maxlen-1 && sum > 9)
//        {
//            int carry = sum % 10;
//            sum /= 10;
//            total += to_string(carry);
//            *f.integer_part = (BigDecimalInt{"1"} + BigDecimalInt(*f.integer_part)).getNumber();
//
//        }
//        else if(i == maxlen-1)
//        {total += to_string(sum);
//        }
//        else{int carry = sum % 10;
//            sum /= 10;
//            total += to_string(carry);}
//
//    }
//    std::reverse(total.begin(), total.end());
//    return total;

    BigReal total;
    string tmp_str = "";

    delete total.integer_part ;
    delete total.fractional_part ;
    delete total.Total;
    delete total.R_sign;
    int frc_max_len = max(first.fractional_part->size() , seccond.fractional_part->size() );
    int frc_min_len = min(first.fractional_part->size() , seccond.fractional_part->size() );
    for (int i = frc_min_len; i < frc_max_len; ++i) {
        (first.fractional_part->size() > seccond.fractional_part->size() ? *seccond.fractional_part : *first.fractional_part) +='0';
    }

    BigDecimalInt A( *first.integer_part + *first.fractional_part);
    BigDecimalInt B(*seccond.integer_part + *seccond.fractional_part);

    BigDecimalInt tmp((A+B).getNumber());
    for (int i = tmp.getNumber().size() - frc_max_len; i <= tmp.getNumber().size(); ++i) {
        tmp_str += tmp.getNumber()[i];
    }
    total.fractional_part = new string{tmp_str};
    tmp_str = "";

    for (int i = 0 ; i < tmp.getNumber().size() - frc_max_len; ++i) {
        tmp_str += tmp.getNumber()[i];
    }
    total.integer_part = new string {"0"+tmp_str};
    total.Total = new string {*total.integer_part + '.'+*total.fractional_part};
    total.R_sign = new int{tmp.sign()};
    return total;
}

BigReal BigReal::substraction(BigReal &first, BigReal& seccond)
{

    BigReal total;
    string tmp_str = "";

    delete total.integer_part ;
    delete total.fractional_part ;
    delete total.Total;
    delete total.R_sign;
    int frc_max_len = max(first.fractional_part->size() , seccond.fractional_part->size() );
    int frc_min_len = min(first.fractional_part->size() , seccond.fractional_part->size() );
    for (int i = frc_min_len; i < frc_max_len; ++i) {
        (first.fractional_part->size() > seccond.fractional_part->size() ? *seccond.fractional_part : *first.fractional_part) +='0';
    }

    BigDecimalInt A( *first.integer_part + *first.fractional_part);
    BigDecimalInt B(*seccond.integer_part + *seccond.fractional_part);

    BigDecimalInt tmp((A-B).getNumber());
    for (int i = tmp.getNumber().size() - frc_max_len; i <= tmp.getNumber().size(); ++i) {
        tmp_str += tmp.getNumber()[i];
    }

    total.fractional_part = new string{tmp_str};
    tmp_str = "";

    for (int i = 0 ; i < tmp.getNumber().size() - frc_max_len; ++i) {
        tmp_str += tmp.getNumber()[i];
    }
    total.integer_part = new string {"0"+tmp_str};
    total.Total = new string {*total.integer_part + '.'+*total.fractional_part};
    total.R_sign = new int{tmp.sign()};
    return total;
    
}