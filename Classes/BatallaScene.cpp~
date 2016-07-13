#include "BatallaScene.h"
#include "PanzerWarsScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
using namespace cocos2d;
using namespace std;

auto audioB = CocosDenshion::SimpleAudioEngine::getInstance();
auto audioB_BM = CocosDenshion::SimpleAudioEngine::getInstance();
////////////////////////////////
//Manejo de fondos y movimientos
Point Batalla::tileCoordForPosition(Point _position)
{
    int x = _position.x / tileMap->getTileSize().width;
    int y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - _position.y)/tileMap->getTileSize().height;
    return Point(x, y);
}

void Batalla::initPlayer1Status()
{
	//Inicio estado de player1
	p1.setHealth(100);
	p1.setDefence(5);
	p1.setAttack(120);
	p1.setSpeed(2);
}
void Batalla::initPlayer2Status()
{
	//Inicio estado de player2
	p2.setHealth(100);
	p2.setDefence(10);
	p2.setAttack(120);
	p2.setSpeed(1);

}

void Batalla::gameUpdate(float interval)
{


    if(!pause) {
    loc1 = _player1->getPosition();
    loc2 = _player2->getPosition();
    bbP1 = _player1->getBoundingBox();
    bbP2 = _player2->getBoundingBox();

    HB1->setPosition(ccp(loc1.x,loc1.y+40));
    HB2->setPosition(ccp(loc2.x,loc2.y+40));
    //Se inician/refrescan los porcentajes de salud por hit al tanque
    HPpercentage1 = p2.getAttack()/p1.getDefence();
    HPpercentage2 = p1.getAttack()/p2.getDefence();
    //Verifica si esta encima de layer 3
    onTop(ccp(loc1.x,loc1.y), _player1);
    onTop(ccp(loc2.x,loc2.y), _player2);

    /////////////////////////////////////////////////////////
    //Bloqueos
	if (bbP1.intersectsRect(bbP2)) {
	    switch(dirAnt2) {
		case 0:
		    up2 = false;
		    break;
		case 1:
		    down2 = false;
		    break;
		case 2:
		    left2 = false;
		    break;
		case 3:
		    right2 = false;
		    break;
	    }
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
    ////////////////////////////////////////////////////////////
    // Movimiento Jugadores y se establece la posicion de health bars
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
	    }
	    dirAnt1 = 2;
	    setPlayer1Position(ccp(--loc1.x-p1.getSpeed(),loc1.y)); // player 1 going left
	}
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


    /////////////////////////////////////////////
    // Para colisiones entre sprites
    for(i=0; i<3; i++) {
	if(bbP1.intersectsRect(bbM2[i]) && (actM2[i]==true)) {
	    //if(!end) {
	    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
	    //-10 a health de p1
	    if(p1.getHealth()>0)
	    p1.setHealth(p1.getHealth()-50);
	    if(p1.getHealth()<0)
	    p1.setHealth(0);
	    hitP2 = true;
	    explosion(minaP2[i]);
	    //}
	    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
	    end = delta;
	    if (end > 2) {
		tileMap->removeChild(minaP2[i]);
		end = 0;
	    }
  		actM2[i] = false;
	}
	if(bbP2.intersectsRect(bbM1[i]) && (actM1[i]==true)) {
	    //if(!end) {
	    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Bomb.mp3");
	    //-10 a health de p2
	    if(p2.getHealth()>0)
	    p2.setHealth(p2.getHealth()-50);
	    if(p2.getHealth()<0)
	    p2.setHealth(0);
	    hitP1 = true;
	    explosion(minaP1[i]);
	    //}
	    delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
	    end = delta;
	    if (end > 2) {
		tileMap->removeChild(minaP1[i]);
		end = 0;
	    }
  		actM1[i] = false;
	}
    }

    /////////////////////////////////////////
    //Misiles
        if(actm1) {
    	  locm1 = misil1->getPosition();
	      bbm1 = misil1->getBoundingBox();
  //       if(_player1->getZOrder()==2)
	// {
	//     misil1->setZOrder(2);
	// }
        //onTop(ccp(locm1.x,locm1.y), misil1);
	//if(movm1) {
	switch (dirm1)
	{
		case 0:
		    setMisil1Position(ccp(locm1.x,++locm1.y+3));
		    break;
		case 1:
		     setMisil1Position(ccp(locm1.x,--locm1.y-3));
		     break;
		case 2:
		    setMisil1Position(ccp(--locm1.x-3,locm1.y));
		    break;
		case 3:
		    setMisil1Position(ccp(++locm1.x+3,locm1.y));
	//}
	}
	if(bbm1.intersectsRect(bbP2))
	{
    log("dispare");
		//if(!end) {
		explosion(misil1);
		movm1 = false;
		p2.setHealth(p2.getHealth()-HPpercentage2);
		hitP1 = true;
		if(p2.getHealth()<0)
		p2.setHealth(0);
		//{
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
		end = delta;
		if (end > 2) {
		    tileMap->removeChild(misil1, _player1->getZOrder());
		    end = 0;
		}
    actm1 = false;
	}
	for(i=0; i<3; i++) {
	    if((actM2[i]) && bbm1.intersectsRect(bbM2[i])) {
		//if(!end) {
		explosion(misil1);
		explosion(minaP2[i]);
		movm1 = false;
		//}
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
		end = delta;
		if (end > 2) {
		    tileMap->removeChild(misil1, _player1->getZOrder());
		    tileMap->removeChild(minaP2[i]);
		    end = 0;
		}
    actm1 = false;
    actM2[i] = false;
	    }
	}
    }
    if(actm2)
    {
	locm2 = misil2->getPosition();
	bbm2 = misil2->getBoundingBox();
	// if(_player2->getZOrder()==2)
	// {
	//     misil2->setZOrder(2);
	// }
        //onTop(ccp(locm2.x,locm2.y), misil2);
	//if(movm2) {
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
	//}
	}
	if(bbm2.intersectsRect(bbP1))
	{
		//if(!end) {
		explosion(misil2);
		p1.setHealth(p1.getHealth()-HPpercentage1);
		hitP2 = true;
		if(p1.getHealth()<0)
		p1.setHealth(0);
		movm2 = false;
		//}
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
		end = delta;
		if (end > 2) {
		    tileMap->removeChild(misil2);
		    end = 0;
		}
    actm2 = false;
	}
	for(i=0; i<3; i++) {
	    if((actM1[i]) && bbm2.intersectsRect(bbM1[i])) {
		//if(!end) {
		explosion(misil2);
		explosion(minaP1[i]);
		movm2 = false;
		//}
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
		end = delta;
		if (end > 2) {
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
		//if(!end) {
		explosion(misil2);
		explosion2(misil1);
		movm1 = false;
		movm2 = false;
		//}
		delta = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-start).count()/1000;
		end = delta;
		if (end > 2) {
		    tileMap->removeChild(misil2, _player2->getZOrder());
		    tileMap->removeChild(misil1, _player1->getZOrder());
		    end = 0;
		    endGO = 0;
		}
    actm2 = false;
    actm1 = false;
	    }
	}
    }
    ////////////////////////////////////
    /// Barras de vida
    if(hitP2)
    {
	if(p1.getHealth()==100)
	{
      	  removeChild(HB1);
      	  HB1 = Sprite::create("healthBar.png");
      	  HB1->setPosition(ccp(loc1.x,loc1.y+40));
      	  HB1->setScaleX(0.225);
      	  HB1->setScaleY(0.1);
      	  addChild(HB1);
	}else if(p1.getHealth()!=100 && p1.getHealth()>0)
	{
	  HB1->setScaleX(0.225*((float)p1.getHealth()/100));
	}
	hitP2 = false;
    }
    if(hitP1)
    {
	if(p2.getHealth()==100)
	 {
      	  removeChild(HB2);
      	  HB2 = Sprite::create("healthBar.png");
   	  HB2->setPosition(ccp(loc2.x,loc2.y+40));
          HB2->setScaleX(0.225);
      	  HB2->setScaleY(0.1);
      	  addChild(HB2);
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

    ///////////////////////////////////////
    //Game Over
    if(!livesP1) {
	auto gameOver = Label::createWithTTF("  Game Over\nPlayer 2 Won", "fonts/Marker Felt.ttf", 26);
    	gameOver->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    	addChild(gameOver, 1);
	pause = true;
	audioB->stopAllEffects();
	audioB_BM->stopBackgroundMusic();
	Director::sharedDirector()->pause();
    }
    if(!livesP2) {
	auto gameOver = Label::createWithTTF("  Game Over\nPlayer 1 Won", "fonts/Marker Felt.ttf", 26);
    	gameOver->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    	addChild(gameOver, 1);
	pause = true;
	audioB->stopAllEffects();
	audioB_BM->stopBackgroundMusic();
	Director::sharedDirector()->pause();
    }

    //////////////////////////////////////////////
    //Spawneo
    if(!p1.getHealth()) {
	if(!endGO) {
	    explosion2(_player1);
	    livesP1--;
	}
	deltaGO = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-startGO).count()/1000;
	endGO = deltaGO;
	if (endGO > 1) {
	    if(livesP1) {
	    removeChild(_player1);
	    _player1 =Sprite::create("tank3.png");
	    setPlayer1Position(ccp(xB1-50,yB1-50));
	    _player1->setScale(0.3);
	    tileMap->addChild(_player1,1);
	    dirAnt1 = 1;
	    _player1->runAction(FadeIn::create(0.01f));
	    initPlayer1Status();
	    hitP2 = true;
	    }
	    endGO=0;
	}
    }
    if(!p2.getHealth()) {
	if(!endGO) {
	    explosion2(_player2);
	    livesP2--;
	}
	deltaGO = std::chrono::duration<double, std::milli>(high_resolution_clock::now()-startGO).count()/1000;
	endGO = deltaGO;
	if (endGO > 1) {
	    if(livesP2) {
	    removeChild(_player2);
	    _player2 = Sprite::create("tank3.png");
	    _player2->setPosition(ccp(xB2,yB2));
	    _player2->setScale(0.3);
	    tileMap->addChild(_player2,1);
	    _player2->runAction(RotateBy::create(0.01, 180));
	    dirAnt2 = 0;
	    _player1->runAction(FadeIn::create(0.01f));
	    initPlayer2Status();
	    hitP1 = true;
	    }
	    endGO = 0;
	}
    }

  }
}

