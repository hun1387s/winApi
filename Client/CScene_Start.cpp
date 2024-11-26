#include "pch.h"
#include "CScene_Start.h"

#include "CCore.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

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
	AddObject(pObj, GROUP_TYPE::DEFAULT);

	// Monster ��ġ
	int iMonsterCount = 16;
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
		pMonsterObj->SetPos(Vec2(blink + fTerm * i, 50.f));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMaxDistande(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::DEFAULT);
	}
}

void CScene_Start::Exit()
{

}
