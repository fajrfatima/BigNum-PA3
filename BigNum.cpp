#include "BigNum.h"

//IMPLEMENT CLASS METHODS HERE

//CONSTRUCTOR CODE
BigNum :: BigNum() : negative(false){
    numbers.push_back('0');
}

BigNum :: BigNum(const std :: string& numStr){
    nstring(numStr);
}

BigNum :: BigNum(int num){
    integer(num);
}
//ASSIGNMENT CODE

BigNum& BigNum :: operator=(const BigNum& other) {
    negative = other.negative;
    numbers = other.numbers;
    return *this;
}

BigNum& BigNum :: operator=(int num){
    negative = (num < 0);
    numbers.clear();

    if(num < 0){
        num = -num;
    }
}

bool BigNum :: operator==(const BigNum& other) const {
    return negative == other.negative && numbers == other.numbers;
}

bool BigNum :: operator==(int other) const {
    return *this == BigNum(other);
}

bool operator==(int lhs, const BigNum& rhs) {
    return BigNum(lhs) == rhs;
}

bool BigNum :: operator!=(const BigNum& other) const {
    return !(*this == other);
}

bool BigNum :: operator!=(int other) const {
    return !(*this == other);
}

bool operator!=(int lhs, const BigNum& rhs) {
    return BigNum(lhs) != rhs;
}


//COMPARISON CODE
//comparison operator: == and !=
// bignum with a bignum
// bignum with an int
// int with a bignum

//MATHEMATICAL OPERATORS
// addition
// subtraction
// multiplication


//SPECIAL OPERATOR
// digit product operator

//POST & PREFIX OPERATORS
//postfix
//prefix

//COMPOUND ASSIGNMENT
// +=
// -=
// *=

//IOSTREAM CODE


//INDEXING CODE




//HELPER FUNCTION CODE

