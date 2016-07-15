#include "ModoArcadeScene.h"
#include "PanzerWarsScene.h"
#include "SimpleAudioEngine.h"
#include <time.h>


USING_NS_CC;
using namespace cocos2d;
using namespace std;

auto audioAA = CocosDenshion::SimpleAudioEngine::getInstance();
auto audioMCC = CocosDenshion::SimpleAudioEngine::getInstance();
char* felipao;

////////////////////////////////
//Manejo de fondos y movimientos
Point ModoArcade::tileCoordForPosition(Point _position)
{
    int x = _position.x / tileMap->getTileSize().width;
    int y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - _position.y)/tileMap->getTileSize().height;
    return Point(x, y);
}

void ModoArcade::initPlayerStatus()
{
	//Inicio estado de player1
	p1.setHealth(100);
	p1.setDefence(5);
	p1.setAttack(120);
	p1.setSpeed(2);
	//Inicio estado de player2
	p2.setHealth(100);
	p2.setDefence(10);
	p2.setAttack(120);
	p2.setSpeed(2);
  //Inico de estado de enemy1
  e1.setHealth(200);
  e1.setDefence(5);
  e1.setAttack(e1.getDefence());
  e1.setSpeed(1);
  //Inico de estado de enemy2
  e2.setHealth(200);
  e2.setDefence(5);
  e2.setAttack(e3.getDefence());
  e2.setSpeed(1);

  e3.setHealth(200);
  e3.setDefence(5);
  e3.setAttack(e3.getDefence());
  e3.setSpeed(1);


  e4.setHealth(200);
  e4.setDefence(5);
  e4.setAttack(e4.getDefence());
  e4.setSpeed(1);

  e5.setHealth(200);
  e5.setDefence(5);
  e5.setAttack(e5.getDefence());
  e5.setSpeed(1);
  //
  e6.setHealth(200);
  e6.setDefence(5);
  e6.setAttack(e6.getDefence());
  e6.setSpeed(1);

  e7.setHealth(200);
  e7.setDefence(5);
  e7.setAttack(e7.getDefence());
  e7.setSpeed(1);
  //

}

void ModoArcade::gameUpdate(float interval)
{
    loc1 = _player1->getPosition();
    loc2 = _player2->getPosition();
    loc3 = _enemy1->getPosition();
    loc4 = _enemy2->getPosition();
    loc5 = _enemy3->getPosition();
     loc6 = _enemy4->getPosition();
     loc7 = _enemy5->getPosition();
    loc8 = _enemy6->getPosition();
    loc9 = _enemy7->getPosition();
    // loc10 = _enemy8->getPosition();



    HB1->setPosition(ccp(loc1.x,loc1.y+40));
    HB2->setPosition(ccp(loc2.x,loc2.y+40));
    //Se inician/refrescan los porcentajes de salud por hit al tanque
    HPpercentage1 = p2.getAttack()/p1.getDefence();
    HPpercentage2 = p1.getAttack()/p2.getDefence();
    if(!pause) {
    //Se chequea si se toman los upgrades
	if(!firstSpeed)
	getUpgrade(speedUp);
	if(!firstAttack)
	getUpgrade(attackUp);
	if(!firstDefence)
	getUpgrade(defenceUp);
	if(!firstHP)
	getUpgrade(HpUp);

	///////////////////////////////////////////
	//Bloqueos
	if ((bbP1.intersectsRect(bbE1) && e1.getHealth())  || (bbP1.intersectsRect(bbE2) && e2.getHealth())) {
	    switch(dirAnt1) {
		case 0:
		    up1 = false;
		    break;
		case 1:
		    down1 = false;
		    break;
		case 2:
		    left1 = false;
		    break;
		case 3:
		    right1 = false;
		    break;
	    }
	}
	if (bbP1.intersectsRect(bbE1)) {
	    e1Collision = true;
	} else {
	    e1Collision = false;
	}
	if (bbP1.intersectsRect(bbE2)) {
	    e2Collision = true;
	} else {
	    e2Collision = false;
	}

    ////////////////////////////////////////////////////////////
    // Movimiento Jugadores y se establece la posicion de health bars
    if(p1.getHealth()) {//Solo se mueve si esta vivo
    if(up1) {
	    switch(dirAnt1) {
		case 0:
		    break;
		case 1:
		    this->_player1->runAction(RotateBy::create(0.02, 180));
		    break;
		case 2:
		    this->_player1->runAction(RotateBy::create(0.01, 90));
		    break;
		case 3:
		    this->_player1->runAction(RotateBy::create(0.01, -90));
		    break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
	    }
	    dirAnt1 = 0;
	    setPlayer1Position(ccp(loc1.x,++loc1.y+p1.getSpeed())); // player 1 going up
	}
	else if(down1) {
	    switch(dirAnt1) {
		case 0:
		    this->_player1->runAction(RotateBy::create(0.02, 180));
		    break;
		case 1:
		    break;
		case 2:
		    this->_player1->runAction(RotateBy::create(0.01, -90));
		    break;
		case 3:
		    this->_player1->runAction(RotateBy::create(0.01, 90));
		    break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;

	    }
	    dirAnt1 = 1;
	    setPlayer1Position(ccp(loc1.x,--loc1.y-p1.getSpeed())); // player 1 going down
	}
	else if(right1) {
	    switch(dirAnt1) {
		case 0:
		    this->_player1->runAction(RotateBy::create(0.01, 90));
		    break;
		case 1:
		    this->_player1->runAction(RotateBy::create(0.01, -90));
		    break;
		case 2:
		    this->_player1->runAction(RotateBy::create(0.02, 180));
		    break;
		case 3:
		    break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;

	    }
	    dirAnt1 = 3;
	    setPlayer1Position(ccp(++loc1.x+p1.getSpeed(),loc1.y)); // player 1 going right
	}
	else if(left1) {
	    switch(dirAnt1) {
		case 0:
		    this->_player1->runAction(RotateBy::create(0.01, -90));
		    break;
		case 1:
		    this->_player1->runAction(RotateBy::create(0.01, 90));
		    break;
		case 2:
		    break;
		case 3:
		    this->_player1->runAction(RotateBy::create(0.02, 180));
		    break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;

	    }
	    dirAnt1 = 2;
	    setPlayer1Position(ccp(--loc1.x-p1.getSpeed(),loc1.y)); // player 1 going left
	}
//--------
  else if(Up_left1) {
      switch(dirAnt1) {
    case 0:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;
    case 1:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;
    case 2:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
    case 3:
        this->_player1->runAction(RotateBy::create(0.02, -135));
        break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.01, -90));
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, 180));
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, 90));
        break;
    case 7:
        break;

      }
      dirAnt1 = 7;
      setPlayer1Position(ccp(--loc1.x-p1.getSpeed(),++loc1.y+p1.getSpeed())); // player 1 going left
  }
  else if(Up_right1) {
      switch(dirAnt1) {
    case 0:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
    case 1:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;
    case 2:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;
    case 3:
        this->_player1->runAction(RotateBy::create(0.02, -45));
        break;
    case 4:
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, -90));
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, 180));
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, 90));
        break;

      }
      dirAnt1 = 4;
      setPlayer1Position(ccp(++loc1.x+p1.getSpeed(),++loc1.y+p1.getSpeed())); // player 1 going left
  }
  else if(Down_right1) {
      switch(dirAnt1) {
    case 0:
        this->_player1->runAction(RotateBy::create(0.01, 135));
        break;
    case 1:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;
    case 2:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;
    case 3:
        this->_player1->runAction(RotateBy::create(0.02, 45));
        break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.02, 90));
        break;
    case 5:
        break;
    case 6:
        this->_player1->runAction(RotateBy::create(0.01, -90));
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, 180));
        break;

      }
      dirAnt1 = 5;
      setPlayer1Position(ccp(++loc1.x+p1.getSpeed(),--loc1.y-p1.getSpeed())); // player 1 going left
  }
  else if(Down_left1) {
      switch(dirAnt1) {
    case 0:
        this->_player1->runAction(RotateBy::create(0.01, -135));
        break;
    case 1:
        this->_player1->runAction(RotateBy::create(0.01, 45));
        break;
    case 2:
        this->_player1->runAction(RotateBy::create(0.01, -45));
        break;
    case 3:
        this->_player1->runAction(RotateBy::create(0.02, 145));
        break;
    case 4:
        this->_player1->runAction(RotateBy::create(0.02, 180));
        break;
    case 5:
        this->_player1->runAction(RotateBy::create(0.01, 90));
        break;
    case 6:
        break;
    case 7:
        this->_player1->runAction(RotateBy::create(0.01, -90));
        break;

      }
      dirAnt1 = 6;
      setPlayer1Position(ccp(--loc1.x-p1.getSpeed(),--loc1.y-p1.getSpeed())); // player 1 going left
  }
  //
    }
    if(e2.getHealth()) {//Solo se mueve si esta vivo
	if(up2) {
	    switch(dirAnt2) {
		case 0:
		    break;
		case 1:
		    this->_player2->runAction(RotateBy::create(0.02, 180));
		    break;
		case 2:
		    this->_player2->runAction(RotateBy::create(0.01, 90));
		    break;
		case 3:
		    this->_player2->runAction(RotateBy::create(0.01, -90));
		    break;
	    }
	    dirAnt2 = 0;
	    setPlayer2Position(ccp(loc2.x,++loc2.y+p2.getSpeed())); // player 2 going up
	}
	else if(down2) {
	    switch(dirAnt2) {
		case 0:
		    this->_player2->runAction(RotateBy::create(0.02, 180));
		    break;
		case 1:
		    break;
		case 2:
		    this->_player2->runAction(RotateBy::create(0.01, -90));
		    break;
		case 3:
		    this->_player2->runAction(RotateBy::create(0.01, 90));
		    break;
	    }
	    dirAnt2 = 1;
	    setPlayer2Position(ccp(loc2.x,--loc2.y-p2.getSpeed())); // player 2 going down
	}
	else if(right2) {
	    switch(dirAnt2) {
		case 0:
		    this->_player2->runAction(RotateBy::create(0.01, 90));
		    break;
		case 1:
		    this->_player2->runAction(RotateBy::create(0.01, -90));
		    break;
		case 2:
		    this->_player2->runAction(RotateBy::create(0.02, 180));
		    break;
		case 3:
		    break;
	    }
	    dirAnt2 = 3;
	    setPlayer2Position(ccp(++loc2.x+p2.getSpeed(),loc2.y)); // player 2 going right
	}
	else if(left2) {
	   switch(dirAnt2) {
		case 0:
		    this->_player2->runAction(RotateBy::create(0.01, -90));
		    break;
		case 1:
		    this->_player2->runAction(RotateBy::create(0.01, 90));
		    break;
		case 2:
		    break;
		case 3:
		    this->_player2->runAction(RotateBy::create(0.02, 180));
		    break;
	    }
	    dirAnt2 = 2;
	    setPlayer2Position(ccp(--loc2.x-p2.getSpeed(),loc2.y)); // player 2 going left
	}
    }
    if(fire){

      dispararMisilPlayer1();
    }

    if(mine){

        activarMinaP1(ccp(loc1.x,loc1.y));

    }

