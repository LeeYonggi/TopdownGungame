#pragma once
#include "Object.h"
class Character :
	public Object
{
private:
	TexVertexRenderer *m_TexRenderer;
	

public:
	void Init();
	void Update();
	void Render();
	void Release();

public:

	Character();
	virtual ~Character();
};

