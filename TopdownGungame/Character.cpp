#include "stdafx.h"
#include "Character.h"


void Character::Init()
{
	AddComponent<TexVertexRenderer>();
	m_TexRenderer = GetComponent<TexVertexRenderer>();

	m_TexRenderer->AddImage("Hitman_gun", L"./PNG/Hitman 1/hitman1_gun.png");
	
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

Character::Character()
{
}


Character::~Character()
{
}