//MOVIMIENTO DE ENEMIGOS
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
if(ronda1){
if(e1.getHealth()) { //Si esta muerto no hace nada
if (!e1Collision) { //Si hay colision no se mueve
  if((abs(loc1.x-loc3.x)<20) &&((loc1.y-loc3.y)>20 )){//0
    switch (dirAntE1) {
      case 0:
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE1 = 0;
    setEnemy1Position(ccp(loc3.x,++loc3.y+e1.getSpeed())); // enemy1 going up
    log("0");
    //KOTHCounter3(_enemy1->getPosition());
    //  dispararMisilENemigo();
  }
  if((abs(loc1.x-loc3.x)<20) &&((loc3.y-loc1.y)>20 )){//1
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE1 = 1;
  //  dispararMisilENemigo();
    setEnemy1Position(ccp(loc3.x,--loc3.y)); // enemy1 going down
    //KOTHCounter3(_enemy1->getPosition());
  }
  //
  if(((loc3.x-loc1.x)>20) &&(abs(loc1.y-loc3.y)<20) ){//2
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE1 = 2;
    //dispararMisilENemigo();
    setEnemy1Position(ccp(--loc3.x,loc3.y)); // enemy1 going left
    //KOTHCounter3(_enemy1->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc3.x)>20) &&(abs(loc1.y-loc3.y)<20) ){//3
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE1 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy1Position(ccp(++loc3.x,loc3.y)); // enemy1 going right
    //KOTHCounter3(_enemy1->getPosition());
  }
  //
  if(((loc1.x-loc3.x)>20) && ((loc1.y-loc3.y)>20)){ //4
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE1 = 4;
    //dispararMisilENemigo();
    setEnemy1Position(ccp((++loc3.x),(++loc3.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc3.x)>20) && ((loc3.y-loc1.y)>20)){ //5
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE1 = 5;
    setEnemy1Position(ccp((++loc3.x),(--loc3.y))); //enemy1 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc3.x-loc1.x)>20) && ((loc3.y-loc1.y)>20)){//6
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE1 = 6;
    //  dispararMisilENemigo();
    setEnemy1Position(ccp((--loc3.x),(--loc3.y))); //enemy1 going down and left
    //dispararMisilENemigo();
  }
  if(((loc3.x-loc1.x)>20) && ((loc1.y-loc3.y)>20)){//7
    switch (dirAntE1) {
      case 0:
        this->_enemy1->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy1->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy1->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy1->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy1->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy1->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy1->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE1 = 7;
    setEnemy1Position(ccp((--loc3.x),(++loc3.y)));//enemy1 going left and up
    //dispararMisilENemigo();
  }
}



}


//---------------------------------------------------------------------------------------------------------------------------------------------------
//MOVIMIENTO ENEMIGO  2
if(e2.getHealth()){ //Si esta muerto no hace nada
if(!e2Collision) { //Solo se mueve si no hay colision
  if((abs(loc1.x-loc4.x)<20) &&((loc1.y-loc4.y)>20 )){//0
    switch (dirAntE2) {
      case 0:
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE2 = 0;
    setEnemy2Position(ccp(loc4.x,++loc4.y+e1.getSpeed())); // enemy2 going up
    log("0");
    //KOTHCounter3(_enemy2->getPosition());
    //  dispararMisilENemigo();
  }
  if((abs(loc1.x-loc4.x)<20) &&((loc4.y-loc1.y)>20 )){//1
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE2 = 1;
  //  dispararMisilENemigo();
    setEnemy2Position(ccp(loc4.x,--loc4.y)); // enemy2 going down
    //KOTHCounter3(_enemy2->getPosition());
  }
  //
  if(((loc4.x-loc1.x)>20) &&(abs(loc1.y-loc4.y)<20) ){//2
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE2 = 2;
    //dispararMisilENemigo();
    setEnemy2Position(ccp(--loc4.x,loc4.y)); // enemy2 going left
    //KOTHCounter3(_enemy2->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc4.x)>20) &&(abs(loc1.y-loc4.y)<20) ){//3
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE2 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy2Position(ccp(++loc4.x,loc4.y)); // enemy2 going right
    //KOTHCounter3(_enemy2->getPosition());
  }
  //
  if(((loc1.x-loc4.x)>20) && ((loc1.y-loc4.y)>20)){ //4
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE2 = 4;
    //dispararMisilENemigo();
    setEnemy2Position(ccp((++loc4.x),(++loc4.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc4.x)>20) && ((loc4.y-loc1.y)>20)){ //5
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE2 = 5;
    setEnemy2Position(ccp((++loc4.x),(--loc4.y))); //enemy2 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc4.x-loc1.x)>20) && ((loc4.y-loc1.y)>20)){//6
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE2 = 6;
    //  dispararMisilENemigo();
    setEnemy2Position(ccp((--loc4.x),(--loc4.y))); //enemy2 going down and left
    //dispararMisilENemigo();
  }
  if(((loc4.x-loc1.x)>20) && ((loc1.y-loc4.y)>20)){//7
    switch (dirAntE2) {
      case 0:
        this->_enemy2->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy2->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy2->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy2->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy2->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy2->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy2->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE2 = 7;
    setEnemy2Position(ccp((--loc4.x),(++loc4.y)));//enemy2 going left and up
    //dispararMisilENemigo();
  }
}

}

//movimiento enemigo3
//--------------------------------------------------------------------------------------
if(e3.getHealth()){ //Si esta muerto no hace nada
if(!e3Collision) { //Solo se mueve si no hay colision
  if((abs(loc1.x-loc5.x)<20) &&((loc1.y-loc5.y)>20 )){//0
    switch (dirAntE3) {
      case 0:
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE3 = 0;
    setEnemy3Position(ccp(loc5.x,++loc5.y+e1.getSpeed())); // enemy3 going up
    log("0");
          }
  if((abs(loc1.x-loc5.x)<20) &&((loc5.y-loc1.y)>20 )){//1
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE3 = 1;
  //  dispararMisilENemigo();
    setEnemy3Position(ccp(loc5.x,--loc5.y)); // enemy3 going down
    //KOTHCounter3(_enemy3->getPosition());
  }
  //
  if(((loc5.x-loc1.x)>20) &&(abs(loc1.y-loc5.y)<20) ){//2
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE3 = 2;
    //dispararMisilENemigo();
    setEnemy3Position(ccp(--loc5.x,loc5.y)); // enemy3 going left
    //KOTHCounter3(_enemy3->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc5.x)>20) &&(abs(loc1.y-loc5.y)<20) ){//3
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE3 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy3Position(ccp(++loc5.x,loc5.y)); // enemy3 going right
    //KOTHCounter3(_enemy3->getPosition());
  }
  //
  if(((loc1.x-loc5.x)>20) && ((loc1.y-loc5.y)>20)){ //4
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE3 = 4;
    //dispararMisilENemigo();
    setEnemy3Position(ccp((++loc5.x),(++loc5.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc5.x)>20) && ((loc5.y-loc1.y)>20)){ //5
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE3 = 5;
    setEnemy3Position(ccp((++loc5.x),(--loc5.y))); //enemy3 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc5.x-loc1.x)>20) && ((loc5.y-loc1.y)>20)){//6
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE3 = 6;
    //  dispararMisilENemigo();
    setEnemy3Position(ccp((--loc5.x),(--loc5.y))); //enemy3 going down and left
    //dispararMisilENemigo();
  }
  if(((loc5.x-loc1.x)>20) && ((loc1.y-loc5.y)>20)){//7
    switch (dirAntE3) {
      case 0:
        this->_enemy3->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy3->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy3->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy3->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy3->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy3->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy3->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE3 = 7;
    setEnemy3Position(ccp((--loc5.x),(++loc5.y)));//enemy3 going left and up

  }
}

}

//movimiento enemigo 4
//-------------------------------------------------------------
if(e4.getHealth()){ //Si esta muerto no hace nada
if(!e4Collision) { //Solo se mueve si no hay colision
  if((abs(loc1.x-loc6.x)<20) &&((loc1.y-loc6.y)>20 )){//0
    switch (dirAntE4) {
      case 0:
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE4 = 0;
    setEnemy4Position(ccp(loc6.x,++loc6.y+e1.getSpeed())); // enemy4 going up
    log("0");
          }
  if((abs(loc1.x-loc6.x)<20) &&((loc6.y-loc1.y)>20 )){//1
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE4 = 1;
  //  dispararMisilENemigo();
    setEnemy4Position(ccp(loc6.x,--loc6.y)); // enemy4 going down
    //KOTHCounter3(_enemy4->getPosition());
  }
  //
  if(((loc6.x-loc1.x)>20) &&(abs(loc1.y-loc6.y)<20) ){//2
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE4 = 2;
    //dispararMisilENemigo();
    setEnemy4Position(ccp(--loc6.x,loc6.y)); // enemy4 going left
    //KOTHCounter3(_enemy4->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc6.x)>20) &&(abs(loc1.y-loc6.y)<20) ){//3
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE4 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy4Position(ccp(++loc6.x,loc6.y)); // enemy4 going right
    //KOTHCounter3(_enemy4->getPosition());
  }
  //
  if(((loc1.x-loc6.x)>20) && ((loc1.y-loc6.y)>20)){ //4
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE4 = 4;
    //dispararMisilENemigo();
    setEnemy4Position(ccp((++loc6.x),(++loc6.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc6.x)>20) && ((loc6.y-loc1.y)>20)){ //5
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE4 = 5;
    setEnemy4Position(ccp((++loc6.x),(--loc6.y))); //enemy4 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc6.x-loc1.x)>20) && ((loc6.y-loc1.y)>20)){//6
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE4 = 6;
    //  dispararMisilENemigo();
    setEnemy4Position(ccp((--loc6.x),(--loc6.y))); //enemy4 going down and left
    //dispararMisilENemigo();
  }
  if(((loc6.x-loc1.x)>20) && ((loc1.y-loc6.y)>20)){//7
    switch (dirAntE4) {
      case 0:
        this->_enemy4->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy4->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy4->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy4->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy4->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy4->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy4->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE4 = 7;
    setEnemy4Position(ccp((--loc6.x),(++loc6.y)));//enemy4 going left and up

  }
}

}

//movimiento enemigo 5
//-------------------------------------------------------------
if(e5.getHealth()){ //Si esta muerto no hace nada
if(!e5Collision) { //Solo se mueve si no hay colision
  if((abs(loc1.x-loc7.x)<20) &&((loc1.y-loc7.y)>20 )){//0
    switch (dirAntE5) {
      case 0:
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE5 = 0;
    setEnemy5Position(ccp(loc7.x,++loc7.y+e1.getSpeed())); // enemy5 going up
    log("0");
          }
  if((abs(loc1.x-loc7.x)<20) &&((loc7.y-loc1.y)>20 )){//1
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE5 = 1;
  //  dispararMisilENemigo();
    setEnemy5Position(ccp(loc7.x,--loc7.y)); // enemy5 going down
    //KOTHCounter3(_enemy5->getPosition());
  }
  //
  if(((loc7.x-loc1.x)>20) &&(abs(loc1.y-loc7.y)<20) ){//2
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE5 = 2;
    //dispararMisilENemigo();
    setEnemy5Position(ccp(--loc7.x,loc7.y)); // enemy5 going left
    //KOTHCounter3(_enemy5->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc7.x)>20) &&(abs(loc1.y-loc7.y)<20) ){//3
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE5 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy5Position(ccp(++loc7.x,loc7.y)); // enemy5 going right
    //KOTHCounter3(_enemy5->getPosition());
  }
  //
  if(((loc1.x-loc7.x)>20) && ((loc1.y-loc7.y)>20)){ //4
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE5 = 4;
    //dispararMisilENemigo();
    setEnemy5Position(ccp((++loc7.x),(++loc7.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc7.x)>20) && ((loc7.y-loc1.y)>20)){ //5
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE5 = 5;
    setEnemy5Position(ccp((++loc7.x),(--loc7.y))); //enemy5 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc7.x-loc1.x)>20) && ((loc7.y-loc1.y)>20)){//6
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE5 = 6;
    //  dispararMisilENemigo();
    setEnemy5Position(ccp((--loc7.x),(--loc7.y))); //enemy5 going down and left
    //dispararMisilENemigo();
  }
  if(((loc7.x-loc1.x)>20) && ((loc1.y-loc7.y)>20)){//7
    switch (dirAntE5) {
      case 0:
        this->_enemy5->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy5->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy5->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy5->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy5->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy5->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy5->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE5 = 7;
    setEnemy5Position(ccp((--loc7.x),(++loc7.y)));//enemy5 going left and up

  }
}

}

//movimiento enemigo 6
//--------------------------------------------------------------
if(e6.getHealth()){ //Si esta muerto no hace nada
if(!e6Collision) { //Solo se mueve si no hay colision
  if((abs(loc1.x-loc8.x)<20) &&((loc1.y-loc8.y)>20 )){//0
    switch (dirAntE6) {
      case 0:
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE6 = 0;
    setEnemy6Position(ccp(loc8.x,++loc8.y+e1.getSpeed())); // enemy6 going up
    log("0");
          }
  if((abs(loc1.x-loc8.x)<20) &&((loc8.y-loc1.y)>20 )){//1
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE6 = 1;
  //  dispararMisilENemigo();
    setEnemy6Position(ccp(loc8.x,--loc8.y)); // enemy6 going down
    //KOTHCounter3(_enemy6->getPosition());
  }
  //
  if(((loc8.x-loc1.x)>20) &&(abs(loc1.y-loc8.y)<20) ){//2
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE6 = 2;
    //dispararMisilENemigo();
    setEnemy6Position(ccp(--loc8.x,loc8.y)); // enemy6 going left
    //KOTHCounter3(_enemy6->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc8.x)>20) &&(abs(loc1.y-loc8.y)<20) ){//3
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE6 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy6Position(ccp(++loc8.x,loc8.y)); // enemy6 going right
    //KOTHCounter3(_enemy6->getPosition());
  }
  //
  if(((loc1.x-loc8.x)>20) && ((loc1.y-loc8.y)>20)){ //4
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE6 = 4;
    //dispararMisilENemigo();
    setEnemy6Position(ccp((++loc8.x),(++loc8.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc8.x)>20) && ((loc8.y-loc1.y)>20)){ //5
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE6 = 5;
    setEnemy6Position(ccp((++loc8.x),(--loc8.y))); //enemy6 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc8.x-loc1.x)>20) && ((loc8.y-loc1.y)>20)){//6
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE6 = 6;
    //  dispararMisilENemigo();
    setEnemy6Position(ccp((--loc8.x),(--loc8.y))); //enemy6 going down and left
    //dispararMisilENemigo();
  }
  if(((loc8.x-loc1.x)>20) && ((loc1.y-loc8.y)>20)){//7
    switch (dirAntE6) {
      case 0:
        this->_enemy6->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy6->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy6->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy6->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy6->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy6->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy6->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE6 = 7;
    setEnemy6Position(ccp((--loc8.x),(++loc8.y)));//enemy6 going left and up

  }
}

}
//movimiento enemigo 7
//-------------------------------------------------------------
if(e7.getHealth()){ //Si esta muerto no hace nada
if(!e7Collision) { //Solo se mueve si no hay colision
  if((abs(loc1.x-loc9.x)<20) &&((loc1.y-loc9.y)>20 )){//0
    switch (dirAntE7) {
      case 0:
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.00002, 180));
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.0000001, 90));
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.0000001, -90));
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.0000005, -45));
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.000000015, -135));
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.0000000015, 135));
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.00000000005, 45));
        break;
      }
    dirAntE7 = 0;
    setEnemy7Position(ccp(loc9.x,++loc9.y+e1.getSpeed())); // enemy7 going up
    log("0");
          }
  if((abs(loc1.x-loc9.x)<20) &&((loc9.y-loc1.y)>20 )){//1
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      case 1:
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      }
    log("1");
    dirAntE7 = 1;
  //  dispararMisilENemigo();
    setEnemy7Position(ccp(loc9.x,--loc9.y)); // enemy7 going down
    //KOTHCounter3(_enemy7->getPosition());
  }
  //
  if(((loc9.x-loc1.x)>20) &&(abs(loc1.y-loc9.y)<20) ){//2
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      case 2:
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      }
    log("2");
    dirAntE7 = 2;
    //dispararMisilENemigo();
    setEnemy7Position(ccp(--loc9.x,loc9.y)); // enemy7 going left
    //KOTHCounter3(_enemy7->getPosition());
    //  dispararMisilENemigo();
  }
  //
  if(((loc1.x-loc9.x)>20) &&(abs(loc1.y-loc9.y)<20) ){//3
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      case 3:
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      }
    dirAntE7 = 3;
    log("3");
    //dispararMisilENemigo();
    setEnemy7Position(ccp(++loc9.x,loc9.y)); // enemy7 going right
    //KOTHCounter3(_enemy7->getPosition());
  }
  //
  if(((loc1.x-loc9.x)>20) && ((loc1.y-loc9.y)>20)){ //4
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      case 4:
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      }
    log("4");
    dirAntE7 = 4;
    //dispararMisilENemigo();
    setEnemy7Position(ccp((++loc9.x),(++loc9.y)));// enemy 1 going up and right
  }
  //
  if(((loc1.x-loc9.x)>20) && ((loc9.y-loc1.y)>20)){ //5
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      case 5:
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      }
    log("5");
    dirAntE7 = 5;
    setEnemy7Position(ccp((++loc9.x),(--loc9.y))); //enemy7 going down and right
    //dispararMisilENemigo();

  }
  //
  if(((loc9.x-loc1.x)>20) && ((loc9.y-loc1.y)>20)){//6
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      case 6:
        break;
      case 7:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      }
    log("6");
    dirAntE7 = 6;
    //  dispararMisilENemigo();
    setEnemy7Position(ccp((--loc9.x),(--loc9.y))); //enemy7 going down and left
    //dispararMisilENemigo();
  }
  if(((loc9.x-loc1.x)>20) && ((loc1.y-loc9.y)>20)){//7
    switch (dirAntE7) {
      case 0:
        this->_enemy7->runAction(RotateBy::create(0.005, -45));
        break;
      case 1:
        this->_enemy7->runAction(RotateBy::create(0.015, 135));
        break;
      case 2:
        this->_enemy7->runAction(RotateBy::create(0.005, 45));
        break;
      case 3:
        this->_enemy7->runAction(RotateBy::create(0.015, -135));
        break;
      case 4:
        this->_enemy7->runAction(RotateBy::create(0.01, -90));
        break;
      case 5:
        this->_enemy7->runAction(RotateBy::create(0.02, 180));
        break;
      case 6:
        this->_enemy7->runAction(RotateBy::create(0.01, 90));
        break;
      case 7:
        break;
      }
    log("7");
    dirAntE7 = 7;
    setEnemy7Position(ccp((--loc9.x),(++loc9.y)));//enemy7 going left and up

  }
}

}

