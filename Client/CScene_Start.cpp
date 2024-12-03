#include "pch.h"
#include "CScene_Start.h"

#include "CCore.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CTexture.h"

#include "CPathMgr.h"
#include "CCollisionMgr.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}


void CScene_Start::Enter()
{
	// Player Object �߰�
	CObject* pObj = new CPlayer;
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// Monster ��ġ
	int iMonsterCount = 5;
	float fMoveDist = 50.f;
	float fObjScale = 50.f;
	float blink = fMoveDist + fObjScale / 2.f;

	Vec2 vResolution = CCore::GetInst()->GetResolution();
	float fTerm = (vResolution.x - blink * 2) / (float)(iMonsterCount - 1);

	CMonster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonsterCount; i++)
	{
		// Monster Object �߰�
		pMonsterObj = new CMonster;
		pMonsterObj->SetName(L"Monster");
		pMonsterObj->SetPos(Vec2(blink + fTerm * i, 70.f + sinf((float)i) * 30));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMaxDistande(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}

	// �浹 ����
	// Player �׷�� Monster �׷� ���� �浹 üũ
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);
}

void CScene_Start::Exit()
{
	CCollisionMgr::GetInst()->Reset();
}
