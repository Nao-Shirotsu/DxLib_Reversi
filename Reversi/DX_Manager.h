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
	void Draw() const;
	void Load( Resource::PicIndex index ) const;
	void Load( Resource::SoundIndex index ) const;
	void DrawStr( const std::string& text, int x, int y ) const;
	void DrawRect( int x1, int y1, int x2, int y2 ) const;
	void DrawPic( Resource::PicIndex index ) const;
	void Play( Resource::SoundIndex index ) const;
	bool HasError() const;
	bool IsKeyDown( KeyCode key ) const;
	bool LeftClickedInBox( int x1, int y1, int x2, int y2 );

private:
	int GetCursolPosX() const;
	int GetCursolPosY() const;
	bool IsLeftButtonDown() const;

	bool dxError;
	static inline char keyState[256];
	class CursolState;
	std::unique_ptr<CursolState> cursol;
};

}