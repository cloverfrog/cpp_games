#include "test2/test2.h"
#include "test1/test1.h"
#include "graphics.h"

int main() {
    initgraph(1280, 720);
    Test1 test1;
    test1.output();
    Test2 test2;
    test2.output();
    return 0;
}