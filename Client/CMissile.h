#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float     m_fDir; // �� �Ʒ� ����
    float     m_fSpeed;

public:
    void SetDir(bool _bUp)
    {
        if (_bUp)
            m_fDir = -1.f;
        else
            m_fDir = 1.f;
    }

public:
    virtual void update();
    virtual void render(HDC _dc) override;

public:
    CMissile();
    ~CMissile();


};

