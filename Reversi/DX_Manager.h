#pragma once

#include "DX_IManager.h"
#include "Resource_Manager.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
#include "Util.h"
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

namespace DX{

// DxLib関数のラッパークラス
class Manager : public IManager, public Resource::Manager{
public:
	Manager();
	~Manager();
	void Update();
	void Load( Resource::PicIndex index );
	void Load( Resource::SoundIndex index );
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	void Draw( std::string text );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );

private:
	// 引数と同じ文字列を持つchar*型のインスタンスを生成して返す
	char* ToCharPtr( const char* str );
=======
=======
>>>>>>> Stashed changes
	void Draw( std::string text, int x, int y );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );
	bool HasError();
<<<<<<< Updated upstream

private:
	bool dxError;
>>>>>>> Stashed changes
=======
	bool IsKeyDown( KeyCode key );

private:
	bool dxError;
	static inline char keyState[256];
>>>>>>> Stashed changes
};

}