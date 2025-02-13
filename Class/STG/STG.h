#pragma once
#include <math.h>
#include "./Class/Object/Player/Player.h"
#include "./Class/Enemies/Enemies.h"

class STG
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	STG();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~STG();

	// Getter
	int GetIsGameStart() { return isStartGame_; }
	int GetIsGameClear() { return isGameClear_; }
	int GetIsGameOver() { return isGameOver_; }

	/// <summary>
	/// ゲームを開始させる
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押したキー</param>
	void GameStart(const char* keys, const char* preKeys);

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押したキー</param>
	void Update(const char* keys , const char* preKeys);

	/// <summary>
	/// スタート画面に戻る
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押した</param>
	void BackStart(const char* keys, const char* preKeys);
	
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	// 倒した敵の数
	static int countKilledEnemy;


private:

	/// <summary>
	/// プレイヤーの弾と敵の当たり判定
	/// </summary>
	void PlayerBulletHitsEnemy();

	/// <summary>
	/// 敵がプレイヤーに当たる
	/// </summary>
	void EnemyHitsPlayer();

	/// <summary>
	/// 敵の弾がプレイヤーに当たる
	/// </summary>
	void EnemyBulletHitsPlayer();

	// ゲームが開始したかどうか（ゲーム開始フラグ）
	int isStartGame_;

	// ゲームをクリアしたかどうか（クリアフラグ）
	int isGameClear_;

	// ゲームオーバーになったかどうか（ゲームオーバーフラグ）
	int isGameOver_;

	// プレイヤー
	Player* player_;

	// 敵
	Enemies* enemies_;
};

