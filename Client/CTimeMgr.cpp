#include "pch.h"
#include "CTimeMgr.h"
#include "CCore.h"
#include <string>

CTimeMgr::CTimeMgr()
	: m_llPrevCount{}
	, m_llCurCount {}
	, m_llFrequency{}	
	, m_dDT(0.0)
	, m_dAcc(0.0)
	, m_iCallCount(0)
	, m_iFPS(0)
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);

	// 초당 카운트 횟수
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// 이전 프레임 카운팅과 현재 프레임 카운팀 값의 차이를 구한다.
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)(m_llFrequency.QuadPart);

	
	// 이전 카운트 값을 현재값으로 갱신 (다음번에 계산을 위해서)
	m_llPrevCount = m_llCurCount;

#ifdef _DEBUG
	if (m_dDT > (1.f / 60.f)) { m_dDT = (1.f / 60.f); }
#endif _DEBUG
}

void CTimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;
	if (m_dAcc >= 1.0)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d,   Dt: %f", m_iFPS, m_dDT);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
