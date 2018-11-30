#include <memory>

#include "Game_Scene_ScoreBoard.h"
#include "Game_Scene_GamePlay.h"

namespace Game::Scene{

ScoreBoard::ScoreBoard(){
	using namespace Game;
	using namespace Resource;

	soundObjects.try_emplace(
		SoundIndex::Decide,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Decide, false ) );

	clickbuttons.try_emplace( 
		SceneID::GamePlay,
		std::make_unique<DX::Object::ClickButton>( dxManager, "ゲームに戻る", 100, 100 ) );
}

ScoreBoard::~ScoreBoard(){}

void ScoreBoard::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void ScoreBoard::Update(){}

void ScoreBoard::Draw() const{
	dxManager->DrawStr( "スコアボード", 0, 0 );
	DrawAllClickButtons();
}

bool ScoreBoard::NeedsTransition(){
	if( clickbuttons[SceneID::GamePlay]->WasLeftClicked() ){
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}
	return false;
}

bool ScoreBoard::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> ScoreBoard::TransitionToNext() const{
	return nullptr;
}

Game::SceneID ScoreBoard::GetSceneID() const{
	return Game::SceneID::ScoreBoard;
}

}