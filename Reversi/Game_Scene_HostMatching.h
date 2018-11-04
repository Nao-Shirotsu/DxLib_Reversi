﻿#pragma once

#include "Game_Scene_IScene.h"
#include "Resource_Index.h"

namespace Game::Scene{

// シーン：マッチング(ホスト)
class HostMatching : public IScene{
public:
	HostMatching();
	~HostMatching();
	void SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager );
	void Update();
	void Draw() const;
	bool NeedsTransition();
	std::unique_ptr<IScene> TransitionToNext() const;

private:
	Game::SceneID GetSceneID() const;

	std::shared_ptr<DX::IManager> dxManager;
	Game::SceneID nextSceneID;
};

}