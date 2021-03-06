#ifndef __MAGICITE_GAME_LIVING__
#define __MAGICITE_GAME_LIVING__

#include "cocos2d.h"
#include <map>
#include "MagiciteGameObject.h"
#include "MagiciteEffectBuffer.h"

#define _LIFE_BAR_OFF

class MagiciteEffect;
class MagiciteLifeBar;

class MagiciteGameLiving : public MagiciteGameObject
{
public:
    enum MoveAbleType : int
    {
        MoveAbleLiving,
        NormalLiving,
    }LivingMoveType;

    enum LivingType : int
    {
        Unknow,
        Piranha,
    }NormalLivingType;

    MagiciteGameLiving(
        MoveAbleType movetype = MoveAbleType::NormalLiving, 
        LivingType livingtype = LivingType::Unknow);

    virtual void useSkill(MagiciteEffect* effect);

    virtual bool init();
    virtual bool initWithFile(const char* filename);

    void setHP(int hp);
    int getHP() const;

    void setMP(int mp);
    int getMP() const;

    void attact(int damage = 1);

    std::map<MagiciteEffectBuffer::Buff_Type, bool>         _buff_map;

protected:
    int                                                     _health_point;
    int                                                     _mana_point;
    MagiciteLifeBar*                                        _life_bar;
};

#endif //__MAGICITE_GAME_LIVING__