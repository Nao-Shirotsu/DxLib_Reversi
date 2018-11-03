#pragma once

#include <string>

#include "Resource_Index.h"
<<<<<<< Updated upstream
=======
#include "DX_KeyCode.h"
>>>>>>> Stashed changes

namespace DX{
// DxLib�֐��̃��b�p�[�N���X�̃C���^�[�t�F�[�X
// DxLib�֐��𗘗p���Ȃ��_�~�[Manager�̂��߁Ainterface������
class IManager{
public:
	virtual ~IManager();

	// �����o�ϐ����̏�Ԃ̃A�b�v�f�[�g
	virtual void Update() = 0;

	// enum class�̒l����~�����摜����肵�ă������ɓǂݍ���
	virtual void Load( Resource::PicIndex index ) = 0;
	virtual void Load( Resource::SoundIndex index ) = 0;

	// �������`��
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	virtual void Draw( std::string text ) = 0;
=======
	virtual void Draw( std::string text, int x, int y ) = 0;
>>>>>>> Stashed changes
=======
	virtual void Draw( std::string text, int x, int y ) = 0;
>>>>>>> Stashed changes

	// *** ���L2�̊֐��́A���\�[�X�t�@�C�����������Ƀ��[�h
	// *** ����Ă��Ȃ���΂����̕`��/�Đ��͍s��Ȃ��B

	// ���[�h�����摜�t�@�C����`��
	virtual void Draw( Resource::PicIndex index ) = 0;

	// ���[�h���������t�@�C�����Đ�
	virtual void Play( Resource::SoundIndex index ) = 0;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======

	virtual bool HasError() = 0;
>>>>>>> Stashed changes
=======

	// �v���I��(���s���I�����ׂ�)�G���[���������Ă��邩�ǂ���
	virtual bool HasError() = 0;

	// ����L�[�������ꂽ������key�Ŏ󂯎���Ē��ׂ�
	virtual bool IsKeyDown( KeyCode key ) = 0;
>>>>>>> Stashed changes
};

}