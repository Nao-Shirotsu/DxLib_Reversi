#include "DX_Manager.h"
#include "Network_Manager.h"

namespace DX{

Manager::Manager(){}

Manager::~Manager(){}

void Manager::Update(){}

void Manager::Load( Resource::PicIndex index ){
	Resource::Manager::GetPicPath( index );
}

void Manager::Load( Resource::SoundIndex index ){}

void Manager::Draw( std::string text ){}

void Manager::Draw( Resource::PicIndex index ){}

void Manager::Play( Resource::SoundIndex index ){}

char * Manager::ToCharPtr( const char* str ){
	return nullptr;
}

}