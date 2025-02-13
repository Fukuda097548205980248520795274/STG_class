#pragma once
#include "./Class/STG/STG.h"
#include "Enumeration.h"

class Scene
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Scene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Scene();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前に押したキー</param>
	void Update(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();


private:

	// シーン
	int sceneNo_;

	// シューティングゲーム
	STG* stg_;
};