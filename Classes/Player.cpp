#include "Player.h"

using namespace std;
using namespace cocos2d;

Player::Player()
{
	;
}
Player::~Player()
{
	;
}
void Player::setHealth(int health)
{
	Health = health;	
}
void Player::setDefence(int defence)
{
	Defence = defence;
}
void Player::setAttack(float attack)
{
	Attack = attack;
}
void Player::setSpeed(float speed)
{
	Speed = speed;
}

int Player::getHealth()
{
	return Health;
}
int Player::getDefence()
{
	return Defence;
}
int Player::getAttack()
{
	return Attack;
}
float Player::getSpeed()
{	
	return Speed;
}
Sprite *Player::getPlayer()
{
	return _player;
}
