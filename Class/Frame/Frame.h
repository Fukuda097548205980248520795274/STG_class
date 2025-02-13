#pragma once
class Frame
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Frame();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Frame();

	// Getter
	int GetFrame() { return current_; }

	/// <summary>
	/// 初期化する
	/// </summary>
	void Initialize();

	/// <summary>
	/// フレームをカウントする
	/// </summary>
	/// <param name="endFrame">最終フレーム</param>
	void CountFrame(int endFrame);

private:

	// 現在
	int current_;
};