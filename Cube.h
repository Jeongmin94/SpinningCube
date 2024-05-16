#pragma once

class Cube
{
public:
	Cube(int w, int h, Options _option)
	{
		width = w;
		height = h;
		option = _option;
	}

	void rotate(float angleX, float angleY, float angleZ, vector<pixel>& pixels) const;

private:
	vec3 rotateXYZ(const vec3& v, float angleX, float angleY, float angleZ) const;
	void calculateSurface(const vec3& v, float angleX, float angleY, float angleZ, vector<pixel>& pixels, ColorType color, char output) const;

private:
	static float incr;

	int width;
	int height;

	Options option;
};

