#if 0
#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"
#include "CardContainer.h"

class PlayingFrame : public Frame {
private:
    const float cardWidth = 50.0f;    // �˿��ƿ��
    const float cardHeight = 70.0f;   // �˿��Ƹ߶�
    const float cardSpacing = 0.0f;   // �˿���֮��ļ��

    const float buttonWidth = 80.0f;  // ��ť���
    const float buttonHeight = 30.0f; // ��ť�߶�
    const float buttonSpacing = 20.0f; // ��ť֮��ļ��

    const float circleButtonRadius = 30.0f; // Բ�ΰ�ť�İ뾶

    // ͷ����ر���
    Texture2D avatarTexture;
    Vector2 avatarPositionLeft;
    Vector2 avatarPositionRight;
    Vector2 avatarPositionTopLeft;
    std::vector<Texture2D> avatarTexturesRandomized;

    // �˿���λ��
    float startX;
    float startY;

    // ��ťλ��
    float buttonX1;
    float buttonY;
    float buttonX2;

    // Բ�ΰ�ťλ��
    float circleButtonX;
    float circleButtonY;

    Texture2D backgroundTexture; // ����ͼƬ����

    CardContainer cardContainer; // ��� CardContainer ʵ��

 

public:
    PlayingFrame();  // ���캯��
    ~PlayingFrame(); // ��������
    void init() override;  // ��ʼ������
    void draw() override;  // ���ƺ���
};

#endif 

#if 1
#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"
#include "CardContainer.h"

class PlayingFrame : public Frame {
private:
    const float cardWidth = 50.0f;       // �˿��ƿ��
    const float cardHeight = 70.0f;      // �˿��Ƹ߶�
    const float cardSpacing = 0.0f;      // �˿���֮��ļ��

    const float buttonWidth = 80.0f;     // ��ť���
    const float buttonHeight = 30.0f;    // ��ť�߶�
    const float buttonSpacing = 20.0f;   // ��ť֮��ļ��

    const float circleButtonRadius = 30.0f; // Բ�ΰ�ť�İ뾶

    const float scale = 0.2f;            // ͷ����������

    // ͷ����ر���
    std::vector<Texture2D> avatarTextures; // ͷ�������б�
    Vector2 avatarPositionLeft;            // ���ͷ��λ��
    Vector2 avatarPositionRight;           // �Ҳ�ͷ��λ��
    Vector2 avatarPositionTopLeft;         // ���Ͻ�ͷ��λ��
    std::vector<Texture2D> avatarTexturesRandomized; // ���������ͷ������

    // �˿���λ��
    float startX;
    float startY;

    // ��ťλ��
    float buttonX1;
    float buttonY;
    float buttonX2;

    // Բ�ΰ�ťλ��
    float circleButtonX;
    float circleButtonY;

    Texture2D backgroundTexture; // ����ͼƬ����

    CardContainer cardContainer; // �˿�������ʵ��

public:
    PlayingFrame();  // ���캯��
    ~PlayingFrame(); // ��������

    void init() override;  // ��ʼ������
    void draw() override;  // ���ƺ���
};


#endif 