void Batalla::explosion(Sprite *player)
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

void Batalla::explosion2(Sprite *player)
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

void Batalla::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
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
	    if(cantM1>0 && !pause){
		for(i=0; i<3; i++) {
		    if(actM1[i]==false) {
			cantM1--;
			minaP1[i] = Sprite::create("mina.png");
			minaP1[i]->setPosition(_player1->getPosition());
			minaP1[i]->setScale(0.4);
			tileMap->addChild(minaP1[i],_player1->getZOrder());
			bbM1[i] = minaP1[i]->getBoundingBox();
			actM1[i] = true;
			break;
		    }
		}
	    }
	    break;
	case EventKeyboard::KeyCode::KEY_E:
	    if(!actm1 && !pause) {
   	 	audioB->playEffect("Audio/explosion3.mp3");
    		audioB->setEffectsVolume(0.3);
		misil1 = Sprite::create("c1.png");
		misil1->setPosition(_player1->getPosition());
		misil1->setScale(0.4);
		tileMap->addChild(misil1,_player1->getZOrder());
		actm1 = true;
		movm1 = true;
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
	    if(cantM2>0 && !pause){
		for(i=0; i<3; i++) {
		    if(actM2[i]==false) {
			cantM2--;
			minaP2[i] = Sprite::create("mina.png");
			minaP2[i]->setPosition(_player2->getPosition());
			minaP2[i]->setScale(0.4);
			tileMap->addChild(minaP2[i],_player2->getZOrder());
			bbM2[i] = minaP2[i]->getBoundingBox();
			actM2[i] = true;
			break;
		    }
		}
	    }
	    break;
	case EventKeyboard::KeyCode::KEY_O:
	    if(!actm2 && !pause) {
   	 	audioB->playEffect("Audio/explosion3.mp3");
    		audioB->setEffectsVolume(0.3);
		misil2 = Sprite::create("c1.png");
		misil2->setPosition(_player2->getPosition());
		misil2->setScale(0.4);
		tileMap->addChild(misil2,_player2->getZOrder());
		actm2 = true;
		movm2 = true;
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

void Batalla::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
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

void Batalla::setPlayer1Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
	    auto onTop  = properties["onTop"].asString();
	    auto collisionTop = properties["collisionTop"].asString();
            auto collision = properties["Collision"].asString();
            if ("True" == collision || ((_player1->getZOrder()==2) && (collisionTop == "True"))) {
		log("COLISION");
                return;
            }
        }else return;
    }
    _player1->setPosition(position);
}

