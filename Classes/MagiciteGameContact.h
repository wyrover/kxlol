#ifndef __MAGICITE_GAME_CONTACT__
#define __MAGICITE_GAME_CONTACT__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "MagiciteGamePhysics.h"
#include <map>

class MagiciteGameObject;
class MagiciteGameLiving;
class MagiciteGameMoveAbleLiving;
class MagiciteItem;

namespace MagiciteGameContact
{

    bool is_moveable_on_ground(MagiciteGameMoveAbleLiving* moveObj, MagiciteGameObject* ground);
    /*�ж�moveObj��ground�����Ϸ������·�*/

    bool is_moveable_above_ground(MagiciteGameMoveAbleLiving* moveObj, MagiciteGameObject* ground);
    /*�ж�moveObj��ground�����Ϸ�*/

    void change_moveable_direction(MagiciteGameMoveAbleLiving* moveObj);
    /*�ı������ƶ�����*/

    void try_to_change_living_direction(MagiciteGameLiving* living);
    /*���Ըı������ƶ�����*/

    //bool is_in_types(Contact_type);
    /*�ж��Ƿ�����Contact_type*/

    extern std::map < Magicite::FIXTURE_TYPE, std::map<Magicite::FIXTURE_TYPE, bool>>                                                           judge_contact;
    extern std::map<Magicite::FIXTURE_TYPE, std::map<Magicite::FIXTURE_TYPE, std::function<void(MagiciteGameObject*, MagiciteGameObject*)>>>    on_contact;

    void try_living_contact_with_ground(MagiciteGameObject*, MagiciteGameObject*);
    void try_player_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void try_enemy_contact_with_hole(MagiciteGameObject*, MagiciteGameObject*);
    void try_player_contact_with_pitfall(MagiciteGameObject*, MagiciteGameObject*);
    void try_friend_contact_with_pitfall(MagiciteGameObject*, MagiciteGameObject*);
    void try_friend_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void try_enemy_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void try_player_contact_with_end(MagiciteGameObject*, MagiciteGameObject*);
    void try_ammo_contact_with_enemy(MagiciteGameObject*, MagiciteGameObject*);
    void try_ammo_contact_with_ground(MagiciteGameObject*, MagiciteGameObject*);
    void try_ammo_contact_with_edge(MagiciteGameObject*, MagiciteGameObject*);
    void try_living_contact_with_edge(MagiciteGameObject*, MagiciteGameObject*);
    void try_player_contact_with_item(MagiciteGameObject*, MagiciteGameObject*);
    void try_player_contact_with_protal(MagiciteGameObject*, MagiciteGameObject*);


    extern std::function<void(void)>                       _onWin;
    extern std::function<void(void)>                       _onOver;
    extern std::function<void(MagiciteItem*)>              _onPick;
    extern std::function<bool(b2Contact* contact)>         _onJudgeContact;
    extern std::function<void(b2Contact* contact)>         _onBeginContact;

    void onWin();
    void onOver();

    void resiger_contact();
}

#endif //__MAGICITE_GAME_CONTACT__