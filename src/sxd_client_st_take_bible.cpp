#include <boost/format.hpp>
#include "common.h"
#include "sxd_client.h"

class Mod_StTakeBible_Base {
public:
    static const int SUCCESS = 9;
};

// �ο�ʥ��ȡ��
void sxd_client::st_take_bible() {
    std::string protectors[] = { "", "������", "ɳ��", "��˽�", "�����", "��ɮ" };
    // first get
    Json::Value data = this->Mod_StTakeBible_Base_get_take_bible_info();
    Json::Value bible_info = data;
    if (bible_info[2].asInt() == bible_info[3].asInt()) {
        common::log("���ɽ�ȡ��������������");
        return;
    }
    if (bible_info[6].asInt() == 0) {
        data = this->Mod_StTakeBible_Base_refresh();
        if (data[0].asInt() != Mod_StTakeBible_Base::SUCCESS) {
            common::log(boost::str(boost::format("���ɽ�ȡ����ˢ��ȡ��ʹ��ʧ�ܣ�msg[%1%]") % data[0]));
            return;
        }
        common::log(boost::str(boost::format("���ɽ�ȡ����ˢ��ȡ��ʹ�ߣ���� [%1%]") % protectors[data[1].asInt()]));
    }
    // second get
    bible_info = this->Mod_StTakeBible_Base_get_take_bible_info();
    if (bible_info[6].asInt() == 0) {
        common::log(boost::str(boost::format("���ɽ�ȡ���������쳣��can_protection[%1%]") % bible_info[6]));
        return;
    }
    if (bible_info[5].asInt() == 0) {
        data = this->Mod_StTakeBible_Base_start_take_bible();
        if (data[0].asInt() != Mod_StTakeBible_Base::SUCCESS) {
            common::log(boost::str(boost::format("���ɽ�ȡ��������ʧ�ܣ�msg[%1%]") % data[0]));
            return;
        }
        common::log(boost::str(boost::format("���ɽ�ȡ������ʼ���ͣ�ȡ��ʹ�� [%1%]") % protectors[bible_info[6].asInt()]));
    }
}

//============================================================================
// R172 ����ȡ���������
// {module:114, action:2, request:[],
// response:[[Utils.UByteUtil, Utils.ByteUtil, Utils.IntUtil, Utils.ShortUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.IntUtil], [Utils.IntUtil, Utils.StringUtil, Utils.ByteUtil, Utils.ByteUtil, Utils.ByteUtil], Utils.ByteUtil, Utils.ByteUtil, Utils.ShortUtil, Utils.ByteUtil, Utils.UByteUtil, Utils.StringUtil, Utils.ByteUtil, Utils.ByteUtil]};
// �ο�ʥ��ȡ��
//============================================================================
Json::Value sxd_client::Mod_StTakeBible_Base_get_take_bible_info() {
    Json::Value data;
    return this->send_and_receive(data, 114, 2);
}

//============================================================================
// R172 ˢ��ȡ��ʹ��
// {module:114, action:8, request:[],
// response:[Utils.UByteUtil, Utils.UByteUtil, Utils.ShortUtil, Utils.ByteUtil]};
// �ο�ʥ��ȡ��
//============================================================================
Json::Value sxd_client::Mod_StTakeBible_Base_refresh() {
    Json::Value data;
    return this->send_and_receive(data, 114, 8);
}

//============================================================================
// R172 ��ʼ����
// {module:114, action:10, request:[],
// response:[Utils.UByteUtil, Utils.ByteUtil]};
// �ο�ʥ��ȡ��
//============================================================================
Json::Value sxd_client::Mod_StTakeBible_Base_start_take_bible() {
    Json::Value data;
    return this->send_and_receive(data, 114, 10);
}
