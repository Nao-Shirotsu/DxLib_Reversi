#include <memory>

#include "Game_Scene_Title.h"
#include "Game_Scene_Achievements.h"
#include "Game_Scene_PlayingRecord.h"
#include "Game_Scene_GuestMatching.h"
#include "Game_Scene_HostMatching.h"
#include "Game_Scene_Settings.h"
#include "Game_Scene_Error.h"

#include "Resource_Index.h"

namespace Game::Scene{

Title::Title():
	nextSceneID( Game::SceneID::Title ){
	using namespace Game;
	using namespace Resource;

	soundObjects.try_emplace(
		SoundIndex::Piano,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Piano, true ) );

	soundObjects.try_emplace(
		SoundIndex::Decide,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Decide, false ) );

	clickbuttons.try_emplace( 
		SceneID::Achievements, 
		std::make_unique<DX::Object::ClickButton>( dxManager, "実績一覧", 100, 100 ) );

	clickbuttons.try_emplace( 
		SceneID::PlayingRecord,
		std::make_unique<DX::Object::ClickButton>( dxManager, "総合戦績", 400, 100 ) );

	clickbuttons.try_emplace( 
		SceneID::Settings,
		std::make_unique<DX::Object::ClickButton>( dxManager, "システム設定", 250, 200 ) );

	clickbuttons.try_emplace( 
		SceneID::GuestMatching,
		std::make_unique<DX::Object::ClickButton>( dxManager, "対戦(ゲスト)", 100, 300 ) );

	clickbuttons.try_emplace( 
		SceneID::HostMatching,
		std::make_unique<DX::Object::ClickButton>( dxManager, "対戦(ホスト)", 400, 300 ) );

	soundObjects[SoundIndex::Piano]->Play();
}

Title::~Title(){}

void Title::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void Title::Update(){}

void Title::Draw() const{
	dxManager->DrawStr( "タイトル", 0, 0 );
	DrawAllClickButtons();
}

bool Title::NeedsTransition(){
	using namespace Game;
	using namespace Resource;

	if( clickbuttons[SceneID::Achievements]->WasLeftClicked() ){
		nextSceneID = SceneID::Achievements;
		soundObjects[SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::PlayingRecord]->WasLeftClicked() ){
		nextSceneID = SceneID::PlayingRecord;
		soundObjects[SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::Settings]->WasLeftClicked() ){
		nextSceneID = SceneID::Settings;
		soundObjects[SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::GuestMatching]->WasLeftClicked() ){
		nextSceneID = SceneID::GuestMatching;
		soundObjects[SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::HostMatching]->WasLeftClicked() ){
		nextSceneID = SceneID::HostMatching;
		soundObjects[SoundIndex::Decide]->Play();
		return true;
	}
	return false;
}

bool Title::IsTitleScene(){
	return true;
}

std::unique_ptr<IScene> Title::TransitionToNext() const{
	using namespace Game;

	switch( nextSceneID ){
		case SceneID::Achievements :
			return std::make_unique<Achievements>();

		case SceneID::PlayingRecord :
			return std::make_unique<PlayingRecord>();

		case SceneID::Settings :
			return std::make_unique<Settings>();

		case SceneID::GuestMatching :
			return std::make_unique<GuestMatching>();

		case SceneID::HostMatching :
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