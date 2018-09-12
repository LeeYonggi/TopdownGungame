#include "stdafx.h"
#include "DataManager.h"


Texture *DataManager::AddTexture(string str, LPCWSTR route)
{
	auto iter = m_TextureData.find(str);
	if (iter != m_TextureData.end()) return iter->second;

	Texture *texture = new Texture;
	D3DXCreateTextureFromFileEx
	(
		DEVICE,
		route,
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT,
		0, &texture->info, nullptr, &texture->_tex
	);
	m_TextureData.insert(make_pair(str, texture));
	return texture;
}

Texture * DataManager::GetTexture(string str)
{
	auto iter = m_TextureData.find(str);
	if (iter != m_TextureData.end()) return iter->second;
	return nullptr;
}

vector<Texture*>* DataManager::AddanimeTexture(string str, LPCWSTR route, int low, int high)
{
	auto iter = m_animeData.find(str);
	if (iter != m_animeData.end()) return iter->second;
	vector<Texture*>* m_anime = new vector<Texture*>;
	for (int i = low; i <= high; i++)
	{
		char ctr[10];
		sprintf(ctr, "%d", i);
		TCHAR ttr[128] = L"";
		wsprintf(ttr, route, i);
		m_anime->push_back(AddTexture(str + ctr, ttr));
	}
	return m_anime;
}

vector<Texture*>* DataManager::GetanimeTexture(string str)
{
	auto iter = m_animeData.find(str);
	if (iter != m_animeData.end()) return iter->second;
	return nullptr;
}

vector<string> DataManager::GetWallProcessing(WALL_PROCESS state)
{
	auto iter = m_WallProcessing.find(state);

	return *iter->second;
}

DataManager::DataManager()
{
	_vertex.push_back(NormalTexVertex(D3DXVECTOR3(1, 1, 0), D3DXVECTOR3(0, 0, -1), D3DXVECTOR2(1, 0)));
	_vertex.push_back(NormalTexVertex(D3DXVECTOR3(1, -1, 0), D3DXVECTOR3(0, 0, -1), D3DXVECTOR2(1, 1)));
	_vertex.push_back(NormalTexVertex(D3DXVECTOR3(-1, -1, 0), D3DXVECTOR3(0, 0, -1), D3DXVECTOR2(0, 1)));
	_vertex.push_back(NormalTexVertex(D3DXVECTOR3(-1, -1, 0), D3DXVECTOR3(0, 0, -1), D3DXVECTOR2(0, 1)));
	_vertex.push_back(NormalTexVertex(D3DXVECTOR3(-1, 1, 0), D3DXVECTOR3(0, 0, -1), D3DXVECTOR2(0, 0)));
	_vertex.push_back(NormalTexVertex(D3DXVECTOR3(1, 1, 0), D3DXVECTOR3(0, 0, -1), D3DXVECTOR2(1, 0)));

	for (int i = 0; i < WALL_PROCESS_SIZE; i++)
		m_WallProcessing.insert(make_pair(WALL_PROCESS(i), new vector<string>));
	auto iter = m_WallProcessing.find(WALL_PROCESS::WALL_FLOOR);
	iter->second->push_back("tile_100.png");
	iter->second->push_back("tile_101.png");
	iter->second->push_back("tile_154.png");
	iter->second->push_back("tile_468.png");

	iter = m_WallProcessing.find(WALL_PROCESS::WALL_MIRROR);
	iter->second->push_back("tile_433.png");
	iter->second->push_back("tile_434.png");
	iter->second->push_back("tile_435.png");
	iter->second->push_back("tile_436.png");
	iter->second->push_back("tile_437.png");
	iter->second->push_back("tile_438.png");
	iter->second->push_back("tile_460.png");
	iter->second->push_back("tile_461.png");
	iter->second->push_back("tile_462.png");
	iter->second->push_back("tile_463.png");
	iter->second->push_back("tile_464.png");
	iter->second->push_back("tile_465.png");
}


DataManager::~DataManager()
{
	for (auto iter : m_TextureData)
	{
		SAFE_RELEASE(iter.second->_tex);
		SAFE_DELETE(iter.second);
	}
	m_TextureData.clear();
	for (auto iter : m_animeData)
	{
		for (auto _iter : *(iter.second))
		{
			SAFE_RELEASE(_iter->_tex);
			SAFE_DELETE(_iter);
		}
	}
	m_animeData.clear();
}
