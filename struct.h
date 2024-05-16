#pragma once

struct vec3
{
	float x, y, z;

	vec3() : x(0.0f), y(0.0f), z(0.0f) {};
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
	vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {};

	vec3& operator=(const vec3& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}
};

enum class ColorType {
	BLACK,  	//0
	DarkBLUE,	//1
	DarkGreen,	//2
	darkSkyBlue,    //3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE,		//15

	END,
};

struct pixel
{
	char c = '.';
	float depth = 0.0f;
	ColorType color = ColorType::WHITE;
};

struct Options
{
	int distanceFromEye = 0;
	float scailFactor = 1.0f;
	int d = 1;
	int screenWidth = 0;
	int screenHeight = 0;

	int offsetX = 0;
	int offsetY = 0;

	ColorType colors[6] = {
		ColorType::RED,
		ColorType::BLUE,
		ColorType::DarkBLUE,
		ColorType::DarkPurple,
		ColorType::GREEN,
		ColorType::YELLOW,
	};
};
