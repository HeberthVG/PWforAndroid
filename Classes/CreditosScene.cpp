#include "CreditosScene.h"
#include "PanzerWarsScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Creditos::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Creditos::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Creditos::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Creditos::createButtons(visibleSize);

    //Se agrega una etiqueta con el titulo    
    auto label = Label::createWithTTF("Creditos", "fonts/Marker Felt.ttf", 26);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    //Se agrega una etiqueta con el titulo    
    auto label2 = Label::create("Desarrollado por: \n\nEmanuel 'El Ligador' Hernandez\nFelipe 'El Charlatan' Moya\nHeberth Valverde", "fonts/arial.ttf", 18);
    label2->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + 0.95*visibleSize.height - label2->getContentSize().height));
    label2->setDimensions(3*visibleSize.width/5, 0);
    this->addChild(label2, 1);

    //Se configura el background
    LayerGradient *bgLayer = LayerGradient::create(ccc4(0, 0, 128, 255), ccc4(0, 0, 0, 255));
    bgLayer->setZOrder(0);
    this->addChild(bgLayer);
    
    return true;
}

/////////////////////////////////////////////////////////
////////// Se crean los botones del arcade //////////////
/////////////////////////////////////////////////////////

void Creditos::createButtons(Size visibleSize)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // set the font for menu with text
    MenuItemFont::setFontSize(20);

    // Boton para volver al menu de inicio
    auto mbVolver = MenuItemFont::create("Atras", CC_CALLBACK_1(Creditos::VolverCallBack, this));
    mbVolver->setAnchorPoint(Vec2(0.0,0.0));
    mbVolver->setPosition(0, 0);
    mbVolver->setColor(Color3B(240, 230, 140));

    // Se crea un boton de salir
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(Creditos::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    auto menu = Menu::create(mbVolver, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);
}


void Creditos::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Creditos::VolverCallBack(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Button.mp3");
    Director::sharedDirector()->replaceScene(PanzerWars::createScene());
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}
