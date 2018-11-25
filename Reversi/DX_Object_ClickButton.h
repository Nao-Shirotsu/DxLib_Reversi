#pragma once
#include <string>
#include <memory>

#include "DX_UtilManager.h"

namespace DX::Object{

// クリックで反応する四角形クラス
class ClickButton{
public:
	// 文字列入りクリックボタン  DxManagerのDIと、テキストと左上頂点の座標を渡す
	ClickButton( std::shared_ptr<DX::UtilManager> dxManager_, const std::string& text_, int x1_, int y1_ );

	// 空のクリックボタン  DxManagerのDIと、左上(x1, y1) 右下(x2, y2)の座標を渡す
	ClickButton( std::shared_ptr<DX::UtilManager> dxManager_, int x1_, int y1_, int x2_, int y2_ );

	// 何もしない
	ClickButton();

	// 描画する
	void Draw() const;

	// クリックされたかどうか
	bool WasLeftClicked() const;

private:
	std::string text;
	int x1, y1; // ボックスの左上頂点
	int x2, y2; // ボックスの右下頂点
	int strX, strY; // 文字列の左上頂点
	std::shared_ptr<DX::UtilManager> dxManager;
};

}