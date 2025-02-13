#pragma once
#include "./Class/Object/Object.h"
#include "./Class/Object/Bullet/PlayerBullet/PlayerBullet.h"

class Player : public Object
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	// Getter
	int GetIsArrival() { return isArrival_; }

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize();

	/// <summary>
	/// 移動させる
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押したキー</param>
	void Move(const char* keys, const char* preKeys);

	/// <summary>
	/// 弾を発射する
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押したキー</param>
	void Shot(const char* keys, const char* preKeys);

	/// <summary>
	/// プレイヤーを消す
	/// </summary>
	void Kill();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw();

	/// <summary>
	/// 弾の更新処理
	/// </summary>
	void BulletUpdate();

	/// <summary>
	/// 弾の描画処理
	/// </summary>
	void BulletDraw();

	// 弾
	Bullet* bullet_[kPlayerBulletNum];


private:

	// 出現しているかどうか（出現フラグ）
	int isArrival_;

	// 弾のクールタイム
	int bulletCoolTime_;
};