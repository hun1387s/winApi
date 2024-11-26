#include "pch.h"
#include "CKeyMgr.h"

#include "CCore.h"

// ���� ���� KEY ���� ���� ������ ���� �迭
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
	// ������ ��Ŀ�� �˾Ƴ���
	// HWND hMainWnd = CCore::GetInst()->GetMainHwnd();
	HWND hWnd = GetFocus(); // ���� ��Ŀ�̵� ������ ID ��ȯ

	// �����찡 ��Ŀ�� ���� �� Ű �̺�Ʈ ����
	if (hWnd != nullptr)
	{
		// Ű�� ������Ʈ
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// Ű�� ��������.
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPush)
				{
					// �������� �����־���.
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					// �������� �������� �ʾҴ�.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
				m_vecKey[i].bPrevPush = true;
			}
			// Ű�� �ȴ�������.
			else
			{
				if (m_vecKey[i].bPrevPush)
				{
					// �������� �����־���.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					// �������� �������� �ʾҴ�.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
				m_vecKey[i].bPrevPush = false;
			}


			m_vecKey[i].eState;
		}
	}
	// ������ ��Ŀ�� ���������϶� NONE ������ ��ȯ
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

