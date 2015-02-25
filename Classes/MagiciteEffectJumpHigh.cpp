#include "MagiciteEffectJumpHigh.h"

USING_NS_CC;

MagiciteEffectJumpHigh::MagiciteEffectJumpHigh()
{

}

void MagiciteEffectJumpHigh::positive()
{
    if (_moveable != nullptr)
    {
        auto action = Sequence::create(DelayTime::create(3), CallFunc::create([&]()
        {
            _moveable->setJumpHeight(_moveable->getJumpHeight() / 2);
            _moveable->_buff_map[Jump_High] = false;

            delete this;
        }), nullptr);

        action->setTag(Jump_High);
        if (!_moveable->_buff_map[Jump_High])
        {
            _moveable->setJumpHeight(_moveable->getJumpHeight() * 2);
            _moveable->_buff_map[Jump_High] = true;
        }
        else
        {
            _moveable->stopAllActionsByTag(Jump_High);
        }
        _moveable->runAction(action);
    }
}
//MagiciteEffectValueChange.positive
//timer-negative

void MagiciteEffectJumpHigh::negative()
{

}

MagiciteEffectJumpHigh* MagiciteEffectJumpHigh::create(MagiciteGameMoveAbleLiving* moveable)
{
    auto ptr = new MagiciteEffectJumpHigh();
    if (ptr && ptr->init(moveable))
    {
        return ptr;
    }
    else
    {
        CC_SAFE_DELETE(ptr);
        return nullptr;
    }
}

bool MagiciteEffectJumpHigh::init(MagiciteGameMoveAbleLiving* moveable)
{
    _moveable = moveable;

    return true;
}