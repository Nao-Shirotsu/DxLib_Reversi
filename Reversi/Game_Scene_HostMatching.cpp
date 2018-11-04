#include <memory>

#include "Game_Scene_HostMatching.h"
#include "Game_Scene_Title.h"
#include "Game_Scene_GamePlay.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

HostMatching::HostMatching():
	nextSceneID( Game::SceneID::HostMatching ){}

HostMatching::~HostMatching(){}

void HostMatching::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void HostMatching::Update(){}

void HostMatching::Draw() const{
	dxManager->DrawStr( "Scene::HostMatching", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );

	dxManager->DrawRect( 98, 298, 240, 330 );
	dxManager->DrawStr( "GamePlay", 100, 300 );
}

bool HostMatching::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		nextSceneID = Game::SceneID::Title;
		return true;
	}

	if( dxManager->LeftClickedInBox( 98, 298, 240, 330 ) ){
		nextSceneID = Game::SceneID::GamePlay;
		return true;
	}

	return false;
}

std::unique_ptr<IScene> HostMatching::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::Title:
			return nullptr;

		case Game::SceneID::GamePlay:
			return std::make_unique<GamePlay>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID HostMatching::GetSceneID() const{
	return Game::SceneID::HostMatching;
}

}