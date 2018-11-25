#pragma once

#include <string>
#include <memory>

#include "Resource_Manager.h"
#include "DX_KeyCode.h"
#include "DX_MouseCursol.h"

namespace DX{

// DxLib関数のラッパークラス
// 1フレームに1回だけ呼ばれる必要がある処理のアクセスレベルを隔離するため
// どこで呼ばれてもいい関数のみこのクラスに記述
class UtilManager: public Resource::Manager{
public:
	UtilManager();

	~UtilManager();

	// enum classの値から欲しい画像を特定してメモリに読み込む
	void Load( Resource::PicIndex index ) const;
	void Load( Resource::SoundIndex index ) const;

	// 文字列を描画(テスト用出力であり、大きさなどは変更できない)
	void DrawStr( const std::string& text, int x, int y ) const;

	// (x1, y1)を左上頂点,(x2, y2)を右下頂点とする四角形を描画
	void DrawRect( int x1, int y1, int x2, int y2 ) const;

	// *** 下記2つの関数は、リソースファイルがメモリにロード
	// *** されていなければそれらの描画/再生は行わない。

	// ロードした画像ファイルを描画
	void DrawPic( Resource::PicIndex index ) const;

	// ロードした音声ファイルを再生
	void Play( Resource::SoundIndex index ) const;

	// あるキーが押されたか引数keyで受け取って調べる
	bool IsKeyDown( KeyCode key ) const;

	// (x1, y1)を左上, (x2, y2)を右下とする四角形の範囲で左クリックされたかどうか
	bool LeftClickedInBox( int x1, int y1, int x2, int y2 );

protected:
	static inline char keyState[256];
	static std::shared_ptr<MouseCursol> cursol;
};

}