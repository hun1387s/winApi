#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"
#include "CCollider.h"

CMissile::CMissile()
	: m_vDir(Vec2(1.f, 1.f))
	, m_fTheta(0.f)
	, m_Speed(600.f)
{
	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

CMissile::~CMissile()
{
}


void CMissile::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObject(this);
	}

}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.x += m_Speed * m_vDir.x * fDT;
	vPos.y -= m_Speed * m_vDir.y * fDT;

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

	component_render(_dc);
}  
