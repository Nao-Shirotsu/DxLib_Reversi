#pragma once

#include <memory>

#include "Resource_Index.h"
#include "DX_IManager.h"

namespace Game::Scene{

// Scene�N���X�̃C���^�[�t�F�[�X
class IScene{
public:
	virtual ~IScene();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
	// DxLib�̊֐����V�[���ŗ��p���邽�߂�
=======
	// DxLib�̊֐����V�[���ŗ��p���邽�߂��߲�����擾
>>>>>>> Stashed changes
=======
	// DxLib�̊֐����V�[���ŗ��p���邽�߂��߲�����擾
>>>>>>> Stashed changes
	virtual void SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager ) = 0;

	// �����o�ϐ����̏�Ԃ̃A�b�v�f�[�g
	virtual void Update() = 0;

	// ��ʂ֕`�悷��
	virtual void Draw() = 0;

	// �V�[���J�ڊ֐�
	// �Ⴄ�V�[���Ɉڍs����ꍇ�͂��̎��̂𐶐����ĕԂ��A
	// �����łȂ��Ȃ�nullptr��Ԃ�
	virtual std::unique_ptr<IScene> TransitionToNext() = 0;
};

}