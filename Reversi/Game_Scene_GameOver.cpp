#include <memory>

#include "Game_Scene_GameOver.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

GameOver::GameOver(){
	using namespace Game;
	using namespace Resource;

	soundObjects.try_emplace(
		SoundIndex::Decide,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Decide, false ) );

	clickbuttons.try_emplace(
		SceneID::Title,
		std::make_unique<DX::Object::ClickButton>( dxManager, "タイトルへ戻る", 100, 100 ) );
}

GameOver::~GameOver(){}

void GameOver::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void GameOver::Update(){}

void GameOver::Draw() const{
	dxManager->DrawStr( "ゲームオーバー！", 100, 60 );
	DrawAllClickButtons();
}

bool GameOver::NeedsTransition(){
	using namespace Game;
	if( clickbuttons[SceneID::Title]->WasLeftClicked() ){
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}
	return false;
}

bool GameOver::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> GameOver::TransitionToNext() const{
	return std::make_unique<Title>();
}

Game::SceneID GameOver::GetSceneID() const{
	return Game::SceneID::GameOver;
}

}