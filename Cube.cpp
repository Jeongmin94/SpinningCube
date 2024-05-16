#include "pch.h"
#include "Cube.h"

float Cube::incr = 0.1f;

void Cube::rotate(float angleX, float angleY, float angleZ, vector<pixel>& pixels) const
{
	for (float x = -width; x < width; x += incr)
	{
		for (float y = -height; y < height; y += incr) {

			calculateSurface(vec3(x, y, -width), angleX, angleY, angleZ, pixels, ColorType::RED, '0');
			calculateSurface(vec3(x, y, width), angleX, angleY, angleZ, pixels, ColorType::BLUE, '1');

			calculateSurface(vec3(width, x, y), angleX, angleY, angleZ, pixels, ColorType::GREEN, '2');
			calculateSurface(vec3(-width, x, y), angleX, angleY, angleZ, pixels, ColorType::GRAY, '3');

			calculateSurface(vec3(x, width, y), angleX, angleY, angleZ, pixels, ColorType::DarkYellow, '4');
			calculateSurface(vec3(x, -width, y), angleX, angleY, angleZ, pixels, ColorType::DarkPurple, '5');

		}
	}
}

vec3 Cube::rotateXYZ(const vec3& v, float angleX, float angleY, float angleZ) const
{
	vec3 ret(v);
	ret = rotationAboutX(ret, angleX);
	ret = rotationAboutY(ret, angleY);
	ret = rotationAboutZ(ret, angleZ);

	return ret;
}

void Cube::calculateSurface(const vec3& v, float angleX, float angleY, float angleZ, vector<pixel>& pixels, ColorType color, char output) const
{
	vec3 tmp(v);
	tmp = rotateXYZ(tmp, angleX, angleY, angleZ);

	// ���� ���� �� ������ �Ÿ� d = 1 �� ����
	float depth = 1.0f / (tmp.z + option.distanceFromEye);

	// �ֿܼ��� ���ΰ� ������ �� ��
	int px = (int)(option.screenWidth / 2 + option.scailFactor * tmp.x * depth * 2);
	int py = (int)(option.screenHeight / 2 + option.scailFactor * tmp.y * depth);

	int idx = option.screenWidth * py + px;

	if (0 <= idx && idx < option.screenHeight * option.screenWidth) {
		if (pixels[idx].depth <= depth)
		{
			pixels[idx].depth = depth;
			pixels[idx].color = color;
			pixels[idx].c = output;
		}
	}
}
