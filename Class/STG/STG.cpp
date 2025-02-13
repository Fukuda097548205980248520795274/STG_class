#include "STG.h"

// 倒した敵の数
int STG::countKilledEnemy = 0;

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

		// 倒した敵の数
		STG::countKilledEnemy = 0;
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

	// 敵の更新処理
	enemies_->Update();


	/*   当たり判定   */

	// プレイヤーの弾を敵に当てると、敵を倒すことができる
	PlayerBulletHitsEnemy();

	// 敵がプレイヤーに当たると、プレイヤーがやられる
	EnemyHitsPlayer();

	// 敵の弾がプレイヤーに当たると、プレイヤーがやられる
	EnemyBulletHitsPlayer();



	/*   クリア条件   */

	// 敵を5回倒すとクリア（クリアフラグがtrueになる）
	if (STG::countKilledEnemy >= 5)
	{
		isGameClear_ = true;
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


	/*   敵   */

	// 敵
	enemies_->Draw();
}

/// <summary>
/// プレイヤーの弾が敵に当たる
/// </summary>
void STG::PlayerBulletHitsEnemy()
{
	for (int i = 0; i < kPlayerBulletNum; i++)
	{
		// 発射していない（発射フラグがfalseである）弾は当たらない
		if (player_->bullet_[i]->GetIsShot() == false)
		{
			continue;
		}

		for (int j = 0; j < kEnemyNum; j++)
		{
			// 出現していない（出現フラグがfalseである）敵には当たらない
			if (enemies_->enemy_[j]->GetIsArrival() == false)
			{
				continue;
			}

			// 当たると、敵と弾が消える（出現、発射フラグがfalseになる）
			if (powf(player_->bullet_[i]->GetRadius() + enemies_->enemy_[j]->GetRadius(), 2) >=
				powf(enemies_->enemy_[j]->GetPosX() - player_->bullet_[i]->GetPosX(), 2) +
				powf(enemies_->enemy_[j]->GetPosY() - player_->bullet_[i]->GetPosY(), 2))
			{
				player_->bullet_[i]->Kill();
				enemies_->enemy_[j]->Kill();

				// 倒した敵をカウントする
				STG::countKilledEnemy++;
			}
		}
	}
}

/// <summary>
/// 敵がプレイヤーに当たる
/// </summary>
void STG::EnemyHitsPlayer()
{
	if (player_->GetIsArrival())
	{
		for (int i = 0; i < kEnemyNum; i++)
		{
			// 出現していない（出現フラグがfalseである）敵は、当たらない
			if (enemies_->enemy_[i]->GetIsArrival() == false)
			{
				continue;
			}

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

/// <summary>
/// 敵の弾がプレイヤーに当たる
/// </summary>
void STG::EnemyBulletHitsPlayer()
{
	if (player_->GetIsArrival())
	{
		for (int i = 0; i < kEnemyNum; i++)
		{
			// 出現していない（出現フラグがfalseである）敵には当たらない
			if (enemies_->enemy_[i]->GetIsArrival() == false)
			{
				continue;
			}

			for (int j = 0; j < kEnemyBulletNum; j++)
			{
				// 発射していない（発射フラグがfalseである）弾には当たらない
				if (enemies_->enemy_[i]->bullet_[j]->GetIsShot() == false)
				{
					continue;
				}

				// 当たると、プレイヤーと弾が消える（出現、発射フラグがfalseになる）
				if (powf(enemies_->enemy_[i]->bullet_[j]->GetRadius() + player_->GetRadius(), 2) >=
					powf(player_->GetPosX() - enemies_->enemy_[i]->bullet_[j]->GetPosX(), 2) +
					powf(player_->GetPosY() - enemies_->enemy_[i]->bullet_[j]->GetPosY(), 2))
				{
					player_->Kill();
					enemies_->enemy_[i]->bullet_[j]->Kill();
				}
			}
		}
	}
}