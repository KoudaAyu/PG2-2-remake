#include"Enemy.h"
#include"Texture.h"

Enemy::Enemy()
{
	pos_.x = 1280.0f;
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
