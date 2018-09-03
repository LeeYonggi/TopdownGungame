#pragma once
#include "Component.h"


class Transform :
	public Component
{
private:
	vector<Object*> childs;
	Object *parent;
	Transform *worldTransform;

public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;

public:
	void Init();
	void Update();
	void Render();
	void Release();

public:
	Transform *GetWorldTransform() { return worldTransform; };
	void SetParent(Object *obj) { parent = obj; }
	Object *GetParent() { return parent; }
	void AddChild(Object *obj) { childs.push_back(obj); }
	vector<Object*> GetChilds() { return childs; }

public:
	Transform(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale)
		:position(_position), rotation(_rotation), scale(_scale)
	{ }

	Transform()
	{
		parent = nullptr;
		position = { 0, 0, 0 };
		rotation = { 0, 0, 0 };
		scale = { 1.0f, 1.0f, 1.0f };
		tag = "Transform";
	}
	~Transform() { }
};