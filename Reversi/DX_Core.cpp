#include <iostream>

#include "DxLib.h"

#include "DX_ConstantValues.h"
#include "DX_Core.h"
#include "Util.h"

namespace DX{

Core::Core():
	UtilManager(),
	dxError( false ){
	ChangeWindowMode( SET_WINDOW_MODE );
	SetDrawScreen( SCREEN_BACK );
	SetGraphMode( WINDOW_WIDTH_X, WINDOW_WIDTH_Y, COLOR_BIT_NUM );
	SetMainWindowText( Util::ToCharPtr( "リバーシ　オンライン対戦" ) );
	dxError = DxLib_Init();
	ChangeFont("M+ 2m light"); //Fontインストール済じゃないと意味ないよ
}

Core::~Core(){
	DxLib_End();
}

void Core::Update(){
	GetHitKeyStateAll( keyState );
	cursol->SetClickFlag( !GetMouseInputLog2( cursol->GetPtrClickButtonType(), cursol->GetPtrPosX(), cursol->GetPtrPosY(), cursol->GetPtrClickLogType() ) );
	GetMousePoint( cursol->GetPtrPosX(), cursol->GetPtrPosY() );
	dxError = ProcessMessage();
}

void Core::Draw() const{
	ScreenFlip();
	ClearDrawScreen();
}

bool Core::HasError() const{
	return dxError;
}

}