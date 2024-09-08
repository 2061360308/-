// ������
#if 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "raylib.h"
#include <string>
#include <unordered_map>

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
// ��̬������������ʼ����Ϸ
// static void InitGame(void);         // Initialize game
// void InitFrame(void);       // Update game (one frame)
// ��̬����������������Ϸ����
// static void DrawGame(void);         // Draw game (one frame)
// ��̬����������ж����Ϸ��Դ
// static void UnloadGame(void);       // Unload game
// ��̬������������ʼ����Ϸ���ظ�����
// static void InitGame(void);  // Update and Draw (one frame)

// �����Զ���ͷ�ļ������岻ͬ����Ϸ֡�͹�����
#include "Frame.h"
#include "FrameManager.h"
#include "LaunchFrame.h"
#include "PlayingFrame.h"
#include "global.h"

// ���������
int main()
{
    // ���ô��ڿɵ�����С
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // ��ʼ�����ڣ������ֱ�Ϊ��ȡ��߶Ⱥʹ��ڱ���
    InitWindow(screenWidth, screenHeight, "Raylib Menu Example");

    // ����Ŀ��֡��Ϊ60֡ÿ��
    SetTargetFPS(60);

    // ʵ���� LaunchFrame �� PlayingFrame ����
    LaunchFrame launchFrame;
    PlayingFrame playingFrame;

    // �� FrameManager �����Ϸ����
    frameManager.addFrame(&launchFrame);
    frameManager.addFrame(&playingFrame);

    // ���õ�ǰ��ʾ�Ľ���Ϊ "MAIN_MENU"
    frameManager.setFrame("MAIN_MENU");

    // ����Ϸѭ�������ڹر�ǰһֱ����
    while (!WindowShouldClose())
    {
        // ���ºͻ��Ƶ�ǰ��Ϸ����
        frameManager.draw();
    }

    // �رմ��ڲ�ж�������Դ
    CloseWindow();

    return 0;
}

#endif
