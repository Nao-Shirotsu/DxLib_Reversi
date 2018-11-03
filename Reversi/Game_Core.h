#pragma once

#include <memory>

#include "Game_Scene_IScene.h"
#include "Game_Scene_Title.h"
#include "DX_IManager.h"
#include "DX_Manager.h"
#include "Network_Manager.h"

namespace Game{

// �Q�[���R�A ��X�̃��W���[���N���X���Ǘ�
// 1�t���[�����ƂɕK�v�ȏ������s�Ȃ�
class Core{
public:
	Core();
	~Core();

	// true�Ȃ�E�B���h�E����ăQ�[���I��
	bool IsGameEnd();

	// 1�t���[�����ƂɕK�v�ȏ���
	void Update();

	// �Q�[����ʂɕ`��
	void Draw();

private:
	std::unique_ptr<Game::Scene::IScene> scene;
	std::shared_ptr<DX::IManager> dxManager;
	std::unique_ptr<Network::Manager> networkManager;
};

}