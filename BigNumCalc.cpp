#include <string>
#include <list>

#include "BigNumCalc.h"

BigNumCalc::BigNumCalc(){};

// Creates a list representing the provided string
// For example, a string "12345" would become a list with elements 1,2,3,4, and 5

std::list<int> BigNumCalc::buildBigNum(std::string numString) 
{
    int len = numString.length();

    std::list<int> numberList;

    for (int i = 0; i < len; i++) 
    {
        numberList.push_back(numString[i] - '0');
    }
    return numberList;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) 
{
    std::list<int> sum;

    int carryover = 0;
    
    // we need to add the digits in the list digit by digit starting wiht the least significant digit taking note of the carryover 
    while (!num1.empty() || !num2.empty() || carryover) 
    {
        int digitSum = carryover;

        if (!num1.empty()) 
        {
            digitSum += num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) 
        {
            digitSum += num2.back();
            num2.pop_back();
        }
        carryover = digitSum / 10;
        sum.push_front(digitSum % 10);
    }

    return sum;
}

// subtraction digit by digit 
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) 
{
    std::list<int> difference;

    int borrow = 0;
// while loop untill we have iteriated thorugh all the list
    while (!num1.empty() || !num2.empty()) 
    {
        // varibale borrow if num 2 is bigger than num 1
        int digitDiff = borrow;

        if (!num1.empty()) 
        {
            digitDiff += num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) 
        {
            digitDiff -= num2.back();
            num2.pop_back();
        }
        if (digitDiff < 0) 
        {
            digitDiff += 10;
            borrow = -1;
        }
        else 
        {
            borrow = 0;
        }
        difference.push_front(digitDiff);
    }

    // Removing any leading zeros
    while (difference.size() > 1 && difference.front() == 0) 
    {
        difference.pop_front();
    }
    return difference;
}

// can assume num2 is only 1 digit long 
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) 
{
    std::list<int> product;

    int carry = 0;

    // for loop to iteriate through each digit in reverse order using reverse iteriator 
    // reverse order because we start with the least signifcant bit and keep multiplying 
    for (auto it = num1.rbegin(); it != num1.rend(); it++) 
    {
        int digitProd = (*it) * num2.front() + carry;
        carry = digitProd / 10;
        product.push_front(digitProd % 10);
    }
    if (carry) 
    {
        product.push_front(carry);
    }
    // Removing any leading zeros
    while (product.size() > 1 && product.front() == 0) 
    {
        product.pop_front();
    }
    return product;
}

BigNumCalc::~BigNumCalc(){};