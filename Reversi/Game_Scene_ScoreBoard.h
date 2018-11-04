﻿#pragma once

#include "Game_Scene_IScene.h"
#include "Resource_Index.h"

namespace Game::Scene{

// シーン：スコアボード
class ScoreBoard : public IScene{
public:
	ScoreBoard();
	~ScoreBoard();
	void SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager );
	void Update();
	void Draw() const;
	bool NeedsTransition();
	std::unique_ptr<IScene> TransitionToNext() const;

private:
	Game::SceneID GetSceneID() const;

	std::shared_ptr<DX::IManager> dxManager;
};

}