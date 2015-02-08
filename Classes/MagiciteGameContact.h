#ifndef __MAGICITE_GAME_CONTACT__
#define __MAGICITE_GAME_CONTACT__

#include "cocos2d.h"
#include "MagiciteGameObject.h"
#include "MagiciteGameLiving.h"
#include "MagiciteGamePitfall.h"
#include "MagiciteGameMoveAbleLiving.h"

namespace MagiciteGameContact
{
    bool is_moveable_on_ground(MagiciteGameMoveAbleLiving* moveObj, MagiciteGameObject* ground);
    /*�ж�moveObj��ground�����Ϸ������·�*/

    bool is_moveable_above_ground(MagiciteGameMoveAbleLiving* moveObj, MagiciteGameObject* ground);
    /*�ж�moveObj��ground�����Ϸ�*/

    bool is_all_living(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*�ж�objectA��objectB�Ƿ�ȫ��ΪLiving��*/

    bool is_have_player(MagiciteGameLiving* livingA, MagiciteGameLiving* livingB);
    /*�ж�livingA��livingA��û����ҿ��Ƶ�*/

    MagiciteGameObject* trivialGround(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*��objectA��objectB����ȡTypeΪT_Ground�� ��ȡʧ�ܷ���nullptr*/

    MagiciteGameLiving* trivialEnemy(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*��objectA��objectB����ȡTypeΪT_Living�ң�MoveAbleTypeΪNormalLiving�������ƶ����� 
        �� MoveAbleTypeΪMoveAbleLiving ��_is_contraledΪfalse��û����ҿ��ƣ��� ��ȡʧ�ܷ���nullptr*/

    MagiciteGameMoveAbleLiving* trivialPlayer(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*��objectA��objectB����ȡTypeΪT_Living�ң�MoveAbleTypeΪMoveAbleLiving ��_is_contraledΪtrue������ҿ��ƣ���
        ��ȡʧ�ܷ���nullptr*/
    MagiciteGameMoveAbleLiving* trivialFriend(MagiciteGameObject* objectA, MagiciteGameObject* objectB);

    MagiciteGamePitfall* trivialPitfall(MagiciteGameObject* objectA, MagiciteGameObject* objectB);

    bool calc_player_and_enemy(MagiciteGameMoveAbleLiving* objectA, MagiciteGameLiving* objectB);
    /*����player��enemy���Ϸ� ������򷵻�true */

    void change_moveable_direction(MagiciteGameMoveAbleLiving* moveObj);
    /*��moveObj��ǰ�������÷�*/

    void try_to_change_living_direction(MagiciteGameLiving* living);
    /*���living���ƶ� ���÷�����ǰ������*/

    bool try_moveable_contact_with_ground(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*��ȡ�����ƶ���living��ground �����ȡʧ�ܷ���false �����ȡ�ɹ� ���living��ground�Ϸ� ��living��jump״̬ȡ��
        �������living���·����ж��Ƿ�����ҿ��� ���û�����÷�ǰ������*/

    void try_enemy_contact_with_enemy(MagiciteGameLiving* enemyA, MagiciteGameLiving* enemyB);
    /*�����÷�enemyA��enemyB��ǰ������*/

    bool try_player_contact_with_enemy(MagiciteGameMoveAbleLiving* player, MagiciteGameLiving* enemy);
    /*�ж�player��enemy��ײ ���player��enemy�Ϸ� ��ɱ��enemy ��player������Ծ ������Ϸ����*/

    bool try_player_to_end(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*�ж�player�ߵ�������*/

    bool try_player_to_pitfall(MagiciteGameObject* objectA, MagiciteGameObject* objectB);
    /*�ж�player��������*/

    bool try_friend_to_enemy(MagiciteGameLiving* livingA, MagiciteGameLiving* livingB);
    /*�ж�friend��enemy����ײ*/

    bool try_friend_to_pitfall(MagiciteGameObject* objectA, MagiciteGameObject* objectB);

}

#endif //__MAGICITE_GAME_CONTACT__