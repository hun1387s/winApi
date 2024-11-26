#include "pch.h"
#include "CCore.h"

#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"


//CCore* CCore::g_pInst = nullptr;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
{
};

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
};

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = {0, 0, _ptResolution.x, _ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	// 이중 버퍼링 용도의 비트맵솨 DC를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	// Manager 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();

	return S_OK;
}

// 계속 실행되는 곳
void CCore::progress()
{
	// Manger Update
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();

	// =========
	// Rendering
	// =========
	// 화면 Clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInst()->render(m_memDC);


	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
		m_memDC, 0, 0, SRCCOPY);
}

//void CCore::update()
//{
//	// 물체들의 변경점 확인
//	Vec2 vPos = g_obj.GetPos();
//
//	// 키의 상태 확인 (NONE TAP AWAY HOLD)
//	KEY_STATE key_state = KEY_STATE::HOLD;
//
//	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == key_state)
//	{
//		vPos.x -= 300.0f * fDT; // fDT = CTimeMgr::GetInst()->GetfDT()
//	}
//	if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == key_state)
//	{
//		vPos.x += 300.0f * fDT;
//	}
//	if (CKeyMgr::GetInst()->GetKeyState(KEY::ESCAPE) == key_state)
//	{
//		DestroyWindow(m_hWnd);
//	}
//	g_obj.SetPos(vPos);
//}
//
//void CCore::render()
//{
//	// 화면 Clear
//	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
//	// 그리기
//	Vec2 vPos = g_obj.GetPos();
//	Vec2 vScale = g_obj.GetScale();
//	Rectangle(m_memDC,
//		int(vPos.x - vScale.x / 2.f),
//		int(vPos.y - vScale.y / 2.f),
//		int(vPos.x + vScale.x / 2.f),
//		int(vPos.y + vScale.y / 2.f));
//	
//	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
//		 m_memDC, 0, 0, SRCCOPY);
//}
