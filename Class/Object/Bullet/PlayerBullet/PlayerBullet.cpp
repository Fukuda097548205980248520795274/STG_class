#include "PlayerBullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerBullet::PlayerBullet()
{
	// 位置
	pos_ = new Vector(0.0f, 0.0f);

	// 移動速度
	vel_ = new Vector(0.0f, -8.0f);

	// 図形の半径
	radius_ = 4.0f;

	// 発射しているかどうか（発射フラグ）
	isShot_ = false;
}

/// <summary>
/// 描画する
/// </summary>
void PlayerBullet::Draw()
{
	// 発射してない（発射フラグがfalseである）ときは、描画しない
	if (isShot_ == false)
	{
		return;
	}

	// プレイヤーの弾
	Novice::DrawEllipse
	(
		static_cast<int>(pos_->x_), static_cast<int>(pos_->y_),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, 0xFFFFFFFF, kFillModeSolid
	);
}