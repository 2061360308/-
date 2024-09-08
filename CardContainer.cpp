#if 0
// CardContainer.cpp
#include "CardContainer.h"

CardContainer::CardContainer(float startX, float startY, float cardWidth, float cardHeight, float cardSpacing)
    : startX(startX), startY(startY), cardWidth(cardWidth), cardHeight(cardHeight), cardSpacing(cardSpacing) {}

void CardContainer::AddCard(Texture2D cardTexture) {
    cards.push_back(cardTexture);
}

void CardContainer::Draw() {
    for (size_t i = 0; i < cards.size(); ++i) {
        float cardX = startX + i * (cardWidth + cardSpacing);
        DrawTexture(cards[i], static_cast<int>(cardX), static_cast<int>(startY), WHITE);
        DrawRectangleLines(static_cast<int>(cardX), static_cast<int>(startY), static_cast<int>(cardWidth), static_cast<int>(cardHeight), BLACK); // ���Ʊ߿�
    }
}

void CardContainer::UpdatePosition(float startX, float startY) {
    this->startX = startX;
    this->startY = startY;
}

void CardContainer::SetCardSpacing(float spacing) {
    cardSpacing = spacing;
}
#endif 

#if 1
#include "CardContainer.h"

CardContainer::CardContainer(float startX, float startY, float cardWidth, float cardHeight, float cardSpacing)
    : startX(startX), startY(startY), cardWidth(cardWidth), cardHeight(cardHeight), cardSpacing(cardSpacing) {}

void CardContainer::AddCard(Texture2D cardTexture) {
    cards.push_back(cardTexture);
}

void CardContainer::Draw() {
    UpdateCardPositions(); // ȷ��λ���ڻ���ʱ�����µ�
    for (size_t i = 0; i < cards.size(); ++i) {
        float cardX = startX + i * (cardWidth + cardSpacing);
        DrawTexture(cards[i], static_cast<int>(cardX), static_cast<int>(startY), WHITE);
        DrawRectangleLines(static_cast<int>(cardX), static_cast<int>(startY), static_cast<int>(cardWidth), static_cast<int>(cardHeight), BLACK); // ���Ʊ߿�
    }
}

void CardContainer::UpdatePosition(float startX, float startY) {
    this->startX = startX;
    this->startY = startY;
    UpdateCardPositions(); // �����˿��Ƶ�λ��
}

void CardContainer::SetCardSpacing(float spacing) {
    cardSpacing = spacing;
}

void CardContainer::SetCardSize(float width, float height) {
    cardWidth = width;
    cardHeight = height;
}

void CardContainer::UpdateCardPositions() {
    // ����������ʵ�ָ����ӵ�λ�õ����߼������紦���ڴ�С�仯
}

#endif 
