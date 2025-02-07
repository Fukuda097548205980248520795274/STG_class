#include "STG.h"

/// <summary>
/// コンストラクタ
/// </summary>
STG::STG()
{
	// ゲームを開始しているかどうか（ゲーム開始フラグ）
	isStartGame_ = false;

	// ゲームをクリアしたどうか（クリアフラグ）
	isGameClear_ = false;

	// ゲームオーバーになったかどうか（ゲームオーバーフラグ）
	isGameOver_ = false;

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
/// ゲームを開始する
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void STG::GameStart(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}

	// Zキーで、ゲームを開始する（ゲーム開始フラグをtrueにする）
	if (!preKeys[DIK_Z] && keys[DIK_Z])
	{
		isStartGame_ = true;
	}
}

/// <summary>
/// スタート画面に戻る
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void STG::BackStart(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}

	// Zキーで、スタート画面に戻る（ゲーム開始、クリア、ゲームオーバーフラグをfalseにする）
	if (!preKeys[DIK_Z] && keys[DIK_Z])
	{
		isStartGame_ = false;
		isGameClear_ = false;
		isGameOver_ = false;
	}
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