#include "MagiciteEffectSpeedUp.h"

USING_NS_CC;

MagiciteEffectSpeedUp::MagiciteEffectSpeedUp(MagiciteGameMoveAbleLiving* moveable)
:_moveable(moveable)
{

}
void MagiciteEffectSpeedUp::positive()
{
    if (_moveable != nullptr)
    {
        _moveable->setSpeed(_moveable->getSpeed() * 2);
        auto action = Sequence::create(DelayTime::create(3), CallFunc::create([&]()
        {
            _moveable->setSpeed(_moveable->getSpeed() / 2);

            delete this;
        }), nullptr);
        _moveable->runAction(action);
        
    }
    //MagiciteEffectValueChange.positive
    //timer-negative

}

void MagiciteEffectSpeedUp::negative()
{
    ///> �������Ҫ��ɶ ����timer��ȡ��Ч��
}

