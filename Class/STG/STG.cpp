#include "STG.h"

/// <summary>
/// コンストラクタ
/// </summary>
STG::STG()
{
	// プレイヤー
	player_ = new Player();
}

/// <summary>
/// デストラクタ
/// </summary>
STG::~STG()
{
	// プレイヤー
	delete player_;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void STG::Update(const char* keys, const char* preKeys)
{
	/*   プレイヤー   */

	// 移動操作
	player_->Move(keys, preKeys);

	// 発射する
	player_->Shot(keys, preKeys);

	// 弾の更新処理
	player_->BulletUpdate();
}

/// <summary>
/// 描画処理
/// </summary>
void STG::Draw()
{
	/*   プレイヤー   */

	// 自機
	player_->Draw();

	// 弾
	player_->BulletDraw();
}