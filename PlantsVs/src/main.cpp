#include <chrono>
#include <graphics.h>

#include "scene_manager.h"

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;
constexpr int FPS = 60;
constexpr int FRAME_INTERVAL_US = 1000'000.0 / FPS;

int main() {
	initgraph(WIDTH, HEIGHT);
    BeginBatchDraw();

    timeBeginPeriod(1);

    bool running = true;
	
    /*==========初始化=========*/
    SceneManager scene_manager;
    /*==========初始化=========*/

	while (running) {
        auto last_time = std::chrono::steady_clock::now();
		
		ExMessage msg;
		while (peekmessage(&msg)) {
            /*==========读取操作=========*/
            scene_manager.onEvent(msg);
			/*==========读取操作=========*/
		}
		
        /*==========处理数据=========*/
        scene_manager.onUpdate();
		/*==========处理数据=========*/
		
		cleardevice();
        /*==========绘制画面=========*/
        scene_manager.onDraw();
        /*==========绘制画面=========*/
		FlushBatchDraw();

        /*==========状态切换=========*/
        /*==========状态切换=========*/

        auto target_time = last_time + std::chrono::microseconds(FRAME_INTERVAL_US);
        auto now_time = std::chrono::steady_clock::now();
        if(target_time > now_time)
            Sleep(static_cast<DWORD>(std::chrono::duration_cast<std::chrono::milliseconds>(target_time - now_time).count()));
        last_time = target_time;
	}
	
	EndBatchDraw();

    timeEndPeriod(1);
	
	/*==========释放资源=========*/
    /*==========释放资源=========*/
	
	return 0;
}