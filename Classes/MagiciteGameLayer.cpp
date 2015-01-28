#include "MagiciteGameLayer.h"

USING_NS_CC;

bool MagiciteGameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    this->setKeyboardEnabled(true);
    this->schedule(schedule_selector(MagiciteGameLayer::update));

    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();

    _background = MagiciteGameMap::create();
    this->addChild(_background, -1);

    _phyLayer = MagiciteGamePhyLayer::create(Size(_background->getBackSize().width, _visibleSize.height));
    this->addChild(_phyLayer);

    _player = MagiciteGamePhySprite::create("img\\avatar\\1.png");
    _player->setPosition(Vec2(_visibleSize.width / 2 + _origin.x, _visibleSize.height / 2 + _origin.y));
    this->addChild(_player, 1);
    _phyLayer->addPhysicSprite(_player,false);
    this->runAction(Follow::create(_player, Rect(0, 0, _background->getBackSize().width, _visibleSize.height)));

    _move_left = false;
    _move_right = false;

    TMXTiledMap* tiled = TMXTiledMap::create("test.tmx");
    TMXObjectGroup* ground = tiled->getObjectGroup("physics");
    ValueVector VV = ground->getObjects();

    for (auto it = VV.begin(); it != VV.end(); ++it)
    {
        Value obj = *it;
        ValueMap vm = obj.asValueMap();
        if (vm.at("type").asString() == "cube")
        {
            float x = vm.at("x").asFloat();
            float w = vm.at("width").asFloat();
            float h = vm.at("height").asFloat();
            float y = vm.at("y").asFloat();
            auto node = MagiciteGamePhySprite::create();
            node->setPosition(ccp(x, y));
            node->setContentSize(Size(w, h));
            node->setAnchorPoint(Point::ZERO);
            _phyLayer->addPhysicSprite(node,true);
            this->addChild(node);
        }
    }

    return true;
}

void MagiciteGameLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    switch (keyCode)
    {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
        _move_left = true;
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        _move_right = true;
        break;
    default:
        break;
    }
}

void MagiciteGameLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    switch (keyCode)
    {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
        _move_left = false;
        _player->getBody()->SetLinearVelocity(b2Vec2(0, _player->getBody()->GetLinearVelocity().y));
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        _move_right = false;
        _player->getBody()->SetLinearVelocity(b2Vec2(0, _player->getBody()->GetLinearVelocity().y));
        break;
    default:
        break;
    }
}

void MagiciteGameLayer::update(float timeDelta)
{
    b2Vec2 bodyVelocity = _player->getBody()->GetLinearVelocity();
    if (_move_left && !_move_right)
    {
        _player->getBody()->SetLinearVelocity(b2Vec2(-3, bodyVelocity.y));
    }
    else if (!_move_left && _move_right)
    {
        _player->getBody()->SetLinearVelocity(b2Vec2(3, bodyVelocity.y));
    }
}


