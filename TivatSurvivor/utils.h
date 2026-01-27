#ifndef UTILS_H
#define UTILS_H

#include <graphics.h>
#include <cmath>
#include <random>

struct Position {
    double x;
    double y;

    operator POINT() const { return {static_cast<int>(std::round(x)), static_cast<int>(std::round(y))}; }
    Position(const POINT& p) : x(static_cast<double>(p.x)), y(static_cast<double>(p.y)) {}
    Position() = default;
    Position(double x_, double y_) : x(x_), y(y_) {}
};

inline void loadimage_safe(IMAGE* pDstImg, LPCTSTR pImgFile, int nWidth = 0, int nHeight = 0, bool bResize = false) {
    int ret = loadimage(pDstImg, pImgFile, nWidth, nHeight, bResize);
    while(ret) {
        int handle = MessageBox(GetHWnd(), _T(pImgFile), _T("图片加载错误"), MB_ABORTRETRYIGNORE | MB_ICONSTOP);
        switch (handle) {
        case IDABORT:
            exit(1);
            break;
        case IDRETRY:
            ret = loadimage(pDstImg, pImgFile, nWidth, nHeight, bResize);
            break;
        case IDIGNORE:
            ret = 0;
            break;
        }
    }
}

//绘制带alpha通道的png图像
#ifdef _MSC_VER
#pragma comment(lib, "MSIMG32.LIB")
#endif
inline void putimage_alpha(int x, int y, IMAGE* img) {
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

class Random {
public:
    // 禁止拷贝，保证全局唯一引擎
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;
    
    // 获取单例
    static Random& Instance() {
        static Random inst;
        return inst;
    }
    
    // [min, max] 整数
    int Int(int min, int max) {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen_);
    }
    
    // [min, max] 浮点数
    double Double(double min, double max) {
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen_);
    }
    
    // 布尔概率，如 Bool(0.3) => 30% true
    bool Bool(double probability = 0.5) {
        std::bernoulli_distribution dis(probability);
        return dis(gen_);
    }
    
private:
    Random() : gen_(std::random_device{}()) {}
    std::mt19937 gen_;
};

#endif // UTILS_H