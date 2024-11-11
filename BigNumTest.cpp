#include <iostream>
#include <sstream>
#include "BigNum.h"

using namespace std;

int testConstructors() {
    cout << "\nTesting Constructors..." << endl;
    int score = 0;

    BigNum defaultConstructor;
    if (defaultConstructor == 0) {
        cout << "Default constructor test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Default constructor test failed." << endl;
    }

    BigNum stringConstructor("123456789");
    if (stringConstructor == BigNum(123456789)) {
        cout << "String constructor test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "String constructor test failed." << endl;
    }

    BigNum intConstructor(987654321);
    if (intConstructor == BigNum("987654321")) {
        cout << "Int constructor test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Int constructor test failed." << endl;
    }

    BigNum intAssignment = 900;
    if (intAssignment == BigNum("900")) {
        cout << "Int assignment test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Int assignment test failed." << endl;
    }

    BigNum copyConstructor = BigNum(200328);
    if (copyConstructor == BigNum("200328")) {
        cout << "Copy constructor test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Copy constructor test failed." << endl;
    }

    return score;
}

int testComparisonOperators() {
    cout << "\nTesting Comparison Operators..." << endl;
    int score = 0;

    BigNum num1("123456789");
    BigNum num2("987654321");
    BigNum num3(123456789);

    if ((num1 == num3) && !(num1 == num2)) {
        cout << "Comparison operator == test passed (+1)" << endl;
        score += 1;
    } else {
        cout << "Comparison operator == test failed." << endl;
    }

    if ((num1 != num2) && !(num1 != num3)) {
        cout << "Comparison operator != test passed (+1)" << endl;
        score += 1;
    } else {
        cout << "Comparison operator != test failed." << endl;
    }

    if ((num2 == 987654321) && !(num2 == 123456789)) {
        cout << "Comparison operator == with int test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Comparison operator == with int test failed." << endl;
    }

    if ((num1 != 987654321) && !(num1 != 123456789)) {
        cout << "Comparison operator != with int test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Comparison operator != with int test failed." << endl;
    }

    if ((987654321 == num2) && !(987654321 == num3)) {
        cout << "Comparison operator == with int on LHS test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Comparison operator == with int on LHS test failed." << endl;
    }

    if ((987654321 != num1) && !(987654321 != num2)) {
        cout << "Comparison operator != with int on LHS test passed (+2)" << endl;
        score += 2;
    } else {
        cout << "Comparison operator != with int on LHS test failed." << endl;
    }

    return score;
}

int testArithmeticOperators() {
    cout << "\nTesting Arithmetic Operators..." << endl;
    int score = 0;

    cout << "\nTesting addition operator (+): \n";
    BigNum num1("123456789");
    BigNum num2("987654321");
    BigNum num3("89938493893341123");
    BigNum num4("121090939012312");
    BigNum num5("695003492398239");
    BigNum num6("685309439090901");

    BigNum sum = num1 + num2;
    BigNum expectedSum("1111111110");
    if (sum == expectedSum) {
        cout << "Addition operator test 1 passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Addition operator test 1 failed." << endl;
    }

    BigNum sum2 = num3 + num4;
    BigNum expectedSum2("90059584832353435");
    if (sum2 == expectedSum2) {
        cout << "Addition operator test 2 passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Addition operator test 2 failed." << endl;
    }

    cout << "\nTesting subtraction operator (-): \n";
    BigNum difference = num2 - num1;
    BigNum expectedDifference("864197532");
    if (difference == expectedDifference) {
        cout << "Subtraction operator test 1 passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Subtraction operator test 1 failed." << endl;
    }

    BigNum difference2 = num5 - num6;
    BigNum expectedDifference2("9694053307338");
    if (difference2 == expectedDifference2) {
        cout << "Subtraction operator test 2 passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Subtraction operator test 2 failed." << endl;
    }

    cout << "\nTesting multiplication operator (*): \n";
    BigNum product = num1 * num2;
    BigNum expectedProduct("121932631112635269");

    if (product == expectedProduct) {
        cout << "Multiplication operator test 1 passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Multiplication operator test 1 failed." << endl;
    }

    BigNum product2 = num3 * num4;
    BigNum expectedProduct2("10890736678897765168199312906376");
    if (product2 == expectedProduct2) {
        cout << "Multiplication operator test 2 passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Multiplication operator test 2 failed." << endl;
    }

    return score;
}

