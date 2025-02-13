#pragma once
#include "./Class/Object/Object.h"
#include "./Class/Object/Bullet/EnemyBullet/EnemyBullet.h"
#include "./Class/Frame/Frame.h"


class Enemy : public Object
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemy();

	// Getter
	int GetIsArrival() { return isArrival_; }

	// Setter
	void SetIsArrivalTrue() { isArrival_ = true; }

	/// <summary>
	/// 初期化する
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 出現させる
	/// </summary>
	void Arrival();

	/// <summary>
	/// 復活させる
	/// </summary>
	void Respawn();

	/// <summary>
	/// 動かす
	/// </summary>
	virtual void Move();

	/// <summary>
	/// 敵を消す
	/// </summary>
	void Kill();

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// 弾の更新処理
	/// </summary>
	void BulletUpdate();

	/// <summary>
	/// 弾の描画処理
	/// </summary>
	void BulletDraw();

	// 弾
	Bullet* bullet_[kEnemyBulletNum];


protected:

	// 出現しているかどうか（出現フラグ）
	int isArrival_;

	// 復活処理
	int respawnTimer_;

	// フレーム
	Frame* frame_;
};