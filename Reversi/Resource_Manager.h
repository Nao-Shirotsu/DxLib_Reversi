
#pragma once

#include <string>

#include "Resource_Index.h"

namespace Resource{

// リソースファイル名の管理クラス
class Manager{
protected:
	// Index型の値からファイル名(path)を返す
	static const char* GetPicPath( PicIndex index );
	static const char* GetSoundPath( SoundIndex index );
};

}