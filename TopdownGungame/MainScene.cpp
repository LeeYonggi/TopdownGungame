#include "stdafx.h"
#include "MainScene.h"


void MainScene::Init()
{
	Camera01 *camera = dynamic_cast<Camera01*>(OBJECTMANAGER->AddObject(OBJ_CAMERA, new Camera01));
	OBJECTMANAGER->AddObject(OBJ_CHARACTER, new Character(camera));
	OBJECTMANAGER->AddObject(OBJ_BACKGROUND, new CMaps("test.MSF"));
}

void MainScene::Update()
{
	

}

void MainScene::Render()
{
	//char ctr[10];
	//sprintf(ctr, "%d", SOUNDMANAGER->Getsecond());
	//TEXTMANAGER->Drawtext(ctr, { 640, 360 }, 0, Color(255, 255, 255, 255));
	//cout << ctr << endl;
}

void MainScene::Release()
{
	OBJECTMANAGER->Release();
}

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}
