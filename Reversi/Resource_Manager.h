#pragma once

#include <string>

#include "Resource_Index.h"

namespace Resource{

// ���\�[�X�t�@�C�����̊Ǘ��N���X
class Manager{
protected:
	// Index�^�̒l����t�@�C����(path)��Ԃ�
	static const char* GetPicPath( PicIndex );
	static const char* GetSoundPath( SoundIndex );
};

}