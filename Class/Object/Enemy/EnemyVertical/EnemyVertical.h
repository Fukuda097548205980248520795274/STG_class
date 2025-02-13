#pragma once
#include "./Class/Object/Enemy/Enemy.h"

class EnemyVertical : public Enemy
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyVertical();

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 動かす
	/// </summary>
	void Move() override;

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};