#pragma once
#include "./Class/Object/Object.h"


class Enemy : public Object
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemy();

	// Getter
	int GetIsArrival() { return isArrival_; }

	// Setter
	void SetIsArrivalTrue() { isArrival_ = true; }

	/// <summary>
	/// 初期化する
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 出現させる
	/// </summary>
	void Arrival();

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 敵を消す
	/// </summary>
	void Kill();

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();


protected:

	// 出現しているかどうか（出現フラグ）
	int isArrival_;
};