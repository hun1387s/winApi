#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CMissile.h"

void CPlayer::update()
{
	Vec2 vPos = GetPos();
	if (KEY_HOLD(KEY::W)) // (CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}
	SetPos(vPos);
}

void CPlayer::CreateMissile()
{
	static int repeatValue = 0;

	// 미사일 생성 위치
	Vec2 vMissilePos = this->GetPos();
	vMissilePos.y -= this->GetScale().y / 2;

	// 미사일 obj	
	if (repeatValue % 5 == 0)
	{
		// 미사일 obj
		CMissile* pMissile = new CMissile;
		pMissile->SetPos(vMissilePos);
		pMissile->SetScale(Vec2(40.f, 40.f));
		pMissile->SetDir(true); // up 방향
		pMissile->SetSpeed(-100.f, 500.f);

		CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
		pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);

		pMissile = new CMissile;
		pMissile->SetPos(vMissilePos);
		pMissile->SetScale(Vec2(40.f, 40.f));
		pMissile->SetDir(true); // up 방향
		pMissile->SetSpeed(100.f, 500.f);

		pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);

		pMissile = new CMissile;
		pMissile->SetPos(vMissilePos);
		pMissile->SetScale(Vec2(40.f, 40.f));
		pMissile->SetDir(true); // up 방향
		pMissile->SetSpeed(0.f, 600.f);

		pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
	}
	else
	{
		CMissile* pMissile = new CMissile;
		pMissile->SetPos(vMissilePos);
		pMissile->SetScale(Vec2(25.f, 25.f));
		pMissile->SetDir(true); // up 방향

		CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
		pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
	}

	repeatValue++;
}
