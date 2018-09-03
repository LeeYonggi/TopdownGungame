#pragma once
#include "Object.h"
class CMapManager :
	public Object
{
private:
	vector<CMaps*> v_Maps;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	CMapManager();
	~CMapManager();
};

