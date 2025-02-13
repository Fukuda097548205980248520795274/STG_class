#pragma once

class Vector
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	Vector(float x, float y);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Vector();

	// 座標
	float x_;
	float y_;
};