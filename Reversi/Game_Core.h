#pragma once

#include <memory>

#include "Game_Scene_IScene.h"
#include "Game_Scene_Title.h"
#include "DX_IManager.h"
#include "DX_Manager.h"
#include "Network_Manager.h"

namespace Game{

// ゲームコア 種々のモジュールクラスを管理
// 1フレームごとに必要な処理を行なう
class Core{
public:
	Core();
	~Core();

	// trueならウィンドウを閉じてゲーム終了
	bool IsGameEnd();

	// 1フレームごとに必要な処理
	void Update();

	// ゲーム画面に描画
	void Draw();

private:
	std::unique_ptr<Game::Scene::IScene> scene;
	std::shared_ptr<DX::IManager> dxManager;
	std::unique_ptr<Network::Manager> networkManager;
};

}