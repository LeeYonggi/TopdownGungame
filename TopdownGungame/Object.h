#pragma once

class Component;
enum COLLIDERTAG;
class Object
{
protected:
	bool active;
	Transform *transform;
	float speed;

public:
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;
	virtual void BoxColliderPress2D(COLLIDERTAG collision) { }
	virtual void TriggerBoxColliderPress2D(COLLIDERTAG collision) { }

	bool GetActive() { return active; }
	void SetActive(bool _active) { active = _active; }
	Transform* GetTransform() { return transform; }
	void SetTransform(Transform _transform) { *transform = _transform; }
	

	Object();
	virtual ~Object();
public:
	float GetAngle(const D3DXVECTOR2 pt2)
	{
		D3DXVECTOR2 temp = transform->position;
		return D3DXToDegree(atan2f(pt2.y - temp.y, pt2.x - temp.x));
	}
	D3DXVECTOR2 GetCameraPos(D3DXVECTOR2 cameraPos, D3DXVECTOR2 p1)
	{
		return D3DXVECTOR2((p1.x * 2.0f) - SCREEN_WIDTH - cameraPos.x, -(p1.y * 2.0f - SCREEN_HEIGHT) + cameraPos.y);
	}
	float GetSpeed() { return speed; }

private://component
	std::map<string, Component*> components;
public: //component
	template<class T>
	void AddComponent()
	{
		Component *p = new T;
		auto iter = components.find(p->GetTag());
		if (iter != components.end()) { delete p;  return; }
		p->SetObj(this);
		components.insert(make_pair(p->GetTag(), p));
	}
	template<class T>
	T *GetComponent()
	{
		Component *p = new T;
		auto iter = components.find(p->GetTag()); delete p;
		if (iter == components.end())  return nullptr; 
		return dynamic_cast<T*>(iter->second);
	}
	map<string, Component*> M_GetComponent() { return components; }
};
