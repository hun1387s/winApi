#pragma once
#include "CObject.h"
#include "CCollider.h"


class CMissile :
    public CObject
{
private:
    Vec2      m_vDir;    // 이동 방향 (vector)
    float     m_fTheta; // 이동 방향 (각도)
    float     m_Speed;  // 이동 속도

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

