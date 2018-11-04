#include <memory>

#include "Game_Scene_GamePlay.h"
#include "Game_Scene_ScoreBoard.h"
#include "Game_Scene_GameOver.h"
#include "Game_Scene_Pause.h"
#include "Game_Scene_Disconnection.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

GamePlay::GamePlay():
	nextSceneID( Game::SceneID::GamePlay ){}

GamePlay::~GamePlay(){}

void GamePlay::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void GamePlay::Update(){}

void GamePlay::Draw() const{
	dxManager->DrawStr( "Scene::GamePlay", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "ScoreBoard", 100, 100 );

	dxManager->DrawRect( 98, 298, 240, 330 );
	dxManager->DrawStr( "Disconnection", 100, 300 );

	dxManager->DrawRect( 398, 98, 540, 130 );
	dxManager->DrawStr( "Pause",400, 100 );

	dxManager->DrawRect( 398, 298, 540, 330 );
	dxManager->DrawStr( "GameOver", 400, 300 );
}

bool GamePlay::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		nextSceneID = Game::SceneID::ScoreBoard;
		return true;
	}

	if( dxManager->LeftClickedInBox( 98, 298, 240, 330 ) ){
		nextSceneID = Game::SceneID::Disconnection;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 98, 540, 130 ) ){
		nextSceneID = Game::SceneID::Pause;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 298, 540, 330 ) ){
		nextSceneID = Game::SceneID::GameOver;
		return true;
	}
	return false;
}

std::unique_ptr<IScene> GamePlay::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::ScoreBoard:
			return std::make_unique<ScoreBoard>();

		case Game::SceneID::Disconnection:
			return std::make_unique<Disconnection>();

		case Game::SceneID::Pause:
			return std::make_unique<Pause>();

		case Game::SceneID::GameOver:
			return std::make_unique<GameOver>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID GamePlay::GetSceneID() const{
	return Game::SceneID::GamePlay;
}

}