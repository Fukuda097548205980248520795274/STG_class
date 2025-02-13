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

	// 弾
	for (int i = 0; i < kEnemyBulletNum; i++)
	{
		delete bullet_[i];
	}

	// フレーム
	delete frame_;
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
/// 復活させる
/// </summary>
void Enemy::Respawn()
{
	// すでに出現している（出現フラグがtrueである）敵は、処理をしない
	if (isArrival_)
	{
		return;
	}

	// 復活処理を進める
	respawnTimer_--;

	// 処理が終了したら復活させる（復活フラグをtrueにする）
	if (respawnTimer_ <= 0)
	{
		isArrival_ = true;

		// 復活処理を初期化する
		respawnTimer_ = 120;
	}
}

/// <summary>
/// 動かす
/// </summary>
void Enemy::Move()
{

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

/// <summary>
/// 弾の更新処理
/// </summary>
void Enemy::BulletUpdate()
{
	for (int i = 0; i < kEnemyBulletNum; i++)
	{
		bullet_[i]->Move();
	}
}

/// <summary>
/// 弾の描画処理
/// </summary>
void Enemy::BulletDraw()
{
	for (int i = 0; i < kEnemyBulletNum; i++)
	{
		bullet_[i]->Draw();
	}
}