int testSpecialOperator()
{
    cout << "\nTesting Special Operator Digit Product..." << endl;
    int score = 0;

    BigNum n1(632);
    BigNum n2(891);
    BigNum n3 = n1 / n2;

    if (n3 == BigNum("48272")) 
    {
        cout << "Digit Product Test 1 passed (+5)" << endl;
        score += 5;
    } 
    else 
    {
        cout << "Output: " << n3 << endl;
        cout << "Digit Product Test 1 failed." << endl;
    }


    BigNum n4("798239");
    BigNum n5("239012");
    BigNum n6 = n4 / n5;
    if (n6 == BigNum("1427720318")) 
    {
        cout << "Digit Product Test 2 passed (+5)" << endl;
        score += 5;
    } 
    else 
    {
        cout << "Output: " << n6 << endl;
        cout << "Digit Product Test 2 failed." << endl;
    }

    BigNum n7("9839238430129032");
    BigNum n8("4639434340123422");
    BigNum n9 = n7 / n8;
    if (n9 == BigNum("36489818932121201427064")) 
    {
        cout << "Digit Product Test 3 passed (+5)" << endl;
        score += 5;
    } 
    else 
    {
        cout << "Output: " << n9 << endl;
        cout << "Digit Product Test 3 failed." << endl;
    }

    return score;
}

int testUnaryIncDecOperators() {
    cout << "\nTesting Unary Increment/Decrement Operators..." << endl;
    int score = 0;
    bool check = true;

    BigNum num("1000");

    BigNum prefixInc = ++num;
    if (prefixInc == BigNum("1001") && num == BigNum("1001")) {
        cout << "Prefix increment operator test passed" << endl;
    } else {
        cout << "Prefix increment operator test failed." << endl;
        check = false;
    }
    
    BigNum postfixInc = num++;
    if (postfixInc == BigNum("1001") && num == BigNum("1002")) {
        cout << "Postfix increment operator test passed" << endl;
    } else {
        cout << "Postfix increment operator test failed." << endl;
        check = false;
    }

    BigNum prefixDec = --num;
    if (prefixDec == BigNum("1001") && num == BigNum("1001")) {
        cout << "Prefix decrement operator test passed." << endl;
    } else {
        cout << "Prefix decrement operator test failed." << endl;
        check = false;
    }

    BigNum postfixDec = num--;
    if (postfixDec == BigNum("1001") && num == BigNum("1000")) {
        cout << "Postfix decrement operator test passed" << endl;
    } else {
        cout << "Postfix decrement operator test failed." << endl;
        check = false;
    }

    if (check)
    {
        cout << "All tests passed! (+5)\n";
        score += 5;
        return score;
    }

    cout << "Not all tests passed. (0)\n";
    return score;
}

int testCompoundAssignmentOperators() {
    cout << "\nTesting Compound Assignment Operators..." << endl;
    int score = 0;

    BigNum num1("1000");
    BigNum num2("2000");

    num1 += num2;
    if (num1 == BigNum("3000")) {
        cout << "Addition assignment operator test passed" << endl;
    } else {
        cout << "Addition assignment operator test failed." << endl;
        return 0;
    }

    num1 -= num2;
    if (num1 == BigNum("1000")) {
        cout << "Subtraction assignment operator test passed" << endl;
    } else {
        cout << "Subtraction assignment operator test failed." << endl;
        return 0;
    }

    num1 *= num2;
    if (num1 == BigNum("2000000")) {
        cout << "Multiplication assignment operator test passed" << endl;
    } else {
        cout << "Multiplication assignment operator test failed." << endl;
        return 0;
    }

    cout << "All three compound assignment operators passed (+5)\n";
    score += 5;
    return score;
}

int testSafeIndexing()
{
    cout << "\nTesting Indexing Overloads..." << endl;
    int score = 0;

    const BigNum num("123456789");

    char digit = num[3];  // Should return '4'
    if (digit == '4') {
        cout << "Index retrieval test passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Index retrieval test failed." << endl;
    }

    char outOfBounds = num[10];
    if (outOfBounds == '\0') {
        cout << "Out-of-bounds test passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Out-of-bounds test failed." << endl;
    }

    return score;
}

int testIOStreamOperators() {
    cout << "\n\nTesting IO Stream Operators..." << endl;
    int score = 0;

    BigNum num("123456789");
    ostringstream os;
    os << num;
    if (os.str() == "123456789") {
        cout << "Output stream operator test passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Output stream operator test failed." << endl;
    }

    istringstream is("987654321");
    BigNum inputNum;
    is >> inputNum;
    if (inputNum == BigNum("987654321")) {
        cout << "Input stream operator test passed (+5)" << endl;
        score += 5;
    } else {
        cout << "Input stream operator test failed." << endl;
    }

    return score;
}

int main() {
    cout << "Running Tests..." << endl;
    int totalScore = 0;

    totalScore += testConstructors();                 // 10 points
    totalScore += testComparisonOperators();          // 10 points
    totalScore += testArithmeticOperators();          // 30 points
    totalScore += testSpecialOperator();              // 15 points
    totalScore += testUnaryIncDecOperators();         // 5 points
    totalScore += testCompoundAssignmentOperators();  // 5 points
    totalScore += testSafeIndexing();                 // 10 points
    totalScore += testIOStreamOperators();            // 10 points

    cout << "\n\nTotal Score: " << totalScore << "/95" << endl;

    if (totalScore == 95) {
        cout << "All Tests Passed!" << endl;
    } else {
        cout << "Some Tests Failed." << endl;
    }

    return 0;
}
