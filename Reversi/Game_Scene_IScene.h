#pragma once

#include <memory>
#include <unordered_map>

#include "Resource_Index.h"
#include "DX_Core.h"
#include "Game_SceneID.h"
#include "DX_Object_ClickButton.h"

namespace Game::Scene{

// 全てのSceneクラスの基底クラス
class IScene{
public:
	virtual ~IScene();

	// DxLibの関数をシーンで利用するためにﾎﾟｲﾝﾀを取得 (Dependency Injection)
	virtual void SetDXManagerPtr( std::shared_ptr<DX::UtilManager> dxManager ) = 0;

	// メンバ変数等の状態のアップデート
	virtual void Update() = 0;

	// 画面へ描画する
	virtual void Draw() const = 0;

	// シーン遷移を行なうかどうか
	virtual bool NeedsTransition() = 0;

	// Titleシーンであるかどうか
	virtual bool IsTitleScene() = 0;

	// シーン遷移関数
	// 次のシーンの実体を生成して返すか、nullptrを返す
	// (nullptrが返されるのは、前のシーンへ戻る時)
	virtual std::unique_ptr<IScene> TransitionToNext() const = 0;

protected:
	// どのシーンの実体であるか確認するため、
	// シーンごとに固有のenum classなIDを返す
	virtual Game::SceneID GetSceneID() const = 0;

	void DrawAllClickButtons() const;

	// クリックボタンを格納
	std::unordered_map<Game::SceneID, DX::Object::ClickButton> clickbuttons;
};

}