srand (time(NULL));
int ramdom;
ramdom= rand() % 10;
//
if(ramdom<2 && e3.getHealth()){
//
//   dispararMisilENemigo3();
  dispararMisilENemigo4();
  dispararMisilENemigo5();
  dispararMisilENemigo6();
  dispararMisilENemigo7();

 }


// switch (ramdom) {
//   case 1:
//     dispararMisilENemigo1();
//     break;
//   case 2:
//       dispararMisilENemigo2();
//       break;
// }


/////////////////////////////////////////////
    // Para colisiones entre sprites
    bbP1 = _player1->getBoundingBox();
    bbP2 = _player2->getBoundingBox();
    bbE1= _enemy1->getBoundingBox();
    bbE2= _enemy2->getBoundingBox();
    bbE3= _enemy3->getBoundingBox();
     bbE4= _enemy4->getBoundingBox();
    bbE5= _enemy5->getBoundingBox();
    bbE6= _enemy6->getBoundingBox();
    bbE7= _enemy7->getBoundingBox();
    // bbE8= _enemy8->getBoundingBox();


    for(i=0; i<3; i++) {
	if(bbP1.intersectsRect(bbM2[i]) && (actM2[i]==true)) {
	    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
	    //-10 a health de p1
	    if(p1.getHealth()>0)
	    p1.setHealth(p1.getHealth()-50);
	    if(p1.getHealth()<0)
	    p1.setHealth(0);
	    hitP2 = true;
	    explosion(minaP2[i]);
	    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
	    end += delta;
	    if (end > 5) {
		tileMap->removeChild(minaP2[i]);
		end = 0;
	    }
	    actM2[i] = false;
	}
	if(bbP2.intersectsRect(bbM1[i]) && (actM1[i]==true)) {
	    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
	    //-10 a health de p2
	    if(p2.getHealth()>0)
	    p2.setHealth(p2.getHealth()-50);
	    if(p2.getHealth()<0)
	    p2.setHealth(0);
	    hitP1 = true;
	    explosion(minaP1[i]);
	    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
	    end += delta;
	    if (end > 5) {
		tileMap->removeChild(minaP1[i]);
		end = 0;
	    }
	    actM1[i] = false;
	}

  if(bbE1.intersectsRect(bbM5[i]) && (actM5[i]==true)) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
    //-10 a health de p2
    if(e1.getHealth()>0)
    e1.setHealth(e1.getHealth()-50);
    log("health e2=%d",e1.getHealth());
    if(e1.getHealth()<0)
    e1.setHealth(0);
    hitP1 = true;
    explosion(minaP1b[i]);
    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
    end += delta;
    if (end > 5) {
      tileMap->removeChild(minaP1b[i]);
      end = 0;
    }
    actM5[i] = false;
  }


  if(bbE2.intersectsRect(bbM5[i]) && (actM5[i]==true)) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
    //-10 a health de p2
    if(e2.getHealth()>0)
    e2.setHealth(e2.getHealth()-50);
    log("health e2=%d",e2.getHealth());
    if(e2.getHealth()<0)
    e2.setHealth(0);
    hitP1 = true;
    explosion(minaP1b[i]);
    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
    end += delta;
    if (end > 5) {
  tileMap->removeChild(minaP1[i]);
  end = 0;
    }
    actM5[i] = false;
  }





  if(bbP1.intersectsRect(bbM4[i]) && (actM4[i]==true)) {
      CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
      //-10 a health de p1
      if(p1.getHealth()>0)
      p1.setHealth(p1.getHealth()-50);
      if(p1.getHealth()<0)
      p1.setHealth(0);
      hitE2 = true;
      explosion(minaE2[i]);
      delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
      end += delta;
      if (end > 5) {
    tileMap->removeChild(minaE2[i]);
    end = 0;
      }
      actM4[i] = false;
  }
    }

    /////////////////////////////////////////

    if(actm2)
    {
	locm2 = misil2->getPosition();
	bbm2 = misil2->getBoundingBox();
	switch (dirm2)
	{
		case 0:
		    setMisil2Position(ccp(locm2.x,++locm2.y+3));
		    break;
		case 1:
		    setMisil2Position(ccp(locm2.x,--locm2.y-3));
		    break;
		case 2:
		    setMisil2Position(ccp(--locm2.x-3,locm2.y));
		    break;
		case 3:
		    setMisil2Position(ccp(++locm2.x+3,locm2.y));
	}
	if(bbm2.intersectsRect(bbP1))
	{
		explosion(misil2);
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
		end += delta;
		if (end > 5) {
		    tileMap->removeChild(misil2);
		    end = 0;
		}
		actm2 = false;
		p1.setHealth(p1.getHealth()-HPpercentage1);
		hitP2 = true;
		if(p1.getHealth()<0)
		p1.setHealth(0);
	}
	for(i=0; i<3; i++) {
	    if((actM1[i]) && bbm2.intersectsRect(bbM1[i])) {
		explosion(misil2);
		explosion(minaP1[i]);
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
		end += delta;
		if (end > 5) {
		    tileMap->removeChild(misil2);
		    tileMap->removeChild(minaP1[i]);
		    end = 0;
		}
		actm2 = false;
		actM1[i] = false;
	    }
	}
	if(actm1) {
	    if(bbm1.intersectsRect(bbm2)) {
		explosion(misil2);
		explosion2(misil1);
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
		end += delta;
		if (end > 5) {
		    tileMap->removeChild(misil2);
		    tileMap->removeChild(misil1);
		    end = 0;
		}
		actm2 = false;
		actm1 = false;
	    }
	}
  if(actm1) {
	    if(bbm1.intersectsRect(bbmE1)) {
		explosion(misil3);
		explosion2(misil1);
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
		end += delta;
		if (end > 5) {
		    tileMap->removeChild(misil3);
		    tileMap->removeChild(misil1);
		    end = 0;
		}
		actmE1 = false;
		actm1 = false;
	    }
	}
  if(actm1) {
	    if(bbm1.intersectsRect(bbmE2)) {
		explosion(misil4);
		explosion2(misil1);
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
		end += delta;
		if (end > 5) {
		    tileMap->removeChild(misil4);
		    tileMap->removeChild(misil1);
		    end = 0;
		}
		actmE2 = false;
		actm1 = false;
	    }

      if(bbm1.intersectsRect(bbmE3)) {
		explosion(misil6);
		explosion2(misil1);
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
		end += delta;
		if (end > 5) {
		    tileMap->removeChild(misil6);
		    tileMap->removeChild(misil1);
		    end = 0;
		}
		actmE3 = false;
		actm1 = false;
	    }

	}



    }
