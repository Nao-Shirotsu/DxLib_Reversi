#include "DxLib.h"

#include "DX_ConstantValues.h"
#include "DX_Object_ClickButton.h"
#include "DX_Core.h"


namespace DX::Object{

ClickButton::ClickButton( std::shared_ptr<DX::UtilManager> dxManager_, const std::string & text_, int x1_, int y1_ ):
	dxManager( dxManager_ ),
	text( text_ ),
	x1( x1_ ),
	y1( y1_ ){
	strX = x1_ + GetDrawStringWidth( "A", 1 ) * 2 / 3;
	strY = y1_ + GetDrawStringWidth( "A", 1 ) * 2 / 3;
	x2 = x1_ + GetDrawStringWidth( text.c_str(), int( text.size() ) ) + GetDrawStringWidth( "AA", 2 ) * 2 / 3;
	y2 = y1_ + GetDrawStringWidth( "AAA", 3 );;
}

ClickButton::ClickButton( std::shared_ptr<DX::UtilManager> dxManager_, int x1_, int y1_, int x2_, int y2_ ):
	dxManager( dxManager_ ),
	text( "" ),
	x1( x1_ ),
	y1( y1_ ),
	x2( x2_ ),
	y2( y2_ ){}

ClickButton::ClickButton(){}

void ClickButton::Draw() const{
	DrawBox( x1, y1, x2, y2, COLOR_WHITE, NO_FILL );
	DrawString( strX, strY, text.c_str(), COLOR_WHITE );
}

bool ClickButton::WasLeftClicked() const{
	return dxManager->LeftClickedInBox( x1, y1, x2, y2 );
}

}
