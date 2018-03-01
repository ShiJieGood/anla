#include "sxd_client.h"

//============================================================================
// R171
// ��������
// {module:124, action:0,
// request:[], response:[Utils.IntUtil, [Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil, [Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil]], [Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil], [Utils.ShortUtil, Utils.IntUtil]]}
// ChaosEquipmentData.as 35:
//     this._chaosEquipmentInfo.chaos_ling_ye = param1[0];      // ������Һ
//     this._chaosEquipmentInfo.chaosMonsterExt(param1[1]);     // ���ޱ���
//     this._chaosEquipmentInfo.chaosItemExt(param1[2]);        // �鱦����
//     this._chaosEquipmentInfo.chaosScrapInfoExt(param1[3]);   // ����ͼ��
// ChaosEquipmentInfo.as 94:
//     oObject.list(_loc_2, _loc_3, ["player_chaos_monster_id", "item_id", "grid_id", "potential", "break_count_1", "break_count_2", "number", "price", "player_role_id", "eat_count", "three_percent", "four_percent", "item_info"]);
// ChaosEquipmentInfo.as 208:
//     oObject.list(_loc_2, _loc_3, ["player_chaos_item_id", "item_id", "grid_id", "age_level", "number", "price", "player_chaos_monster_id"]);
// ChaosEquipmentInfo.as 993:
//     oObject.list(_loc_2, _loc_3, ["item_id", "number"]);
// Example
//     [ 1605, [ [ 133162, 1824, 3, 1, 0, 0, 1, 0, 0, 0, 0, 0, null ], [ 133163, 1825, 4, 1, 0, 0, 1, 0, 0, 0, 0, 0, null ], [ 112970, 1827, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, null ], [ 112434, 1824, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, null ] ],
//             [ [ 282844, 1842, 1, 600, 1, 0, 0 ] ],
//             [ [ 1854, 93 ], [ 1855, 89 ], [ 1856, 89 ], [ 1857, 47 ], [ 1858, 34 ], [ 1859, 35 ], [ 1860, 29 ], [ 1861, 29 ], [ 1862, 20 ], [ 1863, 3 ], [ 1864, 4 ], [ 1865, 2 ], [ 3697, 0 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ChaosEquipment_Base_get_pack_chaos_monster_list() {
    Json::Value data;
    return this->send_and_receive(data, 124, 0);
}

//============================================================================
// R171
// �ϳ�
// {module:124, action:8,
// request:[Utils.ShortUtil],
// Example
//     [ 1824 ]
// response:[Utils.UByteUtil, [Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil], [Utils.ShortUtil, Utils.IntUtil]]}
// ChaosEquipmentData.as 121:
//     this.makeChaosMonsterResult = param1[0];
//     this._chaosEquipmentInfo.chaosMonsterExt(param1[1]);     // ���ޱ���(����)
//     this._chaosEquipmentInfo.chaosScrapInfoExt(param1[2]);   // ����ͼ��(ˢ��)
// Example
//     [ 0, [ [ 133164, 1824, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0 ] ], [ [ 1854, 83 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ChaosEquipment_Base_make_chaos_monster(int id) {
    Json::Value data;
    data.append(id);
    return this->send_and_receive(data, 124, 8);
}

//============================================================================
// R171
// �ֽ�
// {module:124, action:13,
// request:[Utils.IntUtil],
// Example
//     [ 112434 ]
// response:[Utils.UByteUtil, [Utils.ShortUtil, Utils.IntUtil], [Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil, Utils.ByteUtil, Utils.IntUtil, Utils.IntUtil]]}
// ChaosEquipmentData.as 151:
//     this.playerResolveChaosResult = param1[0];
//     this._chaosEquipmentInfo.chaosScrapInfoExt(param1[1]);   // ����ͼ��(ˢ��)
//     this._chaosEquipmentInfo.chaosMonsterExt(param1[2]);     // ���ޱ���(����)
// Example
//     [ 0, [ [ 1857, 48 ] ], [ [ 112434, 1824, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ChaosEquipment_Base_resolve_player_chaos_monster(int id) {
    Json::Value data;
    data.append(id);
    return this->send_and_receive(data, 124, 13);
}

//============================================================================
// R171
// �������
// {module:123, action:0,
// request:[], response:[Utils.ShortUtil, Utils.IntUtil, Utils.ShortUtil, Utils.StringUtil, Utils.ShortUtil, Utils.IntUtil, Utils.UByteUtil]}
// SpaceFindController.as 20:
//     oObject.list(_loc_2, _loc_1, ["count", "item_id", "golden", "be_app_nickname", "can_buy_count", "integral", "useType"]);
// Example
//     [ 2, 0, 5, "", 20, 0, 0 ]
//============================================================================
Json::Value sxd_client::Mod_SpaceFind_Base_open_space_find() {
    Json::Value data;
    return this->send_and_receive(data, 123, 0);
}

//============================================================================
// R171
// Ѱ������
// {module:123, action:1,
// request:[Utils.UByteUtil],
// Example
//     [ 0 ]
// response:[Utils.UByteUtil, Utils.IntUtil, Utils.ShortUtil, Utils.IntUtil, Utils.UByteUtil]}
// SpaceFindController.as 34:
//     oObject.list(_loc_2, _loc_1, ["result", "item_id", "golden", "integral", "useType"]);
// Example
//     [ 2, 1824, 5, 0, 0 ]
//============================================================================
Json::Value sxd_client::Mod_SpaceFind_Base_do_space_find(int type) {
    Json::Value data;
    data.append(type);
    return this->send_and_receive(data, 123, 1);
}
//============================================================================
// R171
// ץ��
// {module:123, action:2,
// request:[], response:[Utils.UByteUtil, [Utils.IntUtil, Utils.ShortUtil], Utils.ShortUtil, Utils.ShortUtil]}
// SpaceFindController.as 44:
//     oObject.list(_loc_2, _loc_1, ["result", "find_goods", "count", "can_buy_count"]);
// Example
//     [ 2, [ [ 1845, 1 ], [ 1854, 1 ] ], 1, 20 ]
//============================================================================
Json::Value sxd_client::Mod_SpaceFind_Base_get_space_find() {
    Json::Value data;
    return this->send_and_receive(data, 123, 2);
}
