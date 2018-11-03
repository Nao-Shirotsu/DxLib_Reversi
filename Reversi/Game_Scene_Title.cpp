#include "Game_Scene_Title.h"

namespace Game::Scene{

Title::Title(){}

Title::~Title(){}

void Title::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

<<<<<<< Updated upstream
void Title::Update(){}

void Title::Draw(){}
=======
void Title::Update(){

}

void Title::Draw(){
	dxManager->Draw( "DxLib Reversi Project", 200, 290 );
}
>>>>>>> Stashed changes

std::unique_ptr<IScene> Title::TransitionToNext(){
	return nullptr;
}

}