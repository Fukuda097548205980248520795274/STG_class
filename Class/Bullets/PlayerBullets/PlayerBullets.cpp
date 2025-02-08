#include "PlayerBullets.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerBullets::PlayerBullets()
{
	// プレイヤーの弾
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i] = new PlayerBullet();
	}

	// クールタイム
	coolTime_ = 0;
}