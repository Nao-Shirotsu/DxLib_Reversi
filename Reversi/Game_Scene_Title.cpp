#include <memory>

#include "Game_Scene_Title.h"
#include "Game_Scene_Achievements.h"
#include "Game_Scene_PlayingRecord.h"
#include "Game_Scene_GuestMatching.h"
#include "Game_Scene_HostMatching.h"
#include "Game_Scene_Settings.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

Title::Title():
	nextSceneID( Game::SceneID::Title ){}

Title::~Title(){}

void Title::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Title::Update(){}

void Title::Draw() const{
	dxManager->DrawStr( "Current Scene : Title", 0, 0 );
	dxManager->DrawStr( "Click any scene to move there.", 0, 15 );

	dxManager->DrawRect( 98, 98, 240, 130 );
	dxManager->DrawStr( "Achievements", 100, 100 );

	dxManager->DrawRect( 398, 98, 540, 130 );
	dxManager->DrawStr( "PlayingRecord", 400, 100 );

	dxManager->DrawRect( 248, 198, 390, 230 );
	dxManager->DrawStr( "Settings", 250, 200 );

	dxManager->DrawRect( 98, 298, 240, 330 );
	dxManager->DrawStr( "GuestMatching", 100, 300 );

	dxManager->DrawRect( 398, 298, 540, 330 );
	dxManager->DrawStr( "HostMatching", 400, 300 );
}

bool Title::NeedsTransition(){
	if( dxManager->LeftClickedInBox( 98, 98, 240, 130 ) ){
		nextSceneID = Game::SceneID::Achievements;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 98, 540, 130 ) ){
		nextSceneID = Game::SceneID::PlayingRecord;
		return true;
	}

	if( dxManager->LeftClickedInBox( 248, 198, 390, 230 ) ){
		nextSceneID = Game::SceneID::Settings;
		return true;
	}

	if( dxManager->LeftClickedInBox( 98, 298, 240, 330 ) ){
		nextSceneID = Game::SceneID::GuestMatching;
		return true;
	}

	if( dxManager->LeftClickedInBox( 398, 298, 540, 330 ) ){
		nextSceneID = Game::SceneID::HostMatching;
		return true;
	}
	return false;
}

bool Title::IsTitleScene(){
	return true;
}

std::unique_ptr<IScene> Title::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::Achievements :
			return std::make_unique<Achievements>();

		case Game::SceneID::PlayingRecord :
			return std::make_unique<PlayingRecord>();

		case Game::SceneID::Settings :
			return std::make_unique<Settings>();

		case Game::SceneID::GuestMatching :
			return std::make_unique<GuestMatching>();

		case Game::SceneID::HostMatching :
			return std::make_unique<HostMatching>();

		default :
			// 何らかのシーン遷移エラー発生時
			return std::make_unique<Error>();
	}
}

Game::SceneID Title::GetSceneID() const{
	return Game::SceneID::Title;
}

}