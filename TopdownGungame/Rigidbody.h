#pragma once
#include "Component.h"
class Rigidbody :
	public Component
{
private:
	D3DXVECTOR2 movePosition;
	D3DXVECTOR2 tempPosition;

public:
	D3DXVECTOR2 GetMovePosition() { return movePosition; }
	void SetMovePosition(D3DXVECTOR2 pos) {	tempPosition = pos;	}

public:
	D3DXVECTOR2 PositionTransform(D3DXVECTOR3 pos) 
	{
		return { pos.x, pos.y };
	}

public:
	void Init();
	void Update();
	void Render();
	void Release();

	Rigidbody();
	virtual ~Rigidbody();
};

