#pragma once

namespace DX{

// マウスカーソルの状態を格納する構造体(セット不可)
class UnsettableMouseCursol{
public:
	UnsettableMouseCursol();

	int GetPosX() const;
	int GetPosY() const;

	int GetLastClickPosX() const;
	int GetLastClickPosY() const;

	int GetClickButtonType() const;
	int GetClickLogType() const;

	// 押された瞬間or離された瞬間ならtrue, それ以外はfalse
	bool ClickLogChanged() const;

protected:
	// 現在のマウスカーソルのWindow内での座標
	int posX;
	int posY;

	// 最後にマウスの任意のボタンを押した時のWindow内での座標
	int lastClickPosX;
	int lastClickPosY;

	// クリックしたボタンの種類(左,右など)
	int clickButtonType;

	// クリックの状態(今押されている、押されていない)
	int clickLogType;

	// クリックされた瞬間と離した瞬間ならtrue, それ以外false
	bool clickFlag;
};

}