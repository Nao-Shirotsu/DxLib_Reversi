#include "DxLib.h"

#include "DX_UtilManager.h"
#include "DX_ConstantValues.h"
#include "Util.h"

namespace DX{

std::unique_ptr<MouseCursol> UtilManager::cursol = std::make_unique<MouseCursol>();

UtilManager::UtilManager(){}

UtilManager::~UtilManager(){}

void UtilManager::Load( Resource::PicIndex index ) const{
	Resource::Manager::GetPicPath( index );
}

void UtilManager::Load( Resource::SoundIndex index ) const{}

void UtilManager::DrawStr( const std::string& text, int x, int y ) const{
	DrawString( x, y, Util::ToCharPtr( text.c_str() ), COLOR_WHITE );
}

void UtilManager::DrawRect( int x1, int y1, int x2, int y2 ) const{
	DrawBox( x1, y1, x2, y2, COLOR_WHITE, NO_FILL );
}

void UtilManager::DrawPic( Resource::PicIndex index ) const{}

void UtilManager::Play( Resource::SoundIndex index ) const{}

bool UtilManager::IsKeyDown( KeyCode key ) const{
	return keyState[static_cast< int >( key )];
}

bool UtilManager::LeftClickedInBox( int x1, int y1, int x2, int y2 ){

	cursol->ClickLogChanged();
	cursol->GetClickButtonType();

 	if( cursol->ClickLogChanged() && ( cursol->GetClickButtonType() & MOUSE_LEFT ) ){
		if( cursol->GetClickLogType() == MOUSE_LOG_DOWN ){
			cursol->SetLastClickPosX( cursol->GetPosX() );
			cursol->SetLastClickPosY( cursol->GetPosY() );
		}
		else{
			int posX = cursol->GetLastClickPosX();
			int posY = cursol->GetLastClickPosY();
			int currentX = cursol->GetPosX();
			int currentY = cursol->GetPosY();
			if( x1 <= posX && posX <= x2 &&
				y1 <= posY && posY <= y2 &&
				x1 <= currentX && currentX <= x2 &&
				y1 <= currentY && currentY <= y2 ){
				return true;
			}
		}
	}
	return false;
}

}