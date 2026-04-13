#ifndef GRAPHICS_UTIL_H
#define GRAPHICS_UTIL_H

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
inline void putimage_alpha(int x, int y, IMAGE* img) {
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

#endif // GRAPHICS_UTIL_H