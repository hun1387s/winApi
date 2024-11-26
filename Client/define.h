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

// 오브젝트의 종류 나누는 그룹
enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,


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