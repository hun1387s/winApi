#pragma once


class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;

	double			m_dDT; // Delta TIme
	double			m_dAcc; //누적
	UINT			m_iCallCount; // 초당 호출 횟수
	UINT			m_iFPS;

	// FPS
	// 1 프레임당 시간 (Delta Time)

public:
	void init();
	void update();
	void render();

	double GetDT() { return m_dDT; };
	float GetfDT() { return (float)m_dDT; };
};

