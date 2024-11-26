#pragma once

// 1. ������ ����ȭ
// ���� ������ ������ ���� Ű������, ������ �̺�Ʈ�� ��������.

// 2. Ű �Է� �̺�Ʈ ó��
// tap, hold, release, away etc.

enum class KEY_STATE
{
	NONE,	// ������ ����
	TAP,	// �� ���� ����
	HOLD,	// ������ �ִ�
	AWAY,	// �� �� ����
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
	KEY_STATE	eState; // Ű�� ���°�
	bool		bPrevPush;	// ���� �����ӿ����� ���� ����
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

