#ifndef BIGNUMCALC
#define BIGNUMCALC

#include <list>
#include <string>

class BigNumCalc
{
    private:
    std::list<int> num1;
    std::list<int> num2;

    public:
    BigNumCalc();
    BigNumCalc(std::list<int> num1, std::list<int> num2);
    std::list<int> buildBigNum(std::string numString);
    std::list<int> add(std::list<int> num1, std::list<int> num2);
    std::list<int> sub(std::list<int> num1, std::list<int> num2);
    std::list<int> mul(std::list<int> num1, std::list<int> num2);
    ~BigNumCalc();



}

#endif