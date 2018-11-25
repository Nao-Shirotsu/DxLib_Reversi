#pragma once

#include "DX_UnsettableMouseCursol.h"

namespace DX{

// マウスカーソルの状態を格納する構造体 (セットもゲットも可)
class MouseCursol: public UnsettableMouseCursol{
public:
	MouseCursol();
	void SetPosX( int x );
	void SetPosY( int y );

	void SetLastClickPosX( int lx );
	void SetLastClickPosY( int ly );

	void SetClickButtonType( int buttonType );
	void SetClickLogType( int logType );

	void SetClickFlag( bool flag );

	// DxLibのGetMouseInputLog2()などで使うPtrGetters
	int* GetPtrPosX();
	int* GetPtrPosY();
	int* GetPtrClickButtonType();
	int* GetPtrClickLogType();
};

}