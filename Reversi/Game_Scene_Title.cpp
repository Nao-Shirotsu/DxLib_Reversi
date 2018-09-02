#include "Game_Scene_Title.h"

namespace Game::Scene{

Title::Title(){}

Title::~Title(){}

void Title::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Title::Update(){}

void Title::Draw(){}

std::unique_ptr<IScene> Title::TransitionToNext(){
	return nullptr;
}

}