#include "LaunchFrame.h"
#include "global.h"

// LaunchFrame ���캯��������֡������
LaunchFrame::LaunchFrame() {
    this->name = "MAIN_MENU";  // ��֡����������Ϊ "MAIN_MENU"
}

// ��ʼ�����������ð�ť��ǩ
void LaunchFrame::init() {
    // ����ÿ����ť�ı�ǩ
    buttonLabels[0] = "Create Room";
    buttonLabels[1] = "Join Room";

    // ���֡�ѳ�ʼ��
    has_init = true;
}

// ���ƺ��������ư�ť���������¼�
void LaunchFrame::draw() {
    // ��ȡ��ǰ���ڳߴ�
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // ��ȡ��ǰ����λ��
    Vector2 mousePosition = GetMousePosition();

    // �����Ѿ�����ʱ��
    elapsedTime += GetFrameTime();

    if (elapsedTime < animationDuration) {
        // ���������߼�
        ClearBackground(RAYWHITE);
        DrawText("ZhuoHongSan", screenWidth / 2 - MeasureText("ZhuoHongSan", 40) / 2, screenHeight / 2 - 20, 40, RED);
        // �������������Ӹ������˿�����ص�Ԫ��
        // ���磬�����˿���ͼ�񣬽��м򵥶�����
    }
    else {
        animationFinished = true;
    }

    if (animationFinished) {
        // ���㰴ť�ĳ�ʼλ��
        const float startX = screenWidth / 2.0f - buttonWidth / 2.0f;
        const float startY = screenHeight / 2.0f - (buttonHeight * 0.5f) - buttonSpacing;

        // ����ÿ����ť��λ�úͳߴ�
        buttons[0] = { startX, startY, buttonWidth, buttonHeight };
        buttons[1] = { startX, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };

        // ���ÿ����ť�Ƿ񱻵������������л��� "GAME_PLAY" ֡
        for (int i = 0; i < 2; i++) {
            if (CheckCollisionPointRec(mousePosition, buttons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                frameManager.setFrame("GAME_PLAY");
            }
        }

        // ����ÿ����ť
        for (int i = 0; i < 2; i++) {
            // ��������ͣ�ڰ�ť�ϣ��ı䰴ť��ɫ
            if (CheckCollisionPointRec(mousePosition, buttons[i])) {
                DrawRectangleRec(buttons[i], DARKGRAY);
            }
            else {
                DrawRectangleRec(buttons[i], LIGHTGRAY);
            }
            // ���ư�ť�߿�
            DrawRectangleLinesEx(buttons[i], 3, BLACK);

            // �����ı��Ŀ�Ȳ������ı���ʹ���ڰ�ť�о���
            int textWidth = MeasureText(buttonLabels[i], 20);
            DrawText(buttonLabels[i], buttons[i].x + (buttons[i].width - textWidth) / 2, buttons[i].y + (buttons[i].height - 20) / 2, 20, BLACK);
        }
    }
}
