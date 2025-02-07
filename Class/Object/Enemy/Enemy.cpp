#include "Enemy.h"

/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy()
{
	// 位置
	delete pos_;

	// 移動速度
	delete vel_;
}

/// <summary>
/// 初期化する
/// </summary>
void Enemy::Initialize()
{

}

/// <summary>
/// 出現させる
/// </summary>
void Enemy::Arrival()
{
	// すでに出現している（出現フラグがtrue）であるときは、出現させない
	if (isArrival_)
	{
		return;
	}

	// 出現させる（出現フラグをtrueにする）
	isArrival_ = true;
}

/// <summary>
/// 動かす
/// </summary>
void Enemy::Move()
{
	// 出現していない（出現フラグがfalseである）敵は、動かさない
	if (isArrival_ == false)
	{
		return;
	}

	// 動かす
	pos_->x_ += vel_->x_;
	pos_->y_ += vel_->y_;

	// 画面端に触れたら、反転する
	if (pos_->x_ + radius_ > static_cast<float>(kScreenWidth) || pos_->x_ - radius_ < 0.0f)
	{
		vel_->x_ *= -1.0f;
	}

	if (pos_->y_ + radius_ > static_cast<float>(kScreenHeight) || pos_->y_ - radius_ < 0.0f)
	{
		vel_->y_ *= -1.0f;
	}
}

/// <summary>
/// 敵を消す
/// </summary>
void Enemy::Kill()
{
	// すでに消えている（出現フラグがfalseである）敵は、消さない
	if (isArrival_ == false)
	{
		return;
	}

	// 敵を消す（出現フラグがfalseになる）
	isArrival_ = false;
}

/// <summary>
/// 描画する
/// </summary>
void Enemy::Draw()
{

}