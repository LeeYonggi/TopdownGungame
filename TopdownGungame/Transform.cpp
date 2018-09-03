#include "stdafx.h"
#include "Transform.h"


void Transform::Init()
{
	worldTransform = new Transform;
}

void Transform::Update()
{
	if (parent)
	{
		worldTransform->position = position + parent->GetTransform()->position;
		worldTransform->scale = scale + parent->GetTransform()->scale;
		worldTransform->rotation = rotation + parent->GetTransform()->rotation;
	}
	else
	{
		worldTransform->position = position;
	}
}

void Transform::Render()
{

}

void Transform::Release()
{

}
