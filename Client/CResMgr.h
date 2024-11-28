#pragma once

class CTexture;

class CResMgr
{
	SINGLE(CResMgr);
private:
	map<wstring, CTexture*> m_mapTex;

public:
	// 키값, 상대경로
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);

};

