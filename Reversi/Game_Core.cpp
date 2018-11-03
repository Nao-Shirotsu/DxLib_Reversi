#include "Game_Core.h"

namespace Game{

Core::Core():
	scene( std::make_unique<Scene::Title>() ),
	dxManager( std::make_shared<DX::Manager>() ),
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	networkManager( nullptr ){
	scene->SetDXManagerPtr( dxManager );
=======
=======
>>>>>>> Stashed changes
	networkManager( nullptr ),
	criticalError( false ),
	endFlag( false ){
	scene->SetDXManagerPtr( dxManager );
	criticalError = dxManager->HasError();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
}

Core::~Core(){}

bool Core::IsGameEnd(){
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	return false;
}

void Core::Update(){
	std::unique_ptr<Scene::IScene> nextScene = scene->TransitionToNext();
=======
=======
>>>>>>> Stashed changes
	return criticalError | endFlag;
}

void Core::Update(){
	std::unique_ptr<Scene::IScene>&& nextScene = scene->TransitionToNext();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
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