#pragma once
#include "Component.h"


class Boxcollider2d :
	public Component
{
private:
	D3DXVECTOR2 size;
	bool istrigger;
	
public:
	void SetTrigger(bool set) { istrigger = set; }
	bool GetTrigger() { return istrigger; }
	D3DXVECTOR2 GetSize() { return size; }

public:
	void Init();
	void Update();
	void Render();
	void Release();
	bool IsCollision(D3DXVECTOR2 pos, D3DXVECTOR2 size);

	Boxcollider2d();
	virtual ~Boxcollider2d();
};

