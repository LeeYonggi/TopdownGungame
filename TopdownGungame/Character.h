#pragma once
#include "Object.h"
class Character :
	public Object
{
private:
	TexVertexRenderer *m_TexRenderer;
	Boxcollider2d *m_BoxCollider;
	Rigidbody *m_Rigidbody;
	float speed;
	

public:
	void Init();
	void Update();
	void Render();
	void Release();
	void BoxColliderPress2D(COLLIDERTAG collision) override;

public:

	Character();
	virtual ~Character();
};

