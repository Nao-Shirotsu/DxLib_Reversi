#include <memory>

#include "Game_Scene_Error.h"

namespace Game::Scene{

Error::Error(){}

Error::~Error(){}

void Error::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Error::Update(){}

void Error::Draw() const{
	dxManager->DrawStr( "GAME CRASHED : ゲームを終了してください。", 100, 290 );
}

bool Error::NeedsTransition(){
	return false;
}

std::unique_ptr<IScene> Error::TransitionToNext() const{
	return nullptr;
}

Game::SceneID Error::GetSceneID() const{
	return Game::SceneID::Error;
}

}