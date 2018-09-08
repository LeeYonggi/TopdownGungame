#include "stdafx.h"
#include "cCamera.h"


void cCamera::Init()
{
	SetCam({ 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f });
}

void cCamera::SetCam(D3DXVECTOR3 viewtargetPoint, D3DXVECTOR3 viewworldUp)
{
	D3DXVECTOR3 position = GetObject_()->GetTransform()->GetWorldTransform()->position;
	D3DXMATRIX V, matRY;
	this->viewtargetPoint = viewtargetPoint;
	this->viewworldUp = viewworldUp;
	D3DXMatrixLookAtLH(&V, &position, &viewtargetPoint, &viewworldUp);
	D3DXMatrixRotationY(&matRY, GetObject_()->GetTransform()->GetWorldTransform()->rotation.y);
	V = V * matRY;
	d3dxdevice->SetTransform(D3DTS_VIEW, &V);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DXToRadian(90),//D3DX_PI * 0.5f, // 90 - degree
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		1.0f,
		1000.0f);
	d3dxdevice->SetTransform(D3DTS_PROJECTION, &proj);

	d3dxdevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cCamera::Render()
{
	SetCam(viewtargetPoint, viewworldUp);
}

void cCamera::SetViewPostarget(D3DXVECTOR3 pos, D3DXVECTOR3 target)
{
	GetObject_()->GetTransform()->GetWorldTransform()->position = pos;
	GetObject_()->GetTransform()->position = pos;
	viewtargetPoint = target;
}

cCamera::cCamera()
{
	tag = "Camera";
}


cCamera::~cCamera()
{
}
