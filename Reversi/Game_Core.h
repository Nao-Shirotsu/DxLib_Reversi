#pragma once

#include <memory>
#include <stack>

#include "Game_Scene_IScene.h"
#include "DX_Core.h"
#include "Network_Manager.h"

namespace Game{

// ゲームコア 他の各クラスの実体を所有して管理
class Core{
public:
	explicit Core();
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
	std::shared_ptr<DX::Core> dxManager;
	std::unique_ptr<Network::Manager> networkManager;
};

}