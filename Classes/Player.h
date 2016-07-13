#ifndef __Player_H__
#define __Player_H__


#include "cocos2d.h"
#include <CCTMXLayer.h>
#include <CCTMXTiledMap.h>
#include <CCTMXObjectGroup.h>
#include <CCScene.h>

using namespace std;
using namespace cocos2d;

class Player
{
private:
	Sprite *_player;
	int Health;
	int Defence;
	int Attack;	
	float Speed;

public:

	Player();
	~Player();
	Sprite *getPlayer();
	void setHealth(int health);
	void setDefence(int defence);
	void setAttack(float attack);
	void setSpeed(float speed);
	int getHealth();
	int getDefence();
	int getAttack();
	float getSpeed();

};

#endif

