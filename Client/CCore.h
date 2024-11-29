#pragma once

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����

// ������ ������ �ִ� ���
// ������ �Ű� ���� �ʾƵ� �ȴ�.
// ���縦 �ϰ� �; ���Ѵ�.
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			 // ���� ������ �ڵ�
	POINT	m_ptResolution;	 // ���� ������ �ػ�
	HDC		m_hDC;			 // ���� ������ Draw Context

	HBITMAP m_hBit;
	HDC		m_memDC;

	// ���� ����ϴ� GDI object (Graphic Device Interface)
	HBRUSH  m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

	void CreateBrushPen();

public:
	HWND  GetMainHwnd() { return m_hWnd; };
	HDC	  GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
};