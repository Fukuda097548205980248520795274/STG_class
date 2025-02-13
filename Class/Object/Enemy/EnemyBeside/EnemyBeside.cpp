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

	// 復活処理
	respawnTimer_ = 120;

	// 弾
	for (int i = 0; i < kEnemyBulletNum; i++)
	{
		bullet_[i] = new EnemyBullet();
	}

	// フレーム
	frame_ = new Frame();
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

	// 復活処理
	respawnTimer_ = 120;

	// 弾
	for (int i = 0; i < kEnemyBulletNum; i++)
	{
		bullet_[i]->Initialize();
	}

	// フレーム
	frame_->Initialize();
}

/// <summary>
/// 動かす
/// </summary>
void EnemyBeside::Move()
{
	// 出現していない（出現フラグがfalseである）敵は、動かさない
	if (isArrival_ == false)
	{
		return;
	}

	// フレームを進める
	frame_->CountFrame(90);

	// 90フレームで発射する
	if (frame_->GetFrame() == 90)
	{
		for (int i = 0; i < kEnemyBulletNum; i++)
		{
			// すでに発射している（発射フラグがtrueである）弾は、発射しない
			if (bullet_[i]->GetIsShot())
			{
				continue;
			}

			// 発射する
			bullet_[i]->Shot(pos_);

			break;
		}
		
		// フレームを初期化する
		frame_->Initialize();
	}


	// 動かす
	pos_->x_ += vel_->x_;

	// 画面端に触れたら、反転する
	if (pos_->x_ + radius_ > static_cast<float>(kScreenWidth) || pos_->x_ - radius_ < 0.0f)
	{
		vel_->x_ *= -1.0f;
	}
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