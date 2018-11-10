#include <memory>

#include "Game_Scene_GuestMatching.h"
#include "Game_Scene_Title.h"
#include "Game_Scene_GamePlay.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

GuestMatching::GuestMatching():
	nextSceneID( Game::SceneID::GuestMatching ){}

GuestMatching::~GuestMatching(){}

void GuestMatching::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void GuestMatching::Update(){}

void GuestMatching::Draw() const{
	dxManager->DrawStr( "Scene::GuestMatching", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );

	dxManager->DrawRect( 398, 298, 540, 330 );
	dxManager->DrawStr( "GamePlay", 400, 300 );
}

bool GuestMatching::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		nextSceneID = Game::SceneID::Title;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 298, 540, 330 ) ){
		nextSceneID = Game::SceneID::GamePlay;
		return true;
	}

	return false;
}

bool GuestMatching::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> GuestMatching::TransitionToNext() const{
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

Game::SceneID GuestMatching::GetSceneID() const{
	return Game::SceneID::GuestMatching;
}

}