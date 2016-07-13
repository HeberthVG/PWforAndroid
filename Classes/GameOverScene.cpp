#include "SimpleAudioEngine.h"
#include "PanzerWarsScene.h"


USING_NS_CC;

Scene* GameOver::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOver::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    GameOver::createButtons(visibleSize);

    //Se agrega una etiqueta con el titulo    
    auto label = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 26);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    //Se configura el background
    LayerGradient *bgLayer = LayerGradient::create(ccc4(0, 0, 128, 255), ccc4(0, 0, 0, 255));
    bgLayer->setZOrder(0);
    this->addChild(bgLayer);
    
    return true;
}

/////////////////////////////////////////////////////////
////////// Se crean los botones del game over /////////////
/////////////////////////////////////////////////////////

void GameOver::createButtons(Size visibleSize)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // set the font for menu with text
    MenuItemFont::setFontSize(20);

    // Boton para volver al menu de inicio
    auto mbVolver = MenuItemFont::create("Volver", CC_CALLBACK_1(GameOver::VolverCallBack, this));
    mbVolver->setAnchorPoint(Vec2(0.0,0.0));
    mbVolver->setPosition(0, 0);
    mbVolver->setColor(Color3B(240, 230, 140));

    // Se crea un boton de salir
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(GameOver::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    auto menu = Menu::create(mbVolver, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);

}


void GameOver::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameOver::VolverCallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    Director::sharedDirector()->replaceScene(PanzerWars::createScene());
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

