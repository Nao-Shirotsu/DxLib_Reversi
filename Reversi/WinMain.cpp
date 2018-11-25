#include <windows.h>
#include "Game_Core.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){
	Game::Core gamecore;
	while( !gamecore.IsGameEnd() ){
		gamecore.Update();
		gamecore.Draw();
	}
	return 0;
}