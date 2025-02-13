#include "Enemies.h"

/// <summary>
/// コンストラクタ
/// </summary>
Enemies::Enemies()
{
	// 横に動く敵
	enemy_[0] = new EnemyBeside();

	// 縦に動く敵
	enemy_[1] = new EnemyVertical();
}

/// <summary>
/// デストラクタ
/// </summary>
Enemies::~Enemies()
{
	// 敵
	for (int i = 0; i < kEnemyNum; i++)
	{
		delete enemy_[i];
	}
}

/// <summary>
/// 初期化する
/// </summary>
void Enemies::Initialize()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy_[i]->Initialize();
	}
}

/// <summary>
/// 出現させる
/// </summary>
void Enemies::Arrival()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy_[i]->Arrival();
	}
}

/// <summary>
/// 更新処理
/// </summary>
void Enemies::Update()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		// 復活処理
		enemy_[i]->Respawn();

		// 動かす
		enemy_[i]->Move();

		// 弾の更新処理
		enemy_[i]->BulletUpdate();
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Enemies::Draw()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		// 敵
		enemy_[i]->Draw();

		// 弾の描画処理
		enemy_[i]->BulletDraw();
	}
}