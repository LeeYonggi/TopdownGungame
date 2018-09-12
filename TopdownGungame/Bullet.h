#pragma once
#include "Object.h"
class CBullet :
	public Object
{
private:
	TexVertexRenderer * m_TexRenderer;
	Boxcollider2d *m_BoxCollider;
	Rigidbody *m_Rigidbody;
	D3DXVECTOR2 direction;

public:
	void Init();
	void Update();
	void Render();
	void Release();
	void TriggerBoxColliderPress2D(COLLIDERTAG collision);

	CBullet(D3DXVECTOR2 center, D3DXVECTOR2 traking, float angle);
	virtual ~CBullet();
};

