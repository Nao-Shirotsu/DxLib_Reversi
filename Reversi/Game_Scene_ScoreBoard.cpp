#include <memory>

#include "Game_Scene_ScoreBoard.h"
#include "Game_Scene_GamePlay.h"

namespace Game::Scene{

ScoreBoard::ScoreBoard(){}

ScoreBoard::~ScoreBoard(){}

void ScoreBoard::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void ScoreBoard::Update(){}

void ScoreBoard::Draw() const{
	dxManager->DrawStr( "Scene::ScoreBoard", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "GamePlay", 100, 100 );
}

bool ScoreBoard::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		return true;
	}
	return false;
}

bool ScoreBoard::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> ScoreBoard::TransitionToNext() const{
	return nullptr;
}

Game::SceneID ScoreBoard::GetSceneID() const{
	return Game::SceneID::ScoreBoard;
}

}