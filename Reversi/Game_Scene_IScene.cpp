#include "Game_Scene_IScene.h"

namespace Game::Scene{

IScene::~IScene(){}

void IScene::DrawAllClickButtons() const{
	for( const auto& button : clickbuttons ){
		button.second->Draw();
	}
}

}