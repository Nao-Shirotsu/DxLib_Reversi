#include <iostream>

#include "DxLib.h"
#include "DX_Manager.h"
#include "Network_Manager.h"
#include "Util.h"

namespace{
	constexpr int WINDOW_WIDTH_X = 800;
	constexpr int WINDOW_WIDTH_Y = 600;
	constexpr int COLOR_BIT_NUM = 16;
	constexpr int MOUSE_LEFT = MOUSE_INPUT_LEFT;
	constexpr int MOUSE_LOG_UP = MOUSE_INPUT_LOG_UP;
	constexpr int MOUSE_LOG_DOWN = MOUSE_INPUT_LOG_DOWN;
	constexpr int TRUE_WINDOW_MODE = TRUE;
	constexpr int SCREEN_BACK = DX_SCREEN_BACK;
	constexpr int NO_FILL = FALSE;
}

namespace DX{

class Manager::CursolState{
public:
	CursolState():
	posX( 0 ),
	posY( 0 ),
	lastClicking_posX( 0 ),
	lastClicking_posY( 0 ),
	clickButton( MOUSE_LEFT ),
	clickLogType( MOUSE_LOG_UP ),
	clickFlag( false ){}

	~CursolState(){}

	int posX;
	int posY;
	int lastClicking_posX;
	int lastClicking_posY;
	int clickButton;
	int clickLogType;

	// クリックされた瞬間と離した瞬間ならtrue, それ以外false
	bool clickFlag;
};

Manager::Manager():
	dxError( false ),
	cursol( std::make_unique<CursolState>() ){
	ChangeWindowMode( TRUE_WINDOW_MODE );
	SetDrawScreen( SCREEN_BACK );
	SetGraphMode( WINDOW_WIDTH_X, WINDOW_WIDTH_Y, COLOR_BIT_NUM );
	SetMainWindowText( Util::ToCharPtr( "リバーシ　オンライン対戦" ) );
	dxError = DxLib_Init();
}

Manager::~Manager(){
	DxLib_End();
}

void Manager::Update(){
	dxError = ProcessMessage();
	GetHitKeyStateAll( keyState );
	cursol->clickFlag = !GetMouseInputLog2( &cursol->clickButton, &cursol->posX, &cursol->posY, &cursol->clickLogType, TRUE );
	GetMousePoint( &cursol->posX, &cursol->posY );
}

void Manager::Load( Resource::PicIndex index ) const{
	Resource::Manager::GetPicPath( index );
}

void Manager::Load( Resource::SoundIndex index ) const{}

void Manager::Draw( std::string text, int x, int y ) const{
	ScreenFlip();
	ClearDrawScreen();
	const unsigned int& white = GetColor( 255, 255, 255 ); //白色
	DrawString( x, y, Util::ToCharPtr( text.c_str() ), white );

	// following : test code
	DrawBox( 96, 396, 240, 430, white, NO_FILL );
	DrawBox( 296, 396, 440, 430, white, NO_FILL );
	clsDx();
	printfDx( "(%d, %d)\n", cursol->lastClicking_posX, cursol->lastClicking_posY );
	printfDx( " ClickLog : %d\n", cursol->clickLogType );
	printfDx( " ClickFlag : %d\n", cursol->clickFlag );
	printfDx( " ClickState : %d\n", cursol->clickButton );
}

void Manager::Draw( Resource::PicIndex index ) const{}

void Manager::Play( Resource::SoundIndex index ) const{}

bool Manager::HasError() const{
	return dxError;
}

bool Manager::IsKeyDown( KeyCode key ) const{
	return keyState[static_cast<int>( key )];
}

bool Manager::LeftClickedInBox( int x1, int y1, int x2, int y2 ){
	if( cursol->clickFlag && IsLeftButtonDown() ){
		if( cursol->clickLogType == MOUSE_LOG_DOWN ){
			cursol->lastClicking_posX = GetCursolPosX();
			cursol->lastClicking_posY = GetCursolPosY();
		}
		else{
			int posX = cursol->lastClicking_posX;
			int posY = cursol->lastClicking_posY;
			int currentX = GetCursolPosX();
			int currentY = GetCursolPosY();
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

int Manager::GetCursolPosX() const{
	return cursol->posX;
}

int Manager::GetCursolPosY() const{
	return cursol->posY;
}

bool Manager::IsLeftButtonDown() const{
	return cursol->clickButton & MOUSE_LEFT;
}

}