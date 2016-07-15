#ifndef __ModoArcade_Scene_H__
#define __ModoArcade_Scene_H__

#include "cocos2d.h"
#include "Player.h"
#include <CCTMXLayer.h>
#include <CCTMXTiledMap.h>
#include <CCTMXObjectGroup.h>
#include <CCDevice.h>
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
    cocos2d::Scene* createScene(char *t);

    virtual bool init();

    CCTMXLayer *_blockage;

    //Inicio atributos de jugadores: salud, defensa...
    void initPlayerStatus();
    //para acelerometro
    virtual void onAcceleration(Acceleration* acc, Event* event);

    //Cosas para los fondos y sprites
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    void setPlayer1Position(Point position);
    void setPlayer2Position(Point position);
    void setEnemy1Position(Point position);
    void setEnemy2Position(Point position);
    void setEnemy3Position(Point position);
    void setEnemy4Position(Point position);
    void setEnemy5Position(Point position);
    void setEnemy6Position(Point position);
    void setEnemy7Position(Point position);
    void setMisil1Position(Point position);
    void setMisil2Position(Point position);
    void setMisil3Position(Point position);
    void setMisil4Position(Point position);
    void setMisil5Position(Point position);
    void setMisil6Position(Point position);
    void setMisil7Position(Point position);
    void setMisil8Position(Point position);
    void setMisil9Position(Point position);
    void setMisil10Position(Point position);
    void dispararMisilENemigo1();
    void dispararMisilPlayer1();
    void dispararMisilENemigo2();
    void dispararMisilENemigo3();
    void dispararMisilENemigo4();
    void dispararMisilENemigo5();
    void dispararMisilENemigo6();
    void dispararMisilENemigo7();


    void activarMinaE2(Point position);
    void activarMinaP1(Point position);
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
    Player p1, p2,e1,e2,e3,e4,e5,e6,e7,e8;
    Vec2 loc1, loc2,loc3,loc4,loc5,loc6,loc7,loc8,loc9,loc10, locm1, locm2,locmE1,locmE2,locmE3,locmE4,locmE5,locmE6,locmE7,locmE8, locm5;
    Size visibleSize; //Para puntos de referencia de la pantalla
    Vec2 origin;
    bool pause = false, exp = false, firstSpeed = false, firstHP = false, firstAttack = false,
    firstDefence = false, hitP1= false, hitP2 = false,hitE2 = false,hitE1 = false, hpup1 = false, hpup2 = false, game_Over = false;
    bool e1Collision = false, e2Collision=false,e3Collision=false,e4Collision=false,e5Collision=false,e6Collision=false,e7Collision=false,e8Collision=false, powerUp = false;
    Sprite *_player1, *_player2,*_enemy1,*_enemy2,*_enemy3,*_enemy4, *_enemy5, *_enemy6, *_enemy7, *_enemy8,  *sprite, *minaP1[3], *minaP2[3],*minaE1[3],*minaE2[3],*minaP1b[3], *misil1, *misil2,*misil3,*misil4,*misil5,*misil6,*misil7,*misil8,*misil9,*misil10,*misi11, *_fire,*bmina,   *HB1, *HB2,*HB3, *explode,
    *attackUp, *speedUp, *defenceUp, *HpUp;
    CCTMXTiledMap *tileMap;
    CCTMXLayer *background;
    bool up1 = false, down1 = false, right1 = false, left1 = false, Up_left1=false, Up_right1=false, Down_left1=false, Down_right1=false,mine=false,ronda1=true, ronda2=false, ronda3=false   ; //Para control del player 1
    bool up2 = false, down2 = false, right2 = false, left2 = false; //Para control del player 2
    Rect bbP1, bbP2,bbE1,bbE2,bbE3,bbE4,bbE5,bbE6,bbE7,bbE8, bbM1[3], bbM2[3], bbM3[3], bbM4[3], bbM5[3], bbm1,bbm5, bbm2,bbmE1,bbmE2,bbmE3,bbmE4,bbmE5,bbmE6,bbmE7,bbmE8, bbspeedUp; //Para las colisiones con las minas
    int cantM1 = 5, cantM2 = 5,cantM4 = 5,cantM5 = 5; //Cantidad inicial de minas
    bool actM1[3], actM2[3],actM3[3],actM5[3], actM4[3], actm1 = false, actm2 = false, actmE1=false, actmE2=false,actmE3=false,actmE4=false,actmE5=false,actmE6=false,actmE7=false,actmE8=false, actm5=false, fire=false; //Maximo de minas y misiles a la vez
    int i; //Para recorrer arreglos
    int dirAnt1 = 1, dirAnt2 = 0,dirAntE1=1,dirAntE2=1,dirAntE3=1,dirAntE4=1,dirAntE5=1,dirAntE6=1,dirAntE7=1,dirAntE8=1, dirm1,dirm5, dirm2,dirmE1,dirmE2,dirmE3,dirmE4,dirmE5,dirmE6,dirmE7,dirmE8, tramo=1,r2,r2ant=0; //Direccion anterior: 0 up, 1 down, 2 left, 3 right
    int HPpercentage1, HPpercentage2; //Porcentaje de salud perdida
    high_resolution_clock::time_point start, startGO; //Para explosiones y game over
    double end = 0, delta = 0, endGO = 0, deltaGO = 0;
};

#endif // __Batalla_Scene_H__
