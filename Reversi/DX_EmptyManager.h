#pragma once

#include <memory>
#include "DX_IManager.h"

namespace DX{

// DXManagerクラスを用いない時のテスト用ダミークラス
// 各関数はテスト用出力以外に何もしない
class EmptyManager : public IManager{
public:
	EmptyManager();
	~EmptyManager();
	void Update();
	void Draw() const;
	void Load( Resource::PicIndex index ) const;
	void Load( Resource::SoundIndex index ) const;
	void DrawStr( const std::string& text, int x, int y ) const;
	void DrawRect( int x1, int y1, int x2, int y2 ) const;
	void DrawPic( Resource::PicIndex index ) const;
	void Play( Resource::SoundIndex index ) const;
	bool HasError() const;
	bool IsKeyDown( KeyCode key ) const;
	bool LeftClickedInBox( int x1, int y1, int x2, int y2 );
	int GetCursolPosX() const;
	int GetCursolPosY() const;
};

}