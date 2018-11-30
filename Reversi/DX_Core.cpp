#include <iostream>

#include "DxLib.h"

#include "DX_ConstantValues.h"
#include "DX_Core.h"
#include "Util.h"

#include "DX_Object_SoundPlayer.h"

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
	SetFontSize( 20 );

	//-----test------
	//Load( Resource::SoundIndex::Decide );
	//Load( Resource::SoundIndex::Piano );
	//---------------
}

Core::~Core(){
	DxLib_End();
}

void Core::Update(){
	dxError = ProcessMessage();
	GetHitKeyStateAll( keyState );
	cursol->SetClickFlag( !GetMouseInputLog2( cursol->GetPtrClickButtonType(), cursol->GetPtrPosX(), cursol->GetPtrPosY(), cursol->GetPtrClickLogType() ) );
	GetMousePoint( cursol->GetPtrPosX(), cursol->GetPtrPosY() );

	//-----test----
	//if( LeftClickedInBox( 600, 500, 650, 550 ) ){
	//	Play( Resource::SoundIndex::Decide, false );
	//}
	//Play( Resource::SoundIndex::Jazz, true );
	//Play( Resource::SoundIndex::Piano, true );
	//-------------
}

void Core::Draw() const{
	ScreenFlip();
	ClearDrawScreen();

	//-----test-----
	//DrawBox( 600, 500, 650, 550, COLOR_WHITE, NO_FILL );
	//--------------
}

bool Core::HasError() const{
	return dxError;
}

}