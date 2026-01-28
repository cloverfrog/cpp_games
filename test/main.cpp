#include <windows.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

// 测试 GetTickCount 精度
void TestGetTickCount() {
    std::cout << "=== GetTickCount 精度测试 ===\n";
    
    // 查看最小可分辨间隔
    std::vector<DWORD> deltas;
    DWORD prev = GetTickCount();
    int zeroCount = 0;
    
    for (int i = 0; i < 10000 && deltas.size() < 100; ++i) {
        DWORD now = GetTickCount();
        DWORD delta = now - prev;
        if (delta > 0) {
            deltas.push_back(delta);
            prev = now;
        } else {
            ++zeroCount;
        }
    }
    
    std::cout << "零间隔调用次数: " << zeroCount << "\n";
    std::cout << "非零间隔样本: " << deltas.size() << "\n";
    
    if (!deltas.empty()) {
        auto min = *std::min_element(deltas.begin(), deltas.end());
        auto max = *std::max_element(deltas.begin(), deltas.end());
        auto avg = std::accumulate(deltas.begin(), deltas.end(), 0ULL) / deltas.size();
        
        std::cout << "最小间隔: " << min << " ms\n";
        std::cout << "最大间隔: " << max << " ms\n";
        std::cout << "平均间隔: " << avg << " ms\n";
    }
    
    // 理论精度
    std::cout << "理论精度: ~15-16 ms (Windows 默认定时器精度)\n\n";
}

// 测试 Sleep 精度
void TestSleep() {
    std::cout << "=== Sleep 精度测试 ===\n";
    
    // 测试不同 Sleep 时长的实际耗时
    int testMs[] = {1, 2, 5, 10, 15, 16};
    
    for (int target : testMs) {
        auto start = std::chrono::steady_clock::now();
        
        Sleep(target);
        
        auto end = std::chrono::steady_clock::now();
        auto actualMs = std::chrono::duration_cast<std::chrono::microseconds>(
            end - start).count() / 1000.0;
        
        std::cout << "Sleep(" << target << " ms) 实际耗时: " 
                  << actualMs << " ms (误差: " << (actualMs - target) << " ms)\n";
    }
    
    std::cout << "\n";
}

// 测试 timeBeginPeriod 对 Sleep 的影响
void TestSleepWithHighRes() {
    std::cout << "=== Sleep 高精度模式 (timeBeginPeriod) ===\n";
    
    // 提升到 1ms 精度
    timeBeginPeriod(1);
    
    int testMs[] = {1, 2, 5, 10};
    
    for (int target : testMs) {
        auto start = std::chrono::steady_clock::now();
        Sleep(target);
        auto end = std::chrono::steady_clock::now();
        
        auto actualMs = std::chrono::duration_cast<std::chrono::microseconds>(
            end - start).count() / 1000.0;
        
        std::cout << "Sleep(" << target << " ms) 实际耗时: " 
                  << actualMs << " ms\n";
    }
    
    timeEndPeriod(1);
    std::cout << "\n";
}

// 测试 Sleep(0) 和 Sleep(1) 的行为
void TestSleepZero() {
    std::cout << "=== Sleep(0) vs Sleep(1) ===\n";
    
    // Sleep(0) 只让出时间片，不保证休眠
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
        Sleep(0);
    }
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start).count() / 1000.0;
    std::cout << "1000 x Sleep(0) 总耗时: " << elapsed << " ms\n";
    
    // Sleep(1) 至少休眠一个时间片
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; ++i) {
        Sleep(1);
    }
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start).count() / 1000.0;
    std::cout << "100 x Sleep(1) 总耗时: " << elapsed << " ms (预期 ~100-1600 ms)\n";
}

int main() {
    TestGetTickCount();
    TestSleep();
    TestSleepWithHighRes();
    TestSleepZero();
    
    return 0;
}