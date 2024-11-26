#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

CMissile::CMissile()
	: m_fDir(1.f)
	, m_fXSpeed(0.f)
	, m_fYSpeed(600.f)
{
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.y += m_fYSpeed * m_fDir * fDT;
	vPos.x += m_fXSpeed * m_fDir * fDT;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	Vec2 vPos = this->GetPos();
	Vec2 vScale = this->GetScale();
	Ellipse(_dc,
		int(vPos.x - vScale.x / 2.f),
		int(vPos.y - vScale.y / 2.f),
		int(vPos.x + vScale.x / 2.f),
		int(vPos.y + vScale.y / 2.f));
}  
