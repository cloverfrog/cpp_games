#ifndef GRAPHICS_UTIL_H
#define GRAPHICS_UTIL_H

#include <string>

#include <graphics.h>

//带错误处理的图片加载
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
inline void putimage_alpha(const IMAGE* img, int x, int y, int srcx = 0, int srcy = 0, int w = 0, int h = 0) {
    w = w > 0 ? w : img->getwidth() - srcx;
    h = h > 0 ? h : img->getheight() - srcy;
    AlphaBlend(GetImageHDC(), x, y, w, h,
        GetImageHDC(img), srcx, srcy, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
inline void putimage_alpha_center(const IMAGE* img, int x, int y) {
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(), x-w/2, y-h/2, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

//图像翻转
inline void flipimage(const IMAGE* src, IMAGE* dst) {
    int w = src->getwidth();
    int h = src->getheight();
    Resize(dst, w, h);
    DWORD* src_buffer = GetImageBuffer(src);
    DWORD* dst_buffer = GetImageBuffer(dst);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int idx_src = y * w + x;
            int idx_dst = y * w + (w - x - 1);
            dst_buffer[idx_dst] = src_buffer[idx_src];
        }
    }
}

inline void outtext_shaded(int x, int y, std::string text) {
    settextcolor(RGB(45, 45, 45));
    outtextxy(x + 3, y + 3, text.c_str());
    settextcolor(RGB(255, 255, 255));
    outtextxy(x, y, text.c_str());
}

#endif // GRAPHICS_UTIL_H