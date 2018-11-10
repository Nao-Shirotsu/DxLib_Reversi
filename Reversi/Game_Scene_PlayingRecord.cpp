#include <memory>

#include "Game_Scene_PlayingRecord.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

PlayingRecord::PlayingRecord(){}

PlayingRecord::~PlayingRecord(){}

void PlayingRecord::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void PlayingRecord::Update(){}

void PlayingRecord::Draw() const{
	dxManager->DrawStr( "Scene::PlayingRecord", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Title", 100, 100 );
}

bool PlayingRecord::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		return true;
	}
	return false;
}

bool PlayingRecord::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> PlayingRecord::TransitionToNext() const{
	return nullptr;
}

Game::SceneID PlayingRecord::GetSceneID() const{
	return Game::SceneID::PlayingRecord;
}

}