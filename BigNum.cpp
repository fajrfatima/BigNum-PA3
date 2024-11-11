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
BigNum BigNum::operator+(const BigNum& other) const {
        if (negative != other.negative) {
        // If signs are different, perform subtraction
        BigNum temp = other;
        temp.negative = !temp.negative;
        return *this - temp;
    }

    BigNum result;
    result.numbers.clear();
    result.negative = negative;

    int carry = 0;
    size_t maxLen = numbers.size();
    if (other.numbers.size() > maxLen) maxLen = other.numbers.size();

    for (size_t i = 0; i < maxLen || carry; ++i) {
        int sum = carry;
        if (i < numbers.size()) sum += numbers[i] - '0';
        if (i < other.numbers.size()) sum += other.numbers[i] - '0';
        
        result.numbers.push_back('0' + (sum % 10));
        carry = sum / 10;
    }

    result.leadingZeros();
    return result;
}

BigNum BigNum::operator-(const BigNum& other) const {
    if (negative != other.negative) {
        // If signs are different, perform addition
        BigNum temp = other;
        temp.negative = !temp.negative;
        return *this + temp;
    }

    // Determine which number has larger absolute value
    int cmp = compareNum(*this, other);
    if (cmp == 0) return BigNum(0);

    // Ensure we subtract smaller from larger
    const BigNum* larger;
    const BigNum* smaller;
    if (cmp > 0) {
        larger = this;
        smaller = &other;
    } else {
        larger = &other;
        smaller = this;
    }

    BigNum result;
    result.numbers.clear();
    result.negative = (cmp < 0) != negative;

    int borrow = 0;
    for (size_t i = 0; i < larger->numbers.size(); ++i) {
        int diff = (larger->numbers[i] - '0') - borrow;
        if (i < smaller->numbers.size()) {
            diff -= (smaller->numbers[i] - '0');
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.numbers.push_back('0' + diff);
    }

    result.leadingZeros();
    return result;
}

BigNum BigNum::operator*(const BigNum& other) const {
    BigNum result;
    result.numbers.clear();
    result.numbers.resize(numbers.size() + other.numbers.size(), '0');
    result.negative = negative != other.negative;

    for (size_t i = 0; i < numbers.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.numbers.size() || carry; ++j) {
            int product = (result.numbers[i + j] - '0') + carry;
            if (j < other.numbers.size()) {
                product += (numbers[i] - '0') * (other.numbers[j] - '0');
            }
            result.numbers[i + j] = '0' + (product % 10);
            carry = product / 10;
        }
    }

    result.leadingZeros();
    return result;
}

//SPECIAL OPERATOR
// digit product operator
BigNum BigNum::operator/(const BigNum& other) const {
      std::vector<char> result_digits;
        
        // Since we're guaranteed same length numbers, we can iterate through both vectors
        for(int i = 0; i < numbers.size(); i++) {
            // Get digits from both numbers and convert to integers
            int digit1 = numbers[i] - '0';
            int digit2 = other.numbers[i] - '0';
            
            // Calculate product
            int product = digit1 * digit2;
            
            // Convert product to string
            std::string prod_str = std::to_string(product);
            
            // Add each digit of the product to the result
            for(int j = prod_str.length() - 1; j >= 0; j--) {
                result_digits.push_back(prod_str[j]);
            }
        }
        
        // Create a new BigNum using the string representation of the result
        std::string result_str;
        for(int i = result_digits.size() - 1; i >= 0; i--) {
            result_str += result_digits[i];
        }
        
        return BigNum(result_str);
    }


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
void BigNum :: nstring(const std::string& str) {
    std :: string substring;
    int start = 0;
    int end = str.length();
    
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
    
    substring = str.substr(start, end - start);

    negative = false;
    if (!substring.empty() && substring[0] == '-') {
        negative = true;
        substring = substring.substr(1);
    }

    numbers.clear();
    // Store digits in reverse order for easier arithmetic
    for (int i = substring.length() - 1; i >= 0; --i) {
        if (substring[i] >= '0' && substring[i] <= '9') {
            numbers.push_back(substring[i]);
        }
    }

    if (numbers.empty()) {
        numbers.push_back('0');
    }
    leadingZeros();
}