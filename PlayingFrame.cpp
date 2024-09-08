#if 0
#include "PlayingFrame.h"
#include "global.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

// PlayingFrame ���캯��������֡������
// PlayingFrame.cpp
PlayingFrame::PlayingFrame()
    : cardContainer(0, 0, cardWidth, cardHeight, cardSpacing) { // ��ʼ�� CardContainer
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
    // ��ȡ��ʼ���ڳߴ�
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // ���ر���ͼƬ
    backgroundTexture = LoadTexture("images/bg5.png");
    if (backgroundTexture.id == 0) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }

    // ����ͷ��ͼƬ
    std::vector<std::string> avatarPaths = { "images/MR.png", "images/ZZ.png", "images/XY.png" };
    std::vector<Texture2D> avatarTextures;
    for (const auto& path : avatarPaths) {
        Texture2D texture = LoadTexture(path.c_str());
        if (texture.id == 0) {
            std::cerr << "Failed to load avatar texture from " << path << std::endl;
        }
        avatarTextures.push_back(texture);
    }

    // �������ͷ��˳��
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(avatarTextures.begin(), avatarTextures.end(), g);

    // ����ͷ�����������
    float scale = 0.2f;

    // ����ͷ��λ��
    avatarPositionLeft = { 10, screenHeight - (avatarTextures[0].height * scale) - 10 };
    avatarPositionRight = { screenWidth - (avatarTextures[1].width * scale) - 10, 10 };
    avatarPositionTopLeft = { 10, 10 };

    // �����˿��Ƶ���ʼλ��
    startX = avatarPositionLeft.x + avatarTextures[0].width * scale + 45; // ͷ���ұߵľ���
    startY = avatarPositionLeft.y + (avatarTextures[0].height * scale - cardHeight) / 2;

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

    // �������������ͷ������
    avatarTexturesRandomized = avatarTextures;

    has_init = true;
}


void PlayingFrame::draw() {
    // ��ȡ���ڵ�ʵ�ʳߴ�
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // ���Ʊ���
    DrawTexture(backgroundTexture, 0, 0, WHITE);

    // ����ͷ��
    DrawTextureEx(avatarTexturesRandomized[0], avatarPositionLeft, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[1], avatarPositionRight, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[2], avatarPositionTopLeft, 0.0f, 0.2f, WHITE);

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
    for (const auto& texture : avatarTexturesRandomized) {
        UnloadTexture(texture);
    }
    // �ڲ���Ҫ�������ж���˿�������
}

#endif 

//�޸ĺ�
#if 1
#include "PlayingFrame.h"
#include "global.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

// PlayingFrame ���캯��������֡������
// PlayingFrame.cpp
PlayingFrame::PlayingFrame()
    : cardContainer(0, 0, cardWidth, cardHeight, cardSpacing) { // ��ʼ�� CardContainer
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
    // ��ȡ��ʼ���ڳߴ�
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // ���ر���ͼƬ
    backgroundTexture = LoadTexture("images/bg4.png");
    if (backgroundTexture.id == 0) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }


    // ����ͷ��ͼƬ
    std::vector<std::string> avatarPaths = { "images/MR.png", "images/ZZ.png", "images/XY.png" };
    avatarTextures.clear(); // ���֮ǰ������

    for (const auto& path : avatarPaths) {
        Texture2D texture = LoadTexture(path.c_str());
        if (texture.id == 0) {
            std::cerr << "Failed to load avatar texture from " << path << std::endl;
        }
        else {
            avatarTextures.push_back(texture);
        }
    }

    // ȷ�� avatarTextures ����������Ԫ��
    if (avatarTextures.size() < 2) {
        std::cerr << "Not enough avatar textures loaded!" << std::endl;
        return; // ������ִ������Ĵ���
    }

    // ͷ��λ��
    avatarPositionLeft = { 10, screenHeight - (avatarTextures[0].height * scale) - 10 };
    avatarPositionRight = { screenWidth - (avatarTextures[1].width * scale) - 10, 10 };
    avatarPositionTopLeft = { 10, 10 };

    // �˿��Ƶ���ʼλ��
    startX = avatarPositionLeft.x + avatarTextures[0].width * scale + 45;
    startY = avatarPositionLeft.y + (avatarTextures[0].height * scale - cardHeight) / 2;

    // ���� CardContainer ��λ��
    cardContainer.UpdatePosition(startX, startY);

    // ��ť����ʼλ��
    buttonX1 = screenWidth / 2.0f - (buttonWidth + buttonSpacing) / 2.0f;
    buttonY = startY - buttonHeight - 20.0f;
    buttonX2 = buttonX1 + buttonWidth + buttonSpacing;
    circleButtonX = screenWidth - circleButtonRadius - 20.0f;
    circleButtonY = screenHeight - circleButtonRadius - 20.0f;

    // �����˿���ͼ��
    Texture2D cardTexture = LoadTexture("images/card.png");
    for (int i = 0; i < 18; ++i) {
        cardContainer.AddCard(cardTexture);
    }

    avatarTexturesRandomized = avatarTextures;

    has_init = true;
}

