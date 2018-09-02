#pragma once

#include "DX_IManager.h"
#include "Resource_Manager.h"

namespace DX{

// DxLib関数のラッパークラス
class Manager : public IManager, public Resource::Manager{
public:
	Manager();
	~Manager();
	void Update();
	void Load( Resource::PicIndex index );
	void Load( Resource::SoundIndex index );
	void Draw( std::string text );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );

private:
	char* to_chPtr( const char* str );
};

}