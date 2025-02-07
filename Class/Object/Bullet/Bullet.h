#pragma once
#include "./Class/Object/Object.h"

class Bullet : public Object
{
public:

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	// 発射しているかどうか（発射フラグ）
	int isShot_;
};