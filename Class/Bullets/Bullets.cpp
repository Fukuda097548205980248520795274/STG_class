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