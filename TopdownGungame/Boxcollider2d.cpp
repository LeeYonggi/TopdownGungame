#include "stdafx.h"
#include "Boxcollider2d.h"



void Boxcollider2d::Init()
{
	OBJECTMANAGER->SetColliderObjects(GetObject_());
}

void Boxcollider2d::Update()
{
	if (GetObject_()->GetComponent<Rigidbody>() != nullptr)
	{
		auto iter = OBJECTMANAGER->GetColliderObjects();
		for (int i = 0; i < iter.size(); i++)
		{
			Boxcollider2d *temp2D = iter[i]->GetComponent<Boxcollider2d>();
			if (iter[i] != this->GetObject_() && temp2D->GetTrigger() == false)
			{
				D3DXVECTOR2 position = { iter[i]->GetTransform()->position.x, iter[i]->GetTransform()->position.y };
				if (IsCollision(position, temp2D->GetSize()))
					GetObject_()->BoxColliderPress2D(temp2D->GetColliderTag());
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

bool Boxcollider2d::IsCollision(D3DXVECTOR2 _pos, D3DXVECTOR2 _size)
{
	D3DXVECTOR2 position = GetObject_()->GetTransform()->position;

	RECT rect;
	rect.bottom = position.y + (size.y / 2);
	rect.top = position.y - (size.y / 2);
	rect.right = position.x + (size.x / 2);
	rect.left = position.x - (size.x / 2);
	
	RECT rect2;
	rect2.bottom = _pos.y + (_size.y / 2);
	rect2.top = _pos.y - (_size.y / 2);
	rect2.right = _pos.x + (_size.x / 2);
	rect2.left = _pos.y - (_size.x / 2);
	
	RECT re;
	if (IntersectRect(&re, &rect, &rect2))
	{
		GetObject_()->GetTransform()->position = 
			D3DXVECTOR3(UnAccessBox(position, size, rect2).x, UnAccessBox(position, size, rect2).y, 0);
		//cout << re.left << " " << re.top << " " << re.right << " " << re.bottom << endl;
		return true;
	}
	return false;
}

D3DXVECTOR2 Boxcollider2d::UnAccessBox(D3DXVECTOR2 _pos, D3DXVECTOR2 _size, RECT re)
{
	D3DXVECTOR2 tempPos = GetObject_()->GetComponent<Rigidbody>()->GetMovePosition();
	Transform temp = *GetObject_()->GetComponent<Transform>();
	temp.position = { _pos.x, _pos.y, 0 };
	if (tempPos.x > 0.0f)
	{
		temp.position.x = re.left - (_size.x / 2);
	}
	if (tempPos.x < 0.0f)
	{
		temp.position.x = re.right + (_size.x / 2);
	}
	if (tempPos.y > 0.0f)
	{
		temp.position.y = re.bottom - (_size.y / 2);
	}
	if (tempPos.y < 0.0f)
	{
		temp.position.y = re.top + (_size.y / 2);
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
