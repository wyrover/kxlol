#ifndef __MAGICITE_EFFECT_CREATE__
#define __MAGICITE_EFFECT_CREATE__

#include "MagiciteEffect.h"
#include "MagiciteGameObject.h"

class MagiciteEffectCreate : public MagiciteEffect
{
public:
    typedef MagiciteGameObject::_entityCategory Category;

    virtual void positive()
    {
        ///> ��ָ��λ�ô���һ������
    }
};

#endif //__MAGICITE_EFFECT_CREATE__