#pragma once
#include "Object.h"
class CBullet :
	public Object
{
private:
	TexVertexRenderer * m_TexRenderer;
	Boxcollider2d *m_BoxCollider;
	Rigidbody *m_Rigidbody;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	CBullet();
	virtual ~CBullet();
};

