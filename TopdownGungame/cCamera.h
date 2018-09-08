#pragma once
#include "Component.h"


class cCamera :
	public Component
{
private:
	D3DXVECTOR3 viewtargetPoint;
	D3DXVECTOR3 viewworldUp;
public:
	void Init();
	void SetCam(D3DXVECTOR3 viewtargetPoint, D3DXVECTOR3 viewworldUp);
	void Render() override;

public:
	void SetViewtargetPoint(D3DXVECTOR3 target) { viewtargetPoint = target; }
	D3DXVECTOR3 GetViewtargetPoint() { return viewtargetPoint;  }
	void SetviewworldUp(D3DXVECTOR3 up) { viewworldUp = up; }
	D3DXVECTOR3 GetviewworldUp() { return viewworldUp; }
	void SetViewPostarget(D3DXVECTOR3 pos, D3DXVECTOR3 target);

	cCamera();
	~cCamera();
};

