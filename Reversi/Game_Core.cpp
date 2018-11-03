#include "Game_Core.h"

namespace Game{

Core::Core():
	scene( std::make_unique<Scene::Title>() ),
	dxManager( std::make_shared<DX::Manager>() ),
<<<<<<< Updated upstream
	networkManager( nullptr ){
	scene->SetDXManagerPtr( dxManager );
=======
	networkManager( nullptr ),
	criticalError( false ),
	endFlag( false ){
	scene->SetDXManagerPtr( dxManager );
	criticalError = dxManager->HasError();
>>>>>>> Stashed changes
}

Core::~Core(){}

bool Core::IsGameEnd(){
<<<<<<< Updated upstream
	return false;
}

void Core::Update(){
	std::unique_ptr<Scene::IScene> nextScene = scene->TransitionToNext();
=======
	return criticalError | endFlag;
}

void Core::Update(){
	std::unique_ptr<Scene::IScene>&& nextScene = scene->TransitionToNext();
>>>>>>> Stashed changes
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