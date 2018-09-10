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

	AddComponent<Rigidbody>();
	m_Rigidbody = GetComponent<Rigidbody>();
}

void CBullet::Update()
{

}

void CBullet::Render()
{

}

void CBullet::Release()
{

}

CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}
