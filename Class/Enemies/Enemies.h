#pragma once
#include "./Class/Object/Enemy/EnemyBeside/EnemyBeside.h"
#include "./Class/Object/Enemy/EnemyVertical/EnemyVertical.h"

class Enemies
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Enemies();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemies();

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize();

	/// <summary>
	/// 出現させる
	/// </summary>
	void Arrival();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw();

	// 敵
	Enemy* enemy_[kEnemyNum];
};