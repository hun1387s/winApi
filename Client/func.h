#pragma once


//CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
//pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);

class CObject;

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(CObject* _pObj);