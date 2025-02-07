#pragma once
#include "./Class/Bullets/Bullets.h"
#include "./Class/Object/Bullet/PlayerBullet/PlayerBullet.h"

class PlayerBullets : public Bullets
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	PlayerBullets();

	/// <summary>
	/// 発射する
	/// </summary>
	/// <param name="pos">位置</param>
	void Shot(const Vector* pos) override;
};

