#pragma once

class CCollider;

class CObject
{
private:
	wstring			m_strName;

	Vec2			m_vPos;
	Vec2			m_vScale;

	CCollider*		m_pCollider;

	bool			m_bAlive; // 활성화 체크 (false면 dead상태)

public:
	void SetPos(Vec2 vPos) { m_vPos = vPos; };
	void SetScale(Vec2 vScale) { m_vScale = vScale; };
	
	Vec2 GetPos() { return m_vPos; };
	Vec2 GetScale() { return m_vScale; };

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	CCollider* GetCollider() { return m_pCollider; }

	void CreateCollider();

	bool IsDead() { return !m_bAlive; }

private:
	void SetDead() { m_bAlive = false; }

public:
	virtual void update() = 0; // 순수 가상함수
	virtual void finalupdate() final;
	virtual void render(HDC _dc);

	virtual void OnCollision(CCollider* _pOther) {};
	virtual void OnCollisionEnter(CCollider* _pOther) {};
	virtual void OnCollisionExit(CCollider* _pOther) {};

	void component_render(HDC _dc);

public:
	CObject();
	virtual ~CObject();

	friend class CEventMgr;
};

