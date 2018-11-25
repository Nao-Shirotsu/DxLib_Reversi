#include <memory>

#include "Game_Scene_GuestMatching.h"
#include "Game_Scene_Title.h"
#include "Game_Scene_GamePlay.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

GuestMatching::GuestMatching():
	nextSceneID( Game::SceneID::GuestMatching ){
	using namespace Game;
	clickbuttons[SceneID::Title] = DX::Object::ClickButton( dxManager, "タイトルへ戻る", 100, 100 );
	clickbuttons[SceneID::GamePlay] = DX::Object::ClickButton( dxManager, "マッチング完了", 400, 300 );
}

GuestMatching::~GuestMatching(){}

void GuestMatching::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void GuestMatching::Update(){}

void GuestMatching::Draw() const{
	dxManager->DrawStr( "対戦相手を検索します", 100, 60 );
	DrawAllClickButtons();
}

bool GuestMatching::NeedsTransition(){
	if( clickbuttons[SceneID::Title].WasLeftClicked() ){
		nextSceneID = Game::SceneID::Title;
		return true;
	}

	if( clickbuttons[SceneID::GamePlay].WasLeftClicked() ){
		nextSceneID = Game::SceneID::GamePlay;
		return true;
	}

	return false;
}

bool GuestMatching::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> GuestMatching::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::Title:
			return nullptr;

		case Game::SceneID::GamePlay:
			return std::make_unique<GamePlay>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID GuestMatching::GetSceneID() const{
	return Game::SceneID::GuestMatching;
}

}