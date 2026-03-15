#include "test1/test1.h"

#include <iostream>

Test1::Test1() {
    std::cout << "constructor test1" << std::endl;
}

Test1::~Test1() {
    std::cout << "destructor test1" << std::endl;
}

void Test1::output() {
    std::cout << "test1" << std::endl;
}