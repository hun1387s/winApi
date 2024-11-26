#include "pch.h"
#include "CKeyMgr.h"

#include "CCore.h"

// 내가 만든 KEY 값과 같은 순서로 만든 배열
int g_arrVK[(int)KEY::LAST] = 
{
	VK_LEFT,	//LEFT,
	VK_RIGHT,	//RIGHT,
	VK_UP,		//UP,
	VK_DOWN,	//DOWN,
	'Q',		//Q,
	'W',		//W,
	'E',		//E,
	'R',		//R,
	'T',		//T,
	'Y',		//Y,
	'U',		//U,
	'I',		//I,
	'O',		//O,
	'P',		//P,
	'A',		//A,
	'S',		//S,
	'D',		//D,
	'F',		//F,
	'G',		//G,
	'H',		//H,
	'J',		//J,
	'K',		//K,
	'L',		//L,
	'Z',		//Z,
	'X',		//X,
	'C',		//C,
	'V',		//V,
	'B',		//B,
	'N',		//N,
	'M',		//M,
	
	VK_CONTROL,	//CTRL, 
	VK_MENU,    //ALT, 
	VK_SHIFT,   //LSHIFT, 
	VK_SPACE,   //SPACE, 
	VK_RETURN,  //ENTER, 
	VK_ESCAPE,  //ESCAPE,

	//LAST,
};


CKeyMgr::CKeyMgr()
{

}

CKeyMgr::~CKeyMgr()
{

}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i) 
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::update()
{
	// 윈도우 포커싱 알아내기
	// HWND hMainWnd = CCore::GetInst()->GetMainHwnd();
	HWND hWnd = GetFocus(); // 현재 포커싱된 윈도우 ID 반환

	// 윈도우가 포커싱 중일 때 키 이벤트 동작
	if (hWnd != nullptr)
	{
		// 키값 업데이트
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// 키가 눌러졌다.
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에도 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					// 이전에는 눌려있지 않았다.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
				m_vecKey[i].bPrevPush = true;
			}
			// 키가 안눌러졌다.
			else
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에는 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					// 이전에도 눌려있지 않았다.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
				m_vecKey[i].bPrevPush = false;
			}


			m_vecKey[i].eState;
		}
	}
	// 윈도우 포커싱 해제상태일때 NONE 값으로 변환
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;
			
			if (m_vecKey[i].eState == KEY_STATE::TAP || m_vecKey[i].eState == KEY_STATE::HOLD)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (m_vecKey[i].eState == KEY_STATE::AWAY)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
	
}

KEY_STATE CKeyMgr::GetKeyState(KEY _eKey)
{
	return m_vecKey[(int)_eKey].eState;
}

