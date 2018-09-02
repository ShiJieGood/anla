#include <boost/regex.hpp>
#include <boost/format.hpp>
#define BOOST_THREAD_PROVIDES_GENERIC_SHARED_MUTEX_ON_WIN
#include <boost/thread.hpp>

#include <winsock2.h>
#include <windows.h>

#include "resource.h"
#include "database.h"
#include "common.h"
#include "sxd_client.h"
#include "sxd_web.h"

#define SB_SETTEXTA (WM_USER+1)
#define SB_SETPARTS (WM_USER+4)
#define STATUSCLASSNAME "msctls_statusbar32"
#define SBARS_SIZEGRIP 0x100

#define g_szClassName "myWindowClass"
#define version "R184"

int iEdit = 0;

void auto_play(sxd_client& sxd_client_town, sxd_client& sxd_client_super_town, sxd_client& sxd_client_saint_area, sxd_client& sxd_client_chat_room, const std::vector<std::string>& function_signs) {

    /*data = sxd_client_town.Mod_Player_Base_get_player_info();
     SendMessage(GetDlgItem(hwnd, IDC_MAIN_STATUS), SB_SETTEXTA, 0, (LPARAM) "������...");
     SendMessage(GetDlgItem(hwnd, IDC_MAIN_STATUS), SB_SETTEXTA, 1, (LPARAM) "���¼");*/

    // gift
    sxd_client_town.item_use();
    sxd_client_town.gift3(); // ��ʯ, ٺ», ����
    sxd_client_town.function_end(); // ������
    sxd_client_town.gift(); // �������
    sxd_client_town.Mod_HeroesWar_Base_get_end_gift(); // ��Ӫս���
    sxd_client_town.Mod_StChallenge_Base_get_end_li_bao(); // �Զ�����ս���
    sxd_client_town.Mod_UnlimitChallenge_Base_get_end_award(); // ������ս����
    sxd_client_town.item_use();

    // lucky shop
    if (!common::common::contain(function_signs, "LuckyShop"))
        common::log("���������ˡ�δ����", 0);
    else {
        sxd_client_town.item_sell();                            // ��Ʒ����
        sxd_client_town.lucky_shop();                            // ��������
        sxd_client_town.black_shop();                            // �����챦
        sxd_client_town.item_reel();                            // ����ϳ�
        sxd_client_town.item_use();                            // ��Ʒʹ��
    }

    // release welfare�����¸���
    sxd_client_town.release_welfare();
    sxd_client_town.item_use();

    // rune
    if (!common::common::contain(function_signs, "Rune"))
        common::log("���в������δ����", 0);
    else {
        sxd_client_town.rune();
    }

    // get peach
    if (!common::common::contain(function_signs, "GetPeach"))
        common::log("��ժ���ҡ�δ����", 0);
    else {
        sxd_client_town.get_peach();
    }

    // farm
    if (!common::common::contain(function_signs, "Farm"))
        common::log("��ҩ԰��δ����", 0);
    else {
        sxd_client_town.harvest();
        if (!common::contain(function_signs, "CoinTree"))
            common::log("��ҩ԰��δ���� [������]", 0);
        else {
            sxd_client_town.plant();
            sxd_client_town.harvest();
        }
    }

    // ����
    if (!common::contain(function_signs, "HaloRole"))
        common::log("��������δ����", 0);
    else {
        // sign in��ǩ��
        sxd_client_town.sign_in();
        // wager shop�����ֳǶķ�
        sxd_client_town.wager_shop();
        // hide treasure map���ر�ͼ
        sxd_client_town.hide_treasure_map();
        // dice messenger������ʹ��
        sxd_client_town.dice_messenger();
        // dunhuang treasure���ػ��ر�
        sxd_client_town.dunhuang_treasure();
    }

    // link fate
    if (!common::contain(function_signs, "LinkFate"))
        common::log("����Ե��δ����", 0);
    else {
        sxd_client_town.link_fate();
    }

    // training
    if (!common::contain(function_signs, "Training"))
        common::log("��������δ����", 0);
    else {
        sxd_client_town.training();
    }

    // chaos equipment
    if (!common::contain(function_signs, "ChaosVoid"))
        common::log("��������ա�δ����", 0);
    else {
        sxd_client_town.space_find();           // �������
        sxd_client_town.chaos_equipment();           // ��������
    }

    // email
    if (!common::contain(function_signs, "Email"))
        common::log("�����䡿δ����", 0);
    else {
        sxd_client_town.email();
    }

    // super sport
    if (!common::contain(function_signs, "SuperSport"))
        common::log("����������δ����", 0);
    else {
        sxd_client_town.super_sport();
    }

    // courtyard pet
    if (!common::contain(function_signs, "CourtyardPet"))
        common::log("�����δ����", 0);
    else {
        sxd_client_town.courtyard_pet();        // ���﷿
        sxd_client_town.courtyard_pet_quest();        // ��������
    }

    // pot world
    if (!common::contain(function_signs, "PotWorld"))
        common::log("�����н硿δ����", 0);
    else {
        sxd_client_town.pot_world();
    }

    // beelzebub trials
    if (!common::contain(function_signs, "BeelzebubTrials"))
        common::log("��ħ��������δ����", 0);
    else {
        sxd_client_town.beelzebub_trials();
    }

    // pet animal
    if (!common::contain(function_signs, "PetAnimal"))
        common::log("��Ҷ��������δ����", 0);
    else {
        sxd_client_town.pet_animal();
    }

    // travel event
    if (!common::contain(function_signs, "TravelEvent"))
        common::log("��������Ե��δ����", 0);
    else {
        sxd_client_town.travel_event();
    }

    // hunt demon
    if (!common::contain(function_signs, "HuntDemon"))
        common::log("��������δ����", 0);
    else {
        sxd_client_town.hunt_demon();
    }

    // awake
    if (!common::contain(function_signs, "Awake"))
        common::log("�����ѡ�δ����", 0);
    else {
        sxd_client_town.awake();
    }

    // bai lian qian kun
    if (!common::contain(function_signs, "BaiLianQianKun"))
        common::log("������Ǭ����δ����", 0);
    else {
        sxd_client_town.bai_lian_qian_kun();
    }

    // five elements laba
    if (!common::contain(function_signs, "FiveElementsLaBa"))
        common::log("���������ǡ�δ����", 0);
    else {
        sxd_client_town.five_elements_laba();
    }

    // roll cake
    if (!common::contain(function_signs, "RollCake"))
        common::log("�����Ǹ��ա�δ����", 0);
    else {
        sxd_client_town.roll_cake();
    }

    // send flower
    if (!common::contain(function_signs, "SendFlower"))
        common::log("���ͻ���δ����", 0);
    else {
        sxd_client_town.send_flower();
    }

    // fate
    if (!common::contain(function_signs, "Fate"))
        common::log("��������δ����", 0);
    else {
        sxd_client_town.fate();
    }

    // find immortal
    if (!common::contain(function_signs, "FindImmortal"))
        common::log("��ϲ���콵��δ����", 0);
    else {
        sxd_client_town.find_immortal();      // ϲ���콵
        sxd_client_town.find_immortal2();      // �帣����
    }

    // rob money
    if (!common::contain(function_signs, "RobMoney"))
        common::log("�����ڡ�δ����", 0);
    else {
        sxd_client_town.rob_money();
    }

    // nine regions���ſ��޽�
    sxd_client_town.nine_regions();

    // nimbus
    if (!common::contain(function_signs, "Nimbus"))
        common::log("��������δ����", 0);
    else {
        //sxd_client_town.nimbus();
    }

    // dance
    if (!common::contain(function_signs, "DanceAction"))
        common::log("��Ⱥ�����衿δ����", 0);
    else {
        sxd_client_town.dance();
    }

    // marry
    if (!common::contain(function_signs, "Marry"))
        common::log("����顿δ����", 0);
    else {
        sxd_client_town.marry();
    }

    // coin mission
    if (!common::contain(function_signs, "CoinMission"))
        common::log("��ͭǮ������δ����", 0);
    else {
        sxd_client_town.coin_mission();
    }

    // hero mission
    if (!common::contain(function_signs, "HeroMissionPractice"))
        common::log("��Ӣ��ɨ����δ����", 0);
    else {
        sxd_client_town.hero_mission();
    }

    // lucky super number�����˴��ƴ
    sxd_client_town.lucky_super_number();

    // sunday fruit����ĩˮ����
    sxd_client_town.sunday_fruit();

    // partner link
    if (!common::contain(function_signs, "PartnerLink"))
        common::log("����Եϵͳ��δ����", 0);
    else {
        sxd_client_town.partner_link();     // Ե�걦��
    }

    // dragonball
    if (!common::contain(function_signs, "Dragonball"))
        common::log("�������Ϲ���δ����", 0);
    else {
        sxd_client_town.dragonball();
    }

    // faction
    if (!common::contain(function_signs, "Faction"))
        common::log("�����ɡ�δ����", 0);
    else {
        std::string faction_name = sxd_client_town.get_faction_name();
        if (faction_name.size() == 0)
            common::log("�����ɡ�δ�������", 0);
        else {
            sxd_client_town.faction_god();              // ���ɼ���
            sxd_client_town.seal_satan();              // ���Ƿ�ħ
            sxd_client_town.faction_roll_cake();              // ���ɼ��Ǹ���
            sxd_client_town.faction_lucky_wheel();              // ����ת��
            sxd_client_town.faction_join_feast();              // ������
            sxd_client_town.faction_approve();              // ���
            sxd_client_town.faction_war();              // ����ս
        }
    }

    // assistant
    if (!common::contain(function_signs, "DailyBox"))
        common::log("����Ծ�ȡ�δ����", 0);
    else {
        sxd_client_town.assistant();
    }

    // fish
    if (!common::contain(function_signs, "Fishing"))
        common::log("�����㡿δ����", 0);
    else {
        sxd_client_town.fish();
    }

    // super town
    try {
        if (sxd_client_super_town.is_login()) {
            // st_union
            if (!common::contain(function_signs, "st_union"))
                common::log("�����ˡ�δ����", 0);
            else {
                std::string st_union_name = sxd_client_super_town.get_st_union_name();
                if (st_union_name.size() == 0)
                    common::log("�����ˡ�δ��������", 0);
                else {
                    common::log(boost::str(boost::format("�����ˡ��������� [%1%]") % st_union_name), 0);
                    sxd_client_super_town.st_union_god_incense();       // ��������
                    sxd_client_super_town.st_union_activity();       // ����֮��
                    sxd_client_super_town.st_union_task();       // ħ����ս
                    sxd_client_super_town.st_union_approve();       // �������
                    sxd_client_super_town.st_union_nimal();       // ��������
                }
            }

            // wish pool
            if (!common::contain(function_signs, "WishPool"))
                common::log("����Ը�ء�δ����", 0);
            else {
                sxd_client_super_town.wish_pool();
            }

            // furniture effect
            if (!common::contain(function_signs, "MarryHome"))
                common::log("����԰��δ����", 0);
            else {
                sxd_client_super_town.furniture_effect();
            }

            // st super sport
            if (!common::contain(function_signs, "st_super_sport"))
                common::log("����ħ������δ����", 0);
            else {
                if (common::contain(function_signs, "Levitate"))
                    common::log("����ħ�����������ѳ�ʥ������Ϊ [ʥ�򾺼���]", 0);
                else {
                    sxd_client_super_town.get_rank_award(&sxd_client_town);     // ��������
                    sxd_client_super_town.get_score_award();     // ��ħ����
                    sxd_client_super_town.point_race(&sxd_client_town);     // ������
                    sxd_client_super_town.war_race(&sxd_client_town);     // ��ħ��ս
                }
            }

            // st arena
            if (!common::contain(function_signs, "StDaoYuanShop"))
                common::log("���ɽ��̵꡿δ����", 0);
            else {
                sxd_client_super_town.st_daoyuan_shop();
            }

            // st big turntable
            if (!common::contain(function_signs, "HaloRole"))
                common::log("��������δ����", 0);
            else {
                sxd_client_super_town.st_big_turntable();           // ���ֳǴ�ת��
            }

            // st altar
            if (!common::contain(function_signs, "StAltar"))
                common::log("���ɽ���̳��δ����", 0);
            else {
                sxd_client_super_town.st_altar();
            }

            // st mine
            if (!common::contain(function_signs, "StMine"))
                common::log("����ɽϵͳ��δ����", 0);
            else {
                sxd_client_super_town.st_mine();
            }

            // st practice room
            if (!common::contain(function_signs, "StPracticeRoom"))
                common::log("���ɽ���������δ����", 0);
            else {
                if (common::contain(function_signs, "Levitate"))
                    common::log("���ɽ��������������ѳ�ʥ������Ϊ [ʥ��������]", 0);
                else {
                    sxd_client_super_town.st_practice_room();
                }
            }

            // st take bible
            if (!common::contain(function_signs, "ServerTakeBible"))
                common::log("���ɽ�ȡ����δ����", 0);
            else {
                if (common::contain(function_signs, "Levitate"))
                    common::log("���ɽ�ȡ���������ѳ�ʥ������Ϊ [ʥ��ȡ��]", 0);
                else {
                    sxd_client_super_town.st_take_bible();                      // ����ȡ��
                    sxd_client_super_town.st_rob_bible(&sxd_client_town);                      // ����ȡ��
                }
            }

            // st arena
            if (!common::contain(function_signs, "StArena"))
                common::log("���ɽ羺������δ����", 0);
            else {
                sxd_client_super_town.st_arena();           // ��ս
                sxd_client_town.exploit_shop();           // �����̵����ڵ�
            }
        }
    } catch (const std::exception& ex) {
        common::log(boost::str(boost::format("���ִ���(super town)��%1%") % ex.what()), iEdit);
    }

    // saint area
    try {
        if (sxd_client_saint_area.is_login()) {
            sxd_client_saint_area.sa_take_bible();                  // ʥ��ȡ��
            sxd_client_saint_area.sa_super_sport();                  // ʥ�򾺼���
        }
    } catch (const std::exception& ex) {
        common::log(boost::str(boost::format("���ִ���(saint area)��%1%") % ex.what()), iEdit);
    }

    // server chat room
    try {
        if (sxd_client_chat_room.is_login()) {
            sxd_client_chat_room.pet_escort(&sxd_client_town);
        }
    } catch (const std::exception& ex) {
        common::log(boost::str(boost::format("���ִ���(server chat room)��%1%") % ex.what()), iEdit);
    }

    // sleep and walk
    common::log("����Ϣ��10����...\r\n", iEdit);
    int x = 200, y = 450;
    for (int i = 0; i < 59; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        if (sxd_client_town.is_login())
            sxd_client_town.town_move_to(x + rand() % 1000, y);
        if (sxd_client_super_town.is_login())
            sxd_client_super_town.st_town_move_to(x + rand() % 1000, y);
        if (sxd_client_chat_room.is_login())
            sxd_client_chat_room.Mod_ServerChatRoom_Base_get_player_pet_escort_info();
    }
}

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {

        // Create Edit Control
        HWND hEdit = CreateWindow ("Edit", "", WS_CHILDWINDOW | WS_VISIBLE | WS_EX_CLIENTEDGE | WS_VSCROLL | WS_TABSTOP | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL, 0, 0, 0, 0, hwnd, (HMENU) IDC_MAIN_EDIT, ((LPCREATESTRUCT) lParam)->hInstance, NULL);
        SendMessage(hEdit, WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(FALSE, 0));
        iEdit = (int) hEdit;

        // Create Status bar
        int statwidths[] = { 100, -1 };
        HWND hStatus = CreateWindowEx(0, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0, hwnd, (HMENU) IDC_MAIN_STATUS, GetModuleHandle(NULL), NULL);
        SendMessage(hStatus, SB_SETPARTS, sizeof(statwidths) / sizeof(int), (LPARAM) statwidths);
        SendMessage(hStatus, SB_SETTEXTA, 0, (LPARAM) "���¼");

        break;
    }
    case WM_SIZE: {
        RECT rect;
        HWND hStatus = GetDlgItem(hwnd, IDC_MAIN_STATUS);
        SendMessage(hStatus, WM_SIZE, 0, 0);
        GetWindowRect(hStatus, &rect);
        int iStatusHeight = rect.bottom - rect.top;
        MoveWindow(GetDlgItem(hwnd, IDC_MAIN_EDIT), 0, 0, LOWORD(lParam), HIWORD(lParam) - iStatusHeight, TRUE);
        break;
    }
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_MAIN_EDIT: {
            switch (HIWORD(wParam)) {
            case EN_MAXTEXT:
                SendMessage(GetDlgItem(hwnd, IDC_MAIN_EDIT), EM_SETSEL, 0, -1);
                SendMessage(GetDlgItem(hwnd, IDC_MAIN_EDIT), WM_CLEAR, 0, 0);
                break;
            }
            break;
        }
        case ID_USER_EXIT:
            PostMessage(hwnd, WM_CLOSE, 0, 0);
            break;
        case ID_USER_LOGIN: {
            EnableMenuItem(GetMenu(hwnd), ID_USER_LOGIN, MF_DISABLED | MF_GRAYED);
            SendMessage(GetDlgItem(hwnd, IDC_MAIN_STATUS), SB_SETTEXTA, 0, (LPARAM) "������...");
            boost::thread t([hwnd]() {
                try {
                    const char* filename = ".\\sxdweb\\sxdweb.tmp";
                    std::remove(filename);
                    if (common::read_file(filename).size()) throw std::runtime_error("δ��ɾ���ļ� [sxdweb.tmp]");

                    // initiation
                    STARTUPINFO si;
                    PROCESS_INFORMATION pi;
                    ZeroMemory( &si, sizeof(si) );
                    si.cb = sizeof(si);
                    ZeroMemory( &pi, sizeof(pi) );

                    // Start the child process.
                    char sxdweb[] = ".\\sxdweb\\sxdweb.exe �������� V587";
                    if (!CreateProcessA( NULL, sxdweb, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) throw std::runtime_error("δ���ҵ����ɵ���¼�� [sxdweb.exe]");

                    // Wait until child process exits.
                    WaitForSingleObject(pi.hProcess, INFINITE);

                    // Close process and thread handles.
                    CloseHandle(pi.hProcess);
                    CloseHandle(pi.hThread);

                    // Open login file
                    std::string user_ini = common::read_file(filename);
                    if (!user_ini.size()) throw std::runtime_error("δ���ҵ��û���¼��Ϣ");

                    boost::smatch match;
                    if (!regex_search(user_ini, match, boost::regex("url=(?<url>.*?)\r\ncode=(?<code>.*?)\r\ntime=(?<time>.*?)\r\nhash=(?<hash>.*?)\r\ntime1=(?<time1>.*?)\r\nhash1=(?<hash1>.*?)\r\n")))
                    throw std::runtime_error("��Ч���û���¼��Ϣ");

                    std::string url(match["url"]);
                    std::string code(match["code"]);
                    std::string time(match["time"]);
                    std::string hash(match["hash"]);
                    std::string time1(match["time1"]);
                    std::string hash1(match["hash1"]);

                    std::ostringstream oss;
                    oss << "Cookie: user=" << code << ";";
                    oss << "_time=" << time << ";_hash=" << hash << ";";
                    oss << "login_time_sxd_xxxxxxxx=" << time1 << ";login_hash_sxd_xxxxxxxx=" << hash1 << "\r\n";
                    std::string cookie = oss.str();

                    // get web page from url and cookie
                    std::string web_page;
                    {
                        if (!boost::regex_search(url, match, boost::regex("http://(.*?)(:\\d*)?/(.*)")))
                        throw std::runtime_error("[url] ƥ�����");
                        std::string host(match[1]);
                        std::string port(match[2]);
                        port = port.size() ? port.substr(1) : "80";
                        sxd_web web;
                        web.connect(host, port);
                        web_page = web.get(url, cookie);
                    }

                    // login town
                    sxd_client sxd_client_town(version, iEdit);
                    sxd_client sxd_client_super_town(version, iEdit);
                    sxd_client sxd_client_saint_area(version, iEdit);
                    sxd_client sxd_client_chat_room(version, iEdit);
                    if (sxd_client_town.login_town(web_page)) throw std::runtime_error("��¼ʧ��");

                    // get player functions
                    std::vector<std::string> function_signs;
                    {
                        Json::Value data = sxd_client_town.Mod_Player_Base_get_player_function();
                        common::log(boost::str(boost::format("����¼������ѿ��� [%1%] ���") % data[0].size()), 0);
                        for (const auto& item : data[0]) {
                            try {
                                std::string function_name = db.get_code(version, "Function", item[0].asInt())["sign"];
                                common::log(boost::str(boost::format("��Function��[%1%(%2%)]") % function_name % item[0]), 0);
                                function_signs.push_back(function_name);
                            } catch (const std::exception& ex) {
                                common::log(boost::str(boost::format("���ִ���(function)��%1%") % ex.what()), iEdit);
                            }
                        }
                    }

                    // super_town
                    if (!common::contain(function_signs, "SuperTown")) common::log("���ɽ硿δ����", 0);
                    else sxd_client_super_town.login_super_town(&sxd_client_town);

                    // saint area
                    if (!common::contain(function_signs, "SaintArea")) common::log("��ʥ��δ����", 0);
                    else sxd_client_saint_area.login_saint_area(&sxd_client_town);

                    // chat room
                    if (!common::contain(function_signs, "ServerChatRoom")) common::log("��ȫ�����졿δ����", 0);
                    else sxd_client_chat_room.login_server_chat(&sxd_client_town);

                    for(;;) {
                        auto_play(sxd_client_town, sxd_client_super_town, sxd_client_saint_area, sxd_client_chat_room, function_signs);
                        ////////////////////////////////////////////
                        //common::log("����¼���˳�\r\n", iEdit);
                        //break;
                        ////////////////////////////////////////////
                    }
                } catch (const std::exception& ex) {
                    common::log(boost::str(boost::format("���ִ���(ID_USER_LOGIN)��%1%") % ex.what()), iEdit);
                }
                EnableMenuItem(GetMenu(hwnd), ID_USER_LOGIN, MF_ENABLED);
                SendMessage(GetDlgItem(hwnd, IDC_MAIN_STATUS), SB_SETTEXTA, 0, (LPARAM) "���¼");
            });
            break;
        }
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    //wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    //wc.lpszMenuName = NULL;
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
    wc.lpszClassName = g_szClassName;
    //wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = (HICON) LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
        MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, g_szClassName, "����", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
