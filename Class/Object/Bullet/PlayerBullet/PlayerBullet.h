#pragma once
#include "./Class/Object/Bullet/Bullet.h"

class PlayerBullet : public Bullet
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerBullet();

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize() override;
	
	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};

