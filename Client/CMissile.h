#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float     m_fDir; // 위 아래 방향
    float     m_fXSpeed;
    float     m_fYSpeed;
public:
    void SetDir(bool _bUp)
    {
        if (_bUp)
            m_fDir = -1.f;
        else
            m_fDir = 1.f;
    }
    void SetSpeed(float _x, float _y)
    {
        m_fXSpeed = _x;
        m_fYSpeed = _y;
    }

public:
    virtual void update();
    virtual void render(HDC _dc) override;

public:
    CMissile();
    ~CMissile();


};

