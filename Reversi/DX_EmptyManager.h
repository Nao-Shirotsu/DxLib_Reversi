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
	void Load( Resource::PicIndex index );
	void Load( Resource::SoundIndex index );
	void Draw( std::string text );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );
};

}