#pragma once

#include "DX_IManager.h"

namespace DX{

// DXManager�N���X��p���Ȃ����̃e�X�g�p�_�~�[�N���X
// �e�֐��̓e�X�g�p�o�͈ȊO�ɉ������Ȃ�
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