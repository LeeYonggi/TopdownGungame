#include "stdafx.h"
#include "CMaps.h"
#include <string>


void CMaps::Init()
{

}

void CMaps::Update()
{
}

void CMaps::Render()
{
}

void CMaps::Release()
{
}

void CMaps::DataTransform(string str)
{
	string file = "./PNG/Tiles/";
	string route = "./MapFile/" + str;
	
	char cline[1000];
	string line;
	ifstream stream(route);
	
	if (!stream.eof())
	{
		stream.getline(cline, 100);

		line = cline;
		m_Size = GetStreamSize(line);
		while (!stream.eof())
		{
			stream.getline(cline, 100);
			line = cline;
			string name = "";
			D3DXVECTOR2 point = GetStreamPoint(line, &name);

			TCHAR temproute[100];
			string tempfile = file + name;
			if (tempfile == file)
				break;
			_tcscpy_s(temproute, CA2T(tempfile.c_str()));

			point.y = (0 - point.y) * 2 + SCREEN_HEIGHT - 64;
			point.x = point.x * 2 - SCREEN_WIDTH + 64;	

			CTile *tempTile = new CTile(name, temproute, point);
			OBJECTMANAGER->AddObject(OBJ_BACKGROUND, tempTile);
		}
		stream.close();
	}
}

D3DXVECTOR2 CMaps::GetStreamSize(string str)
{
	D3DXVECTOR2 point;
	point.x = 0; point.y = 0;

	string line = str;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == 'X')
		{
			string tempstr = "";
			for (int j = i + 2; ; j++)
			{
				if (line[j] == ',')
					break;
				else
					tempstr = tempstr + line[j];
			}
			point.x = stoi(tempstr);
		}
		else if (line[i] == 'Y')
		{
			string tempstr = "";
			for (int j = i + 2; ; j++)
			{
				if (line[j] == '}')
					break;
				else
					tempstr = tempstr + line[j];
			}
			point.y = stoi(tempstr);
		}
	}
	return point;
}

D3DXVECTOR2 CMaps::GetStreamPoint(string route, string *str)
{
	D3DXVECTOR2 point;
	point.x = 0; point.y = 0;

	string line = route;
	string temp = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ',')
		{
			*str = temp;
			break;
		}
		else
		{
			temp = temp + line[i];
		}
	}
	string pointLine = "";

	for (int i = str->length(); i < line.length(); i++)
	{
		pointLine = pointLine + line[i];
	}
	point = GetStreamSize(pointLine);

	return point;
}

CMaps::CMaps(string maproute)
{
	DataTransform(maproute);
}


CMaps::~CMaps()
{
}
