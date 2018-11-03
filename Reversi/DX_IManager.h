#pragma once

#include <string>

#include "Resource_Index.h"
#include "DX_KeyCode.h"


namespace DX{
// DxLib関数のラッパークラスのインターフェース
// DxLib関数を利用しないダミーManagerのため、interface化する
class IManager{
public:
	virtual ~IManager();

	// メンバ変数等の状態のアップデート
	virtual void Update() = 0;

	// enum classの値から欲しい画像を特定してメモリに読み込む
	virtual void Load( Resource::PicIndex index ) const = 0;
	virtual void Load( Resource::SoundIndex index ) const = 0;

	// 文字列を描画
	virtual void Draw( std::string text, int x, int y ) const = 0;

	// ロードした画像ファイルを描画　ロード済でないなら何もしない
	virtual void Draw( Resource::PicIndex index ) const = 0;

	// ロードした音声ファイルを再生　ロード済でないなら何もしない
	virtual void Play( Resource::SoundIndex index ) const = 0;

	// 致命的な(実行を終了すべき)エラーが発生しているかどうか
	virtual bool HasError() const = 0;

	// あるキーが押されたか引数keyで受け取って調べる
	virtual bool IsKeyDown( KeyCode key ) const = 0;

	// マウスカーソルの位置を取得
	virtual int GetCursolPosX() const = 0;
	virtual int GetCursolPosY() const = 0;

	// (x1, y1)を左上, (x2, y2)を右下とする四角形の範囲で左クリックされたかどうか
	virtual bool LeftClickedInBox( int x1, int y1, int x2, int y2 ) = 0;
};

}