///-----------------------------------------------------
if(actm5)  {
  locm5 = misil5->getPosition();
  bbm5 = misil5->getBoundingBox();
  switch (dirm5)
  {
    case 0:
        setMisil5Position(ccp(locm5.x,++locm5.y+3));
        break;
    case 1:
        setMisil5Position(ccp(locm5.x,--locm5.y-3));
        break;
    case 2:
        setMisil5Position(ccp(--locm5.x-3,locm5.y));
        break;
    case 3:
        setMisil5Position(ccp(++locm5.x+3,locm5.y));
        break;
    case 4:
        setMisil5Position(ccp(++locm5.x+3,++locm5.y+3));
        break;
    case 5:
        setMisil5Position(ccp(++locm5.x+3,--locm5.y-3));
        break;
    case 6:
        setMisil5Position(ccp(--locm5.x-3,--locm5.y-3));
        break;
    case 7:
        setMisil5Position(ccp(--locm5.x-3,++locm5.y+3));
    }
// if(bbm5.intersectsRect(bbE1))
// {
//   tileMap->removeChild(misil5);
//   actm5 = false;
//   e1.setHealth(p1.getHealth()-20);
//   if(e1.getHealth()<0)
//   e1.setHealth(0);
// }


if(bbm5.intersectsRect(bbE1))
{
  explosion(misil5);
  delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
  end += delta;
  if (end > 5) {
      tileMap->removeChild(misil5);
      end = 0;
  }
  actm5 = false;
  e1.setHealth(e1.getHealth()-20);
  hitP1 = true;
  if(e1.getHealth()<0)
  e1.setHealth(0);
}

if(bbm5.intersectsRect(bbE2))
{
  explosion(misil5);
  delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
  end += delta;
  if (end > 5) {
      tileMap->removeChild(misil1);
      end = 0;
  }
  actm5 = false;
  e2.setHealth(e2.getHealth()-50);
  hitP1 = true;
  if(e2.getHealth()<0)
  e2.setHealth(0);
}



  if(bbm5.intersectsRect(bbE3))
  {
    explosion(misil5);
    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
    end += delta;
    if (end > 5) {
        tileMap->removeChild(misil5);
        end = 0;
    }
    actm5 = false;
    e3.setHealth(e3.getHealth()-50);
    hitP1 = true;
    if(e3.getHealth()<0)
    e3.setHealth(0);
  }

for(i=0; i<3; i++) {
    if((actM2[i]) && bbm5.intersectsRect(bbM2[i])) {
  explosion(misil5);
  explosion(minaP2[i]);
  delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
  end += delta;
  if (end > 5) {
      tileMap->removeChild(misil5);
      tileMap->removeChild(minaP2[i]);
      end = 0;
  }
  actm5 = false;
  actM2[i] = false;
    }
}
for(i=0; i<3; i++) {
    if((actM4[i]) && bbm5.intersectsRect(bbM4[i])) {
  explosion(misil5);
  explosion(minaE2[i]);
  delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count();
  end += delta;
  if (end > 5) {
      tileMap->removeChild(misil5);
      tileMap->removeChild(minaE2[i]);
      end = 0;
  }
  actm5 = false;
  actM4[i] = false;
    }
}

  }



  if(actmE1)  {
    locmE1 = misil3->getPosition();
    bbmE1 = misil3->getBoundingBox();
    switch (dirmE1)
    {
      case 0:
          setMisil3Position(ccp(locmE1.x,++locmE1.y+3));
          break;
      case 1:
          setMisil3Position(ccp(locmE1.x,--locmE1.y-3));
          break;
      case 2:
          setMisil3Position(ccp(--locmE1.x-3,locmE1.y));
          break;
      case 3:
          setMisil3Position(ccp(++locmE1.x+3,locmE1.y));
          break;
      case 4:
          setMisil3Position(ccp(++locmE1.x+3,++locmE1.y+3));
          break;
      case 5:
          setMisil3Position(ccp(++locmE1.x+3,--locmE1.y-3));
          break;
      case 6:
          setMisil3Position(ccp(--locmE1.x-3,--locmE1.y-3));
          break;
      case 7:
          setMisil3Position(ccp(--locmE1.x-3,++locmE1.y+3));
      }
  if(bbmE1.intersectsRect(bbP1))
  {
    tileMap->removeChild(misil3);
    actmE1 = false;
    p1.setHealth(p1.getHealth()-20);
    if(p1.getHealth()<0)
    p1.setHealth(0);
  }
    }




    if(actmE2)  {
      locmE2 = misil4->getPosition();
      bbmE2 = misil4->getBoundingBox();
      switch (dirmE2)
      {
        case 0:
            setMisil4Position(ccp(locmE2.x,++locmE2.y+3));
            break;
        case 1:
            setMisil4Position(ccp(locmE2.x,--locmE2.y-3));
            break;
        case 2:
            setMisil4Position(ccp(--locmE2.x-3,locmE2.y));
            break;
        case 3:
            setMisil4Position(ccp(++locmE2.x+3,locmE2.y));
            break;
        case 4:
            setMisil4Position(ccp(++locmE2.x+3,++locmE2.y+3));
            break;
        case 5:
            setMisil4Position(ccp(++locmE2.x+3,--locmE2.y-3));
            break;
        case 6:
            setMisil4Position(ccp(--locmE2.x-3,--locmE2.y-3));
            break;
        case 7:
            setMisil4Position(ccp(--locmE2.x-3,++locmE2.y+3));
        }
    if(bbmE2.intersectsRect(bbP1))
    {
      tileMap->removeChild(misil4);
      actmE2 = false;
      p1.setHealth(p1.getHealth()-20);
      if(p1.getHealth()<0)
      p1.setHealth(0);
    }
      }


        //enemy 3 disparo
        if(actmE3)  {
          locmE3 = misil6->getPosition();
          bbmE3 = misil6->getBoundingBox();
             switch (dirmE3)
            {
              case 0:
                  setMisil6Position(ccp(locmE3.x,++locmE3.y+3));
                  break;
              case 1:
                  setMisil6Position(ccp(locmE3.x,--locmE3.y-3));
                  break;
              case 2:
                  setMisil6Position(ccp(--locmE3.x-3,locmE3.y));
                  break;
              case 3:
                  setMisil6Position(ccp(++locmE3.x+3,locmE3.y));
                  break;
              case 4:
                  setMisil6Position(ccp(++locmE3.x+3,++locmE3.y+3));
                  break;
              case 5:
                  setMisil6Position(ccp(++locmE3.x+3,--locmE3.y-3));
                  break;
              case 6:
                  setMisil6Position(ccp(--locmE3.x-3,--locmE3.y-3));
                  break;
              case 7:
                  setMisil6Position(ccp(--locmE3.x-3,++locmE3.y+3));
             }
        if(bbmE3.intersectsRect(bbP1))
        {
          tileMap->removeChild(misil6);
          actmE3 = false;
          p1.setHealth(p1.getHealth()-20);
          if(p1.getHealth()<0)
          p1.setHealth(0);
        }
          }
