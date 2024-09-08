#pragma once
#include <unordered_map>
#include <string>
#include "Frame.h"

//����������е�֡����������Ҫ�л��ͻ��Ƶ�ǰ֡
class FrameManager {
private:
    std::unordered_map<std::string, Frame*> frames; // �洢����֡�Ĺ�ϣ��
    std::string state = "MAIN_MENU";               // ��ǰ֡��״̬

public:
    FrameManager();  // ���캯��

    void addFrame(Frame* frame);  // ���֡
    void setFrame(std::string name);  // ���õ�ǰ֡,�����л�����һ������
    void draw();  // ���Ƶ�ǰ֡
};

// ��ͷ�ļ������� frameManager ʵ��
extern FrameManager frameManager;
