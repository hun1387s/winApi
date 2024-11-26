#pragma once

// 1. 프레임 동기화
// 동일 프레임 내에서 같은 키에대해, 동일한 이벤트를 가져간다.

// 2. 키 입력 이벤트 처리
// tap, hold, release, away etc.

enum class KEY_STATE
{
	NONE,	// 눌리지 않음
	TAP,	// 막 누른 시점
	HOLD,	// 누르고 있는
	AWAY,	// 막 땐 시점
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	CTRL, ALT, LSHIFT, SPACE, ENTER, ESCAPE,


	LAST,

};

struct tKeyInfo
{
	KEY_STATE	eState; // 키의 상태값
	bool		bPrevPush;	// 이전 프레임에서의 눌린 여부
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey);
};

