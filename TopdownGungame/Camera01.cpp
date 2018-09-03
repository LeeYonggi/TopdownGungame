#include "stdafx.h"
#include "Camera01.h"


void Camera01::Init()
{
	AddComponent<cCamera>();
	transform->position = { 0.0f, 0.0f, MAX_SIZE_DIVISION };
	transform->rotation = { 0.0f, 0.0f, 0.0f };
	m_Camera = GetComponent<cCamera>();
}

void Camera01::Update()
{
	//transform->position.y -= 1;
	//m_Camera->SetViewtargetPoint( m_Camera->GetViewtargetPoint() + D3DXVECTOR3(0, -1, 0));
}

void Camera01::Render()
{
}

void Camera01::Release()
{
}

Camera01::Camera01()
{
}


Camera01::~Camera01()
{
}
