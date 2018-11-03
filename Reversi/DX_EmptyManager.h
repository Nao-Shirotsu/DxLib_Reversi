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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	void Draw( std::string text );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );
=======
=======
>>>>>>> Stashed changes
	void Draw( std::string text, int x, int y );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );
	bool HasError();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
	bool IsKeyDown( KeyCode key );
>>>>>>> Stashed changes
};

}