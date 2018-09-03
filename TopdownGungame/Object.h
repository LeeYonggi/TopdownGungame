#pragma once

class Component;
class Object
{
protected:
	bool active;
	Transform *transform;

public:
	virtual void Init()		PURE;
	virtual void Update()	PURE;
	virtual void Render()	PURE;
	virtual void Release()	PURE;

	bool GetActive() { return active; }
	void SetActive(bool _active) { active = _active; }
	Transform* GetTransform() { return transform; }
	void SetTransform(Transform _transform) { *transform = _transform; }
	

	Object();
	virtual ~Object();

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

