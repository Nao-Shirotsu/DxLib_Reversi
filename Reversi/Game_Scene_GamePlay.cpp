#include <memory>

#include "Game_Scene_GamePlay.h"
#include "Game_Scene_ScoreBoard.h"
#include "Game_Scene_GameOver.h"
#include "Game_Scene_Pause.h"
#include "Game_Scene_Disconnection.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

GamePlay::GamePlay():
	nextSceneID( Game::SceneID::GamePlay ){
	using namespace Game;
	using namespace Resource;

	soundObjects.try_emplace(
		SoundIndex::Decide,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Decide, false ) );

	clickbuttons.try_emplace( 
		SceneID::ScoreBoard,
		std::make_unique<DX::Object::ClickButton>( dxManager, "スコアボード", 100, 100 ) );

	clickbuttons.try_emplace( 
		SceneID::Disconnection,
		std::make_unique<DX::Object::ClickButton>( dxManager, "通信切断", 400, 100 ) );

	clickbuttons.try_emplace( 
		SceneID::Pause,
		std::make_unique<DX::Object::ClickButton>( dxManager, "ポーズ", 100, 300 ) );

	clickbuttons.try_emplace( 
		SceneID::GameOver,
		std::make_unique<DX::Object::ClickButton>( dxManager, "ゲームオーバー", 400, 300 ) );
}

GamePlay::~GamePlay(){}

void GamePlay::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void GamePlay::Update(){}

void GamePlay::Draw() const{
	dxManager->DrawStr( "対局中...", 0, 0 );
	DrawAllClickButtons();
}

bool GamePlay::NeedsTransition(){
	if( clickbuttons[SceneID::ScoreBoard]->WasLeftClicked() ){
		nextSceneID = Game::SceneID::ScoreBoard;
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::Disconnection]->WasLeftClicked() ){
		nextSceneID = Game::SceneID::Disconnection;
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::Pause]->WasLeftClicked() ){
		nextSceneID = Game::SceneID::Pause;
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}

	if( clickbuttons[SceneID::GameOver]->WasLeftClicked() ){
		nextSceneID = Game::SceneID::GameOver;
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}
	return false;
}

bool GamePlay::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> GamePlay::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::ScoreBoard:
			return std::make_unique<ScoreBoard>();

		case Game::SceneID::Disconnection:
			return std::make_unique<Disconnection>();

		case Game::SceneID::Pause:
			return std::make_unique<Pause>();

		case Game::SceneID::GameOver:
			return std::make_unique<GameOver>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID GamePlay::GetSceneID() const{
	return Game::SceneID::GamePlay;
}

}