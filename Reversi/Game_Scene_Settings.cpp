#include <memory>

#include "Game_Scene_Settings.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

Settings::Settings(){}

Settings::~Settings(){}

void Settings::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Settings::Update(){}

void Settings::Draw() const{
	dxManager->DrawStr( "Scene::Settings", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );
}

bool Settings::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		return true;
	}
	return false;
}

std::unique_ptr<IScene> Settings::TransitionToNext() const{
	return nullptr;
}

Game::SceneID Settings::GetSceneID() const{
	return Game::SceneID::Settings;
}

}