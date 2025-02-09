#include <Novice.h>
#include"Bullet.h"
#include"Conster.h"
#include"Enemy.h"
#include"Enumuration.h"
#include"Object.h"
#include"Player.h"
#include"Texture.h"

int gh;

const char kWindowTitle[] = "LC1A_13_コウダ＿アユ＿タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	gh = Novice::LoadTexture("white1x1.png");

	Player* player =new Player({640.0f,360.0f});

	Bullet* bullet[kMaxBullet];
	for (int i = 0; i < kMaxBullet; i++)
	{
		bullet[i] = new Bullet();
	}

	Enemy* enemy[kMaxEnemies];
	for (int i = 0; i < kMaxEnemies; i++)
	{
		enemy[i] = new Enemy();
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Move(keys);

	

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		for (int i = 0; i < kMaxBullet; i++)
		{
			bullet[i]->Draw();
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
