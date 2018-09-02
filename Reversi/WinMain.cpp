#include "DxLib.h"
#include "Game_Core.h"

// ƒvƒƒOƒ‰ƒ€‚Í WinMain ‚©‚çn‚Ü‚è‚Ü‚·
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){
	Game::Core gamecore;
	while( !gamecore.IsGameEnd() ){
		gamecore.Update();
		gamecore.Draw();
	}
	return 0;
}