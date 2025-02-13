#include "Frame.h"

/// <summary>
/// コンストラクタ
/// </summary>
Frame::Frame()
{
	current_ = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
Frame::~Frame()
{

}

/// <summary>
/// 初期化する
/// </summary>
void Frame::Initialize()
{
	current_ = 0;
}

/// <summary>
/// フレームをカウントする
/// </summary>
/// <param name="endFrame">最終フレーム</param>
void Frame::CountFrame(int endFrame)
{
	if (current_ < endFrame)
	{
		current_++;
	}
}