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
/// 動かす
/// </summary>
void Enemies::Move()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy_[i]->Move();
	}
}

/// <summary>
/// 描画する
/// </summary>
void Enemies::Draw()
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy_[i]->Draw();
	}
}