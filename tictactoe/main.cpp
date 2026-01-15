#include<graphics.h>

int main() {
    initgraph(1270, 720);

    BeginBatchDraw();

    while(true) { 
        ExMessage msg;
        while (peekmessage(&msg)) {

        }

        cleardevice();

        FlushBatchDraw();
    }

    EndBatchDraw();

    return 0;
}