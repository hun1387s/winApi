#pragma once
#include "CObject.h"
#include "CCollider.h"


class CMissile :
    public CObject
{
private:
    Vec2      m_vDir;    // �̵� ���� (vector)
    float     m_fTheta; // �̵� ���� (����)
    float     m_Speed;  // �̵� �ӵ�

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir) { m_vDir = _vDir.Normalize(); }
    void SetSpeed(float _fSpeed) { m_Speed = _fSpeed; }
    void SetColliderScale(Vec2 _scale) { GetCollider()->SetScale(_scale); }

public:
    virtual void update();
    virtual void render(HDC _dc) override;
    void OnCollisionEnter(CCollider* _pOther) override;

public:
    CMissile();
    ~CMissile();


};

