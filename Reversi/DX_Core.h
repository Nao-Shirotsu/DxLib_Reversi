#pragma once

#include <string>
#include <memory>

#include "DX_UtilManager.h"

namespace DX{

// DxLib関数のラッパークラス
class Core: public UtilManager{
public:
	Core();
	~Core();

	// メンバ変数等の状態のアップデート 1フレームに1回実行
	void Update();

	// 画面に描画処理 1フレームに1回実行
	void Draw() const;

	// 致命的な(実行を終了すべき)エラーが発生しているかどうか
	bool HasError() const;

private:
	bool dxError;
};

}