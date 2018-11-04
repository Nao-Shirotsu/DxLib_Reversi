#include "DX_EmptyManager.h"

namespace DX{

EmptyManager::EmptyManager(){}

EmptyManager::~EmptyManager(){}

void EmptyManager::Update(){}

void EmptyManager::Draw() const{}

void EmptyManager::Load( Resource::PicIndex index ) const{}

void EmptyManager::Load( Resource::SoundIndex index ) const{}

void EmptyManager::DrawStr( const std::string& text, int x, int y ) const{}

void EmptyManager::DrawRect( int x1, int y1, int x2, int y2 ) const{}

void EmptyManager::DrawPic( Resource::PicIndex index ) const{}

void EmptyManager::Play( Resource::SoundIndex index ) const{}

bool EmptyManager::HasError() const{
	return false;
}

bool EmptyManager::IsKeyDown( KeyCode key ) const{
	return false;
}

bool EmptyManager::LeftClickedInBox( int x1, int y1, int x2, int y2 ){
	return false;
}

int EmptyManager::GetCursolPosX() const{
	return 0;
}

int EmptyManager::GetCursolPosY() const{
	return 0;
}

}