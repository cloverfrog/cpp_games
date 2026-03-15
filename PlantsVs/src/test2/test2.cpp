#include "test2/test2.h"

#include <iostream>

Test2::Test2() {
    std::cout << "constructor test2" << std::endl;
}

Test2::~Test2() {
    std::cout << "destructor test2" << std::endl;
}

void Test2::output() {
    std::cout << "test2" << std::endl;
}