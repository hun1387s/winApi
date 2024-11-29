#pragma once

class CCollider;

class CObject
{
private:
	Vec2			m_vPos;
	Vec2			m_vScale;

	CCollider*		m_pCollider;

public:
	void SetPos(Vec2 vPos) { m_vPos = vPos; };
	void SetScale(Vec2 vScale) { m_vScale = vScale; };
	
	Vec2 GetPos() { return m_vPos; };
	Vec2 GetScale() { return m_vScale; };

	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }

public:
	virtual void update() = 0; // 순수 가상함수
	virtual void finalupdate() final;
	virtual void render(HDC _dc);

	void component_render(HDC _dc);

public:
	CObject();
	virtual ~CObject();
};

