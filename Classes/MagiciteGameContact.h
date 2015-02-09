#ifndef __MAGICITE_GAME_CONTACT__
#define __MAGICITE_GAME_CONTACT__

#include "cocos2d.h"
#include "MagiciteGameObject.h"
#include "MagiciteGameLiving.h"
#include "MagiciteGamePitfall.h"
#include "MagiciteGameMoveAbleLiving.h"
#include "map"

namespace MagiciteGameContact
{
    enum Contact_type : int
    {
        friend_type,
        player_type,
        enemy_type,
        ground_type,
        pitfall_type,
        end_type,
        unknow_type,
    };

    bool is_moveable_on_ground(MagiciteGameMoveAbleLiving* moveObj, MagiciteGameObject* ground);
    /*�ж�moveObj��ground�����Ϸ������·�*/

    bool is_moveable_above_ground(MagiciteGameMoveAbleLiving* moveObj, MagiciteGameObject* ground);
    /*�ж�moveObj��ground�����Ϸ�*/

    void change_moveable_direction(MagiciteGameMoveAbleLiving* moveObj);
    /*�ı������ƶ�����*/

    void try_to_change_living_direction(MagiciteGameLiving* living);
    /*���Ըı������ƶ�����*/

    bool is_in_types(Contact_type);
    /*�ж��Ƿ�����Contact_type*/

    extern std::map<Contact_type, std::map<Contact_type, std::function<void(MagiciteGameObject*, MagiciteGameObject*)>>> on_contact;

    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_living_contact_with_ground;
    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_player_contact_with_enemy;
    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_player_contact_with_pitfall;
    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_friend_contact_with_pitfall;
    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_friend_contact_with_enemy;
    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_enemy_contact_with_enemy;
    extern std::function<void(MagiciteGameObject*, MagiciteGameObject*)> try_player_contact_with_end;

    void holders(MagiciteGameObject*, MagiciteGameObject*);

    void _try_living_contact_with_ground(MagiciteGameObject*, MagiciteGameObject*);
    void _try_player_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void _try_player_contact_with_pitfall(MagiciteGameObject*, MagiciteGameObject*);
    void _try_friend_contact_with_pitfall(MagiciteGameObject*, MagiciteGameObject*);
    void _try_friend_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void _try_enemy_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void _try_player_contact_with_end(MagiciteGameObject*, MagiciteGameObject*);

    void resiger_contact();

    Contact_type trivial_contact_type(MagiciteGameObject*);
}

#endif //__MAGICITE_GAME_CONTACT__