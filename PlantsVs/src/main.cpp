#include <chrono>
#include <graphics.h>

#include "scene_manager.h"
#include "resource_manager.h"

namespace{
constexpr int kWidth = 1280;
constexpr int kHeight = 720;
constexpr int kFps = 60;
constexpr int kFrameIntervalUs = static_cast<int>(1000'000.0f / static_cast<float>(kFps));
}

int main() {
	initgraph(kWidth, kHeight);
    BeginBatchDraw();

    timeBeginPeriod(1);

    bool running = true;
	
    /*==========初始化=========*/
    PlantsVs::GetResourceManager().LoadResouces();
    PlantsVs::SceneManager scene_manager;
    /*==========初始化=========*/

	while (running) {
        auto last_time = std::chrono::steady_clock::now();
		
		ExMessage msg;
		while (peekmessage(&msg)) {
            /*==========读取操作=========*/
            scene_manager.OnEvent(msg);
			/*==========读取操作=========*/
		}
		
        /*==========处理数据=========*/
        scene_manager.OnUpdate(static_cast<float>(kFrameIntervalUs) / 1000.0f);
		/*==========处理数据=========*/
		
		cleardevice();
        /*==========绘制画面=========*/
        scene_manager.OnDraw();
        /*==========绘制画面=========*/
		FlushBatchDraw();

        /*==========状态切换=========*/
        /*==========状态切换=========*/

        auto target_time = last_time + std::chrono::microseconds(kFrameIntervalUs);
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