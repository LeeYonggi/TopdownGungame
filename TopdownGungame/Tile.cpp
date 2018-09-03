#include "stdafx.h"
#include "Tile.h"


void CTile::Init()
{
	AddComponent<TexVertexRenderer>();
	m_TexRenderer = GetComponent<TexVertexRenderer>();
	m_TexRenderer->AddImage(tileName, route);
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
