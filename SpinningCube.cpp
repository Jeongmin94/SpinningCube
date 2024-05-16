#pragma once

#include "pch.h"
#include "timer.h"
#include "util.h"

#include "Cube.h"

int width = 140;
int height = 40;

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

int main()
{
	char buf[256];
	sprintf_s(buf, "mode con: lines=%d cols=%d", height+1, width+1);
	system(buf);

	Options option;
	option.d = 1;
	option.scailFactor = 15.0f;
	option.screenHeight = height;
	option.screenWidth = width;
	option.distanceFromEye = 50;

	CONSOLE_CURSOR_INFO info{ 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	Timer t;
	int maxSize = width * height;

	vector<Cube> cubes;

	Cube cube0(20, 20, option);
	cubes.push_back(cube0);

	ColorType colors1[6] = { ColorType::GREEN, ColorType::DarkGray, ColorType::SkyBlue, ColorType::BLUE, ColorType::DarkRed, ColorType::PURPLE };
	option.offsetX = 20;
	option.offsetY = 10;
	for (int i = 0; i < 6; i++) { option.colors[i] = colors1[i]; }
	Cube cube1(15, 15, option);
	cubes.push_back(cube1);

	while (true)
	{
		t.update();

		vector<pixel> pixels(maxSize);

		for (int i = 0; i < cubes.size(); i++)
			cubes[i].rotate(angleX, angleY, angleZ, pixels);

		COORD coord{ 0, 0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		for (int i = 0; i < height * width; i++) {
			setTextColor((int)pixels[i].color);
			if (i % width == 0) {
				cout << '\n';
			}
			else {
				cout << pixels[i].c;
			}
		}

		angleX += t.dt() * 10.0f;
		angleY += t.dt() * 20.0f;
		angleZ += t.dt() * 30.0f;
	}

	return 0;
}
