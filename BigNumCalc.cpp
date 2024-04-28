#include "BigNumCalc.h"


BigNumCalc::BigNumCalc(){

}



std::list<int> BigNumCalc::buildBigNum(std::string numString){
    std::list<int> bigNum;
    for (char digit : numString) {
        bigNum.push_back(digit - '0');
    }
    return bigNum;
}

// Add num1 and num2
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
        std::list<int> result;
        int carry = 0;

        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();

        while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
            int sum = carry;
            if (it1 != num1.rend()) {
                sum += *it1;
                ++it1;
            }
            if (it2 != num2.rend()) {
                sum += *it2;
                ++it2;
            }
            result.push_front(sum % 10);
            carry = sum / 10;
        }

        return result;

}

// Subtract num2 from num1
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int borrow = 0;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    while (it1 != num1.rend() || it2 != num2.rend()) {
        int diff = borrow;
        if (it1 != num1.rend()) {
            diff += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            diff -= *it2;
            ++it2;
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
    }

    // Remove leading zeroes
    while (result.front() == 0 && result.size() > 1) {
        result.pop_front();
    }

    return result;
}
    



// Multiply num1 and num2
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int carry = 0;
    auto it1 = num1.rbegin();
    while (it1 != num1.rend() || carry != 0) {
        int product = carry;
        if (it1 != num1.rend()) {
            product += (*it1) * num2.front();
            ++it1;
        }
        result.push_front(product % 10);
        carry = product / 10;
    }
    return result;
}

// For simplicity, assume that num2 will be only one digit long. 
        


BigNumCalc::~BigNumCalc(){

}
