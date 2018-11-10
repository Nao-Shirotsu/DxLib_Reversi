#include <memory>

#include "Game_Scene_Disconnection.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

Disconnection::Disconnection(){}

Disconnection::~Disconnection(){}

void Disconnection::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Disconnection::Update(){}

void Disconnection::Draw() const{
	dxManager->DrawStr( "Scene::Disconnection", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );
}

bool Disconnection::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		return true;
	}
	return false;
}

bool Disconnection::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Disconnection::TransitionToNext() const{
	return std::make_unique<Title>();
}

Game::SceneID Disconnection::GetSceneID() const{
	return Game::SceneID::Disconnection;
}

}