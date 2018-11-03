#pragma once

#include "Game_Scene_IScene.h"
#include "Resource_Index.h"

namespace Game::Scene{

// シーン：タイトル画面
class Title : public IScene{
public:
	Title();
	~Title();
	void SetDXManagerPtr( const std::shared_ptr<DX::IManager>& dxManager );
	void Update();
	void Draw() const;
	std::unique_ptr<IScene> TransitionToNext() const;

private:
	std::shared_ptr<DX::IManager> dxManager;
};

}