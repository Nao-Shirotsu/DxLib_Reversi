#include "DX_UnsettableMouseCursol.h"
#include "DX_ConstantValues.h"

namespace DX{

UnsettableMouseCursol::UnsettableMouseCursol():
	posX( 0 ),
	posY( 0 ),
	lastClickPosX( 0 ),
	lastClickPosY( 0 ),
	clickButtonType( MOUSE_LEFT ),
	clickLogType( MOUSE_LOG_UP ),
	clickFlag( false ){}

int UnsettableMouseCursol::GetPosX() const{
	return posX;
}

int UnsettableMouseCursol::GetPosY() const{
	return posY;
}

int UnsettableMouseCursol::GetLastClickPosX() const{
	return lastClickPosX;
}

int UnsettableMouseCursol::GetLastClickPosY() const{
	return lastClickPosY;
}

int UnsettableMouseCursol::GetClickButtonType() const{
	return clickButtonType;
}

int UnsettableMouseCursol::GetClickLogType() const{
	return clickLogType;
}

bool UnsettableMouseCursol::ClickLogChanged() const{
	return clickFlag;
}

}