void PlayingFrame::draw() {
    // ��ȡ���ڵ�ʵ�ʳߴ�
    int currentScreenWidth = GetScreenWidth();
    int currentScreenHeight = GetScreenHeight();

    // ������ڳߴ�仯������Ԫ��λ��
    if (currentScreenWidth != screenWidth || currentScreenHeight != screenHeight) {
        screenWidth = currentScreenWidth;
        screenHeight = currentScreenHeight;

        // ���¼���Ԫ�ص�λ��
        avatarPositionLeft = { 10, screenHeight - (avatarTextures[0].height * scale) - 10 };
        avatarPositionRight = { screenWidth - (avatarTextures[1].width * scale) - 10, 10 };
        avatarPositionTopLeft = { 10, 10 };

        startX = avatarPositionLeft.x + avatarTextures[0].width * scale + 45;
        startY = avatarPositionLeft.y + (avatarTextures[0].height * scale - cardHeight) / 2;

        cardContainer.UpdatePosition(startX, startY);

        buttonX1 = screenWidth / 2.0f - (buttonWidth + buttonSpacing) / 2.0f;
        buttonY = startY - buttonHeight - 20.0f;
        buttonX2 = buttonX1 + buttonWidth + buttonSpacing;
        circleButtonX = screenWidth - circleButtonRadius - 20.0f;
        circleButtonY = screenHeight - circleButtonRadius - 20.0f;
    }

    // ���㱳��ͼƬ�����ű���
    float scaleX = (float)screenWidth / backgroundTexture.width;
    float scaleY = (float)screenHeight / backgroundTexture.height;
    float scale = std::max(scaleX, scaleY); // ѡ��һ����Ӧ��Ȼ�߶ȵı���

    // ���Ʊ���
    DrawTextureEx(backgroundTexture, { 0, 0 }, 0.0f, scale, WHITE);

    // ����ͷ��
    DrawTextureEx(avatarTexturesRandomized[0], avatarPositionLeft, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[1], avatarPositionRight, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[2], avatarPositionTopLeft, 0.0f, 0.2f, WHITE);

    // �����˿���
    cardContainer.Draw();

    Vector2 mousePosition = GetMousePosition();

    // ���ư�ť��Բ�ΰ�ť
    DrawRectangle(buttonX1, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX1, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    int buttonTextWidth = MeasureText("Skip", 20);
    DrawText("Skip", buttonX1 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    DrawRectangle(buttonX2, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX2, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    buttonTextWidth = MeasureText("Hit", 20);
    DrawText("Hit", buttonX2 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    if (CheckCollisionPointCircle(mousePosition, { circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        frameManager.setFrame("MAIN_MENU");
    }

    DrawCircleV({ circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius, LIGHTGRAY);
    DrawCircleLines(circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius, circleButtonRadius, BLACK);

    int circleButtonTextWidth = MeasureText("Exit", 20);
    DrawText("Exit", circleButtonX + circleButtonRadius - circleButtonTextWidth / 2, circleButtonY + circleButtonRadius - 10, 20, BLACK);
}



PlayingFrame::~PlayingFrame() {
    for (const auto& texture : avatarTexturesRandomized) {
        UnloadTexture(texture);
    }
    // �ڲ���Ҫ�������ж���˿�������
}

#endif 