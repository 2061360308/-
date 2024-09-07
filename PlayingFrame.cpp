#include "PlayingFrame.h"
#include "global.h"
#include <iostream>

// PlayingFrame ���캯��������֡������
// PlayingFrame.cpp
PlayingFrame::PlayingFrame()
    : cardContainer(0, 0, cardWidth, cardHeight, cardSpacing) { // ��ʼ�� CardContainer
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
    // ���ر���ͼƬ
    backgroundTexture = LoadTexture("images/bg1.png");
    if (backgroundTexture.id == 0) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }

    // ����ͷ��ͼƬ
    avatarTexture = LoadTexture("images/head.png");

    // ����ͷ�����������
    float scale = 0.2f;

    // �������½�ͷ���λ��
    avatarPositionLeft = { 10, screenHeight - (avatarTexture.height * scale) - 10 };

    // �������Ͻ�ͷ���λ��
    avatarPositionRight = { screenWidth - (avatarTexture.width * scale) - 10, 10 };

    // �������Ͻ�ͷ���λ��
    avatarPositionTopLeft = { 10, 10 };

    // �����˿��Ƶ���ʼλ��
    startX = avatarPositionLeft.x + avatarTexture.width * scale + 45; // ͷ���ұߵľ���
    startY = avatarPositionLeft.y + (avatarTexture.height * scale - cardHeight) / 2;

    // ���� CardContainer ��λ��
    cardContainer.UpdatePosition(startX, startY);

    // ���㰴ť����ʼλ��
    buttonX1 = screenWidth / 2.0f - (buttonWidth + buttonSpacing) / 2.0f;
    buttonY = startY - buttonHeight - 20.0f;

    // ���� "Hit" ��ť��x����
    buttonX2 = buttonX1 + buttonWidth + buttonSpacing;

    // ����Բ�ΰ�ť��λ��
    circleButtonX = screenWidth - circleButtonRadius - 20.0f;
    circleButtonY = screenHeight - circleButtonRadius - 20.0f;

    // ����˿��Ƶ�������
    Texture2D cardTexture = LoadTexture("images/card.png"); // �滻Ϊʵ�ʵ��˿���ͼƬ·��
    for (int i = 0; i < 18; ++i) {
        cardContainer.AddCard(cardTexture);
    }

    has_init = true;
}

void PlayingFrame::draw() {
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawTextureEx(avatarTexture, avatarPositionLeft, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexture, avatarPositionRight, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexture, avatarPositionTopLeft, 0.0f, 0.2f, WHITE);

    // �����˿���
    cardContainer.Draw();

    Vector2 mousePosition = GetMousePosition();

    // ���� "Skip" ��ť
    DrawRectangle(buttonX1, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX1, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    int buttonTextWidth = MeasureText("Skip", 20);
    DrawText("Skip", buttonX1 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    // ���� "Hit" ��ť
    DrawRectangle(buttonX2, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX2, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    buttonTextWidth = MeasureText("Hit", 20);
    DrawText("Hit", buttonX2 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    // ���Բ�ΰ�ť�Ƿ񱻵��
    if (CheckCollisionPointCircle(mousePosition, { circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        frameManager.setFrame("MAIN_MENU");
    }

    // ����Բ�ΰ�ť
    DrawCircleV({ circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius, LIGHTGRAY);
    DrawCircleLines(circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius, circleButtonRadius, BLACK);

    // ����Բ�ΰ�ť�ϵ��ı�
    int circleButtonTextWidth = MeasureText("Exit", 20);
    DrawText("Exit", circleButtonX + circleButtonRadius - circleButtonTextWidth / 2, circleButtonY + circleButtonRadius - 10, 20, BLACK);
}

PlayingFrame::~PlayingFrame() {
    UnloadTexture(avatarTexture);
    // �ڲ���Ҫ�������ж���˿�������
}
