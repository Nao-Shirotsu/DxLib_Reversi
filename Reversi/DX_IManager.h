#pragma once

#include <string>

#include "Resource_Index.h"
<<<<<<< Updated upstream
=======
#include "DX_KeyCode.h"
>>>>>>> Stashed changes

namespace DX{
// DxLib関数のラッパークラスのインターフェース
// DxLib関数を利用しないダミーManagerのため、interface化する
class IManager{
public:
	virtual ~IManager();

	// メンバ変数等の状態のアップデート
	virtual void Update() = 0;

	// enum classの値から欲しい画像を特定してメモリに読み込む
	virtual void Load( Resource::PicIndex index ) = 0;
	virtual void Load( Resource::SoundIndex index ) = 0;

	// 文字列を描画
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	virtual void Draw( std::string text ) = 0;
=======
	virtual void Draw( std::string text, int x, int y ) = 0;
>>>>>>> Stashed changes
=======
	virtual void Draw( std::string text, int x, int y ) = 0;
>>>>>>> Stashed changes

	// *** 下記2つの関数は、リソースファイルがメモリにロード
	// *** されていなければそれらの描画/再生は行わない。

	// ロードした画像ファイルを描画
	virtual void Draw( Resource::PicIndex index ) = 0;

	// ロードした音声ファイルを再生
	virtual void Play( Resource::SoundIndex index ) = 0;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======

	virtual bool HasError() = 0;
>>>>>>> Stashed changes
=======

	// 致命的な(実行を終了すべき)エラーが発生しているかどうか
	virtual bool HasError() = 0;

	// あるキーが押されたか引数keyで受け取って調べる
	virtual bool IsKeyDown( KeyCode key ) = 0;
>>>>>>> Stashed changes
};

}