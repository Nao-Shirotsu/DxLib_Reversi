﻿#pragma once

#include "Game_Scene_IScene.h"
#include "Resource_Index.h"

namespace Game::Scene{

// シーン：設定
class Settings : public IScene{
public:
	Settings();
	~Settings();
	void SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager );
	void Update();
	void Draw() const;
	bool NeedsTransition();
	bool IsTitleScene();
	std::unique_ptr<IScene> TransitionToNext() const;

private:
	Game::SceneID GetSceneID() const;

	std::shared_ptr<DX::IManager> dxManager;
};

}
