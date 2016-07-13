#ifndef __Creditos_Scene_H__
#define __Creditos_Scene_H__

#include "cocos2d.h"

class Creditos : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void VolverCallBack(cocos2d::Ref* pSender);
    void createButtons(cocos2d::Size size);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Creditos);
};

#endif // __Creditos_Scene_H__
