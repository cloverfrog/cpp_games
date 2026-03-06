#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <random>

#include <graphics.h>

struct Vec2;
struct Position;
struct RectArea;

struct Vec2 {
    double x;
    double y;

    Vec2() = default;
    Vec2(double x_, double y_) : x(x_), y(y_) {}
    Vec2 operator+(const Vec2& v) const { return {x + v.x, y + v.y}; }
    Vec2 operator-(const Vec2& v) const { return {x - v.x, y - v.y}; }
    Vec2 operator*(double k) const { return {x * k, y * k}; }
    void Normalize() {
        double len = sqrt(x * x + y * y);
        if(len == 0) return;
        x /= len; y /= len;
    }
};

struct Position {
    double x;
    double y;

    operator POINT() const { return {static_cast<int>(std::round(x)), static_cast<int>(std::round(y))}; }
    Position(const POINT& p) : x(static_cast<double>(p.x)), y(static_cast<double>(p.y)) {}
    Position() = default;
    Position(double x_, double y_) : x(x_), y(y_) {}
    Position operator+(const Vec2& v) const;
    Position operator+=(const Vec2& v);
    Position operator-(const Vec2& v) const;
    Position operator-=(const Vec2& v);
    void Restrict(const RectArea& r);
};

struct RectArea {
    double left;
    double top;
    double right;
    double bottom;

    operator RECT() const { return {static_cast<int>(std::round(left)), static_cast<int>(std::round(top)), static_cast<int>(std::round(right)), static_cast<int>(std::round(bottom))}; }
    RectArea(const RECT& r) : left(static_cast<double>(r.left)), top(static_cast<double>(r.top)), right(static_cast<double>(r.right)), bottom(static_cast<double>(r.bottom)) {}
    RectArea() = default;
    RectArea(double left_, double top_, double right_, double bottom_) : left(left_), top(top_), right(right_), bottom(bottom_) {}
    Position GetCenter() const { return {(left + right) / 2, (top + bottom) / 2}; }
    bool IsCollision(const Position& p) const;
    bool IsCollision(const RectArea& r) const;
};

//其它
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