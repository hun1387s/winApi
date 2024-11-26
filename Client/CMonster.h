#pragma once
#include "CObject.h"


class CMonster :
    public CObject
{
private:
    Vec2    m_vCenterPos;       // 물체의 위치
    float   m_fSpeed;           // 물체의 이동 속도
    float   m_fMaxDistance;     // 물체의 최대 이동거리
    int     m_iDir;             // 물체의 방향

public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }

    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
    void SetMaxDistande(float _f) { m_fMaxDistance = _f; }

public:
    virtual void update();

public:
    CMonster();
    ~CMonster();
};

