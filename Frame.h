#pragma once
#include <string>

//������࣬���ڶ�����Ϸ�в�ͬ����Ĺ����ӿڡ�
class Frame {
public:
    virtual void init() = 0;  // ���麯������ʼ��֡
    virtual void draw() = 0;  // ���麯��������֡
    bool has_init = false;    // ���֡�Ƿ��ѳ�ʼ��
    std::string name = "";    // ֡������
};
