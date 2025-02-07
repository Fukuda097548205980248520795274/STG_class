#pragma once
#include "./Class/Object/Enemy/Enemy.h"

class EnemyBeside : public Enemy
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyBeside();

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};