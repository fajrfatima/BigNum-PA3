#ifndef BIGNUM_H
#define BIGNUM_H

//HEADER FILE - implement methods in BigNum.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class BigNum 
{
    protected:
        std::vector <char> numbers;
        bool negative;

        void nstring(const std:: string &str);
        void integer(int num);
        static int compareNum(const BigNum &a, const BigNum &b);
        void leadingZeros();

    public:
    // Constructors
    BigNum();
    BigNum(const string& numStr);
    BigNum(int num);

    // Assignment Operators
    BigNum& operator=(const BigNum& other);
    BigNum& operator=(int num);

    // Comparison Operators
    bool operator==(const BigNum& other) const;
    bool operator==(int other) const;
    friend bool operator==(int lhs, const BigNum& rhs);

    bool operator!=(const BigNum& other) const;
    bool operator!=(int other) const;
    friend bool operator!=(int lhs, const BigNum& rhs);

    // Arithmetic Operators
    BigNum operator+(const BigNum& other) const;
    BigNum operator-(const BigNum& other) const;
    BigNum operator*(const BigNum& other) const;

    // Special Operator
    BigNum operator/(const BigNum& other) const;

    // Unary Increment and Decrement Operators
    BigNum& operator++();    // Prefix
    BigNum operator++(int);  // Postfix
    BigNum& operator--();    // Prefix
    BigNum operator--(int);  // Postfix

    // Arithmetic/Assignment Operators
    BigNum& operator+=(const BigNum& other);
    BigNum& operator-=(const BigNum& other);
    BigNum& operator*=(const BigNum& other);

    // Stream I/O Operators
    friend ostream& operator<<(ostream& os, const BigNum& b);
    friend istream& operator>>(istream& is, BigNum& b);

    // Indexing Operator
    char& operator[](int index);
    const char& operator[](int index) const;

};

#endif 
