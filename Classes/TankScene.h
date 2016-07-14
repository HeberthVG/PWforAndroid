#ifndef __Tank_Scene_H__
#define __Tank_Scene_H__

#include "cocos2d.h"

class Tank : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    //Constructor
    Tank();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void VolverCallBack(cocos2d::Ref* pSender);
    void createButtons(cocos2d::Size size);
    void Tank1CallBack(cocos2d::Ref* pSender);
    void Tank2CallBack(cocos2d::Ref* pSender);
    void Tank3CallBack(cocos2d::Ref* pSender);
    void Tank6CallBack(cocos2d::Ref* pSender);
    int getTank();

    char* tanque;
    int tanqueS;
    
    // implement the "static create()" method manually
    CREATE_FUNC(Tank);
};

#endif // __Tank_Scene_H__
