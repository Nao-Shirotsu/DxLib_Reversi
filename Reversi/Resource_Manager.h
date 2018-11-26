
#pragma once

#include <string>
#include <unordered_map>

#include "Resource_Index.h"

namespace Resource{

// リソースファイル名の管理クラス
class Manager{
protected:
	// Index型の値からファイル名(path)を返す
	static const char* GetPicPath( PicIndex index );
	static const char* GetSoundPath( SoundIndex index );

	static inline std::unordered_map<Resource::PicIndex, int> picHandles;
	static inline std::unordered_map<Resource::SoundIndex, int> soundHandles;
};

}