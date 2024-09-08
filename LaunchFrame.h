#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"

class LaunchFrame : public Frame {
private:
    const float buttonWidth = 200.0f;  // ��ť�Ŀ��
    const float buttonHeight = 50.0f;  // ��ť�ĸ߶�
    const float buttonSpacing = 20.0f;  // ��ť֮��ļ��
    Rectangle buttons[2];  // �洢2����ť��λ�úͳߴ�
    const char* buttonLabels[2];  // ��ť�ı�ǩ�ı�

    // ����������ر���
    float animationDuration = 3.0f;  // ��������ʱ��
    float elapsedTime = 0.0f;  // �Ѿ�����ʱ��
    bool animationFinished = false;  // �����Ƿ����

public:
    LaunchFrame();  // ���캯��
    void init() override;  // ��ʼ������
    void draw() override;  // ���ƺ���
};
