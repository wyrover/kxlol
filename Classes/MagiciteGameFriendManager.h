#ifndef __MAGICITE_GAME_FRIEND_MANAGER__
#define __MAGICITE_GAME_FRIEND_MANAGER__

#include "cocos2d.h"
#include "vector"
#include "MagiciteGameHuman.h"
#include "MagiciteGameChicken.h"
#include "MagiciteGameSlime.h"
#include "MagiciteGameSheep.h"

namespace MagiciteGameFriendManager
{
    enum Friend_Type : int
    {
        Human,
        Chicken,
        Slime,
        Sheep,
    };

    MagiciteGameMoveAbleLiving* createFriend(Friend_Type type, bool is_to_left = false);
    void destroyFriend(MagiciteGameMoveAbleLiving* living);
};

#endif //__MAGICITE_GAME_FRIEND_MANAGER__