//-----------------------------------------------------------------------------------

if(actmE4)  {
  locmE4 = misil7->getPosition();
  bbmE4 = misil7->getBoundingBox();
     switch (dirmE4)
    {
      case 0:
          setMisil7Position(ccp(locmE4.x,++locmE4.y+3));
          break;
      case 1:
          setMisil7Position(ccp(locmE4.x,--locmE4.y-3));
          break;
      case 2:
          setMisil7Position(ccp(--locmE4.x-3,locmE4.y));
          break;
      case 3:
          setMisil7Position(ccp(++locmE4.x+3,locmE4.y));
          break;
      case 4:
          setMisil7Position(ccp(++locmE4.x+3,++locmE4.y+3));
          break;
      case 5:
          setMisil7Position(ccp(++locmE4.x+3,--locmE4.y-3));
          break;
      case 6:
          setMisil7Position(ccp(--locmE4.x-3,--locmE4.y-3));
          break;
      case 7:
          setMisil7Position(ccp(--locmE4.x-3,++locmE4.y+3));
     }
if(bbmE4.intersectsRect(bbP1))
{
  tileMap->removeChild(misil7);
  actmE4 = false;
  p1.setHealth(p1.getHealth()-20);
  if(p1.getHealth()<0)
  p1.setHealth(0);
}
  }

  //e5
  if(actmE5)  {
    locmE5 = misil8->getPosition();
    bbmE5 = misil8->getBoundingBox();
       switch (dirmE5)
      {
        case 0:
            setMisil8Position(ccp(locmE5.x,++locmE5.y+3));
            break;
        case 1:
            setMisil8Position(ccp(locmE5.x,--locmE5.y-3));
            break;
        case 2:
            setMisil8Position(ccp(--locmE5.x-3,locmE5.y));
            break;
        case 3:
            setMisil8Position(ccp(++locmE5.x+3,locmE5.y));
            break;
        case 4:
            setMisil8Position(ccp(++locmE5.x+3,++locmE5.y+3));
            break;
        case 5:
            setMisil8Position(ccp(++locmE5.x+3,--locmE5.y-3));
            break;
        case 6:
            setMisil8Position(ccp(--locmE5.x-3,--locmE5.y-3));
            break;
        case 7:
            setMisil8Position(ccp(--locmE5.x-3,++locmE5.y+3));
       }
  if(bbmE5.intersectsRect(bbP1))
  {
    tileMap->removeChild(misil8);
    actmE5 = false;
    p1.setHealth(p1.getHealth()-20);
    if(p1.getHealth()<0)
    p1.setHealth(0);
  }
    }


  //e6

  if(actmE6)  {
    locmE6 = misil9->getPosition();
    bbmE6 = misil9->getBoundingBox();
       switch (dirmE6)
      {
        case 0:
            setMisil9Position(ccp(locmE6.x,++locmE6.y+3));
            break;
        case 1:
            setMisil9Position(ccp(locmE6.x,--locmE6.y-3));
            break;
        case 2:
            setMisil9Position(ccp(--locmE6.x-3,locmE6.y));
            break;
        case 3:
            setMisil9Position(ccp(++locmE6.x+3,locmE6.y));
            break;
        case 4:
            setMisil9Position(ccp(++locmE6.x+3,++locmE6.y+3));
            break;
        case 5:
            setMisil9Position(ccp(++locmE6.x+3,--locmE6.y-3));
            break;
        case 6:
            setMisil9Position(ccp(--locmE6.x-3,--locmE6.y-3));
            break;
        case 7:
            setMisil9Position(ccp(--locmE6.x-3,++locmE6.y+3));
       }
  if(bbmE6.intersectsRect(bbP1))
  {
    tileMap->removeChild(misil9);
    actmE6 = false;
    p1.setHealth(p1.getHealth()-20);
    if(p1.getHealth()<0)
    p1.setHealth(0);
  }
    }


  //e7
  if(actmE7)  {
    locmE7 = misil10->getPosition();
    bbmE7 = misil10->getBoundingBox();
       switch (dirmE7)
      {
        case 0:
            setMisil10Position(ccp(locmE7.x,++locmE7.y+3));
            break;
        case 1:
            setMisil10Position(ccp(locmE7.x,--locmE7.y-3));
            break;
        case 2:
            setMisil10Position(ccp(--locmE7.x-3,locmE7.y));
            break;
        case 3:
            setMisil10Position(ccp(++locmE7.x+3,locmE7.y));
            break;
        case 4:
            setMisil10Position(ccp(++locmE7.x+3,++locmE7.y+3));
            break;
        case 5:
            setMisil10Position(ccp(++locmE7.x+3,--locmE7.y-3));
            break;
        case 6:
            setMisil10Position(ccp(--locmE7.x-3,--locmE7.y-3));
            break;
        case 7:
            setMisil10Position(ccp(--locmE7.x-3,++locmE7.y+3));
       }
  if(bbmE7.intersectsRect(bbP1))
  {
    tileMap->removeChild(misil10);
    actmE7 = false;
    p1.setHealth(p1.getHealth()-20);
    if(p1.getHealth()<0)
    p1.setHealth(0);
  }
    }


//------------------------------------------------------------
    ////////////////////////////////////
    /// Barras de vida
    if(hitP2||hitE2||hitE1)
    {
	if(p1.getHealth()==100)
	{
      	  tileMap->removeChild(HB1);
      	  HB1 = Sprite::create("healthBar.png");
      	  HB1->setPosition(ccp(loc1.x,loc1.y+40));
      	  HB1->setScaleX(0.225);
      	  HB1->setScaleY(0.1);
      	  tileMap->addChild(HB1,1);
	}else if(p1.getHealth()!=100 && p1.getHealth()>0)
	{
	  HB1->setScaleX(0.225*((float)p1.getHealth()/100));
	}
	hitP2 = false;
  hitE2 = false;
  hitE1 = false;
    }
    if(false)
    {
	if(p2.getHealth()==100)
	 {
      	  tileMap->removeChild(HB2);
      	  HB2 = Sprite::create("healthBar.png");
   	  HB2->setPosition(ccp(loc2.x,loc2.y+40));
          HB2->setScaleX(0.225);
      	  HB2->setScaleY(0.1);
      	  tileMap->addChild(HB2,1);
	}else if(p2.getHealth()!=100 && p2.getHealth()>0)
	{
	  HB2->setScaleX(0.225*((float)p2.getHealth()/100));
	}
	hitP1 = false;
    }
    if(hpup1)
    {
	HB1->setScaleX(1.2*0.225);
	hpup1 = false;
    }
    if(hpup2)
    {
	HB2->setScaleX(1.2*0.225);
	hpup2 = false;
    }

    ////////////////////////////////////////////////
    // Enemy is dead
    if(!e1.getHealth())
	explosion2(_enemy1);

    if(!e2.getHealth())
	explosion2(_enemy2);

  if(!e3.getHealth())
explosion2(_enemy3);



