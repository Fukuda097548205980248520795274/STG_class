#pragma once
#include "./Class/Vector/Vector.h"

class Object
{
protected:

	// 位置
	Vector* pos_;

	// 移動速度
	Vector* vel_;

	// 図形の半径
	float radius_;
};