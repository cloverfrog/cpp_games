#include "utils.h"
#include "manager.h"

#include <chrono>

#include <graphics.h>

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;
constexpr int FPS = 60;
constexpr int FRAME_INTERVAL_US = 1000'000.0 / FPS;

int main() {
	initgraph(WIDTH, HEIGHT);
    BeginBatchDraw();

    timeBeginPeriod(1);
	
    /*==========初始化=========*/
    mciSendString(_T("open mus/bgm.mp3 alias bgm"), NULL, 0, NULL);
    mciSendString(_T("open mus/hit.wav alias hit"), NULL, 0, NULL);

    mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);

    IMAGE img_background;
    loadimage_safe(&img_background, _T("img/background.png"));

    Manager manager(RectArea(0, 0, WIDTH, HEIGHT), static_cast<double>(FRAME_INTERVAL_US) / 1000.0);

    //键盘标志
    bool hold_key_up = false;
    bool hold_key_down = false;
    bool hold_key_left = false;
    bool hold_key_right = false;
    /*==========初始化=========*/

	while (manager.Running()) {
        auto last_time = std::chrono::steady_clock::now();
		
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

        auto target_time = last_time + std::chrono::microseconds(FRAME_INTERVAL_US);
        auto now_time = std::chrono::steady_clock::now();
        if(target_time > now_time)
            Sleep(static_cast<DWORD>(std::chrono::duration_cast<std::chrono::milliseconds>(target_time - now_time).count()));
        last_time = target_time;
	}
	
	EndBatchDraw();

    timeEndPeriod(1);
	
	/*==========释放资源=========*/
    std::string over_str = "最终得分:" + std::to_string(manager.GetScore());
    MessageBox(GetHWnd(), over_str.c_str(), _T("Game Over"), MB_OK);
    /*==========释放资源=========*/
	
	return 0;
}