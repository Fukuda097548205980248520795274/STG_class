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

/// <summary>
/// 発射する
/// </summary>
/// <param name="pos">位置</param>
void PlayerBullets::Shot(const Vector* pos)
{
	// null を探す
	if (pos == nullptr)
	{
		return;
	}

	// クールタイムが完了するまで、発射しない
	if (coolTime_ > 0)
	{
		return;
	}

	for (int i = 0; i < kBulletNum; i++)
	{
		// すでに発射している（発射フラグがtrueである）弾は、発射しない
		if (bullet_[i]->isShot_)
		{
			continue;
		}

		// クールタイムを開始する
		coolTime_ = kStartPlayerBulletCoolTime;

		// 発射する（発射フラグがtrueになる）
		bullet_[i]->isShot_ = true;

		// 入力した位置から
		bullet_[i]->SetPos(pos);

		break;
	}
}