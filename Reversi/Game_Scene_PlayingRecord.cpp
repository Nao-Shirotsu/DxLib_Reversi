﻿#include <memory>

#include "Game_Scene_PlayingRecord.h"
#include "Game_Scene_Title.h"

namespace Game::Scene{

PlayingRecord::PlayingRecord(){
	using namespace Game;
	clickbuttons[SceneID::Title] = DX::Object::ClickButton( dxManager, "タイトルへ戻る", 100, 100 );
}

PlayingRecord::~PlayingRecord(){}

void PlayingRecord::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void PlayingRecord::Update(){}

void PlayingRecord::Draw() const{
	dxManager->DrawStr( "総合戦績", 0, 0 );
	DrawAllClickButtons();
}

bool PlayingRecord::NeedsTransition(){
	if( clickbuttons[SceneID::Title].WasLeftClicked() ){
		return true;
	}
	return false;
}

bool PlayingRecord::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> PlayingRecord::TransitionToNext() const{
	return nullptr;
}

Game::SceneID PlayingRecord::GetSceneID() const{
	return Game::SceneID::PlayingRecord;
}

}