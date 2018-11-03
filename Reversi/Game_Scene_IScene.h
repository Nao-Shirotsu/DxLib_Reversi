#pragma once

#include <memory>

#include "Resource_Index.h"
#include "DX_IManager.h"

namespace Game::Scene{

// Sceneクラスのインターフェース
class IScene{
public:
	virtual ~IScene();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
	// DxLibの関数をシーンで利用するために
=======
	// DxLibの関数をシーンで利用するためにﾎﾟｲﾝﾀを取得
>>>>>>> Stashed changes
=======
	// DxLibの関数をシーンで利用するためにﾎﾟｲﾝﾀを取得
>>>>>>> Stashed changes
	virtual void SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager ) = 0;

	// メンバ変数等の状態のアップデート
	virtual void Update() = 0;

	// 画面へ描画する
	virtual void Draw() = 0;

	// シーン遷移関数
	// 違うシーンに移行する場合はその実体を生成して返し、
	// そうでないならnullptrを返す
	virtual std::unique_ptr<IScene> TransitionToNext() = 0;
};

}