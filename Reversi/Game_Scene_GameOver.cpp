#include <memory>

#include "Game_Scene_GameOver.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

GameOver::GameOver(){}

GameOver::~GameOver(){}

void GameOver::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void GameOver::Update(){}

void GameOver::Draw() const{
	dxManager->DrawStr( "Scene::GameOver", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );
}

bool GameOver::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		return true;
	}
	return false;
}

bool GameOver::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> GameOver::TransitionToNext() const{
	return std::make_unique<Title>();
}

Game::SceneID GameOver::GetSceneID() const{
	return Game::SceneID::GameOver;
}

}