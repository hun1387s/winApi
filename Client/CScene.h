#pragma once

// 전방선언
// include가 아닌 방식으로, 포인트 타입으로만 사용
class CObject;

// 추상클래스
class CScene
{
private:
	// 오브젝트를 저장 및 관리할 벡터를 그룹 갯수만큼 선언
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			 m_strName; // Scene 이름

public:
	void SetName(const wstring& _strName) { m_strName = _strName; };
	const wstring& GetName() { return m_strName; };

	void update();
	void finalupdate();		// 마무리 작업해주는 update
	void render(HDC _dc);
	
	// 순수 가상 함수
	virtual void Enter() = 0; // 해당 Scene에 진입시 호출
	virtual void Exit() = 0;  // 해강 Scene에 탈출시 호출

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

