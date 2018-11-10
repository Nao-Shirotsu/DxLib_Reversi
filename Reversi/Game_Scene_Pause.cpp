#include <memory>

#include "Game_Scene_Pause.h"
#include "Game_Scene_ReturnToTitle.h"
#include "Game_Scene_GamePlay.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

Pause::Pause():
	nextSceneID( Game::SceneID::Pause ){}

Pause::~Pause(){}

void Pause::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Pause::Update(){}

void Pause::Draw() const{
	dxManager->DrawStr( "Scene::Pause", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "GamePlay", 100, 100 );

	dxManager->DrawRect( 398, 298, 540, 330 );
	dxManager->DrawStr( "ReturnToTitle", 400, 300 );
}

bool Pause::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		nextSceneID = Game::SceneID::GamePlay;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 298, 540, 330 ) ){
		nextSceneID = Game::SceneID::ReturnToTitle;
		return true;
	}
	return false;
}

bool Pause::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Pause::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::GamePlay:
			return nullptr;

		case Game::SceneID::ReturnToTitle:
			return std::make_unique<ReturnToTitle>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID Pause::GetSceneID() const{
	return Game::SceneID::Pause;
}

}