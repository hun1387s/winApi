#pragma once


// Sington 매크로
#define SINGLE(type) public:\
						 static type* GetInst()\
						 {\
							static type mgr;	\
							return &mgr;	\
						 }\
					private:\
						type();\
						~type();

#define fDT CTimeMgr::GetInst()->GetfDT();
#define DT CTimeMgr::GetInst()->GetDT();

#define KEY_CHECK(key, state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key)  KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)

#define PI 3.1415926535f

// 오브젝트의 종류 나누는 그룹
enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	PROJ_PLAYER,
	PROJ_MOSTER,


	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,



	END,
};