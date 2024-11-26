#pragma once
#include "CObject.h"


class CMonster :
    public CObject
{
private:
    Vec2    m_vCenterPos;       // ��ü�� ��ġ
    float   m_fSpeed;           // ��ü�� �̵� �ӵ�
    float   m_fMaxDistance;     // ��ü�� �ִ� �̵��Ÿ�
    int     m_iDir;             // ��ü�� ����

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

