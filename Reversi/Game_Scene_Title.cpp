#include "Game_Scene_Title.h"
<<<<<<< Updated upstream
=======
#include "DX_KeyCode.h"
>>>>>>> Stashed changes

namespace Game::Scene{

Title::Title(){}

Title::~Title(){}

void Title::SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void Title::Update(){}

void Title::Draw(){}
=======
=======
>>>>>>> Stashed changes
void Title::Update(){

}

void Title::Draw(){
<<<<<<< Updated upstream
	dxManager->Draw( "DxLib Reversi Project", 200, 290 );
}
>>>>>>> Stashed changes
=======
	if( dxManager->IsKeyDown( DX::KeyCode::D ) ){
		dxManager->Draw( "\'D\' pressed", 200, 290 );
	}else{
		dxManager->Draw( "nothing pressed", 100, 100 );
	}
}
>>>>>>> Stashed changes

std::unique_ptr<IScene> Title::TransitionToNext(){
	return nullptr;
}

}