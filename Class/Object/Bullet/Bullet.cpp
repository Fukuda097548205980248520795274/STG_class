#include "Bullet.h"

/// <summary>
/// デストラクタ
/// </summary>
Bullet::~Bullet()
{
	// 位置
	delete pos_;

	// 移動速度
	delete vel_;
}

/// <summary>
/// 初期化する
/// </summary>
void Bullet::Initialize()
{

}

/// <summary>
/// 発射する
/// </summary>
/// <param name="pos">位置</param>
void Bullet::Shot(const Vector* pos)
{
	// null を探す
	if (pos == nullptr)
	{
		return;
	}

	// すでに発射している（発射フラグがtrueである）ときは、発射しない
	if (isShot_)
	{
		return;
	}

	// 発射する（発射フラグをtrueにする）
	isShot_ = true;

	// 位置
	this->pos_->x_ = pos->x_;
	this->pos_->y_ = pos->y_;
}

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

/// <summary>
/// 弾を消す
/// </summary>
void Bullet::Kill()
{
	// すでに消えている（発射フラグがfalseである）弾は消さない
	if (isShot_ == false)
	{
		return;
	}

	// 弾を消す（発射フラグをfalseにする）
	isShot_ = false;
}

/// <summary>
/// 描画する
/// </summary>
void Bullet::Draw()
{

}