#pragma once
#include "Component.h"

enum COLLIDERTAG
{
	WALL,
	CHARACTER,
	BULLET
};

class Boxcollider2d :
	public Component
{
private:
	D3DXVECTOR2 size;
	bool istrigger;
	COLLIDERTAG colliderTag;
	
public:
	void SetTrigger(bool set) { istrigger = set; }
	bool GetTrigger() { return istrigger; }
	D3DXVECTOR2 GetSize() { return size; }
	void SetSize(D3DXVECTOR2 _pos) { size = _pos; }
	void SetColliderTag(COLLIDERTAG tag) { colliderTag = tag; }
	COLLIDERTAG GetColliderTag() { return colliderTag; }

public:
	void Init();
	void Update();
	void Render();
	void Release();
	bool IsCollision(D3DXVECTOR2 pos, D3DXVECTOR2 _size);
	D3DXVECTOR2 UnAccessBox(D3DXVECTOR2 _pos, D3DXVECTOR2 _size, RECT re);

	Boxcollider2d();
	virtual ~Boxcollider2d();
};

