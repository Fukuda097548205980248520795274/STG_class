#pragma once
#include "./Class/Object/Object.h"

class Bullet : public Object
{
public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();

	// Getter
	int GetIsShot() { return isShot_; }

	// 初期化する
	virtual void Initialize();

	/// <summary>
	/// 発射する
	/// </summary>
	/// <param name="pos">位置</param>
	void Shot(const Vector* pos);

	/// <summary>
	/// 動かす
	/// </summary>
	void Move();

	/// <summary>
	/// 弾を消す
	/// </summary>
	void Kill();

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();


protected:

	// 発射しているかどうか（発射フラグ）
	int isShot_;
};