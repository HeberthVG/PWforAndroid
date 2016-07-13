#ifndef __KOTH_Scene_H__
#define __KOTH_Scene_H__

#include "cocos2d.h"
#include "Player.h"
#include <CCTMXLayer.h>
#include <CCTMXTiledMap.h>
#include <CCTMXObjectGroup.h>
#include <CCScene.h>


using namespace std;
using namespace cocos2d;

class KOTH : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CCTMXLayer *_blockage;
   // CCTMXLayer *_koth;

    //Cosas para los fondos
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void setPlayer1Position(Point position);
    void setPlayer2Position(Point position);
    void setEnemy1Position(Point position);

    void setMisil1Position(Point position);
    void setMisil2Position(Point position);
    void setMisil3Position(Point position);
    void dispararMisilENemigo();
    Point tileCoordForPosition(Point _position);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
    void ModoArcadePlayerPosition(Point position);
    //Inicio atributos de jugadores: salud, defensa...
    void initPlayerStatus();
    //Para actualizar el juego
    void gameUpdate(float interval);
    void KOTHCounter1(Point position);
    void KOTHCounter2(Point position);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void VolverCallBack(cocos2d::Ref* pSender);
    void createButtons(cocos2d::Size size);

    // implement the "static create()" method manually
    CREATE_FUNC(KOTH);
private:
    Player p1, p2,e1;
    Vec2 loc1, loc2, loc3, locm1, locm2, locmE1;
    double duration1=0, duration2=0;
    bool pause = false, hitP1 = false, hitP2 = false;
    bool stop = false;
    Sprite *_player1, *_player2,*_enemy1, *sprite, *minaP1[3], *minaP2[3], *misil1, *misil2,*misil3, *HB1, *HB2;
    CCTMXTiledMap *tileMap;
    CCTMXLayer *background;
    bool up1 = false, down1 = false, right1 = false, left1 = false; //Para control del player 1
    bool up2 = false, down2 = false, right2 = false, left2 = false; //Para control del player 2
    Rect bbP1, bbP2,bbE1, bbM1[3], bbM2[3], bbm1, bbm2,bbmE1 ; //Para las colisiones con las minas
    int cantM1 = 5, cantM2 = 5; //Cantidad inicial de minas
    bool actM1[3], actM2[3], actm1 = false, actm2 = false, actmE1=false; //Maximo de minas y misiles a la vez
    int i; //Para recorrer arreglos
    int HPpercentage1, HPpercentage2; //Porcentaje de salud perdida
    int dirAnt1 = 1, dirAnt2 = 1,dirAntE1=1, dirm1, dirm2, dirmE1; //Direccion anterior: 0 up, 1 down, 2 left, 3 right
};

#endif // __KOTH_Scene_H__
