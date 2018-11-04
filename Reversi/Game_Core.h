#pragma once

#include <memory>
#include <stack>

#include "Game_Scene_IScene.h"
#include "Game_Scene_Title.h"
#include "DX_IManager.h"
#include "DX_Manager.h"
#include "Network_Manager.h"

namespace Game{

// ゲームコア 他の各クラスの実体を所有して管理
class Core{
public:
	Core();
	~Core();

	// trueならウィンドウを閉じてゲーム終了
	bool IsGameEnd() const;

	// 毎フレーム必要な処理
	void Update();

	// 毎フレーム ゲームを画面に描画
	void Draw() const;

private:
	// sceneStackに積まれているすべてのリソースを解放
	void DestructAllSceneObjects();

	std::stack<std::unique_ptr<Game::Scene::IScene>> sceneStack;
	std::shared_ptr<DX::IManager> dxManager;
	std::unique_ptr<Network::Manager> networkManager;
};

}