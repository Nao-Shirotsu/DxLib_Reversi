#pragma once

#include <memory>

#include "Resource_Index.h"
#include "DX_IManager.h"
#include "Game_SceneID.h"

namespace Game::Scene{

// Sceneクラスのインターフェース
class IScene{
public:
	virtual ~IScene();

	// DxLibの関数をシーンで利用するためにﾎﾟｲﾝﾀを取得
	virtual void SetDXManagerPtr( std::shared_ptr<DX::IManager>& dxManager ) = 0;

	// メンバ変数等の状態のアップデート
	virtual void Update() = 0;

	// 画面へ描画する
	virtual void Draw() const = 0;

	// シーン遷移を行なうかどうか
	virtual bool NeedsTransition() = 0;

	// シーン遷移関数
	// 次のシーンの実体を生成して返すか、nullptrを返す
	// (nullptrが返されるのは、前のシーンへ戻る時)
	virtual std::unique_ptr<IScene> TransitionToNext() const = 0;

	// どのシーンの実体であるか確認するため、
	// シーンごとに固有のenum classなIDを返す
	virtual Game::SceneID GetSceneID() const = 0;
};

}