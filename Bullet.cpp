#include "Bullet.h"

Bullet::Bullet(Vector2 pos, Vector2 velocity, bool isActive, float coolTimes)
{	pos_ = pos;
	velocity_ = velocity;
	isActive_ = isActive;
	coolTimes_ = coolTimes;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
}

void Bullet::Draw()
{
	
}
