#include <boost/format.hpp>
#include "common.h"
#include "sxd_client.h"

//============================================================================
// R171
// ������
// {module:127, action:1,
// request:[],
// response:[[Utils.ShortUtil, Utils.ShortUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.IntUtil, Utils.ByteUtil]]}
// FunctionEndData.as 56:
//     _loc_4 = GiftType.getEndFunctionGift(_loc_1[_loc_3][0]);
//     GiftType.getEndFunctionGift(_loc_1[_loc_3][0]).giftId = _loc_4.id;
//     _loc_4.iconPath = URI.functionEndUrl + _loc_4.id + ".png";
//     _loc_4.flag = 1;
//     _loc_4.message = "";
//     _loc_4.addMsg = "";
//     _loc_4.state_point = _loc_1[_loc_3][1];       // ����
//     _loc_4.skill = _loc_1[_loc_3][2];             // ����
//     _loc_4.xian_ling = _loc_1[_loc_3][3];         // ����
//     _loc_4.fame = _loc_1[_loc_3][4];              // ����
//     _loc_4.nimbus = _loc_1[_loc_3][5];            // ����
//     _loc_4.coin_buff = _loc_1[_loc_3][6];         // ͭǮ�ӳ�
//     _loc_4.exp_buff = _loc_1[_loc_3][7];          // ����ӳ�
//     _loc_4.ingot = _loc_1[_loc_3][8];             // Ԫ��
//     _loc_4.sortNum = 2000 + _loc_4.sort * 100;    // ����
//     _loc_4.bei = _loc_1[_loc_3][9];               // ����
// Example
//     [ [ [ 13, 0, 0, 0, 0, 0, 0, 0, 0, 10 ], [ 7, 0, 0, 0, 0, 0, 0, 0, 0, 2 ], [ 16, 0, 0, 0, 0, 0, 0, 0, 0, 2 ], [ 1, 0, 0, 0, 0, 0, 0, 0, 0, 2 ], [ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_FunctionEnd_Base_game_function_end_gift() {
    Json::Value data;
    return this->send_and_receive(data, 127, 1);
}

//============================================================================
// R171
// ���
// {module:127, action:3,
// request:[Utils.ShortUtil],
// response:[Utils.ShortUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil]}
// FunctionEndData.as 202:
//     _loc_3.state_point = param1[0];
//     _loc_3.skill = param1[1];
//     _loc_3.xian_ling = param1[2];
//     _loc_3.fame = param1[3];
//     _loc_3.nimbus = param1[4];
//     _loc_3.exp_buff = param1[5];
//     this.randomIngot = param1[6];
//============================================================================
Json::Value sxd_client::Mod_FunctionEnd_Base_random_award(int id) {
    Json::Value data;
    data.append(id);
    return this->send_and_receive(data, 127, 3);
}

//============================================================================
// R171
// ��ȡ
// {module:127, action:2,
// request:[Utils.ShortUtil],
// response:[Utils.UByteUtil, Utils.ShortUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil]}
// FunctionEndData.as 191:
//     this.result = param1[0];
//     this.isHaveNext = param1[8] == 1;
//============================================================================
Json::Value sxd_client::Mod_FunctionEnd_Base_get_game_function_end_gift(int id) {
    Json::Value data;
    data.append(id);
    return this->send_and_receive(data, 127, 2);
}

