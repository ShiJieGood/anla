#include "sxd_client.h"

//============================================================================
// R171
// ��������������(town)
// {module:336, action:0,
// request:[], response:[Utils.UByteUtil, [Utils.ByteUtil]]}
// ServerChatRoomData.as 69:
//     this.result = param1[0];
//     this.isOpen = this.result == Mod_ServerChatRoom_Base.SUCCESS;
//     for each (_loc_2 in param1[1])
//         this.recentIds.push(_loc_2[0]);
// Example
//     [ 9, null ]
//     [ 9, [ [ 1 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_get_recent_room_list() {
    Json::Value data;
    return this->send_and_receive(data, 336, 0);
}

//============================================================================
// R171
// ������״̬(town)
// {module:336, action:1,
// request:[], response:[Utils.UByteUtil, [Utils.ByteUtil, Utils.IntUtil, Utils.UByteUtil]]}
// ServerChatRoomData.as 84:
//     this.result = param1[0];
//     this.isOpen = this.result == Mod_ServerChatRoom_Base.SUCCESS;
//     for each (_loc_2 in param1[1])
//         _loc_3.setData(_loc_2[0], _loc_2[1], _loc_2[2]);
// ServerChatRoomRoomInfo.as 27:
//     this.id = param1;
//     this.count = param2;
//     this.status = param3;
// Example
//     [ 9, [ [ 1, 228, 11 ], [ 2, 42, 11 ], [ 8, 31, 11 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_get_chat_room_status() {
    Json::Value data;
    return this->send_and_receive(data, 336, 1);
}

//============================================================================
// R171
// �����ҵ�¼��Ϣ(town)
// {module:336, action:11,
// request:[Utils.ByteUtil],
// View.as 7158:
//     _data.call(Mod_ServerChatRoom_Base.get_chat_room_logincode, this.onGetLoginCodeCallBack, [this._roomToConnect.id]);
// Example
//     [ 1 ] ����Ƶ��1
//     [ 2 ] ���ɶ�һ��
//     [ 8 ] ս������
// response:[Utils.ByteUtil, Utils.StringUtil, Utils.StringUtil, Utils.StringUtil, Utils.IntUtil, Utils.StringUtil, Utils.StringUtil, Utils.IntUtil]}
// ServerChatRoomData.as 203:
//     oObject.list(param1, _loc_2, ["id", "node", "servername", "stagename", "timestamp", "login_code", "ip", "port"]);
// Example
//     [ 1, "s04@8x096.xd.com", "s04", "verycd", 1519388840, "6452aede170151bc81e1ebe73a3f7fdd", "8x127.xd.com", 8340 ]
//     [ 2, "s04@8x096.xd.com", "s04", "verycd", 1519388840, "5998cdcfc3e26cbaf3320ad7a51bd2ad", "8x162.xd.com", 8531 ]
//     [ 8, "s04@8x096.xd.com", "s04", "verycd", 1519388840, "12b4bafe1fb789b73c2a1cbdbcb40b4e", "8x141.xd.com", 8340 ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_get_chat_room_logincode(int id) {
    Json::Value data;
    data.append(id);
    return this->send_and_receive(data, 336, 11);
}

//============================================================================
// R171
// ��¼(chat_room)
// {module:336, action:12,
// request:[Utils.StringUtil, Utils.IntUtil, Utils.StringUtil, Utils.StringUtil, Utils.IntUtil, Utils.StringUtil],
// View.as 7168:
//     _data.call(Mod_ServerChatRoom_Base.login_chat_room, onLoginChatRoomCallBack,
//         [_roomToConnect.node, _ctrl.player.playerId, _roomToConnect.servername, _roomToConnect.stagename, _roomToConnect.timestamp, _roomToConnect.login_code], true, DataBase.SOCKETSERVERCHATROOM);
// Example
//     [ "s04@8x096.xd.com", 355547, "s04", "verycd", 1519380632, "d1b1e9dd3e7153f826f8e169278e66dd" ]
// response:[Utils.UByteUtil, Utils.IntUtil]}
// ServerChatRoomData.as 210:
//     this.result = param1[0];
//     this.playerId = param1[1];
// Example
//     [ 9, 74784 ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_login_chat_room(const std::string& node, int player_id, const std::string& servername, const std::string& stagename, int timestamp, const std::string& login_code) {
    Json::Value data;
    data.append(node);
    data.append(player_id);
    data.append(servername);
    data.append(stagename);
    data.append(timestamp);
    data.append(login_code);
    return this->send_and_receive(data, 336, 12);
}

