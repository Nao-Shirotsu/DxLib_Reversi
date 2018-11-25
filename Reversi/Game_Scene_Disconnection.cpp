#include <memory>

#include "Game_Scene_Disconnection.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

Disconnection::Disconnection(){
	using namespace Game;
	clickbuttons[SceneID::Title] = DX::Object::ClickButton( dxManager, "タイトルへ戻る", 100, 100 );
}

Disconnection::~Disconnection(){}

void Disconnection::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void Disconnection::Update(){}

void Disconnection::Draw() const{
	dxManager->DrawStr( "通信が切断されました", 100, 60 );
	DrawAllClickButtons();
}

bool Disconnection::NeedsTransition(){
	using namespace Game;
	if( clickbuttons[SceneID::Title].WasLeftClicked() ){
		return true;
	}
	return false;
}

bool Disconnection::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Disconnection::TransitionToNext() const{
	return std::make_unique<Title>();
}

Game::SceneID Disconnection::GetSceneID() const{
	return Game::SceneID::Disconnection;
}

}