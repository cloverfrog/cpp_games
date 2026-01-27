#include "utils.h"
#include "manager.h"

#include <graphics.h>

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;
constexpr int FPS = 30;

int main() {
	initgraph(WIDTH, HEIGHT);
	
	bool running = true;
	
    /*==========初始化=========*/
    IMAGE img_background;
    loadimage_safe(&img_background, _T("img/background.png"));

    Manager manager({0, 0, WIDTH, HEIGHT});

    //键盘标志
    bool hold_key_up = false;
    bool hold_key_down = false;
    bool hold_key_left = false;
    bool hold_key_right = false;
    /*==========初始化=========*/

	BeginBatchDraw();
	
	while (running) {
		DWORD start_time = GetTickCount();
		
		ExMessage msg;
		while (peekmessage(&msg)) {
            /*==========读取操作=========*/
            if(msg.message == WM_KEYDOWN || msg.message == WM_KEYUP) {
                if(msg.vkcode == VK_LEFT) hold_key_left = msg.message == WM_KEYDOWN;
                if(msg.vkcode == VK_RIGHT) hold_key_right = msg.message == WM_KEYDOWN;
                if(msg.vkcode == VK_UP) hold_key_up = msg.message == WM_KEYDOWN;
                if(msg.vkcode == VK_DOWN) hold_key_down = msg.message == WM_KEYDOWN;
            }
            else if(msg.message == WM_ACTIVATE) {
                hold_key_left = false;
                hold_key_right = false;
                hold_key_up = false;
                hold_key_down = false;
            }
			/*==========读取操作=========*/
		}
		
        /*==========处理数据=========*/
        manager.ProcessKey({hold_key_left, hold_key_right, hold_key_up, hold_key_down});
        manager.Update();
		/*==========处理数据=========*/
		
		cleardevice();
		
        /*==========绘制画面=========*/
        putimage(0, 0, &img_background);

        manager.Draw();
        /*==========绘制画面=========*/
		
		FlushBatchDraw();
		
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if(delta_time < 1000 / FPS) {
			Sleep(1000 / FPS - delta_time);
		}
			
	}
	
	EndBatchDraw();
	
	/*==========释放资源=========*/
    /*==========释放资源=========*/
	
	return 0;
}