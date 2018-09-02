#include "Game_Core.h"

namespace Game{

Core::Core():
	scene( std::make_unique<Scene::Title>() ),
	dxManager( std::make_shared<DX::Manager>() ),
	networkManager( nullptr ){
	scene->SetDXManagerPtr( dxManager );
}

Core::~Core(){}

bool Core::IsGameEnd(){
	return false;
}

void Core::Update(){
	std::unique_ptr<Scene::IScene> nextScene = std::move( scene->TransitionToNext() );
	if( nextScene ){
		scene = std::move( nextScene );
	}
	scene->Update();
	dxManager->Update();
}

void Core::Draw(){
	scene->Draw();
}
	
}