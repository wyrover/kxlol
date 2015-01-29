#include "MagiciteGamePhyLayer.h"

USING_NS_CC;

MagiciteGamePhyLayer::MagiciteGamePhyLayer()
    :_world(nullptr)
{

}

MagiciteGamePhyLayer::~MagiciteGamePhyLayer()
{
    delete _world;
    delete _debugDraw;
    delete _contactListener;
}

bool MagiciteGamePhyLayer::initPhysics(Size size, MagiciteGamePlayer* player)
{
    if (!Layer::init())
    {
        return false;
    }
    _visibleSize = Director::getInstance()->getVisibleSize();
    this->schedule(schedule_selector(MagiciteGamePhyLayer::update));

    b2Vec2 gravity;
    gravity.Set(0.0f, -10.0f);
    _world = new b2World(gravity);
    _world->SetAllowSleeping(true);
    _world->SetContinuousPhysics(true);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body* body = _world->CreateBody(&groundBodyDef);
    _body = body;
    Size boxSize = Size(size.width, _visibleSize.height);

    b2EdgeShape groundBox;
    groundBox.Set(b2Vec2(0, 0), b2Vec2(boxSize.width / PTM_RATIO, 0));
    body->CreateFixture(&groundBox, 0);
    groundBox.Set(b2Vec2(0, boxSize.height / PTM_RATIO), b2Vec2(boxSize.width / PTM_RATIO, boxSize.height / PTM_RATIO));
    body->CreateFixture(&groundBox, 0);
    groundBox.Set(b2Vec2(0, boxSize.height / PTM_RATIO), b2Vec2(0, 0));
    body->CreateFixture(&groundBox, 0);
    groundBox.Set(b2Vec2(boxSize.width / PTM_RATIO, boxSize.height / PTM_RATIO), b2Vec2(boxSize.width / PTM_RATIO, 0));
    body->CreateFixture(&groundBox, 0);

    _contactListener = MagiciteGameContactListener::create(player);
    _world->SetContactListener(_contactListener);

    _debugDraw = new GLESDebugDraw(PTM_RATIO);
    _world->SetDebugDraw(_debugDraw);
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    _debugDraw->SetFlags(flags);

    return true;
}

void MagiciteGamePhyLayer::addPhysicSprite(MagiciteGamePhySprite* ptr, bool is_static)
{
    b2BodyDef bodyDef;
    bodyDef.type = is_static ? b2_staticBody :b2_dynamicBody;
    bodyDef.position.Set((ptr->getPositionX() + ptr->getContentSize().width / 2) / PTM_RATIO, (ptr->getPositionY() + ptr->getContentSize().height / 2) / PTM_RATIO);
    bodyDef.userData = ptr;
    b2Body* body = _world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(ptr->getContentSize().width / 2 / PTM_RATIO, ptr->getContentSize().height / 2 / PTM_RATIO);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    body->CreateFixture(&fixtureDef);
    ptr->setBody(body);
    this->addChild(ptr);
}

void MagiciteGamePhyLayer::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);
    _world->DrawDebugData();
    CHECK_GL_ERROR_DEBUG();
}

void MagiciteGamePhyLayer::update(float timeDelta)
{
    int velocityIterations = 8;
    int positionIterations = 1;
    _world->Step(0.03f, velocityIterations, positionIterations);
    for (auto it = _world->GetBodyList(); it; it = it->GetNext())
    {
        if (it->GetUserData() != nullptr)
        {
            Sprite* sprite = reinterpret_cast<Sprite*>(it->GetUserData());
            sprite->setPosition(Vec2(it->GetPosition().x * PTM_RATIO, it->GetPosition().y * PTM_RATIO));
            sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(it->GetAngle()));
        }
    }
}

MagiciteGamePhyLayer* MagiciteGamePhyLayer::create(cocos2d::Size size, MagiciteGamePlayer* player)
{
    auto ptr = new MagiciteGamePhyLayer();
    if (ptr && ptr->initPhysics(size, player))
    {
        ptr->autorelease();
        return ptr;
    }
    else
    {
        CC_SAFE_DELETE(ptr);
        return nullptr;
    }
}