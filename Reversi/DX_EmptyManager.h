#pragma once

#include "DX_IManager.h"

namespace DX{

// DXManagerクラスを用いない時のテスト用ダミークラス
// 各関数はテスト用出力以外に何もしない
class EmptyManager : public IManager{
public:
	EmptyManager();
	~EmptyManager();
	void Update();
	void Load( Resource::PicIndex index ) const;
	void Load( Resource::SoundIndex index ) const;
	void Draw( std::string text, int x, int y ) const;
	void Draw( Resource::PicIndex index ) const;
	void Play( Resource::SoundIndex index ) const;
	bool HasError() const;
	bool IsKeyDown( KeyCode key ) const;
	int GetCursolPosX() const;
	int GetCursolPosY() const;
	bool LeftClickedInBox( int x1, int y1, int x2, int y2 );
};

}