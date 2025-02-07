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
	/// 描画する
	/// </summary>
	void Draw() override;
};

