#include <iostream>
#include "raylib.h"
#include <unordered_map>
#include "Frame.h"
#include "FrameManager.h"

// FrameManager ���캯��
FrameManager::FrameManager() {
    // ���캯�����Խ���һЩ��ʼ��������������û���ض��ĳ�ʼ���߼�
}

// ���֡�� FrameManager
void FrameManager::addFrame(Frame* frame) {
    // ʹ��֡��������Ϊ������֡����洢�� frames ��ϣ����
    frames[frame->name] = frame;
}

// ���õ�ǰ��ʾ��֡
void FrameManager::setFrame(std::string name) {
    // ���õ�ǰ֡��״̬
    this->state = name;
}

// ���Ƶ�ǰ֡
void FrameManager::draw() {
    // ���ݵ�ǰ״̬��ȡ��Ӧ��֡����
    Frame* currentFrame = frames[state];

    if (currentFrame != nullptr) {  // ȷ��֡�������
        if (!currentFrame->has_init) {  // ���֡��δ��ʼ��
            currentFrame->init();  // ��ʼ��֡
            currentFrame->has_init = true;  // ���֡�ѳ�ʼ��
        }

        // ��ʼ����
        BeginDrawing();
        ClearBackground(RAYWHITE);  // ��ձ���Ϊ��ɫ
        currentFrame->draw();  // ���Ƶ�ǰ֡������
        EndDrawing();
    }
}

// ȫ�� FrameManager ����ʵ��
FrameManager frameManager;
