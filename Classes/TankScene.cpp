#include "TankScene.h"
#include "PanzerWarsScene.h"
#include "SimpleAudioEngine.h"
#include "ModoArcadeScene.h"

USING_NS_CC;

Scene* Tank::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Tank::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Tank::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Tank::createButtons(visibleSize);

    //Se agrega una etiqueta con el titulo    
    auto label = Label::createWithTTF("Seleccione un tanque", "fonts/Marker Felt.ttf", 36);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    //Se configura el background
    LayerGradient *bgLayer = LayerGradient::create(ccc4(0, 0, 128, 255), ccc4(0, 0, 0, 255));
    bgLayer->setZOrder(0);
    this->addChild(bgLayer);
    
    return true;
}

///////////////////////////////////////////////////////////////////////
////////// Se crean los botones con tanques a seleccionar /////////////
///////////////////////////////////////////////////////////////////////

void Tank::createButtons(Size visibleSize)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // set the font for menu with text
    MenuItemFont::setFontSize(20);

    // Boton para volver al menu de inicio
    auto mbVolver = MenuItemFont::create("Volver", CC_CALLBACK_1(Tank::VolverCallBack, this));
    mbVolver->setAnchorPoint(Vec2(0.0,0.0));
    mbVolver->setPosition(0, 0);
    mbVolver->setColor(Color3B(240, 230, 140));

    // Se crea un boton de salir
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(Tank::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    auto menu = Menu::create(mbVolver, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 3);

    // Tanque 1
    auto mbT1 = MenuItemImage::create("tank1.png", "tank1.png",
                                           CC_CALLBACK_1(Tank::Tank1CallBack, this));
    mbT1->setPosition(Vec2(1*visibleSize.width/12 - mbT1->getContentSize().width/2,
				visibleSize.height/12));
    mbT1->setScale(0.5);
    // Tanque 2
    auto mbT2 = MenuItemImage::create("tank2.png", "tank2.png",
                                           CC_CALLBACK_1(Tank::Tank2CallBack, this));
    mbT2->setPosition(Vec2(3*visibleSize.width/12 - mbT2->getContentSize().width/2,
				visibleSize.height/12));
    mbT2->setScale(0.5);
    // Tanque 3
    auto mbT3 = MenuItemImage::create("tank3.png", "tank3.png",
                                           CC_CALLBACK_1(Tank::Tank3CallBack, this));
    mbT3->setPosition(Vec2(5*visibleSize.width/12 - mbT3->getContentSize().width/2,
				visibleSize.height/12));
    mbT3->setScale(0.5);
    // Tanque 6
    auto mbT6 = MenuItemImage::create("tank6.png", "tank6.png",
                                           CC_CALLBACK_1(Tank::Tank6CallBack, this));
    mbT6->setPosition(Vec2(7*visibleSize.width/12 - mbT6->getContentSize().width/2,
				visibleSize.height/12));
    mbT6->setScale(0.5);

    // now create a menu with menu items.
    auto menuTank = Menu::create(mbT1, mbT2, mbT3, mbT6, NULL);

    // set the position of menu
    menuTank->setPosition(Vec2(visibleSize.width/6, visibleSize.height/2.0));

    // set the alignment & padding for the menu.
    //menuCenter->alignItemsVertically();

    // add it to scene-layer
    addChild(menuTank,2);
}

void Tank::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Tank::VolverCallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    Director::sharedDirector()->replaceScene(PanzerWars::createScene());
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void Tank::Tank1CallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    ModoArcade tankSel;
    Director::sharedDirector()->replaceScene(tankSel.createScene("tank1.png"));
}

void Tank::Tank2CallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    ModoArcade tankSel;
    Director::sharedDirector()->replaceScene(tankSel.createScene("tank2.png"));
}

void Tank::Tank3CallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    ModoArcade tankSel;
    Director::sharedDirector()->replaceScene(tankSel.createScene("tank3.png"));
}

void Tank::Tank6CallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    ModoArcade tankSel;
    Director::sharedDirector()->replaceScene(tankSel.createScene("tank6.png"));
}

int Tank::getTank()
{
    return tanqueS;
}

Tank::Tank()
{
}
