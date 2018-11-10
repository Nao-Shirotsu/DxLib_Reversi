#include <memory>

#include "Game_Scene_Achievements.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

Achievements::Achievements(){}

Achievements::~Achievements(){}

void Achievements::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Achievements::Update(){}

void Achievements::Draw() const{
	dxManager->DrawStr( "Scene::Achievements", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );
}

bool Achievements::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		return true;
	}
	return false;
}

bool Achievements::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Achievements::TransitionToNext() const{
	return nullptr;
}

Game::SceneID Achievements::GetSceneID() const{
	return Game::SceneID::Achievements;
}

}