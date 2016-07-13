#ifndef __Batalla_Scene_H__
#define __Batalla_Scene_H__

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

class Batalla : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CCTMXLayer *_blockage;

    //Inicio atributos de jugadores: salud, defensa...
    void initPlayer1Status();
    void initPlayer2Status();

    //Cosas para los fondos y sprites
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void setPlayer1Position(Point position);
    void setPlayer2Position(Point position);
    void setMisil1Position(Point position);
    void setMisil2Position(Point position);
    Point tileCoordForPosition(Point _position);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
    void ModoArcadePlayerPosition(Point position);
    void getUpgrade(Sprite *upgrade);
    //Para actualizar el juego
    void gameUpdate(float interval);
    void onTop(Point position, Sprite *player);
    //

    //Explosiones
    void explosion(Sprite *player);
    void explosion2(Sprite *player);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void VolverCallBack(cocos2d::Ref* pSender);
    void createButtons(cocos2d::Size size);

    // implement the "static create()" method manually
    CREATE_FUNC(Batalla);
private:
    Player p1, p2;
    Vec2 loc1, loc2, locm1, locm2;
    Size visibleSize; //Para puntos de referencia de la pantalla
    Vec2 origin;
    bool pause = false, exp = false, firstSpeed = false, firstHP = false, firstAttack = false,
    firstDefence = false, hitP1= false, hitP2 = false, hpup1 = false, hpup2 = false, game_Over = false,
    onTopP1 = false, onTopP2 = false;
    Sprite *_player1, *_player2, *sprite, *minaP1[3], *minaP2[3], *misil1, *misil2, *HB1, *HB2, *explode,
    *attackUp, *speedUp, *defenceUp, *HpUp;
    CCTMXTiledMap *tileMap;
    CCTMXLayer *background, *_layer1,*_layer2, *_layer3, *_onTop;
    bool up1 = false, down1 = false, right1 = false, left1 = false; //Para control del player 1
    bool up2 = false, down2 = false, right2 = false, left2 = false; //Para control del player 2
    Rect bbP1, bbP2, bbM1[3], bbM2[3], bbm1, bbm2, bbspeedUp; //Para las colisiones con las minas
    int cantM1 = 5, cantM2 = 5, layerOrderP1 = 1, layerOrderP2 = 1, layerTempP1, layerTempP2; //Cantidad inicial de minas
    bool actM1[3], actM2[3], actm1 = false, actm2 = false; //Maximo de minas y misiles a la vez
    bool movm1 = false, movm2 = false;
    int livesP1 = 3, livesP2 = 3;
    int xB1, xB2, yB1, yB2;
    int i; //Para recorrer arreglos
    int dirAnt1 = 1, dirAnt2 = 0, dirm1, dirm2; //Direccion anterior: 0 up, 1 down, 2 left, 3 right
    int HPpercentage1, HPpercentage2; //Porcentaje de salud perdida
    high_resolution_clock::time_point start, startGO; //Para explosiones y game over
    double end = 0, delta = 0, endGO = 0, deltaGO = 0;
};

#endif // __Batalla_Scene_H__
