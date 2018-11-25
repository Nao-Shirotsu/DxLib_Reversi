#pragma once

#include "Game_Scene_IScene.h"
#include "Resource_Index.h"

namespace Game::Scene{

// シーン：設定
class Settings : public IScene{
public:
	Settings();
	~Settings();
	void SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager ) override;
	void Update() override;
	void Draw() const override;
	bool NeedsTransition() override;
	bool IsTitleScene() override;
	std::unique_ptr<IScene> TransitionToNext() const override;

private:
	Game::SceneID GetSceneID() const override;

	std::shared_ptr<DX::UtilManager> dxManager;
};

}
