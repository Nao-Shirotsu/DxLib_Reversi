#include "Game_Core.h"

namespace Game{

Core::Core():
	dxManager( std::make_shared<DX::Manager>() ),
	networkManager( nullptr ){
	sceneStack.push( std::make_unique<Scene::Title>() );
	sceneStack.top()->SetDXManagerPtr( dxManager );
}

Core::~Core(){}

bool Core::IsGameEnd() const{
	return dxManager->HasError();
}

void Core::Update(){
	if( sceneStack.top()->NeedsTransition() ){
		auto&& nextScene = sceneStack.top()->TransitionToNext();
		if( nextScene ){
			if( nextScene->GetSceneID() == Game::SceneID::Title ){
				// ゲームが一周プレイされてしてタイトル画面に戻ってくる直前
				// Titleシーンの実体を生成する前にsceneStackを空にする
				DestructAllSceneObjects();
			}

			nextScene->SetDXManagerPtr( dxManager );
			sceneStack.push( std::move( nextScene ) );
		}
		else{
			sceneStack.pop();
		}
	}
	dxManager->Update();
	sceneStack.top()->Update();
}

void Core::Draw() const{
	dxManager->Draw();
	sceneStack.top()->Draw();
}

void Core::DestructAllSceneObjects(){
	while( !sceneStack.empty() ){
		sceneStack.pop();
	}
}
	
}