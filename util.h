#pragma once
#include "pch.h"

void setTextColor(int colorType) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorType);
}
