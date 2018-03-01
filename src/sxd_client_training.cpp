#include <boost/format.hpp>
#include "common.h"
#include "sxd_client.h"

class Mod_Training_Base {
public:
    static const int GENERAL = 0;       // ��ͨ������xxxͭǮ
    static const int STRENGTHEN = 1;    // ��ǿ������2Ԫ��
    static const int FAVORITEM = 5;     // ϲ��Ʒ������Ů�ʯ��Ƭ��1
    static const int SUCCEED = 6;
    static const int NOENOUGHITEM = 10;
};

void sxd_client::training(const std::string& player_name, int player_id) {
    // config
    std::string config = db.get_config(player_name.c_str(), "Training");
    // roles
    Json::Value data = this->Mod_Role_Base_get_role_list(player_id);
    auto roles = data[14];
    bool find = false;
    for (const auto& role : roles) {
        std::string role_name = common::utf2gbk(role[0].asString());
        int player_role_id = role[2].asInt();
        if (role_name.find(config) != std::string::npos) {
            find = true;
            for (;;) {
                data = this->Mod_Training_Base_training(player_role_id, Mod_Training_Base::FAVORITEM);
                if (data[0].asInt() == Mod_Training_Base::SUCCEED) {
                    this->Mod_Training_Base_modify_role_data(player_role_id);
                    common::log(boost::str(boost::format("��������[%1%] ϲ��Ʒ����������[%2%]������[%3%]������[%4%]") % role_name % data[1] % data[2] % data[3]));
                } else if (data[0].asInt() == Mod_Training_Base::NOENOUGHITEM) {
                    common::log(boost::str(boost::format("��������[%1%] ϲ��Ʒ����ʧ�ܣ�Ů�ʯ��Ƭ��������") % role_name));
                    return;
                } else {
                    common::log(boost::str(boost::format("��������[%1%] ϲ��Ʒ����ʧ�ܣ�result[%2%]") % role_name % data[0]));
                    return;
                }
            }
            break;
        } //if find training_name
    } //for roles
    if (!find)
        common::log(boost::str(boost::format("��������δ���ֻ��[%1%]") % config));
}

//============================================================================
// R171
// ����
// {module:12, action:1,
// request:[Utils.IntUtil, Utils.UByteUtil],
// Example
//     [ 808183, 5 ] 808183��ʾ��������5��ʾϲ��Ʒ����
// response:[Utils.UByteUtil, Utils.IntUtil, Utils.IntUtil, Utils.IntUtil]}
// Example
//     [ 6, 322, 360, 298 ] 6��ʾ�����ɹ�������������������������
//============================================================================
Json::Value sxd_client::Mod_Training_Base_training(int player_role_id, int type) {
    Json::Value data;
    data.append(player_role_id);
    data.append(type);
    return this->send_and_receive(data, 12, 1);
}

//============================================================================
// R171
// ����
// {module:12, action:2,
// request:[Utils.IntUtil],
// Example
//     [ 808183 ]
// response:[Utils.UByteUtil, [Utils.IntUtil, Utils.IntUtil, Utils.IntUtil], Utils.IntUtil]}
// Example
//     [ 6, [ [ 322, 360, 298 ] ], 25 ]
//============================================================================
Json::Value sxd_client::Mod_Training_Base_modify_role_data(int player_role_id) {
    Json::Value data;
    data.append(player_role_id);
    return this->send_and_receive(data, 12, 2);
}
