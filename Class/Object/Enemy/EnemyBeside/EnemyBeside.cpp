#include "EnemyBeside.h"

/// <summary>
/// コンストラクタ
/// </summary>
EnemyBeside::EnemyBeside()
{
	// 位置
	pos_ = new Vector(static_cast<float>(kScreenWidth / 2), static_cast<float>(kScreenHeight / 2 - (kScreenHeight / 2) / 2));

	// 移動速度
	vel_ = new Vector(4.0f, 0.0f);

	// 図形の半径
	radius_ = 16.0f;

	// 出現しているかどうか（出現フラグ）
	isArrival_ = false;
}

/// <summary>
/// 初期化する
/// </summary>
void EnemyBeside::Initialize()
{
	// 位置
	pos_->x_ = static_cast<float>(kScreenWidth / 2);
	pos_->y_ = static_cast<float>(kScreenHeight / 2 - (kScreenHeight / 2) / 2);

	// 移動速度
	vel_->x_ = 4.0f;
	vel_->y_ = 0.0f;

	// 図形の半径
	radius_ = 16.0f;

	// 出現しているかどうか（出現フラグ）
	isArrival_ = false;
}

/// <summary>
/// 描画する
/// </summary>
void EnemyBeside::Draw()
{
	// 出現していない（出現フラグがfalseである）ときは、描画しない
	if (isArrival_ == false)
	{
		return;
	}

	// 敵
	Novice::DrawEllipse
	(
		static_cast<int>(pos_->x_), static_cast<int>(pos_->y_),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, 0xFF0000FF, kFillModeSolid
	);
}