//------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
    ///////////////////////////////////////
    //Game Over
    if(!p1.getHealth()) {
	explosion2(_player1);
	auto gameOver = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 26);
    	gameOver->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    	this->addChild(gameOver, 1);
	deltaGO = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-startGO).count();
	endGO += deltaGO;
	if (endGO > 5) {
            tileMap->removeChild(HB1);
	    pause = true;
	    audioAA->stopAllEffects();
	    audioMCC->stopBackgroundMusic();
	    Director::sharedDirector()->pause();
	}
    }
    if(!e2.getHealth() && !e1.getHealth() && !e3.getHealth()) {

      ronda2=true;




	// auto gameOver = Label::createWithTTF("Level 1 clear", "fonts/Marker Felt.ttf", 26);
  //   	gameOver->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
  //   	this->addChild(gameOver, 1);
	// deltaGO = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-startGO).count();
	// endGO += deltaGO;
	// if (endGO > 5) {
	//     pause = true;
	//     audioAA->stopAllEffects();
	//     audioMCC->stopBackgroundMusic();
	//     Director::sharedDirector()->pause();
	// }
    }



    if(ronda2){
      // _enemy4->runAction(FadeIn::create(2.0f));
      // _enemy4->setOpacity(50);
      _enemy4->runAction(FadeOut::create(0.0f));

      auto gameOver = Label::createWithTTF("Ronda2", "fonts/Marker Felt.ttf", 26);
        	gameOver->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
        	this->addChild(gameOver, 1);





    }



}
}
}
bool ModoArcade::onTouchBegan(Touch *touch, Event *event)
{
  if(touch->getLocation().x > 920  && touch->getLocation().y   < 200  )
  {
   fire = true;
   //player->move(0); // param '0' for left
  }


  if(touch->getLocation().x < 150  && touch->getLocation().y   < 200  )
  {
   mine = true;
   //player->move(0); // param '0' for left
  }

 if(touch->getLocation().x <= loc1.x&& abs(touch->getLocation().y - loc1.y)<100 )
 {
  left1 = true;
  //player->move(0); // param '0' for left
 }
 if(touch->getLocation().x > loc1.x&& abs(touch->getLocation().y - loc1.y)<100 &&(touch->getLocation().x < 920))
 {
  right1 = true;
  //player->move(1); // param '0' for right
 }
  if(touch->getLocation().y > loc1.y && abs(touch->getLocation().x - loc1.x)<100 )
 {
  up1 = true;
 }
  if(touch->getLocation().y <= loc1.y && abs(touch->getLocation().x - loc1.x)<100)
 {
  down1 = true;
 }
//------------------------------------------------
  if((touch->getLocation().x - loc1.x)<-100 && (touch->getLocation().y - loc1.y)>100)
  {
   Up_left1 = true;
   //player->move(0); // param '0' for left
  }
  if((touch->getLocation().x - loc1.x)>100 && (touch->getLocation().y - loc1.y)>100)
  {
   Up_right1 = true;
   //player->move(1); // param '0' for right
  }
  if((touch->getLocation().x - loc1.x)<-100 && ( loc1.y- touch->getLocation().y )>100)
  {
   Down_left1 = true;
   //player->move(0); // param '0' for left
  }
  if((touch->getLocation().x - loc1.x)>100 && (loc1.y-touch->getLocation().y )>100  && (touch->getLocation().x < 920) && (touch->getLocation().y   > 200 )  )
  {
   Down_right1 = true;
   //player->move(1); // param '0' for right
  }



 return true;
}


void ModoArcade::onTouchEnded(Touch *touch, Event *event)
{
        //Cuando se deja de tocar, nada se mueve
 left1 = false;
 right1 = false;
 up1 = false;
 down1 = false;
 Up_right1=false;
 Down_right1=false;
 Up_left1=false;
 Down_left1=false;
fire= false;
mine=false;
}






void ModoArcade::explosion(Sprite *player)
{
    Vector<SpriteFrame*> animFrames(4);
    char str[100] = {0};
    for(int i = 1; i < 5; i++) {
	sprintf(str, "exp%d.png",i);
	auto frame = SpriteFrame::create(str,Rect(0,0,50,63));
	animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);
    auto animate = Animate::create(animation);
    player->runAction(animate);
    player->runAction(FadeOut::create(2.0f));
    start = high_resolution_clock::now();
}

void ModoArcade::explosion2(Sprite *player)
{
    Vector<SpriteFrame*> animFrames(4);
    char str[100] = {0};
    for(int i = 1; i < 5; i++) {
	sprintf(str, "exp%d.png",i);
	auto frame = SpriteFrame::create(str,Rect(0,0,50,63));
	animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);
    auto animate = Animate::create(animation);
    player->runAction(animate);
    player->runAction(FadeOut::create(2.0f));
    startGO = high_resolution_clock::now();
}

void ModoArcade::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key with keycode %d pressed", keyCode);
    switch(keyCode){
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	case EventKeyboard::KeyCode::KEY_A:
	    left1 = true;
	    break;
 	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
	    right1 = true;
	    break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
 	case EventKeyboard::KeyCode::KEY_W:
	    up1 = true;
	    break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
 	case EventKeyboard::KeyCode::KEY_S:
	    down1 = true;
	    break;
	case EventKeyboard::KeyCode::KEY_Q:
	    if(cantM1>0 && !pause && p1.getHealth()){
		for(i=0; i<3; i++) {
		    if(actM1[i]==false) {
			cantM1--;
			minaP1[i] = Sprite::create("mina.png");
			minaP1[i]->setPosition(_player1->getPosition());
			minaP1[i]->setScale(0.4);
			tileMap->addChild(minaP1[i],1);
			bbM1[i] = minaP1[i]->getBoundingBox();
			actM1[i] = true;
			break;
		    }
		}
	    }
	    break;
	case EventKeyboard::KeyCode::KEY_E:
	    if(actm1==false && !pause && p1.getHealth()) {
   	 	audioAA->playEffect("Audio/explosion3.mp3");
    		audioAA->setEffectsVolume(0.3);
		misil1 = Sprite::create("c1.png");
		misil1->setPosition(_player1->getPosition());
		misil1->setScale(0.4);
		tileMap->addChild(misil1, _player1->getZOrder());
		actm1 = true;
		dirm1 = dirAnt1;
		switch (dirm1) {
			case 0:
		    		misil1->runAction(RotateBy::create(0.001, -90));
		    		break;
			case 1:
		    		misil1->runAction(RotateBy::create(0.001, 90));
		     		break;
			case 2:
		    		misil1->runAction(RotateBy::create(0.001, 180));
		    		break;
			default:
		    		break;
		}
	    }
	    break;
	case EventKeyboard::KeyCode::KEY_J:
	    left2 = true;
	    break;
	case EventKeyboard::KeyCode::KEY_L:
	    right2 = true;
	    break;
 	case EventKeyboard::KeyCode::KEY_I:
	    up2 = true;
	    break;
 	case EventKeyboard::KeyCode::KEY_K:
	    down2 = true;
	    break;
	case EventKeyboard::KeyCode::KEY_U:
	    if(cantM2>0 && !pause && p2.getHealth()){
		for(i=0; i<3; i++) {
		    if(actM2[i]==false) {
			cantM2--;
			minaP2[i] = Sprite::create("mina.png");
			minaP2[i]->setPosition(_player2->getPosition());
			minaP2[i]->setScale(0.4);
			tileMap->addChild(minaP2[i], _player2->getZOrder()-1);
			bbM2[i] = minaP2[i]->getBoundingBox();
			actM2[i] = true;
			break;
		    }
		}
	    }
	    break;
	case EventKeyboard::KeyCode::KEY_O:
	    if(actm2==false && !pause && p2.getHealth()) {
   	 	audioAA->playEffect("Audio/explosion3.mp3");
    		audioAA->setEffectsVolume(0.3);
		misil2 = Sprite::create("c1.png");
		misil2->setPosition(_player2->getPosition());
		misil2->setScale(0.4);
		tileMap->addChild(misil2, _player2->getZOrder());
		actm2 = true;
		dirm2 = dirAnt2;
		switch (dirm2) {
			case 0:
		    		misil2->runAction(RotateBy::create(0.001, -90));
		    		break;
			case 1:
		    		misil2->runAction(RotateBy::create(0.001, 90));
		     		break;
			case 2:
		    		misil2->runAction(RotateBy::create(0.001, 180));
		    		break;
			default:
		    		break;
		}
	    }
	    break;
    }
}

void ModoArcade::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key with keycode %d released", keyCode);
    switch(keyCode){
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	case EventKeyboard::KeyCode::KEY_A:
	    left1 = false;
	    break;
 	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_D:
	    right1 = false;
	    break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
 	case EventKeyboard::KeyCode::KEY_W:
	    up1 = false;
	    break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
 	case EventKeyboard::KeyCode::KEY_S:
	    down1 = false;
	    break;
	case EventKeyboard::KeyCode::KEY_J:
	    left2 = false;
	    break;
	case EventKeyboard::KeyCode::KEY_L:
	    right2 = false;
	    break;
 	case EventKeyboard::KeyCode::KEY_I:
	    up2 = false;
	    break;
 	case EventKeyboard::KeyCode::KEY_K:
	    down2 = false;
    }
}

void ModoArcade::setPlayer1Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");
                return;
            }
        }else return;
    }
    _player1->setPosition(position);
}

void ModoArcade::setPlayer2Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    log("tileGid = %d", tileGid);
    if (tileGid) {
	//log("DEBUG");
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");
                return;
            }
        }else return;
    }
    _player2->setPosition(position);
}
void ModoArcade::setEnemy1Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");



                return;
            }
        }else return;
    }
    _enemy1->setPosition(position);
}
void ModoArcade::setEnemy2Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");



                return;
            }
        }else return;
    }
    _enemy2->setPosition(position);
}


void ModoArcade::setEnemy3Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");



                return;
            }
        }else return;
    }
    _enemy3->setPosition(position);
}

void ModoArcade::setEnemy4Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");



                return;
            }
        }else return;
    }
    _enemy4->setPosition(position);
}


void ModoArcade::setEnemy5Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		log("COLISION");



                return;
            }
        }else return;
    }
    _enemy5->setPosition(position);
}


