#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"
#include "CResMgr.h"

#include "CScene.h"
#include "CMissile.h"
#include "CTexture.h"


CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	// Texture 로딩 (CResMgr로 변경)
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");

}

CPlayer::~CPlayer()
{
}

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

void CPlayer::render(HDC _dc)
{
	int iWidth  = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	
	Vec2 vPos = GetPos();

	// 특정 조건을 투명하게 복사하는 함수
	TransparentBlt(_dc, 
		int(vPos.x - ((float)iWidth  / 2)),
		int(vPos.y - ((float)iHeight / 2)), 
		iWidth, iHeight,
		m_pTex->GetDC(),
		0, 0, iWidth, iHeight,
		RGB(255, 0, 255) );		// 이 색상 투명처리

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
		pMissile->SetDir(Vec2(0.f,1.f));
		pMissile->SetSpeed(600.f);

		CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
		pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
	}
	else
	{
		CMissile* pMissile = new CMissile;
		pMissile->SetPos(vMissilePos);
		pMissile->SetScale(Vec2(25.f, 25.f));
		pMissile->SetDir(Vec2(0.f, 1.f));

		CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
		pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
	}

	repeatValue++;
}

