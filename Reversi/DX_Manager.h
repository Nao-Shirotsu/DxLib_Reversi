#pragma once

#include "DX_IManager.h"
#include "Resource_Manager.h"
<<<<<<< Updated upstream
=======
#include "Util.h"
>>>>>>> Stashed changes

namespace DX{

// DxLib�֐��̃��b�p�[�N���X
class Manager : public IManager, public Resource::Manager{
public:
	Manager();
	~Manager();
	void Update();
	void Load( Resource::PicIndex index );
	void Load( Resource::SoundIndex index );
<<<<<<< Updated upstream
	void Draw( std::string text );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );

private:
	// �����Ɠ��������������char*�^�̃C���X�^���X�𐶐����ĕԂ�
	char* ToCharPtr( const char* str );
=======
	void Draw( std::string text, int x, int y );
	void Draw( Resource::PicIndex index );
	void Play( Resource::SoundIndex index );
	bool HasError();

private:
	bool dxError;
>>>>>>> Stashed changes
};

}