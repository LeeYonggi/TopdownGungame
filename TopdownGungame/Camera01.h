#pragma once
#include "Object.h"
class Camera01 :
	public Object
{
private:
	cCamera * m_Camera;
public:
	void Init();
	void Update();
	void Render();
	void Release();

	Camera01();
	virtual ~Camera01();
};

