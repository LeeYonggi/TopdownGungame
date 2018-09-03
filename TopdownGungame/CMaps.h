#pragma once
#include "Object.h"
class CMaps :
	public Object
{
private:
	D3DXVECTOR2 m_Size;
	vector<CTile*> v_Tiles;

public:
	void Init();
	void Update();
	void Render();
	void Release();
	void DataTransform(string str);
	D3DXVECTOR2 GetStreamSize(string str);
	D3DXVECTOR2 GetStreamPoint(string route, string *str);

	CMaps(string maproute);
	virtual ~CMaps();
};

