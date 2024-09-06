#pragma once
#include <unordered_map>
#include <string>
#include "Frame.h"

class FrameManager {
private:
    std::unordered_map<std::string, Frame*> frames;
    std::string state = "MAIN_MENU";

public:
    FrameManager();

    void addFrame(Frame* frame);
    void setFrame(std::string name);
    void draw();
};

// ��ͷ�ļ������� frameManager
extern FrameManager frameManager;