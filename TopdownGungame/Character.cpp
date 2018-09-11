#include "stdafx.h"
#include "Character.h"

#define TILE_X_MIN_SIZE 0.0f
#define TILE_Y_MAX_SIZE -352.0f


void Character::Init()
{
	AddComponent<TexVertexRenderer>();
	m_TexRenderer = GetComponent<TexVertexRenderer>();

	m_TexRenderer->AddImage("Hitman_gun", L"./PNG/Hitman 1/hitman1_gun.png");
	

	AddComponent<Boxcollider2d>();
	m_BoxCollider = GetComponent<Boxcollider2d>();
	m_BoxCollider->SetSize({64, 64});
	m_BoxCollider->SetColliderTag(COLLIDERTAG::CHARACTER);

	AddComponent<Rigidbody>();
	m_Rigidbody = GetComponent<Rigidbody>();

	speed = 6;
	transform->position.x = -100;
}

void Character::Update()
{
	if (camera->GetTransform()->GetWorldTransform()->position.y <= TILE_X_MIN_SIZE &&
		camera->GetTransform()->GetWorldTransform()->position.y >= TILE_Y_MAX_SIZE)
	{
		float tempY = transform->position.y;
		if (tempY > TILE_X_MIN_SIZE)
			tempY = TILE_X_MIN_SIZE;
		else if (tempY < TILE_Y_MAX_SIZE)
			tempY = TILE_Y_MAX_SIZE;
		camera->GetComponent<cCamera>()->SetViewPostarget({ 0, tempY, MAX_SIZE_DIVISION },
			{ 0, tempY, 0 });
	}

	if (INPUTMANAGER->IsKeyHold(0x57))
		transform->position.y += speed;
	if (INPUTMANAGER->IsKeyHold(0x41))
		transform->position.x -= speed;
	if (INPUTMANAGER->IsKeyHold(0x53))
		transform->position.y -= speed;
	if (INPUTMANAGER->IsKeyHold(0x44))
		transform->position.x += speed;

	D3DXVECTOR2 cameraPos = camera->GetTransform()->GetWorldTransform()->position;
	D3DXVECTOR2 mousePos = { (float)INPUTMANAGER->GetCusorPosition().x, (float)INPUTMANAGER->GetCusorPosition().y };
	
	transform->rotation.z = GetAngle(GetCameraPos(cameraPos, mousePos));

	if (INPUTMANAGER->IsKeyDown(VK_LBUTTON))
	{
		D3DXVECTOR2 position = transform->position;
		OBJECTMANAGER->AddObject(OBJ_BULLET, new CBullet(position, GetCameraPos(cameraPos, mousePos), transform->rotation.z));
	}
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

Character::Character(Object * _camera)
{
	camera = _camera;
}

Character::~Character()
{
}
