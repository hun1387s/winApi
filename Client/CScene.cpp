#include "pch.h"
#include "CScene.h"

#include "CObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	// m_arrObj �׷캤��
	for (UINT i = 0; (UINT)GROUP_TYPE::END; i++)
	{
		// m_arrObj[i] �׷캤���� j ��ü
		for (size_t j = 0; j < m_arrObj[i].size(); i++)
		{
			delete m_arrObj[i][j];
		}
	}
}

void CScene::update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++) 
	{
		for (size_t j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->update();
		}
	}
}

void CScene::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->render(_dc);
		}
	}
}
