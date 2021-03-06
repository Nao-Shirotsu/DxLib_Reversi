﻿#include <memory>

#include "Game_Scene_Pause.h"
#include "Game_Scene_ReturnToTitle.h"
#include "Game_Scene_GamePlay.h"
#include "Game_Scene_Error.h"

namespace Game::Scene{

Pause::Pause():
	nextSceneID( Game::SceneID::Pause ){
	using namespace Game;
	clickbuttons[SceneID::GamePlay] = DX::Object::ClickButton( dxManager, "ゲームに戻る", 100, 100 );
	clickbuttons[SceneID::ReturnToTitle] = DX::Object::ClickButton( dxManager, "ルーム退出", 300, 100 );
}

Pause::~Pause(){}

void Pause::SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager_ ){
	dxManager = dxManager_;
}

void Pause::Update(){}

void Pause::Draw() const{
	dxManager->DrawStr( "ポーズ中", 0, 0 );
	DrawAllClickButtons();
}

bool Pause::NeedsTransition(){
	if( clickbuttons[SceneID::GamePlay].WasLeftClicked() ){
		nextSceneID = Game::SceneID::GamePlay;
		return true;
	}

	if( clickbuttons[SceneID::ReturnToTitle].WasLeftClicked() ){
		nextSceneID = Game::SceneID::ReturnToTitle;
		return true;
	}
	return false;
}

bool Pause::IsTitleScene(){
	return false;
}

std::unique_ptr<IScene> Pause::TransitionToNext() const{
	switch( nextSceneID ){
		case Game::SceneID::GamePlay:
			return nullptr;

		case Game::SceneID::ReturnToTitle:
			return std::make_unique<ReturnToTitle>();

		default:
			// 予期せぬ値の時はErrorシーンに遷移
			return std::make_unique<Error>();
	}
}

Game::SceneID Pause::GetSceneID() const{
	return Game::SceneID::Pause;
}

}