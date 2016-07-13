#ifndef __PanzerWars_Scene_H__
#define __PanzerWars_Scene_H__

#include "cocos2d.h"

class PanzerWars : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    //Crear un menu
    void createMenu(cocos2d::Size size);
    void ModoVsCallBack(cocos2d::Ref* pSender);
    void ModoArcadeCallBack(cocos2d::Ref* pSender);
    void CreditosCallBack(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PanzerWars);
};

#endif // __PanzerWars_Scene_H__
