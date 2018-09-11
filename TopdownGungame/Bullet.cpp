#include "stdafx.h"
#include "Bullet.h"


void CBullet::Init()
{
	AddComponent<TexVertexRenderer>();
	m_TexRenderer = GetComponent<TexVertexRenderer>();
	m_TexRenderer->AddImage("laserRed01", L"./PNG/Lasers/laserRed01.png");

	AddComponent<Boxcollider2d>();
	m_BoxCollider = GetComponent<Boxcollider2d>();
	m_BoxCollider->SetTrigger(true);
	m_BoxCollider->SetSize({ 9, 54 });
	m_BoxCollider->SetColliderTag(COLLIDERTAG::BULLET);

	AddComponent<Rigidbody>();
	m_Rigidbody = GetComponent<Rigidbody>();
	speed = 30;
}

void CBullet::Update()
{
	transform->position.x += direction.x * speed;
	transform->position.y += direction.y * speed;
}

void CBullet::Render()
{

}

void CBullet::Release()
{

}

void CBullet::TriggerBoxColliderPress2D(COLLIDERTAG collision)
{
	if (collision == COLLIDERTAG::WALL)
	{
		SetActive(false);
	}
}


CBullet::CBullet(D3DXVECTOR2 center, D3DXVECTOR2 traking, float angle)
{
	D3DXVECTOR2 temp = traking - center;

	D3DXVec2Normalize(&temp, &temp);
	direction = temp;
	transform->position.x = center.x;
	transform->position.y = center.y;
	transform->rotation.z = angle - 90;
}

CBullet::~CBullet()
{
}
