#pragma once

#include "Game_Scene_IScene.h"
#include "Resource_Index.h"

namespace Game::Scene{

// シーン：実績
class Achievements : public IScene{
public:
	Achievements();
	~Achievements();
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