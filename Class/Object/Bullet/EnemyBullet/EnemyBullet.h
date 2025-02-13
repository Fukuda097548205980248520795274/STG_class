#pragma once
#include "./Class/Object/Bullet/Bullet.h"

class EnemyBullet : public Bullet
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	EnemyBullet();

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};