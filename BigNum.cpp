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
    integer(num);
    return *this;   
}

//COMPARISON CODE
//comparison operator: == and !=
// bignum with a bignum
// bignum with an int
// int with a bignum

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

//MATHEMATICAL OPERATORS
// addition
// subtraction
// multiplication


//SPECIAL OPERATOR
// digit product operator

//POST & PREFIX OPERATORS
//postfix
BigNum BigNum::operator++(int) {
    BigNum temp = *this;
    ++(*this);
    return temp;
}

BigNum BigNum::operator--(int) {
    BigNum temp = *this;
    --(*this);
    return temp;
}

//prefix
BigNum& BigNum::operator++() {
    *this = *this + BigNum(1);
    return *this;
}

BigNum& BigNum::operator--() {
    *this = *this - BigNum(1);
    return *this;
}

//COMPOUND ASSIGNMENT
// +=
BigNum& BigNum::operator+=(const BigNum& other) {
    *this = *this + other;
    return *this;
}

// -=
BigNum& BigNum::operator-=(const BigNum& other) {
    *this = *this - other;
    return *this;
}

// *=
BigNum& BigNum::operator*=(const BigNum& other) {
    *this = *this * other;
    return *this;
}

//IOSTREAM CODE
std::ostream& operator<<(std::ostream& os, const BigNum& num) {
    if (num.negative) os << '-';
    for (int i = num.numbers.size() - 1; i >= 0; --i) {
        os << num.numbers[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, BigNum& num) {
    std::string str;
    is >> str;
    num.nstring(str);
    return is;
}

//INDEXING CODE
char& BigNum::operator[](int index) {
    static char nullChar = '\0';
    if (index < 0 || index >= static_cast<int>(numbers.size())) {
        return nullChar;
    }
    return numbers[numbers.size() - 1 - index];
}

const char& BigNum::operator[](int index) const {
    static const char nullChar = '\0';
    if (index < 0 || index >= static_cast<int>(numbers.size())) {
        return nullChar;
    }
    return numbers[numbers.size() - 1 - index];
}


//HELPER FUNCTION CODE
void BigNum::integer(int num) {
    numbers.clear();
    if (num < 0) {
        negative = true;
        num = -num;
    } else {
        negative = false;
    }

    do {
        numbers.push_back('0' + (num % 10));
        num /= 10;
    } while (num > 0);
}

int BigNum::compareNum(const BigNum& a, const BigNum& b) {
    if (a.numbers.size() != b.numbers.size()) {
       if(a.numbers.size() < b.numbers.size()){
            return -1;
       }
       else{
        return 1;
       }
    }
    
    for (int i = a.numbers.size() - 1; i >= 0; --i) {
        if (a.numbers[i] != b.numbers[i]) {
            if(a.numbers[i] < b.numbers[i]){ 
                return -1;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

void BigNum::leadingZeros() {
    while (numbers.size() > 1 && numbers.back() == '0') {
        numbers.pop_back();
    }
}

// Helper function to convert string to BigNum
void BigNum::nstring(const std::string& str) {
    std::string trimmed;
    size_t start = 0;
    size_t end = str.length();
    
    // Skip leading whitespace
    while (start < end && (str[start] == ' ' || str[start] == '\t' || 
           str[start] == '\n' || str[start] == '\r')) {
        start++;
    }
    
    // Skip trailing whitespace
    while (end > start && (str[end-1] == ' ' || str[end-1] == '\t' || 
           str[end-1] == '\n' || str[end-1] == '\r')) {
        end--;
    }
    
    trimmed = str.substr(start, end - start);

    negative = false;
    if (!trimmed.empty() && trimmed[0] == '-') {
        negative = true;
        trimmed = trimmed.substr(1);
    }

    numbers.clear();
    // Store digits in reverse order for easier arithmetic
    for (int i = trimmed.length() - 1; i >= 0; --i) {
        if (trimmed[i] >= '0' && trimmed[i] <= '9') {
            numbers.push_back(trimmed[i]);
        }
    }

    if (numbers.empty()) {
        numbers.push_back('0');
    }
    leadingZeros();
}