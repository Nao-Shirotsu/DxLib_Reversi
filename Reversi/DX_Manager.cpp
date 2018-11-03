<<<<<<< Updated upstream
#include "DX_Manager.h"
#include "Network_Manager.h"

namespace DX{

Manager::Manager(){}

Manager::~Manager(){}

void Manager::Update(){}
=======
#include "DxLib.h"

#include "DX_Manager.h"
#include "Network_Manager.h"

namespace{
	constexpr int WINDOW_WIDTH_X = 800;
	constexpr int WINDOW_WIDTH_Y = 600;
	constexpr int COLOR_BIT_NUM = 16;
}

namespace DX{

Manager::Manager() : dxError( false ){
	ChangeWindowMode( TRUE );
	SetGraphMode( WINDOW_WIDTH_X, WINDOW_WIDTH_Y, COLOR_BIT_NUM );
	SetMainWindowText( Util::ToCharPtr( "リバーシ　オンライン対戦" ) );
	dxError = DxLib_Init();
}

Manager::~Manager(){
	DxLib_End();
}

void Manager::Update(){
	dxError = ProcessMessage();
}
>>>>>>> Stashed changes

void Manager::Load( Resource::PicIndex index ){
	Resource::Manager::GetPicPath( index );
}

void Manager::Load( Resource::SoundIndex index ){}

<<<<<<< Updated upstream
void Manager::Draw( std::string text ){}
=======
void Manager::Draw( std::string text, int x, int y ){
	// 白色を取得
	unsigned int color = GetColor( 255, 255, 255 );
	DrawString( x, y, Util::ToCharPtr( text.c_str() ), color );
}
>>>>>>> Stashed changes

void Manager::Draw( Resource::PicIndex index ){}

void Manager::Play( Resource::SoundIndex index ){}

<<<<<<< Updated upstream
char * Manager::ToCharPtr( const char* str ){
	return nullptr;
=======
bool Manager::HasError(){
	return dxError;
>>>>>>> Stashed changes
}

}