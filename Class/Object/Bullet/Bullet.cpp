#include "Bullet.h"

/// <summary>
/// 動かす
/// </summary>
void Bullet::Move()
{
	// 発射していない（発射フラグがfalseである）ときは動かさない
	if (isShot_ == false)
	{
		return;
	}

	// 動かす
	pos_->x_ += vel_->x_;
	pos_->y_ += vel_->y_;

	// 画面外に出たら、消える（発射フラグがfalseになる）
	if (pos_->x_ + radius_ < 0.0f || pos_->x_ - radius_ > static_cast<float>(kScreenWidth) ||
		pos_->y_ + radius_ < 0.0f || pos_->y_ - radius_ > static_cast<float>(kScreenHeight))
	{
		isShot_ = false;
	}
}