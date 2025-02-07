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

	// 敵
	enemies_ = new Enemies();
}

/// <summary>
/// デストラクタ
/// </summary>
STG::~STG()
{
	// プレイヤー
	delete player_;

	// 敵
	delete enemies_;
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

		// 敵を出現させる
		enemies_->Arrival();
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

	// Zキーで、スタート画面に戻る（初期化する）
	if (!preKeys[DIK_Z] && keys[DIK_Z])
	{
		// ゲームを開始しているかどうか（ゲーム開始フラグ）
		isStartGame_ = false;

		// ゲームをクリアしたどうか（クリアフラグ）
		isGameClear_ = false;

		// ゲームオーバーになったかどうか（ゲームオーバーフラグ）
		isGameOver_ = false;

		// プレイヤー
		player_->Initialize();

		// 敵
		enemies_->Initialize();
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void STG::Update(const char* keys, const char* preKeys)
{
	// ゲームが開始するまで（ゲームフラグがfalseのままだと）、ゲームは動かない
	if (isStartGame_ == false)
	{
		return;
	}


	/*   プレイヤー   */

	// 移動操作
	player_->Move(keys, preKeys);

	// 発射する
	player_->Shot(keys, preKeys);

	// 弾の更新処理
	player_->BulletUpdate();


	/*   敵   */

	// 敵を動かす
	enemies_->Move();


	/*   当たり判定   */

	// プレイヤーの弾 と 敵
	for (int i = 0; i < kBulletNum; i++)
	{
		if (player_->bullets_->bullet_[i]->GetIsShot())
		{
			for (int j = 0; j < kEnemyNum; j++)
			{
				if (enemies_->enemy_[j]->GetIsArrival())
				{
					// 当たると、敵と弾が消える（出現、発射フラグがfalseになる）
					if (powf(player_->bullets_->bullet_[i]->GetRadius() + enemies_->enemy_[j]->GetRadius(), 2) >=
						powf(enemies_->enemy_[j]->GetPosX() - player_->bullets_->bullet_[i]->GetPosX(), 2) +
						powf(enemies_->enemy_[j]->GetPosY() - player_->bullets_->bullet_[i]->GetPosY(), 2))
					{
						player_->bullets_->bullet_[i]->Kill();
						enemies_->enemy_[j]->Kill();
					}
				}
			}
		}
	}

	// プレイヤー と 敵
	if (player_->GetIsArrival())
	{
		for (int i = 0; i < kEnemyNum; i++)
		{
			if (enemies_->enemy_[i]->GetIsArrival())
			{
				// 当たると、プレイヤーがやられる（出現フラグがfalseになる）
				if (powf(player_->GetRadius() + enemies_->enemy_[i]->GetRadius(), 2) >=
					powf(enemies_->enemy_[i]->GetPosX() - player_->GetPosX(), 2) +
					powf(enemies_->enemy_[i]->GetPosY() - player_->GetPosY(), 2))
				{
					player_->Kill();
				}
			}
		}
	}


	/*   クリア条件   */

	// 敵をすべて倒す（出現フラグをfalseのとき）
	for (int i = 0; i < kEnemyNum; i++)
	{
		// 倒せていない（出現フラグがtrueである）敵がいたら、処理を中断する
		if (enemies_->enemy_[i]->GetIsArrival())
		{
			break;
		}

		if (i >= kEnemyNum - 1)
		{
			// クリア（クリアフラグがtrueになる）
			isGameClear_ = true;
		}
	}

	/*   ゲームオーバー条件   */

	// プレイヤーがやられる（出現フラグがfalseのとき）
	if (player_->GetIsArrival() == false)
	{
		// ゲームオーバー（ゲームオーバーフラグがtrueになる）
		isGameOver_ = true;
	}
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

	// 敵
	enemies_->Draw();
}