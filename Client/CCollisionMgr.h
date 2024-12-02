#pragma once


class CCollisionMgr
{
	SINGLE(CCollisionMgr);
private:


public:
	void init();
	void CheckGroup(GROUP_TYPE eLeft, GROUP_TYPE _eRight);

};

