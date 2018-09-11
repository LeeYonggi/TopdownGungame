#include "stdafx.h"
#include "Boxcollider2d.h"



void Boxcollider2d::Init()
{
}

void Boxcollider2d::Update()
{
	Rigidbody * m_RigidBody = GetObject_()->GetComponent<Rigidbody>();
	if (m_RigidBody != nullptr)
	{
		for (int state = 0; state < MAX_OBJECT_SIZE; state++)
		{
			auto iter = OBJECTMANAGER->GetObjects(OBJECT_STATE(state));
			for (int i = 0; i < (*iter).size(); i++)
			{
				Boxcollider2d *temp2D = (*iter)[i]->GetComponent<Boxcollider2d>();
				if ((*iter)[i] != this->GetObject_() && temp2D != nullptr)
				{
					D3DXVECTOR2 position = { (*iter)[i]->GetTransform()->GetWorldTransform()->position.x,
						(*iter)[i]->GetTransform()->GetWorldTransform()->position.y };
					if (IsCollision(position, temp2D->GetSize(), temp2D->GetTrigger()))
					{
						if (istrigger)
							GetObject_()->TriggerBoxColliderPress2D(temp2D->GetColliderTag());
						else
							GetObject_()->BoxColliderPress2D(temp2D->GetColliderTag());
					}
					continue;
				}
			}
		}
	}
}

void Boxcollider2d::Render()
{

}

void Boxcollider2d::Release()
{
}

bool Boxcollider2d::IsCollision(D3DXVECTOR2 _pos, D3DXVECTOR2 _size, bool objTrigger)
{
	D3DXVECTOR2 position = GetObject_()->GetTransform()->GetWorldTransform()->position;

	RECT rect;
	rect.left = position.x - (size.x / 2);
	rect.top = position.y - (size.y / 2);
	rect.right = position.x + (size.x / 2);
	rect.bottom = position.y + (size.y / 2);
	
	RECT rect2;
	rect2.left = _pos.x - (_size.x / 2);
	rect2.top = _pos.y - (_size.y / 2);
	rect2.right = _pos.x + (_size.x / 2);
	rect2.bottom = _pos.y + (_size.y / 2);
	
	RECT re;
	if (IntersectRect(&re, &rect, &rect2))
	{
		if (istrigger == false && objTrigger == false)
		{
			GetObject_()->GetTransform()->position =
				D3DXVECTOR3(UnAccessBox(position, size, rect2).x, UnAccessBox(position, size, rect2).y, 0);
		}
		return true;
	}
	return false;
}

D3DXVECTOR2 Boxcollider2d::UnAccessBox(D3DXVECTOR2 _pos, D3DXVECTOR2 _size, RECT re)
{
	D3DXVECTOR2 tempPos = GetObject_()->GetComponent<Rigidbody>()->GetMovePosition();
	Transform temp = *GetObject_()->GetComponent<Transform>();
	temp.position = { _pos.x, _pos.y, 0 };
	if (tempPos.x < 0.0f)
	{
		temp.position.x += tempPos.x;
	}
	if (tempPos.x > 0.0f)
	{
		temp.position.x += tempPos.x;
		//temp.position.x = re.right + (_size.x / 2);
	}
	if (tempPos.y < 0.0f)
	{
		temp.position.y += tempPos.y;
		//temp.position.y = re.top - (_size.y / 2);
	}
	if (tempPos.y > 0.0f)
	{
		temp.position.y += tempPos.y;
		//temp.position.y = re.bottom + (_size.y / 2);
	}
	return D3DXVECTOR3( temp.position.x, temp.position.y, 0 );
}

Boxcollider2d::Boxcollider2d()
{
	istrigger = false;
	tag = "Boxcollider2d";
	size.x = 0;
	size.y = 0;
}


Boxcollider2d::~Boxcollider2d()
{
}
