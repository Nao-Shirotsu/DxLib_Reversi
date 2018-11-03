#include "Game_Core.h"

namespace Game{

Core::Core():
	scene( std::make_unique<Scene::Title>() ),
	dxManager( std::make_shared<DX::Manager>() ),
	networkManager( nullptr ),
	criticalError( false ),
	endFlag( false ){
	scene->SetDXManagerPtr( dxManager );
	criticalError = dxManager->HasError();
}

Core::~Core(){}

bool Core::IsGameEnd() const{
	return false;
}

void Core::Update(){
	std::unique_ptr<Scene::IScene>&& nextScene = scene->TransitionToNext();
	if( nextScene ){
		scene = std::move( nextScene );
	}
	dxManager->Update();
	scene->Update();
}

void Core::Draw() const{
	scene->Draw();
}
	
}