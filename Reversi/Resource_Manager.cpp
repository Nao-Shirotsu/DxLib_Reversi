#include "Resource_Manager.h"

namespace{

constexpr const char* pictureFileName[1] = {
	"Resource\\Picture\\samurai.png"
};

constexpr const char* soundFileName[3] = {
	"Resource\\Sound\\decide.wav",
	"Resource\\Sound\\bgm_jazz.wav",
	"Resource\\Sound\\bgm_piano.wav"
};

}

namespace Resource{

const char* Manager::GetPicPath( PicIndex index ){
	return pictureFileName[static_cast<int>( index )];
}

const char* Manager::GetSoundPath( SoundIndex index ){
	return soundFileName[static_cast<int>( index )];
}

}