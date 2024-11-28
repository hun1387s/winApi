#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"

#include "CScene.h"
#include "CMissile.h"
#include "CTexture.h"


CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	// Texture �ε�
	m_pTex = new CTexture;
	wstring strFilepath = CPathMgr::GetInst()->GetContentPath();
	strFilepath += L"texture\\Player.bmp";
	m_pTex->Load(strFilepath);


}

CPlayer::~CPlayer()
{
	if (nullptr != m_pTex)
		delete m_pTex;
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

	// �̹����� �״�� �����ϴ� �Լ�
	//BitBlt(_dc, 
	//	int(vPos.x - ((float)iWidth  / 2)),
	//	int(vPos.y - ((float)iHeight / 2)),
	//	iWidth, iHeight,
	//	m_pTex->GetDC(),
	//	0, 0, SRCCOPY);

	// Ư�� ������ �����ϰ� �����ϴ� �Լ�
	TransparentBlt(_dc, 
		int(vPos.x - ((float)iWidth  / 2)),
		int(vPos.y - ((float)iHeight / 2)), 
		iWidth, iHeight,
		m_pTex->GetDC(),
		0, 0, iWidth, iHeight,
		RGB(255, 0, 255) );		// �� ���� ����ó��

}

void CPlayer::CreateMissile()
{
	static int repeatValue = 0;

	// �̻��� ���� ��ġ
	Vec2 vMissilePos = this->GetPos();
	vMissilePos.y -= this->GetScale().y / 2;

	// �̻��� obj	
	if (repeatValue % 5 == 0)
	{
		// �̻��� obj
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

