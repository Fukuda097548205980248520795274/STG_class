#pragma once
#include "./Class/Object/Object.h"

class Bullet : public Object
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();

	// Setter
	void SetPos(const Vector* pos) { this->pos_->x_ = pos->x_; this->pos_->y_ = pos->y_; }

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();

	// 発射しているかどうか（発射フラグ）
	int isShot_;
};