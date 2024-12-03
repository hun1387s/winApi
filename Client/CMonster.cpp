#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CMissile.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CCollider.h"

CMonster::CMonster()
	: m_vCenterPos{Vec2(0.f, 0.f)}
	, m_fSpeed(100.f)
	, m_fMaxDistance(100.f)
	, m_iDir(1)
	, m_iHP(5)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
}

CMonster::~CMonster()
{
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Missile_Player")
	{
		m_iHP -= 1;

		if (m_iHP <= 0)
		{
			DeleteObject(this);
		}
	}
	
}


void CMonster::update()
{
	return;
	Vec2 vCurPos = GetPos();

	// 진행 방향으로 시간당 m_fSpeed 만큼 이동
	vCurPos.x += m_fSpeed * m_iDir * fDT;

	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	// 배회 거리 기준량 확인
	if (0.f < fDist)
	{
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
		CreateMissile();
	}

	SetPos(vCurPos);
	
	
}

void CMonster::CreateMissile()
{
	// 미사일 생성 위치
	Vec2 vMissilePos = this->GetPos();
	vMissilePos.y += this->GetScale().y / 2;

	// 미사일 obj
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(10.f, 10.f));
	pMissile->SetDir(PI / 2); // dn 방향

	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);

}