#pragma once
#include <Novice.h>
#include "Constant.h"
#include "./Class/Vector/Vector.h"

class Object
{
public:

	// Getter
	float GetPosX() { return pos_->x_; }
	float GetPosY() { return pos_->y_; }
	float GetRadius() { return radius_; }

protected:

	// 位置
	Vector* pos_;

	// 移動速度
	Vector* vel_;

	// 図形の半径
	float radius_;
};