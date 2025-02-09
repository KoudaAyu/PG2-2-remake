#pragma once
#include"Object.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Conster.h"

class Player : public Object
{
private:

	bool isAlive_;
	Vector2 size_;
	

public:

	Bullet* bullets_[kMaxBullet];
	Enemy* enemy_ = nullptr;

	float coolTimes_;

	Player(Vector2 pos);
	~Player();

	Vector2 GetPos(){ return pos_; };

	void Move(char*keys);



	void Draw();

};