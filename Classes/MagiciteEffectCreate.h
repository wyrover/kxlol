#ifndef __MAGICITE_EFFECT_CREATE__
#define __MAGICITE_EFFECT_CREATE__

#include "MagiciteEffect.h"

class MagiciteGameObject;

class MagiciteEffectCreate : public MagiciteEffect
{
public:

    virtual void positive(MagiciteGameObject* obj)
    {
        ///> ��ָ��λ�ô���һ������
    }
};

#endif //__MAGICITE_EFFECT_CREATE__