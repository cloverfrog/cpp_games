#include "utils.h"
#include "manager.h"
#include "ui.h"

#include <chrono>
#include <optional>

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

    std::optional<Manager> manager;
    UI ui;

    bool running = true;
    /*==========初始化=========*/

	while (running) {
        auto last_time = std::chrono::steady_clock::now();
		
		ExMessage msg;
		while (peekmessage(&msg)) {
            /*==========读取操作=========*/
            if(manager) manager->ProcessEvent(msg);
            else ui.ProcessEvent(msg);
			/*==========读取操作=========*/
		}
		
        /*==========处理数据=========*/
        if(manager) manager->Update();
        else ui.Update();
		/*==========处理数据=========*/
		
		cleardevice();
        /*==========绘制画面=========*/
        if(manager) manager->Draw();
        else ui.Draw();
        /*==========绘制画面=========*/
		FlushBatchDraw();

        /*==========状态切换=========*/
        if(manager && !manager->Running()) {
            std::string over_str = "最终得分:" + std::to_string(manager->GetScore());
            MessageBox(GetHWnd(), over_str.c_str(), _T("Game Over"), MB_OK);
            manager.reset();
        }
        else {
            if(ui.Start()) manager.emplace(RectArea(0, 0, WIDTH, HEIGHT), static_cast<double>(FRAME_INTERVAL_US) / 1000.0);
            else if(ui.Quit()) running = false;
        }
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