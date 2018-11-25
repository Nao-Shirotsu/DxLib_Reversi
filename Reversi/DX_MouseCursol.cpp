#include "DX_MouseCursol.h"
#include "DX_ConstantValues.h"

namespace DX{

MouseCursol::MouseCursol():
	UnsettableMouseCursol(){}

void MouseCursol::SetPosX( int x ){
	posX = x;
}

void MouseCursol::SetPosY( int y ){
	posY = y;
}

void MouseCursol::SetLastClickPosX( int lx ){
	lastClickPosX = lx;
}

void MouseCursol::SetLastClickPosY( int ly ){
	lastClickPosY = ly;
}

void MouseCursol::SetClickButtonType( int buttonType ){
	clickButtonType = buttonType;
}

void MouseCursol::SetClickLogType( int logType ){
	clickLogType = logType;
}

void MouseCursol::SetClickFlag( bool flag ){
	clickFlag = flag;
}

int * MouseCursol::GetPtrPosX(){
	return &posX;
}

int * MouseCursol::GetPtrPosY(){
	return &posY;
}

int * MouseCursol::GetPtrClickButtonType(){
	return &clickButtonType;
}

int * MouseCursol::GetPtrClickLogType(){
	return &clickLogType;
}

}