void Batalla::setPlayer2Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    log("tileGid = %d", tileGid);
    if (tileGid) {
	//log("DEBUG");
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto onTop  = properties["onTop"].asString();
	    auto collisionTop = properties["collisionTop"].asString();
            auto collision = properties["Collision"].asString();
            if ("True" == collision || ((_player2->getZOrder()==2) && (collisionTop == "True"))) {
		log("COLISION");
                return;
            }
        }else return;
    }
    _player2->setPosition(position);
}

void Batalla::setMisil1Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto onTop  = properties["onTop"].asString();
	    auto collisionTop = properties["collisionTop"].asString();
            auto collision = properties["Collision"].asString();
            if ("True" == collision /*|| ((misil1->getZOrder()==2) && (collisionTop == "True"))*/) {
	    	        tileMap->removeChild(misil1,_player1->getZOrder());
	    	        actm1 = false;
                movm1 =false;
	    	        log("COLISION");
            	return;
            }
        }else return;
    }
    misil1->setPosition(position);
}

void Batalla::setMisil2Position(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _blockage->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
            auto onTop  = properties["onTop"].asString();
	    auto collisionTop = properties["collisionTop"].asString();
            auto collision = properties["Collision"].asString();
            if ("True" == collision /*|| ((misil1->getZOrder()==2) && (collisionTop == "True"))*/) {
		            tileMap->removeChild(misil2, _player2->getZOrder());
		            actm2 = false;
                movm2 = false;
		//log("COLISION");
                return;
            }
        }else return;
    }
    misil2->setPosition(position);
}

