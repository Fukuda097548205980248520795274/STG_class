#pragma once
#include "./Class/Object/Object.h"

class Player : public Object
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 移動操作
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押したキー</param>
	void Move(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw();

	// 出現しているかどうか（出現フラグ）
	int isArrival_;
};