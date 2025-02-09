#include"Enemy.h"
#include"Texture.h"

Enemy::Enemy()
{
	pos_.x = 1000.0f;
	pos_.y = static_cast<float>(rand() % 720);
	velocity_ = { 5.0f,0.0f };
	size_ = { 36.0f,36.0f };
	isActive_ = true;
	isAlive_ = true;

}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (pos_.y - size_.y > 0.0f)
	{
		velocity_.y *= -1;
	}
	if (pos_.y + size_.y < 720.0f)
	{
		velocity_.y *= -1;
	}

	pos_.y += velocity_.y;

	
}

void Enemy::SetPos(Vector2 pos)
{
	pos_ = pos;
}

void Enemy::SetIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}


void Enemy::Draw()
{
	if(!isAlive_)
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
		0xFF0000FF
	);

}
