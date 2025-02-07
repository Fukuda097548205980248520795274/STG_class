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

	// Getter
	float GetPosX() { return x_; }
	float GetPosY() { return y_; }


private:

	float x_;
	float y_;
};