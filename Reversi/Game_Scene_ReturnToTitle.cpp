#include <memory>

#include "Game_Scene_ReturnToTitle.h"
#include "Game_Scene_Title.h"
#include "Game_Scene_Pause.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

ReturnToTitle::ReturnToTitle():
	nextSceneID( Game::SceneID::ReturnToTitle ){}

ReturnToTitle::~ReturnToTitle(){}

void ReturnToTitle::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void ReturnToTitle::Update(){}

void ReturnToTitle::Draw() const{
	dxManager->DrawStr( "Scene::ReturnToTitle", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Pause", 100, 100 );

	dxManager->DrawRect( 398, 298, 540, 330 );
	dxManager->DrawStr( "Title", 400, 300 );
}

bool ReturnToTitle::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		nextSceneID = Game::SceneID::Pause;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 298, 540, 330 ) ){
		nextSceneID = Game::SceneID::Title;
		return true;
	}
	return false;
}

std::unique_ptr<IScene> ReturnToTitle::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::Pause :
			return nullptr;

		case Game::SceneID::Title :
			return std::make_unique<Title>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID ReturnToTitle::GetSceneID() const{
	return Game::SceneID::ReturnToTitle;
}

}