#pragma once
#include"Object.h"

class Bullet : public Object
{
private:

	float coolTimes_;

public:

	Bullet(Vector2 pos, Vector2 velocity, bool isActive, float coolTimes);
	~Bullet();


	void Update();
	void Draw();

};