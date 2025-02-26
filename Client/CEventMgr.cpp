#include "pch.h"
#include "CEventMgr.h"

#include "CObject.h"
#include "CSceneMgr.h"
#include "CScene.h"

CEventMgr::CEventMgr()
	: m_vecEvent{}
{

}

CEventMgr::~CEventMgr()
{

}

void CEventMgr::update()
{
	//====================================================
	// 이전 프레임에서 등록해 놓은 Dead Object를 삭제한다.
	//====================================================
	for (size_t i = 0; i < m_vecDead.size(); i++)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	//===========
	// Event 처리
	//===========
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventMgr::Excute(const tEvent& _eve)
{
	
	switch (_eve.eEven)
	{
		
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParm : Object Adress
		// wParm : Group Type
		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

		CSceneMgr::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParm : Object Adress
		// Object를 Dead 상태로 변경 후
		// 삭제예정 오브젝트를 모아둔다.
		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	
		break;
	}
}
