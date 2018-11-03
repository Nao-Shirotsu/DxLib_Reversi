#pragma once

#include <memory>

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
	std::unique_ptr<Game::Scene::IScene> scene;
	std::shared_ptr<DX::IManager> dxManager;
	std::unique_ptr<Network::Manager> networkManager;

	// 何らかの致命的エラーによりゲームを強制終了させるフラグ
	bool criticalError;
	// ゲームを正常終了するフラグ
	bool endFlag;
};

}