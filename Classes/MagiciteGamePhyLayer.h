#ifndef __MAGICITE_GAME_PHY_LAYER__
#define __MAGICITE_GAME_PHY_LAYER__

#define MAGICITE_DEBUG_OFF

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "GLES-Render.h"
#include "MagiciteGameMoveAbleLiving.h"
#include "MagiciteGamePhysics.h"

class MagiciteGameObject;
class MagiciteGamePhyWorld;

class MagiciteGamePhyLayer : public cocos2d::Layer
{
public:
    MagiciteGamePhyLayer();
    ~MagiciteGamePhyLayer();

    bool initPhysics(cocos2d::Size size);
    void createPhyBody(
        MagiciteGameObject* ptr, 
        bool is_static,
        Magicite::FIXTURE_TYPE type);
    b2Body* createBody(b2BodyDef* bd);
    b2Joint* createJoint(const b2JointDef* def);

    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);
    void update(float timeDelta);

    static MagiciteGamePhyLayer* create(cocos2d::Size size);

    bool Ray_Cast(MagiciteGameMoveAbleLiving* sprite, float length, b2Fixture*& outFix, float& output);

private:
    MagiciteGamePhyWorld*               _world;
    GLESDebugDraw*                      _debugDraw;
};

#endif //__MAGICITE_GAME_PHY_LAYER__