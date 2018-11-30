#pragma once
#include <string>
#include <memory>

#include "DX_UtilManager.h"
#include "Resource_Index.h"

namespace DX::Object{

// 1つの音声ファイルを管理/再生するクラス
// SoundIndexをメンバに持つ=このObjectがどのサウンドファイルを司るか
class SoundPlayer{
public:
	explicit SoundPlayer( std::shared_ptr<DX::UtilManager> dxManager_, Resource::SoundIndex soundIndex_, bool loopFlag_ );

	// 何もしない
	SoundPlayer();

	~SoundPlayer();

	void Play();
	void Stop();

private:
	std::shared_ptr<DX::UtilManager> dxManager;
	Resource::SoundIndex soundIndex;
	bool loopFlag;
};

}