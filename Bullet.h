#pragma once
#include"Object.h"
#include"Enumuration.h"

class Bullet : public Object
{
public:

	
	float radius_;

	Bullet();
	


	Vector2 GetPos(){ return pos_; };
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	bool GetIsActive() { return isActive_; };

	void SetPos(Vector2 pos);
	void SetIsActive(bool isActive);

	void Update();
	void Draw();

};