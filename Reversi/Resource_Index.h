#pragma once

namespace Resource{

// 他のコード中で何の画像を使うか分かりやすくするための
// 識別子としてenum classを定義
// Resource::Managerの2つの配列(.cpp内)の要素番号と一致させる

enum class PicIndex{
	Samurai = 0,
};

enum class SoundIndex{
	Decide = 0,
	Jazz,
	Piano,
};

}