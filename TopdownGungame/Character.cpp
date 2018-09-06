#include "stdafx.h"
#include "Character.h"


void Character::Init()
{
	AddComponent<TexVertexRenderer>();
	m_TexRenderer = GetComponent<TexVertexRenderer>();

	m_TexRenderer->AddImage("Hitman_gun", L"./PNG/Hitman 1/hitman1_gun.png");
	

	AddComponent<Boxcollider2d>();
	m_BoxCollider = GetComponent<Boxcollider2d>();
	m_BoxCollider->SetSize({64, 64});

	AddComponent<Rigidbody>();
	m_Rigidbody = GetComponent<Rigidbody>();

}

void Character::Update()
{
}

void Character::Render()
{
}

void Character::Release()
{
}

void Character::BoxColliderPress2D(COLLIDERTAG collision)
{

}

Character::Character()
{
}


Character::~Character()
{
}
