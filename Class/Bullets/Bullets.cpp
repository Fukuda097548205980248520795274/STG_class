#include "Bullets.h"

/// <summary>
/// デストラクタ
/// </summary>
Bullets::~Bullets()
{
	// 弾
	for (int i = 0; i < kBulletNum; i++)
	{
		delete bullet_[i];
	}
}

/// <summary>
/// 初期化する
/// </summary>
void Bullets::Initialize()
{
	// 弾
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i]->Initialize();
	}
}

/// <summary>
/// クールタイムをカウントする
/// </summary>
void Bullets::CountCoolTime()
{
	if (coolTime_ > 0)
	{
		coolTime_--;
	}
}

/// <summary>
/// 発射する
/// </summary>
void Bullets::Shot(const Vector* pos)
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
		if (bullet_[i]->GetIsShot())
		{
			continue;
		}

		// クールタイムを開始する
		coolTime_ = kStartPlayerBulletCoolTime;

		// 発射する
		bullet_[i]->Shot(pos);

		break;
	}
}

/// <summary>
/// 動かす
/// </summary>
void Bullets::Move()
{
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i]->Move();
	}
}

/// <summary>
/// 描画する
/// </summary>
void Bullets::Draw()
{
	for (int i = 0; i < kBulletNum; i++)
	{
		bullet_[i]->Draw();
	}
}