#include "stdafx.h"
#include "Tile.h"


bool CTile::IsWall()
{
	for (int i = 0; i < DATAMANAGER->GetWallProcessing().size(); i++)
	{
		if (DATAMANAGER->GetWallProcessing()[i] == tileName)
			return false;
	}
	return true;
}

void CTile::Init()
{
	AddComponent<TexVertexRenderer>();
	m_TexRenderer = GetComponent<TexVertexRenderer>();
	m_TexRenderer->AddImage(tileName, route);

	if (IsWall())
	{
		AddComponent<Boxcollider2d>();
		m_BoxCollider = GetComponent<Boxcollider2d>();
		m_BoxCollider->SetSize({128, 128});
	}
}

void CTile::Update()
{
}

void CTile::Render()
{
}

void CTile::Release()
{
}

CTile::CTile(string name, TCHAR *route, D3DXVECTOR2 point)
{
	_tcscpy(this->route, route);
	tileName = name;
	transform->position.x = point.x;
	transform->position.y = point.y;
}


CTile::~CTile()
{
}
