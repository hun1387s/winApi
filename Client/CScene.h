#pragma once

// ���漱��
// include�� �ƴ� �������, ����Ʈ Ÿ�����θ� ���
class CObject;

// �߻�Ŭ����
class CScene
{
private:
	// ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			 m_strName; // Scene �̸�

public:
	void SetName(const wstring& _strName) { m_strName = _strName; };
	const wstring& GetName() { return m_strName; };

	void update();
	void finalupdate();		// ������ �۾����ִ� update
	void render(HDC _dc);
	
	// ���� ���� �Լ�
	virtual void Enter() = 0; // �ش� Scene�� ���Խ� ȣ��
	virtual void Exit() = 0;  // �ذ� Scene�� Ż��� ȣ��

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}
	
	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }

public:
	CScene();
	virtual ~CScene();
};

