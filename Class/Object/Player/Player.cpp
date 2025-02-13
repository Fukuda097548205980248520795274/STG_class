#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
{
	// 位置
	pos_ = new Vector(static_cast<float>(kScreenWidth / 2), static_cast<float>(kScreenHeight / 2));

	// 移動速度
	vel_ = new Vector(0.0f, 0.0f);

	// 図形の半径
	radius_ = 16.0f;

	// 出現しているかどうか（出現フラグ）
	isArrival_ = true;

	// 弾のクールタイム
	bulletCoolTime_ = 0;

	// 弾
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		bullet_[i] = new PlayerBullet();
	}
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
	// 位置
	delete pos_;

	// 移動速度
	delete vel_;

	// 弾
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		delete bullet_[i];
	}
}

/// <summary>
/// 初期化する
/// </summary>
void Player::Initialize()
{
	// 位置
	pos_->x_ = static_cast<float>(kScreenWidth / 2);
	pos_->y_ = static_cast<float>(kScreenHeight / 2);

	// 移動速度
	vel_->x_ = 0.0f;
	vel_->y_ = 0.0f;

	// 図形の半径
	radius_ = 16.0f;

	// 出現しているかどうか（出現フラグ）
	isArrival_ = true;

	// 弾のクールタイム
	bulletCoolTime_ = 0;

	// 弾
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		bullet_[i]->Initialize();
	}
}

/// <summary>
/// 移動させる
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void Player::Move(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}

	// 出現していない（出現フラグがfalseである）ときは、操作できない
	if (isArrival_ == false)
	{
		return;
	}


	// 移動速度を初期化する
	vel_->x_ = 0.0f;
	vel_->y_ = 0.0f;

	// Wキーで、上に移動する
	if (keys[DIK_W])
	{
		if (pos_->y_ - radius_ > 0.0f)
		{
			vel_->y_ = -kPlayerSpeed;
		}
	}

	// Aキーで、左に移動する
	if (keys[DIK_A])
	{
		if (pos_->x_ - radius_ > 0.0f)
		{
			vel_->x_ = -kPlayerSpeed;
		}
	}

	// Sキーで、下に移動する
	if (keys[DIK_S])
	{
		if (pos_->y_ + radius_ < static_cast<float>(kScreenHeight))
		{
			vel_->y_ = kPlayerSpeed;
		}
	}

	// Dキーで、右に移動する
	if (keys[DIK_D])
	{
		if (pos_->x_ + radius_ < static_cast<float>(kScreenWidth))
		{
			vel_->x_ = kPlayerSpeed;
		}
	}

	// 動かす
	pos_->x_ += vel_->x_;
	pos_->y_ += vel_->y_;
}

/// <summary>
/// 弾を発射する
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void Player::Shot(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}

	// クールタイムを進め、処理を終了する
	if (bulletCoolTime_ > 0)
	{
		bulletCoolTime_--;

		return;
	}

	// Spaceキーで発射する
	if (keys[DIK_SPACE])
	{
		for (int i = 0; i < kPlayerBulletNum; i++)
		{
			// すでに発射している弾は、発射しない
			if (bullet_[i]->GetIsShot())
			{
				continue;
			}

			// クールタイムを開始する
			bulletCoolTime_ = kStartPlayerBulletCoolTime;

			//　発射する
			bullet_[i]->Shot(pos_);

			break;
		}
	}
}

/// <summary>
/// プレイヤーを消す
/// </summary>
void Player::Kill()
{
	// プレイヤーがすでに消えている（出現フラグがfalseである）ときは、消さない
	if (isArrival_ == false)
	{
		return;
	}

	// プレイヤーを消す（出現フラグをfalseにする）
	isArrival_ = false;
}

/// <summary>
/// 描画する
/// </summary>
void Player::Draw()
{
	// 出現していない（出現フラグがfalseである）ときは、描画しない
	if (isArrival_ == false)
	{
		return;
	}

	// プレイヤー
	Novice::DrawEllipse
	(
		static_cast<int>(pos_->x_), static_cast<int>(pos_->y_), 
		static_cast<int>(radius_), static_cast<int>(radius_), 
		0.0f, 0xFFFFFFFF, kFillModeSolid
	);
}

/// <summary>
/// 弾の更新処理
/// </summary>
void Player::BulletUpdate()
{
	// 弾
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		bullet_[i]->Move();
	}
}

/// <summary>
/// 弾の描画処理
/// </summary>
void Player::BulletDraw()
{
	// 弾
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		bullet_[i]->Draw();
	}
}