void Batalla::onTop(Point position,Sprite *player)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid = _onTop->getTileGIDAt(tileCoord);
    if (tileGid) {
        auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
        if (!properties.empty()) {
	    auto onTop = properties["onTop"].asString();
	    auto notTop = properties["notTop"].asString();
            if (onTop == "True")
	    {
		player->setZOrder(2);
		return;
            }
            if (notTop == "True")
	    {
         	player->setZOrder(1);
		return;
            }

        }
    }
//    player->setZOrder(1);
}

void Batalla::getUpgrade(Sprite *upgrade)
{
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


Scene* Batalla::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Batalla::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Batalla::init()
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

    Batalla::createButtons(visibleSize);

    //Se agrega una etiqueta con el titulo
    auto label = Label::createWithTTF("Batalla", "fonts/Marker Felt.ttf", 26);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    /////////////////////////////////
    ///// Manejo de fondos
    //Se carga el mapa y se hacen los collisions tiles con los que el tanque tiene que chocar
    tileMap = new CCTMXTiledMap();
    tileMap->initWithTMXFile("Arcade2.tmx");
    _blockage = tileMap->layerNamed("Collision");
    _blockage->setVisible(false);
    _onTop = tileMap->layerNamed("onTop");
    _onTop->setVisible(false);


    tileMap->setPosition(origin.x,origin.y);
    this->addChild(tileMap);
    log("HI");
    //Se obtiene la layer de objetos 'palpables' por el juego
    TMXObjectGroup *objects = tileMap->getObjectGroup("Objects");
    CCASSERT(NULL!=objects, "'Object Layer 1' object group not found");

    //Se inician los estados de los players
    initPlayer1Status();
    initPlayer2Status();


    //Se crea el sprite de player 1
    auto Player = objects->getObject("Player1");
    CCASSERT(!Player.empty(),"Player object not found");
    xB1 = Player["x"].asInt();
    yB1 = Player["y"].asInt();
    _player1 = p1.getPlayer();
    _player1 =Sprite::create("tank3.png");
    setPlayer1Position(ccp(xB1-50,yB1-50));
    _player1->setScale(0.3);
    tileMap->addChild(_player1,1);

    //Se crea el sprite de player 2
    auto Player2 = objects->getObject("Player2");
    xB2 = Player2["x"].asInt();
    yB2 = Player2["y"].asInt();
    _player2 = p2.getPlayer();
    _player2 = Sprite::create("tank3.png");
    _player2->setPosition(ccp(xB2,yB2));
    _player2->setScale(0.3);
    tileMap->addChild(_player2,1);
    _player2->runAction(RotateBy::create(0.01, 180));

    //Se crea sprite health bar de player 1
    HB1 = Sprite::create("healthBar.png");
    HB1->setPosition(ccp(xB1,yB1+40));
    HB1->setScaleX(0.225);
    HB1->setScaleY(0.1);
	addChild(HB1);
   //Se crea sprite health bar de player 2
    HB2 = Sprite::create("healthBar.png");
    HB2->setPosition(ccp(xB2,yB2+40));
    HB2->setScaleX(0.225);
    HB2->setScaleY(0.1);
	addChild(HB2);

   //seccion de movimiento
   auto eventListener = EventListenerKeyboard::create();
   eventListener->onKeyPressed = CC_CALLBACK_2(Batalla::onKeyPressed, this);
   eventListener->onKeyReleased = CC_CALLBACK_2(Batalla::onKeyReleased, this);

   this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,_player1);



    ////////////////////////////////////
    // Actualizacion del juego
    this->schedule(schedule_selector(Batalla::gameUpdate));


    // set the background music and continuously play it.
    audioB_BM->playBackgroundMusic("Audio/track01.mp3", true);

    // Pausa o continua el juego
    auto pausa = cocos2d::EventListenerKeyboard::create();
    pausa->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode tecla, cocos2d::Event * event)->void{
	if (tecla == cocos2d::EventKeyboard::KeyCode::KEY_SPACE){
	    if (pause){
		label->setString("Batalla");
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

void Batalla::createButtons(Size visibleSize)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // set the font for menu with text
    MenuItemFont::setFontSize(14);

    // Boton para volver al menu de inicio
    auto mbVolver = MenuItemFont::create("Menu de Inicio", CC_CALLBACK_1(Batalla::VolverCallBack, this));
    mbVolver->setAnchorPoint(Vec2(0.0,0.0));
    mbVolver->setPosition(Vec2(1*visibleSize.width/16, 1*visibleSize.height/10));
    mbVolver->setColor(Color3B(140, 40, 140));

    // Se crea un boton de salir
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(Batalla::menuCloseCallback, this));
    closeItem->setPosition(Vec2(15*visibleSize.width/16, 1*visibleSize.height/10));
    auto menu = Menu::create(mbVolver, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);
}


void Batalla::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Batalla::VolverCallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    Director::sharedDirector()->replaceScene(PanzerWars::createScene());
}
