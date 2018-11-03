#include "Game_Scene_Title.h"
#include "DX_KeyCode.h"

namespace Game::Scene{

Title::Title(){}

Title::~Title(){}

void Title::SetDXManagerPtr( const std::shared_ptr<DX::IManager>& dxManager_ ){
	dxManager = dxManager_;
}

void Title::Update(){}

void Title::Draw() const{
	if( dxManager->IsKeyDown( DX::KeyCode::D ) ){
		dxManager->Draw( "\'D\' pressed", 200, 290 );
	}
	else{
		dxManager->Draw( "nothing pressed", 100, 100 );
	}

	if( dxManager->LeftClickedInBox( 96, 396, 240, 430 ) ){
		dxManager->Draw( "Left Clicked", 100, 400 );
	}

	if( dxManager->LeftClickedInBox( 296, 396, 440, 430 ) ){
		dxManager->Draw( "Left Clicked", 300, 400 );
	}
}

std::unique_ptr<IScene> Title::TransitionToNext() const{
	return nullptr;
}

}