#include "DX_EmptyManager.h"

namespace DX{

EmptyManager::EmptyManager(){
	
}

EmptyManager::~EmptyManager(){

}

void EmptyManager::Update(){

}

void EmptyManager::Load( Resource::PicIndex index ){

}

void EmptyManager::Load( Resource::SoundIndex index ){

}

<<<<<<< Updated upstream
void EmptyManager::Draw( std::string text ){
=======
void EmptyManager::Draw( std::string text, int x, int y ){
>>>>>>> Stashed changes

}

void EmptyManager::Draw( Resource::PicIndex index ){

}

void EmptyManager::Play( Resource::SoundIndex index ){

}

<<<<<<< Updated upstream
=======
bool EmptyManager::HasError(){
	return false;
}

>>>>>>> Stashed changes


}