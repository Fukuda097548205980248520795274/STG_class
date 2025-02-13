#include "Scene.h"

/// <summary>
/// コンストラクタ
/// </summary>
Scene::Scene()
{
	// シーン
	sceneNo_ = SCENE_START;

	// シューティングゲーム
	stg_ = new STG();
}

/// <summary>
/// デストラクタ
/// </summary>
Scene::~Scene()
{
	// シューティングゲーム
	delete stg_;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前に押したキー</param>
void Scene::Update(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}


	// シーン切り替え
	switch (sceneNo_)
	{
	case SCENE_START:
		// スタート画面

		// Zキで、ゲームを開始する
		stg_->GameStart(keys , preKeys);

		// ゲームを開始したら（ゲーム開始フラグがtrueになったら）ゲーム画面に遷移する
		if (stg_->GetIsGameStart())
		{
			sceneNo_ = SCENE_GAME;
		}

		break;

	case SCENE_GAME:
		// ゲーム画面

		// シューティングゲームの更新処理
		stg_->Update(keys, preKeys);

		// クリアしたら（クリアフラグがtrueになったら）クリア画面に遷移する
		if (stg_->GetIsGameClear())
		{
			sceneNo_ = SCENE_CLEAR;
		}

		// ゲームオーバーになったら（ゲームオーバーフラグがtrueになったら）ゲームオーバー画面に遷移する
		if (stg_->GetIsGameOver())
		{
			sceneNo_ = SCENE_GAME_OVER;
		}

		break;

	case SCENE_CLEAR:
		// クリア画面

		// Zキーで、スタート画面に戻る
		stg_->BackStart(keys, preKeys);

		// ゲームを開始していない（ゲーム開始フラグがfalseである）ときに、スタート画面に遷移する
		if (stg_->GetIsGameStart() == false)
		{
			sceneNo_ = SCENE_START;
		}

		break;

	case SCENE_GAME_OVER:
		// ゲームオーバー画面

		// Zキーで、スタート画面に戻る
		stg_->BackStart(keys, preKeys);

		// ゲームを開始していない（ゲーム開始フラグがfalseである）ときに、スタート画面に遷移する
		if (stg_->GetIsGameStart() == false)
		{
			sceneNo_ = SCENE_START;
		}

		break;
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Scene::Draw()
{
	// 背景
	Novice::DrawBox(0, 0, kScreenWidth, kScreenHeight, 0.0f, 0x000000FF, kFillModeSolid);


	// シーン切り替え
	switch (sceneNo_)
	{
	case SCENE_START:
		// スタート画面

		// 文字
		Novice::ScreenPrintf(8, 8, "Scene : Start");
		Novice::ScreenPrintf(8, 40, "GameStart : Z");

		break;

	case SCENE_GAME:
		// ゲーム画面

		// シューティングゲームの描画処理
		stg_->Draw();

		// 文字
		Novice::ScreenPrintf(8, 8, "Scene : Game");
		Novice::ScreenPrintf(8, 40, "Move : WASD");
		Novice::ScreenPrintf(8, 64, "Shot : Space");

		// クリア条件の表記
		Novice::ScreenPrintf(256, 8, "Clear => %d / 5", STG::countKilledEnemy);

		break;

	case SCENE_CLEAR:
		// クリア画面

		// 文字
		Novice::ScreenPrintf(8, 8, "Scene : Clear");
		Novice::ScreenPrintf(8, 40, "Back : Z");

		break;

	case SCENE_GAME_OVER:
		// ゲームオーバー画面

		// 文字
		Novice::ScreenPrintf(8 , 8 , "Scene : GameOver");
		Novice::ScreenPrintf(8, 40, "Back : Z");

		break;
	}
}