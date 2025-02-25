#include"Player.h"
#include"Texture.h"
#include"Conster.h"



Player::Player(Vector2 pos)
{
	pos_ = pos;
	velocity_ = { 5.0f,5.0f };
	isActive_ = true;
	isAlive_ = true;
	size_ = { 64.0f,64.0f };
	coolTimes_ = 1.0f;

	for (int i = 0; i < kMaxBullet; i++)
	{
		bullets_[i] = new Bullet();
	}

	enemy_ = new Enemy;
}

Player::~Player()
{
	for (int i = 0; i < kMaxBullet; i++)
	{
		delete bullets_[i];
	}
}



Bullet* Player::GetBullets()
{
	return bullets_;
}

void Player::Move(char* keys)
{

	if (!isAlive_ || !isActive_)
	{
		return;
	}

	if (keys[DIK_W])
	{
		pos_.y -= velocity_.y;
	}

	if (keys[DIK_A])
	{
		pos_.x -= velocity_.x;
		/*directionNo = DIRECTION_LEFT;*/
	}

	if (keys[DIK_S])
	{
		pos_.y += velocity_.y;
	}

	if (keys[DIK_D])
	{
		pos_.x += velocity_.x;
		/*directionNo = DIRECTION_RIGHT;*/
	}

	if (coolTimes_ < 30.0f)
	{
		coolTimes_++;
	}

	else if (keys[DIK_SPACE])
	{

		for (int i = 0; i < kMaxBullet; i++)
		{
			if (!bullets_[i]->GetIsActive())
			{
				bullets_[i]->SetIsActive(true);
				bullets_[i]->SetPos(pos_);
				coolTimes_ = 0.0f;
				break; // 1発だけ発射
			}
		}

	}





	// 全ての弾を更新
	for (int i = 0; i < kMaxBullet; i++)
	{
		bullets_[i]->Update();
	}
}

void Player::SetIsAlive(bool isAlive)
{
	isActive_ = isAlive;
}


void Player::Draw()
{
	if (!isActive_ || !isAlive_)
	{
		return;
	}

	Novice::DrawQuad(
		static_cast<int>(pos_.x - (size_.x * 0.5f)),
		static_cast<int>(pos_.y - (size_.y * 0.5f)),
		static_cast<int>(pos_.x + (size_.x * 0.5f)),
		static_cast<int>(pos_.y - (size_.y * 0.5f)),
		static_cast<int>(pos_.x - (size_.x * 0.5f)),
		static_cast<int>(pos_.y + (size_.y * 0.5f)),
		static_cast<int>(pos_.x + (size_.x * 0.5f)),
		static_cast<int>(pos_.y + (size_.y * 0.5f)),
		1,
		1,
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		gh,
		0xFFFFFFFF
	);

	for (int i = 0; i < kMaxBullet; i++)
	{
		bullets_[i]->Draw();
	}
}

