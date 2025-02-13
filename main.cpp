#include <Novice.h>
#include "Constant.h"
#include "./Class/Scene/Scene.h"

const char kWindowTitle[] = "LC1C_20_フクダソウワ_STGクラス化";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	/*---------------
	    変数を作る
	---------------*/

	// シーン
	Scene* scene = new Scene();


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// シーンの更新処理
		scene->Update(keys, preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// シーンの描画処理
		scene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}


	/*-------------------------
	    インスタンスを削除する
	-------------------------*/

	// シーン
	delete scene;


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
