#include "stdafx.h"
#include "Rigidbody.h"


void Rigidbody::Init()
{
	tempPosition = PositionTransform(GetObject_()->GetTransform()->position);
	movePosition = tempPosition;
}

void Rigidbody::Update()
{
	movePosition = tempPosition - PositionTransform(GetObject_()->GetTransform()->position);
	tempPosition = PositionTransform(GetObject_()->GetTransform()->position);
}

void Rigidbody::Render()
{

}

void Rigidbody::Release()
{

}

Rigidbody::Rigidbody()
{
	tag = "Rigidbody";
}


Rigidbody::~Rigidbody()
{
}
