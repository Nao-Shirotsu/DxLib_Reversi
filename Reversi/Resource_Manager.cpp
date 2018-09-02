#include "Resource_Manager.h"

namespace{

constexpr const char* pictureFileName[1] = {
	"Resource\\Picture\\samurai.png"
};

constexpr const char* soundFileName[1] = {
	"Resource\\Sound\\decide.wav"
};

}

namespace Resource{

const char* Manager::GetPicPath( PicIndex index ){
	return nullptr;
}

const char* Manager::GetSoundPath( SoundIndex index ){
	return nullptr;
}

}