#include "MagiciteGameMoveAble.h"

MagiciteGameMoveAble::MagiciteGameMoveAble()
{
    _state[S_Move] = false;
    _state[S_Jump] = false;
    _state[S_Animate] = false;
    _speed = DEFAULT_SPEED;
    _base_speed = DEFAULT_SPEED;
    _jumpHeight = DEFAULT_JUMP_HEIGHT;
    _max_jump_time = DEFAULT_JUMP_TIME;
    _jump_time = 0;
    _is_to_left = false;
    _is_dire_changed = false;
}

void MagiciteGameMoveAble::setJumpHeight(int offset)
{
    _jumpHeight = offset;
}

int MagiciteGameMoveAble::getJumpHeight() const
{
    return _jumpHeight;
}

void MagiciteGameMoveAble::setSpeed(float value)
{
    _speed = value;
}

float MagiciteGameMoveAble::getSpeed() const
{
    return _speed;
}

void MagiciteGameMoveAble::setState(State state, bool x)
{
    _state[state] = x;
}

bool MagiciteGameMoveAble::getState(State state) const
{
    return _state.find(state)->second;
}

MagiciteGameMoveAble::Direction MagiciteGameMoveAble::getDire() const
{
    return _is_to_left ? Direction::left : Direction::right;
}

void MagiciteGameMoveAble::setDire(Direction dire)
{
    if ((dire == Direction::left ? true : false) != _is_to_left)
    {
        _is_dire_changed = true;
        _is_to_left = !_is_to_left;
    }
}

void MagiciteGameMoveAble::setBaseSpeed(float value)
{
    _base_speed = value;
    _speed = value;
}

float MagiciteGameMoveAble::getBaseSpeed() const
{
    return _base_speed;
}

void MagiciteGameMoveAble::Move(Direction dire)
{
    setBodyXSpeed(_speed * dire);
    if (getState(State::S_Move) == false)
        setState(State::S_Move, true);
}

void MagiciteGameMoveAble::Stop()
{
    setState(State::S_Move, false);
    setBodyXSpeed(0);
}

void MagiciteGameMoveAble::Jump()
{
    ++_jump_time;
    setBodyYSpeed(_jumpHeight);
    setState(State::S_Jump, true);
}

void MagiciteGameMoveAble::JumpOver()
{
    setState(State::S_Jump, false);
    _jump_time = 0;
}

void MagiciteGameMoveAble::setBodyXSpeed(float x_speed)
{

}

void MagiciteGameMoveAble::setBodyYSpeed(float y_speed)
{

}
