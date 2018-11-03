#pragma once

#include <memory>

#include "DX_IManager.h"
#include "Resource_Manager.h"

namespace DX{

// DxLib関数のラッパークラス
class Manager : public IManager, public Resource::Manager{
public:
	Manager();
	~Manager();
	void Update();
	void Load( Resource::PicIndex index ) const;
	void Load( Resource::SoundIndex index ) const;
	void Draw( std::string text, int x, int y ) const;
	void Draw( Resource::PicIndex index ) const;
	void Play( Resource::SoundIndex index ) const;
	bool HasError() const;
	bool IsKeyDown( KeyCode key ) const;
	bool LeftClickedInBox( int x1, int y1, int x2, int y2 );

private:
	int GetCursolPosX() const;
	int GetCursolPosY() const;

	// マウス左ボタンでクリックされたかどうか
	bool IsLeftButtonDown() const;

	bool dxError;
	static inline char keyState[256];
	class CursolState;
	std::unique_ptr<CursolState> cursol;
};

}