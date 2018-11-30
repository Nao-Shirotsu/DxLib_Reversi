#include <memory>

#include "Game_Scene_Achievements.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

Achievements::Achievements(){
	using namespace Game;
	using namespace Resource;

	soundObjects.try_emplace(
		SoundIndex::Decide,
		std::make_unique<DX::Object::SoundPlayer>( dxManager, SoundIndex::Decide, false ) );

	clickbuttons.try_emplace( 
		SceneID::Title,
		std::make_unique<DX::Object::ClickButton>( dxManager, "タイトルへ戻る", 100, 100 ) );
}

Achievements::~Achievements(){}

void Achievements::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void Achievements::Update(){}

void Achievements::Draw() const{
	dxManager->DrawStr( "実績一覧", 0, 0 );
	DrawAllClickButtons();
}

bool Achievements::NeedsTransition(){
	using namespace Game;
	if( clickbuttons[SceneID::Title]->WasLeftClicked() ){
		soundObjects[Resource::SoundIndex::Decide]->Play();
		return true;
	}
	return false;
}

bool Achievements::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Achievements::TransitionToNext() const{
	return nullptr;
}

Game::SceneID Achievements::GetSceneID() const{
	return Game::SceneID::Achievements;
}

}