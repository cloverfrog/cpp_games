#include <graphics.h>
#include <cstdio>

char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

char current_piece = 'O';

//判断输赢
bool CheckWin(char c) {
    if(board[0][0] == c && board[0][1] == c && board[0][2] == c)
        return true;
    if(board[1][0] == c && board[1][1] == c && board[1][2] == c)
        return true;
    if(board[2][0] == c && board[2][1] == c && board[2][2] == c)
        return true;
    if(board[0][0] == c && board[1][0] == c && board[2][0] == c)
        return true;
    if(board[0][1] == c && board[1][1] == c && board[2][1] == c)
        return true;
    if(board[0][2] == c && board[1][2] == c && board[2][2] == c)
        return true;
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
    return false;
}

//判断是否继续
bool CheckDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void DrawBoard() {
    line(0, 200, 600, 200);
    line(0, 400, 600, 400);
    line(200, 0, 200, 600);
    line(400, 0, 400, 600);
}

void DrawPiece() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (board[i][j]) {
                case 'X':
                    line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
                    line(200 * (j + 1), 200 * i, 200 * j, 200 * (i + 1));
                    break;
                case 'O':
                    circle(200 * j + 100, 200 * i + 100, 100);
                    break;
                case '-':
                    break;
            }
        }
    }
}

void DrawTipText() {
    static TCHAR str[64]; 
    _stprintf_s(str, _T("当前棋子类型:%c"), current_piece);

    settextcolor(RGB(225, 175, 45));
    outtextxy(0, 0, str);
}

int main() {
    initgraph(600, 600);

    bool running = true;

    BeginBatchDraw();

    while(running) { 
        ExMessage msg;
        getmessage(&msg, EX_MOUSE);
        if(msg.message == WM_LBUTTONDOWN) {
            int x = msg.x;
            int y = msg.y;

            int index_x = x / 200;
            int index_y = y / 200;

            if (board[index_y][index_x] == '-') {
                board[index_y][index_x] = current_piece;
                current_piece = current_piece == 'O' ? 'X' : 'O';
            }
        }

        cleardevice();

        DrawBoard();
        DrawPiece();
        DrawTipText();

        FlushBatchDraw();

        if (CheckWin('X')) {
            MessageBox(GetHWnd(), _T("X 玩家获胜"), _T("游戏结束"), MB_OK);
            running = false;
        }
        else if (CheckWin('O')) {
            MessageBox(GetHWnd(), _T("O 玩家获胜"), _T("游戏结束"), MB_OK);
            running = false;
        }
        else if (CheckDraw()) {
            MessageBox(GetHWnd(), _T("平局"), _T("游戏结束"), MB_OK);
            running = false;
        }
    }

    EndBatchDraw();

    return 0;
}