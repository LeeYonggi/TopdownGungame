#pragma once
#include "Object.h"
class CTile :
	public Object
{
private:
	string tileName;
	TCHAR route[100];
	TexVertexRenderer *m_TexRenderer;
	Boxcollider2d *m_BoxCollider;

public:
	bool IsWall();

public:
	void Init();
	void Update();
	void Render();
	void Release();

	CTile(string name, TCHAR *route, D3DXVECTOR2 point);
	virtual ~CTile();
};