//============================================================================
// R171
// ��ǲ����(chat_room)
// {module:336, action:40,
// request:[], response:[Utils.IntUtil, Utils.ByteUtil, Utils.UByteUtil, Utils.ByteUtil, Utils.ByteUtil, [Utils.IntUtil, Utils.IntUtil], Utils.UByteUtil, Utils.UByteUtil, Utils.UByteUtil, Utils.IntUtil]}
// ServerChatRoomData.as 548:
//     oObject.list(param1, this.playerPetEscortInfo, ["skill_value", "pet_id", "status", "cur_hungry", "max_hungry", "award_list", "normal_feed_flag", "ingot_feed_flag", "award_flag", "escort_remain_time"]);
// Example
// ��ʼ(status[2]=34, normal_feed_flag[6]=4)
//     [ 0, 62, 34, 0, 2, [ [ 1845, 20 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 4, 4, 4, 0 ]
// �Լ�ιʳ(status[2]=34, normal_feed_flag[6]=5)
//     [ 0, 62, 34, 1, 2, [ [ 5277, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 5, 4, 4, 0 ]
// �����(�ޱ仯)
//     [ 0, 62, 34, 1, 2, [ [ 5277, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 5, 4, 4, 0 ]
// ��ʳ������������ǲ(status[2]=35)
//     [ 0, 62, 35, 2, 2, [ [ 1845, 20 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 5, 5, 4, 0 ]
// ��ǲ��(status[2]=36)
//     [ 0, 62, 36, 2, 2, [ [ 5277, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 4, 4, 4, 7112 ]
// ��ǲ��ɣ�����ȡ����(status[2]=38, award_flag[8]=4)
//     [ 0, 62, 38, 2, 2, [ [ 5277, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 4, 4, 4, 0 ]
// ������ǲ���������(status[2]=38, award_flag[8]=5)
//    [ 40, 62, 38, 2, 2, [ [ 2452, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ], 4, 4, 5, 0 ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_get_player_pet_escort_info() {
    Json::Value data;
    return this->send_and_receive(data, 336, 40);
}

//============================================================================
// R171
// ιʳ(town)
// {module:336, action:42,
// request:[Utils.UByteUtil],
// Example
//     [ 41 ]
// response:[Utils.UByteUtil, Utils.UByteUtil, Utils.ByteUtil, Utils.ByteUtil]}
// ServerChatRoomData.as 593:
//     this.result = param1[0];
//     this.playerPetEscortInfo.status = param1[1];
//     this.playerPetEscortInfo.cur_hungry = param1[2];
//     this.playerPetEscortInfo.normal_feed_flag = Mod_ServerChatRoom_Base.DONE;
// Example
//     [ 9, 34, 1, 2 ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_feed_pet(int type) {
    Json::Value data;
    data.append(type);
    return this->send_and_receive(data, 336, 42);
}

//============================================================================
// R171
// ��ǲ(town)
// {module:336, action:43,
// request:[Utils.UByteUtil],
// Example
//     [ 41 ]
// response:[Utils.UByteUtil, Utils.UByteUtil, Utils.IntUtil, [Utils.IntUtil, Utils.IntUtil]]}
// ServerChatRoomData.as 609:
//     this.result = param1[0];
//     this.playerPetEscortInfo.status = param1[1];
//     this.playerPetEscortInfo.escort_remain_time = param1[2];
//     for each (_loc_3 in param1[3])
//         oObject.list(_loc_3, _loc_4, ["item_id", "count"]);
// Example
//     [ 9, 36, 7200, [ [ 5277, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_escort_pet(int type) {
    Json::Value data;
    data.append(type);
    return this->send_and_receive(data, 336, 43);
}

//============================================================================
// R171
// ����(chat_room)
// {module:336, action:20,
// request:[Utils.StringUtil, Utils.StringUtil, Utils.StringUtil],
// ServerChatRoomView.as 155:
//     _data.call(Mod_ServerChatRoom_Base.chat_with_players, this.onSendMsgCallBack, [param1.message, param1.eipNum, param1.eipIndex], true, DataBase.SOCKETSERVERCHATROOM);
// Example
//     [ "MSG7_74656_\u9ad8\u5343\u5b57.s1_s04", "", "" ]
// response:[Utils.IntUtil, Utils.UByteUtil]}
// ServerChatRoomData.as 347:
//     this.result = param1[1];
// Example
//     [ 0, 9 ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_chat_with_players(const std::string& message, const std::string& eip_num, const std::string& eip_index) {
    Json::Value data;
    data.append(message);
    data.append(eip_num);
    data.append(eip_index);
    return this->send_and_receive(data, 336, 20);
}

//============================================================================
// R171
// ��ȡ(town)
// {module:336, action:44, request:[], response:[Utils.UByteUtil, Utils.IntUtil, [Utils.IntUtil, Utils.IntUtil]]}
// ServerChatRoomData.as 637:
//     oObject.list(param1, this.getPetEscortAwardResult, ["result", "skill_value", "award_list"]);
// Example
//     [ 9, 20, [ [ 2452, 12 ], [ 5359, 1 ], [ 5362, 3 ], [ 4063, 1 ] ] ]
//============================================================================
Json::Value sxd_client::Mod_ServerChatRoom_Base_get_pet_escort_award() {
    Json::Value data;
    return this->send_and_receive(data, 336, 44);
}
