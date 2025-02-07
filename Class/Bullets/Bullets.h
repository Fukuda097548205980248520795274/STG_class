#pragma once
#include "./Class/Object/Bullet/Bullet.h"

class Bullets
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullets();

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize();

	/// <summary>
	/// クールタイムをカウントする
	/// </summary>
	void CountCoolTime();

	/// <summary>
	/// 発射する
	/// </summary>
	/// <param name="pos">位置</param>
	virtual void Shot(const Vector* pos);

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw();

	// 弾
	Bullet* bullet_[kBulletNum];


protected:

	// クールタイム
	int coolTime_;
};