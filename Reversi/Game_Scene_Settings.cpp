#include <memory>

#include "Game_Scene_Settings.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

Settings::Settings(){
	using namespace Game;
	clickbuttons[SceneID::Title] = DX::Object::ClickButton( dxManager, "タイトルへ戻る", 100, 100 );
}

Settings::~Settings(){}

void Settings::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void Settings::Update(){}

void Settings::Draw() const{
	dxManager->DrawStr( "システム設定", 0, 0 );
	DrawAllClickButtons();
}

bool Settings::NeedsTransition(){
	if( clickbuttons[SceneID::Title].WasLeftClicked() ){
		return true;
	}
	return false;
}

bool Settings::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Settings::TransitionToNext() const{
	return nullptr;
}

Game::SceneID Settings::GetSceneID() const{
	return Game::SceneID::Settings;
}

}