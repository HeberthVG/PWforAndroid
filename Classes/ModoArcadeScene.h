#ifndef __ModoArcade_Scene_H__
#define __ModoArcade_Scene_H__

#include "cocos2d.h"
#include "Player.h"
#include <CCTMXLayer.h>
#include <CCTMXTiledMap.h>
#include <CCTMXObjectGroup.h>
#include <CCScene.h>
#include <chrono>
#include <ctime>
#include <unistd.h>

using namespace std;
using namespace cocos2d;
using namespace std::chrono;

class ModoArcade : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CCTMXLayer *_blockage;

    //Inicio atributos de jugadores: salud, defensa...
    void initPlayerStatus();

    //Cosas para los fondos y sprites
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void setPlayer1Position(Point position);
    void setPlayer2Position(Point position);
    void setEnemy1Position(Point position);
    void setEnemy2Position(Point position);
    void setMisil1Position(Point position);
    void setMisil2Position(Point position);
    void setMisil3Position(Point position);
    void setMisil4Position(Point position);

    void dispararMisilENemigo1();
    void dispararMisilENemigo2();
    void activarMinaE2(Point position);
    Point tileCoordForPosition(Point _position);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
    void ModoArcadePlayerPosition(Point position);
    void getUpgrade(Sprite *upgrade);
    //Para actualizar el juego
    void gameUpdate(float interval);

    //Explosiones
    void explosion(Sprite *player);
    void explosion2(Sprite *player);
    void explosion4(Sprite *player);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void VolverCallBack(cocos2d::Ref* pSender);
    void createButtons(cocos2d::Size size);

    // implement the "static create()" method manually
    CREATE_FUNC(ModoArcade);
private:
    Player p1, p2,e1,e2;
    Vec2 loc1, loc2,loc3,loc4, locm1, locm2,locmE1,locmE2;
    Size visibleSize; //Para puntos de referencia de la pantalla
    Vec2 origin;
    bool pause = false, exp = false, firstSpeed = false, firstHP = false, firstAttack = false,
    firstDefence = false, hitP1= false, hitP2 = false,hitE2 = false,hitE1 = false, hpup1 = false, hpup2 = false, game_Over = false;
    bool e1Collision = false, e2Collision=false;
    Sprite *_player1, *_player2,*_enemy1,*_enemy2, *sprite, *minaP1[3], *minaP2[3],*minaE1[3],*minaE2[3], *misil1, *misil2,*misil3,*misil4, *HB1, *HB2,*HB3, *explode,
    *attackUp, *speedUp, *defenceUp, *HpUp;
    CCTMXTiledMap *tileMap;
    CCTMXLayer *background;
    bool up1 = false, down1 = false, right1 = false, left1 = false; //Para control del player 1
    bool up2 = false, down2 = false, right2 = false, left2 = false; //Para control del player 2
    Rect bbP1, bbP2,bbE1,bbE2, bbM1[3], bbM2[3], bbM3[3], bbM4[3], bbm1, bbm2,bbmE1,bbmE2, bbspeedUp; //Para las colisiones con las minas
    int cantM1 = 5, cantM2 = 5,cantM4 = 5; //Cantidad inicial de minas
    bool actM1[3], actM2[3],actM3[3], actM4[3], actm1 = false, actm2 = false, actmE1=false, actmE2=false; //Maximo de minas y misiles a la vez
    int i; //Para recorrer arreglos
    int dirAnt1 = 1, dirAnt2 = 0,dirAntE1=1,dirAntE2=1, dirm1, dirm2,dirmE1,dirmE2, tramo=1,r2,r2ant=0; //Direccion anterior: 0 up, 1 down, 2 left, 3 right
    int HPpercentage1, HPpercentage2; //Porcentaje de salud perdida
    high_resolution_clock::time_point start, startGO; //Para explosiones y game over
    double end = 0, delta = 0, endGO = 0, deltaGO = 0;
};

#endif // __Batalla_Scene_H__
