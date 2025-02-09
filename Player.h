#pragma once
#include"Object.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Conster.h"

class Player : public Object
{
private:

	bool isAlive_;
	Bullet bullets_[kMaxBullet];
	Vector2 size_;
	

public:

	
	Enemy* enemy_ = nullptr;

	float coolTimes_;

	Player(Vector2 pos);
	~Player();

	Vector2 GetPos(){ return pos_; };

	void SetIsAlive(bool isAlive);

	
	Bullet* GetBullets();

	void Move(char*keys);



	void Draw();

};