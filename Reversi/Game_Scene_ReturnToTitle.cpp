#include <memory>

#include "Game_Scene_ReturnToTitle.h"
#include "Game_Scene_Title.h"
#include "Game_Scene_Pause.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

ReturnToTitle::ReturnToTitle():
	nextSceneID( Game::SceneID::ReturnToTitle ){
	using namespace Game;
	using namespace Resource;

	soundObjects.try_emplace(
		SoundIndex::Decide,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Decide, false ) );

	clickbuttons.try_emplace( 
		SceneID::Title,
		std::make_unique<DX::Object::ClickButton>( dxManager, "切断する", 300, 100 ) );

	clickbuttons.try_emplace( SceneID::Pause,
		std::make_unique<DX::Object::ClickButton>( dxManager, "ゲームに戻る", 100, 100 ) );
}

ReturnToTitle::~ReturnToTitle(){}

void ReturnToTitle::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void ReturnToTitle::Update(){}

void ReturnToTitle::Draw() const{
	dxManager->DrawStr( "通信を切断しますか？", 100, 60 );
	DrawAllClickButtons();
}

bool ReturnToTitle::NeedsTransition(){
	if( clickbuttons[SceneID::Pause]->WasLeftClicked() ){
		soundObjects[Resource::SoundIndex::Decide]->Play();
		nextSceneID = Game::SceneID::Pause;
		return true;
	}

	if( clickbuttons[SceneID::Title]->WasLeftClicked() ){
		soundObjects[Resource::SoundIndex::Decide]->Play();
		nextSceneID = Game::SceneID::Title;
		return true;
	}
	return false;
}

bool ReturnToTitle::IsTitleScene(){
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