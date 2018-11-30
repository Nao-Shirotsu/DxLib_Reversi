#include "DX_Object_SoundPlayer.h"

DX::Object::SoundPlayer::SoundPlayer( std::shared_ptr<DX::UtilManager> dxManager_, Resource::SoundIndex soundIndex_, bool loopFlag_ ):
	dxManager( dxManager_ ),
	soundIndex( soundIndex_ ),
	loopFlag( loopFlag_ ){
	dxManager->Load( soundIndex_ );
}

DX::Object::SoundPlayer::SoundPlayer(){}

DX::Object::SoundPlayer::~SoundPlayer(){
	dxManager->UnLoad( soundIndex );
}

void DX::Object::SoundPlayer::Play(){
	dxManager->Play( soundIndex, loopFlag );
}

void DX::Object::SoundPlayer::Stop(){
	dxManager->StopSound( soundIndex );
}