//
  void ModoArcade::setEnemy6Position(Point position)
  {
      Point tileCoord = this->tileCoordForPosition(position);
      int tileGid = _blockage->getTileGIDAt(tileCoord);
      if (tileGid) {
          auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
          if (!properties.empty()) {
              auto collision = properties["Collision"].asString();
              if ("True" == collision) {
  		log("COLISION");



                  return;
              }
          }else return;
      }
      _enemy6->setPosition(position);
  }

  void ModoArcade::setEnemy7Position(Point position)
  {
      Point tileCoord = this->tileCoordForPosition(position);
      int tileGid = _blockage->getTileGIDAt(tileCoord);
      if (tileGid) {
          auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
          if (!properties.empty()) {
              auto collision = properties["Collision"].asString();
              if ("True" == collision) {
  		log("COLISION");



                  return;
              }
          }else return;
      }
      _enemy7->setPosition(position);
  }




void ModoArcade::setMisil1Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
	    	tileMap->removeChild(misil1);
	    	actm1 = false;
	    	log("COLISION");
            	return;
            }
        }else return;
    }
    misil1->setPosition(position);
}

void ModoArcade::setMisil2Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil2);
		actm2 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil2->setPosition(position);
}
//------------------------------------------
//Misil Player

void ModoArcade::dispararMisilPlayer1(){
   if(actm5==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil5 = Sprite::create("c1.png");
misil5->setPosition(_player1->getPosition());
misil5->setScale(0.4);
tileMap->addChild(misil5, _player1->getZOrder());
actm5 = true;
dirm5 = dirAnt1;
switch (dirm5) {
  case 0:
    misil5->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil5->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil5->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil5->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil5->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil5->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil5->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil5->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil5Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil5);
		actm5 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil5->setPosition(position);
}





///MISIL enemigo
void ModoArcade::dispararMisilENemigo1(){
  if(actmE1==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil3 = Sprite::create("c1.png");
misil3->setPosition(_enemy1->getPosition());
misil3->setScale(0.4);
tileMap->addChild(misil3, _enemy1->getZOrder());
actmE1 = true;
dirmE1 = dirAntE1;
switch (dirmE1) {
  case 0:
    misil3->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil3->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil3->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil3->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil3->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil3->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil3->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil3->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil3Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil3);
		actmE1 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil3->setPosition(position);
}
void ModoArcade::dispararMisilENemigo2(){
  if(actmE2==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil4 = Sprite::create("c1.png");
misil4->setPosition(_enemy2->getPosition());
misil4->setScale(0.4);
tileMap->addChild(misil4, _enemy2->getZOrder());
actmE2 = true;
dirmE2 = dirAntE2;
switch (dirmE2) {
  case 0:
    misil4->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil4->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil4->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil4->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil4->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil4->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil4->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil4->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil4Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil4);
		actmE2 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil4->setPosition(position);
}







void ModoArcade::dispararMisilENemigo3(){
  if(actmE3==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil6 = Sprite::create("c1.png");
misil6->setPosition(_enemy3->getPosition());
misil6->setScale(0.4);
tileMap->addChild(misil6, _enemy3->getZOrder());
actmE3 = true;
dirmE3 = dirAntE3;
switch (dirmE3) {
  case 0:
    misil6->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil6->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil6->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil6->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil6->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil6->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil6->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil6->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil6Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil6);
		actmE3 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil6->setPosition(position);
}

//disparo e4
//-------------------------------------------------------
void ModoArcade::dispararMisilENemigo4(){
  if(actmE4==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil7 = Sprite::create("c1.png");
misil7->setPosition(_enemy4->getPosition());
misil7->setScale(0.4);
tileMap->addChild(misil7, _enemy4->getZOrder());
actmE4 = true;
dirmE4 = dirAntE4;
switch (dirmE4) {
  case 0:
    misil7->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil7->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil7->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil7->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil7->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil7->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil7->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil7->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil7Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil7);
		actmE4 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil7->setPosition(position);
}

//disparo e5
//---------------------------------------------------------------------------------
void ModoArcade::dispararMisilENemigo5(){
  if(actmE5==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil8 = Sprite::create("c1.png");
misil8->setPosition(_enemy5->getPosition());
misil8->setScale(0.4);
tileMap->addChild(misil8, _enemy5->getZOrder());
actmE5 = true;
dirmE5 = dirAntE5;
switch (dirmE5) {
  case 0:
    misil8->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil8->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil8->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil8->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil8->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil8->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil8->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil8->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil8Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil8);
		actmE5 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil8->setPosition(position);
}

//disparar e6
//----------------------------------
void ModoArcade::dispararMisilENemigo6(){
  if(actmE6==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil9 = Sprite::create("c1.png");
misil9->setPosition(_enemy6->getPosition());
misil9->setScale(0.4);
tileMap->addChild(misil9, _enemy6->getZOrder());
actmE6 = true;
dirmE6 = dirAntE6;
switch (dirmE6) {
  case 0:
    misil9->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil9->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil9->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil9->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil9->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil9->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil9->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil9->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil9Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil9);
		actmE6 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil9->setPosition(position);
}
//disparo e7
//-------------------------------------
void ModoArcade::dispararMisilENemigo7(){
  if(actmE7==false && !pause) {
    audioAA->playEffect("Audio/explosion3.mp3");
    audioAA->setEffectsVolume(0.3);
    misil10 = Sprite::create("c1.png");
misil10->setPosition(_enemy7->getPosition());
misil10->setScale(0.4);
tileMap->addChild(misil10, _enemy7->getZOrder());
actmE7 = true;
dirmE7 = dirAntE7;
switch (dirmE7) {
  case 0:
    misil10->runAction(RotateBy::create(0.001, -90));
    break;
  case 1:
    misil10->runAction(RotateBy::create(0.001, 90));
    break;
  case 2:
    misil10->runAction(RotateBy::create(0.001, 180));
    break;
  case 3:
    misil10->runAction(RotateBy::create(0.001, -0));
    break;
  case 4:
    misil10->runAction(RotateBy::create(0.001, -45));
    break;
  case 5:
    misil10->runAction(RotateBy::create(0.001, 45));
    break;
  case 6:
    misil10->runAction(RotateBy::create(0.001, 135));
    break;
  case 7:
    misil10->runAction(RotateBy::create(0.001, -135));
    break;
default:
        break;
      }
  }
}

void ModoArcade::setMisil10Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto collision = properties["Collision"].asString();
            if ("True" == collision) {
		tileMap->removeChild(misil10);
		actmE7 = false;
		log("COLISION");
                return;
            }
        }else return;
    }
    misil10->setPosition(position);
}





void ModoArcade::activarMinaE2(Point position){
  if(cantM4>0 && !pause){
    for(i=0; i<3; i++) {
      if(actM4[i]==false) {
        cantM4--;
        minaE2[i] = Sprite::create("mina.png");
        minaE2[i]->setPosition(_enemy2->getPosition());
        minaE2[i]->setScale(0.4);
        tileMap->addChild(minaE2[i],_enemy2->getZOrder()-1);
        bbM4[i] = minaE2[i]->getBoundingBox();
        actM4[i] = true;
        log("Mina %d puesta",i);
        break;
      }
    }
  }
}



void ModoArcade::activarMinaP1(Point position){
  if(cantM5>0 && !pause){
    for(i=0; i<3; i++) {
      if(actM5[i]==false) {
        cantM5--;
        minaP1b[i] = Sprite::create("mina.png");
        minaP1b[i]->setPosition(_player1->getPosition());
        minaP1b[i]->setScale(0.4);
        tileMap->addChild(minaP1b[i],_player1->getZOrder()-1);
        bbM5[i] = minaP1b[i]->getBoundingBox();
        actM5[i] = true;
        log("Mina %d puesta",i);
        break;
      }
    }
  }
}
//-----------------------------------------
void ModoArcade::getUpgrade(Sprite *upgrade)
{
	//log("Tag = %d",upgrade->getTag());
   bbspeedUp = upgrade->getBoundingBox();
   if((bbP1).intersectsRect(bbspeedUp) && (!firstHP || !firstSpeed || !firstDefence || !firstAttack))
   {
	switch(upgrade->getTag())
	{
	  case 1:
	     p1.setHealth(120);
	     hpup1 = true;
	     firstHP = true;
	  break;
	  case 2:
	     p1.setSpeed(2*p1.getSpeed());
	     firstSpeed = true;
	  break;
	  case 3:
             p1.setDefence(2*p1.getDefence());
	     firstDefence = true;
	  break;
	  case 4:
	     p1.setAttack(2*p1.getAttack());
	     firstAttack = true;
             powerUp     = true;
	  break;
	}
         removeChild(upgrade);
   }

   if((bbP2).intersectsRect(bbspeedUp) && (!firstHP || !firstSpeed || !firstDefence || !firstAttack))
   {
	switch(upgrade->getTag())
	{
	  case 1:
	     p2.setHealth(120);
	     firstHP = true;
	     hpup2 = true;
	  break;
	  case 2:
	     p2.setSpeed(2*p2.getSpeed());
	     firstSpeed = true;
	  break;
	  case 3:
             p2.setDefence(2*p2.getDefence());
	     firstDefence = true;
	  break;
	  case 4:
	     p2.setAttack(2*p2.getAttack());
	     firstAttack = true;
	  break;
	}
        removeChild(upgrade);
   }

}

Scene* ModoArcade::createScene(char *tS)
{
    felipao = tS;

    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = ModoArcade::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ModoArcade::init()
{

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    for (int i=0; i<3; i++) {
	actM1[i] = false;
	actM2[i] = false;
    }

     Director::sharedDirector()->resume();

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    ModoArcade::createButtons(visibleSize);

    //Se agrega una etiqueta con el titulo
    auto label = Label::createWithTTF("ModoArcade", "fonts/Marker Felt.ttf", 26);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    /////////////////////////////////
    ///// Manejo de fondos
    //Se carga el mapa y se hacen los collisions tiles con los que el tanque tiene que chocar
    tileMap = new CCTMXTiledMap();
    tileMap->initWithTMXFile("Arcade1.tmx");
    _blockage = tileMap->layerNamed("Collision");
    _blockage->setVisible(false);

    tileMap->setPosition(origin.x,origin.y);
    this->addChild(tileMap);
    //Se obtiene la layer de objetos 'palpables' por el juego
    TMXObjectGroup *objects = tileMap->getObjectGroup("Objects");
    CCASSERT(NULL!=objects, "'Object Layer 1' object group not found");

    //Se inician los estados de los players
    initPlayerStatus();


    //Se crea el sprite de player 1
    auto Player = objects->getObject("Player1");
    CCASSERT(!Player.empty(),"Player object not found");
    int x = Player["x"].asInt();
    int y = Player["y"].asInt();
    _player1 = p1.getPlayer();
    _player1 =Sprite::create(felipao);
    setPlayer1Position(ccp(x-50,y-50));
    _player1->setScale(0.3);
    tileMap->addChild(_player1,1);

    //Se crea el sprite de player 2
    auto Player2 = objects->getObject("Player2");
    int x2 = Player2["x"].asInt();
    int y2 = Player2["y"].asInt();
    _player2 = p2.getPlayer();
    _player2 = Sprite::create(felipao);
    _player2->setPosition(ccp(x2,y2));
    _player2->setScale(0.3);
    tileMap->addChild(_player2,1);
    _player2->runAction(RotateBy::create(0.01, 180));
    _player2->runAction(FadeOut::create(0.001));

    //Se crea el sprite de enemigo 1
    auto Enemy1 = objects->getObject("Enemy1");
    int   x3 = Enemy1["x"].asInt();
    int y3 = Enemy1["y"].asInt();
    _enemy1 = e1.getPlayer();
    _enemy1 = Sprite::create("tank1.png");
    setEnemy1Position(ccp(530,100));
    //    _enemy1->setPosition(ccp(x-400,y+150));
    _enemy1->setScale(0.3);
    tileMap->addChild(_enemy1,1);

    //Se crea el sprite de enemigo 2
    auto Enemy2 = objects->getObject("Enemy2");
    int x4 = Enemy2["x"].asInt();
    int y4 = Enemy2["y"].asInt();
    _enemy2 = e2.getPlayer();
    _enemy2 = Sprite::create("tank2.png");
    setEnemy2Position(ccp(580,590));
    //    _enemy1->setPosition(ccp(x-400,y+150));
    _enemy2->setScale(0.3);
    tileMap->addChild(_enemy2,1);


    auto Enemy3 = objects->getObject("Enemy3");
    int x5 = Enemy3["x"].asInt();
    int y5 = Enemy3["y"].asInt();
    _enemy3 = e3.getPlayer();
    _enemy3 = Sprite::create("tank3.png");
    setEnemy3Position(ccp(350,500));
    //    _enemy1->setPosition(ccp(x-400,y+150));
    _enemy3->setScale(0.3);
    tileMap->addChild(_enemy3,1);



    auto Enemy4 = objects->getObject("Enemy4");
    int x6 = Enemy4["x"].asInt();
    int y6 = Enemy4["y"].asInt();
    _enemy4 = e4.getPlayer();
    _enemy4 = Sprite::create("tank4.png");
    setEnemy4Position(ccp(550,300));
    //    _enemy1->setPosition(ccp(x-400,y+150));
    _enemy4->setScale(0.3);
    tileMap->addChild(_enemy4,1);
  // _enemy4->runAction(FadeOut::create(2.0f));

//
  auto Enemy5 = objects->getObject("Enemy5");
  int x7 = Enemy5["x"].asInt();
  int y7 = Enemy5["y"].asInt();
  _enemy5 = e5.getPlayer();
  _enemy5 = Sprite::create("tank5.png");
  setEnemy5Position(ccp(650,400));
  //    _enemy1->setPosition(ccp(x-400,y+150));
  _enemy5->setScale(0.3);
  tileMap->addChild(_enemy5,1);
// _enemy5->runAction(FadeOut::create(2.0f));
//
//
auto Enemy6 = objects->getObject("Enemy6");
int x8 = Enemy6["x"].asInt();
int y8 = Enemy6["y"].asInt();
_enemy6 = e6.getPlayer();
_enemy6 = Sprite::create("tank6.png");
setEnemy6Position(ccp(250,400));
//    _enemy1->setPosition(ccp(x-400,y+150));
_enemy6->setScale(0.3);
tileMap->addChild(_enemy6,1);
// _enemy4->runAction(FadeOut::create(2.0f));


auto Enemy7 = objects->getObject("Enemy7");
int x9 = Enemy7["x"].asInt();
int y9 = Enemy7["y"].asInt();
_enemy7 = e7.getPlayer();
_enemy7 = Sprite::create("tank7.png");
setEnemy7Position(ccp(720,250));
//    _enemy1->setPosition(ccp(x-400,y+150));
_enemy7->setScale(0.3);
tileMap->addChild(_enemy7,1);
// _enemy4->runAction(FadeOut::create(2.0f));



    auto _fire = Sprite::create("b.png");
    _fire->setPosition(ccp(970,50));
    _fire->setScale(0.08);
    // _fire->setRotation(-90);
     tileMap->addChild(_fire,1);


     auto _bmina = Sprite::create("bmina.png");
     _bmina->setPosition(ccp(140,50));
     _bmina->setScale(0.545);
     // _fire->setRotation(-90);
      tileMap->addChild(_bmina,1);

    //Se crea sprite health bar de player 1
    HB1 = Sprite::create("healthBar.png");
    HB1->setPosition(ccp(x,y+40));
    HB1->setScaleX(0.225);
    HB1->setScaleY(0.1);
	tileMap->addChild(HB1,1);
   //Se crea sprite health bar de player 2
    HB2 = Sprite::create("healthBar.png");
    HB2->setPosition(ccp(x2,y2+40));
    HB2->setScaleX(0.225);
    HB2->setScaleY(0.1);
	tileMap->addChild(HB2,1);
  HB2->runAction(FadeOut::create(0.001));
   //Se crean los sprites de upgrade
    //Tag = 1
    HpUp = Sprite::create("HpUp.png");
    HpUp->setPosition(ccp(x2,y2-300));
    HpUp->setScale(0.3);
    HpUp->setTag(1);
    addChild(HpUp);

    //Tag = 2
    speedUp = Sprite::create("speedUp.png");
    speedUp->setPosition(ccp(x,y+300));
    speedUp->setScale(0.3);
    speedUp->setTag(2);
    addChild(speedUp);

    //Tag = 3
    defenceUp = Sprite::create("defenceUp.png");
    defenceUp->setPosition(ccp(x,y+200));
    defenceUp->setScale(0.3);
    defenceUp->setTag(3);
    addChild(defenceUp);

    //Tag = 4
    attackUp = Sprite::create("attackUp.png");
    attackUp->setPosition(ccp(x,y+100));
    attackUp->setScale(0.3);
    attackUp->setTag(4);
    addChild(attackUp);

   //seccion de movimiento
   auto eventListener = EventListenerKeyboard::create();
   eventListener->onKeyPressed = CC_CALLBACK_2(ModoArcade::onKeyPressed, this);
   eventListener->onKeyReleased = CC_CALLBACK_2(ModoArcade::onKeyReleased, this);


   this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,_player1);


   auto listener = EventListenerTouchOneByOne::create();
   listener->setSwallowTouches(true);

   listener->onTouchBegan = CC_CALLBACK_2(ModoArcade::onTouchBegan, this);
   listener->onTouchEnded = CC_CALLBACK_2(ModoArcade::onTouchEnded, this);

   Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

   Device::setAccelerometerEnabled(true);
   auto accelerationListener = EventListenerAcceleration::create(CC_CALLBACK_2(ModoArcade::onAcceleration, this));
   this->_eventDispatcher->addEventListenerWithSceneGraphPriority(accelerationListener, this);

    ////////////////////////////////////
    // Actualizacion del juego
    this->schedule(schedule_selector(ModoArcade::gameUpdate));


    // set the background music and continuously play it.
    //auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audioMCC->playBackgroundMusic("Audio/DoneD.mp3", true);

    // Pausa o continua el juego
    auto pausa = cocos2d::EventListenerKeyboard::create();
    pausa->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode tecla, cocos2d::Event * event)->void{
	if (tecla == cocos2d::EventKeyboard::KeyCode::KEY_SPACE){
	    if (pause){
		label->setString("ModoArcade");
		Director::sharedDirector()->resume();
	    }
	    else {
		label->setString("Pausa");
		Director::sharedDirector()->pause();
	    }
	    pause = !pause;
	}
    };


    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(pausa,this);



    return true;
}

/////////////////////////////////////////////////////////
////////// Se crean los botones del arcade //////////////
/////////////////////////////////////////////////////////

void ModoArcade::createButtons(Size visibleSize)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // set the font for menu with text
    MenuItemFont::setFontSize(14);

    // Boton para volver al menu de inicio
    auto mbVolver = MenuItemFont::create("Menu de Inicio", CC_CALLBACK_1(ModoArcade::VolverCallBack, this));
    mbVolver->setAnchorPoint(Vec2(0.0,0.0));
    mbVolver->setPosition(Vec2(1*visibleSize.width/16, 1*visibleSize.height/10));
    mbVolver->setColor(Color3B(140, 40, 140));

    // Se crea un boton de salir
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(ModoArcade::menuCloseCallback, this));
    closeItem->setPosition(Vec2(15*visibleSize.width/16, 1*visibleSize.height/10));
    auto menu = Menu::create(mbVolver, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);
}

void ModoArcade::onAcceleration(Acceleration *acc, Event *event)
{
    Size s = Director::getInstance()->getWinSize();
    /*
     * -1 <= pAccelerationValue <= 1
     * so we add +1 to make it, 0 <= pAccelerationValue <= 2
     * then divide by 2 to make it, 0 <= pAccelerationValue <= 1
     */
    float percentX = (acc->x + 1) / 2;
    float percentY = (acc->y + 1) / 2;

    if(powerUp && (acc->x>=0.8 || acc->y>=0.8))
    {
	e1.setHealth(0);
        powerUp = false;
    }

    // position the sprite exactly as how much device accelerated
    //setPlayer1Position(Point(percentX * s.width, percentY * s.height));
}


void ModoArcade::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void ModoArcade::VolverCallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    Director::sharedDirector()->replaceScene(PanzerWars::createScene());
}
