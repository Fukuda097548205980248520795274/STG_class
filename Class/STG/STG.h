#pragma once
#include "./Class/Object/Player/Player.h"

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

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前のキー</param>
	void Update(const char* keys , const char* preKeys);
	
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();


private:

	Player* player_;
};

