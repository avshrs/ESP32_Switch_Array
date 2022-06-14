#include "MCP_config.h"    


void MCP_CONFIG::init()
{
mcp_in_config[0] = {"light_dzienny_wlacznik", "Pokój Dzienny",                  "light", "binary_sensor",   1, 1, 0};
mcp_in_config[1] = {"light_dzieciakow_wlacznik", "Pokój Dzieciaków",            "light", "binary_sensor",   1, 1, 1};
mcp_in_config[2] = {"light_goscinny_wlacznik", "Pokój Gościnny",                "light", "binary_sensor",   1, 1, 2};
mcp_in_config[3] = {"light_sypialnia1_wlacznik", "Sypialnia male",              "light", "binary_sensor",   1, 1, 3};
mcp_in_config[4] = {"light_sypialnia2_wlacznik", "Sypialnia duże",              "light", "binary_sensor",   1, 1, 4};
mcp_in_config[5] = {"light_garderoba_wlacznik", "Garderoba",                    "light", "binary_sensor",   1, 1, 5};
mcp_in_config[6] = {"light_lazienka_pietro_wlacznik", "Łazienka Piętro",        "light", "binary_sensor",   1, 1, 6};
mcp_in_config[7] = {"light_srtych_wlacznik", "Strych",                          "light", "binary_sensor",   1, 1, 7};
mcp_in_config[8] = {"light_korytarz_wlacznik", "Korytarz",                      "light", "binary_sensor",   1, 1, 8};
mcp_in_config[9] = {"light_schody_pietro_wlacznik", "Schody Piętro",            "light", "binary_sensor",   1, 1, 9};
mcp_in_config[10] = {"light_schody_parter_wlacznik", "Schody Parter",           "light", "binary_sensor",   1, 1, 9};
mcp_in_config[11] = {"light_wiatrolap_wlacznik", "Wiatrołap",                   "light", "binary_sensor",   1, 1, 11};
mcp_in_config[12] = {"light_salon_kom1_wlacznik", "Salon Komunikacyjne małe",   "light", "binary_sensor",   1, 1, 12};
mcp_in_config[13] = {"light_salon_kom2_wlacznik", "Salon Komunikacyjne duże",   "light", "binary_sensor",   1, 1, 13};
mcp_in_config[14] = {"light_salon_glowne_wlacznik", "Salon Główne",             "light", "binary_sensor",   1, 1, 14};
mcp_in_config[15] = {"light_salon_wneka_wlacznik", "Salon Wnęka",               "light", "binary_sensor",   1, 1, 15};
mcp_in_config[16] = {"light_lazienka_parter_wlacznik", "Łazienka Parter",       "light", "binary_sensor",   1, 1, 16};
mcp_in_config[17] = {"light_kuchnia_glowne_wlacznik", "Kuchnia Głowne",         "light", "binary_sensor",   1, 1, 17};
mcp_in_config[18] = {"light_kuchnia_szafki_wlacznik", "Kuchnia Pod Szafkami",   "light", "binary_sensor",   1, 1, 18};
mcp_in_config[19] = {"light_kuchnia_okap_wlacznik", "Kuchnia Okap",             "light", "binary_sensor",   1, 1, 19};
mcp_in_config[20] = {"light_spizarnia_wlacznik", "Spirzarnia",                  "light", "binary_sensor",   1, 1, 20};
mcp_in_config[21] = {"light_garaz_swiatlo_wlacznik", "Garaz Przy Bramie",       "light", "binary_sensor",   1, 1, 21};
mcp_in_config[22] = {"light_garaz_kom_wlacznik", "Garaz Przy Kuchni",           "light", "binary_sensor",   1, 1, 22};
mcp_in_config[23] = {"light_kotlownia_wlacznik", "Kotlownia",                   "light", "binary_sensor",   1, 1, 23};
mcp_in_config[24] = {"light_piwnica_wlacznik", "Piwnica 1",                     "light", "binary_sensor",   1, 1, 24};
mcp_in_config[25] = {"none", "none",         "none", "none",   0, 0, 25};
mcp_in_config[26] = {"none", "none",         "none", "none",   0, 0, 26};
mcp_in_config[27] = {"none", "none",         "none", "none",   0, 0, 27};
mcp_in_config[28] = {"none", "none",         "none", "none",   0, 0, 28};
mcp_in_config[29] = {"light_piwnica_wlacznik2", "Piwnica_2",                    "light", "binary_sensor",   1, 1, 25};
mcp_in_config[30] = {"light_zmierzchowka_czujnik2", "Zmierzchowka",             "light", "binary_sensor",   0, 0, 30};
mcp_in_config[31] = {"light_zmierzchowka_czujnik", "Zmierzchowka",              "light", "binary_sensor",   1, 1, 31};
mcp_in_config[32] = {"switch_odkurzacz_centralny", "Odkurzacz Centralny",       "plug",  "binary_sensor",   1, 1, 59};
// mcp_in_config[33] = {"none", "none",         "none", "none",   0, 0, 33};
// mcp_in_config[34] = {"none", "none",         "none", "none",   0, 0, 34};
// mcp_in_config[35] = {"none", "none",         "none", "none",   0, 0, 35};
// mcp_in_config[36] = {"none", "none",         "none", "none",   0, 0, 36};
// mcp_in_config[37] = {"none", "none",         "none", "none",   0, 0, 37};
// mcp_in_config[38] = {"none", "none",         "none", "none",   0, 0, 38};
// mcp_in_config[39] = {"none", "none",         "none", "none",   0, 0, 39};
// mcp_in_config[40] = {"none", "none",         "none", "none",   0, 0, 40};
// mcp_in_config[41] = {"none", "none",         "none", "none",   0, 0, 41};
// mcp_in_config[42] = {"none", "none",         "none", "none",   0, 0, 42};
// mcp_in_config[43] = {"none", "none",         "none", "none",   0, 0, 43};
// mcp_in_config[44] = {"none", "none",         "none", "none",   0, 0, 44};
// mcp_in_config[45] = {"none", "none",         "none", "none",   0, 0, 45};
// mcp_in_config[46] = {"none", "none",         "none", "none",   0, 0, 46};
// mcp_in_config[47] = {"none", "none",         "none", "none",   0, 0, 47};
// mcp_in_config[48] = {"none", "none",         "none", "none",   0, 0, 48};
// mcp_in_config[49] = {"none", "none",         "none", "none",   0, 0, 49};
// mcp_in_config[50] = {"none", "none",         "none", "none",   0, 0, 50};
// mcp_in_config[51] = {"none", "none",         "none", "none",   0, 0, 51};
// mcp_in_config[52] = {"none", "none",         "none", "none",   0, 0, 52};
// mcp_in_config[53] = {"none", "none",         "none", "none",   0, 0, 53};
// mcp_in_config[54] = {"none", "none",         "none", "none",   0, 0, 54};
// mcp_in_config[55] = {"none", "none",         "none", "none",   0, 0, 55};
// mcp_in_config[56] = {"none", "none",         "none", "none",   0, 0, 56};
// mcp_in_config[57] = {"none", "none",         "none", "none",   0, 0, 57};
// mcp_in_config[58] = {"none", "none",         "none", "none",   0, 0, 58};
// mcp_in_config[59] = {"none", "none",         "none", "none",   0, 0, 59};
// mcp_in_config[60] = {"none", "none",         "none", "none",   0, 0, 60};
// mcp_in_config[61] = {"none", "none",         "none", "none",   0, 0, 61};
// mcp_in_config[62] = {"none", "none",         "none", "none",   0, 0, 62};
// mcp_in_config[63] = {"none", "none",         "none", "none",   0, 0, 63};
//                      unique_id,   Human name,     Device_Class,     device_group, initial value, enable, bistable, input can manage
mcp_out_config[0] = {"light_dzienny_mcp", "Pokój Dzienny",          "light",  "light",     0, 1, 0, 1};
mcp_out_config[1] = {"light_dzieciakow_mcp", "Pokój Dzieciaków",    "light",  "light",     0, 1, 0, 1};
mcp_out_config[2] = {"light_goscinny_mcp", "Pokój Gościnny",        "light",  "light",     0, 1, 0, 1};
mcp_out_config[3] = {"light_sypialnia1_mcp", "Sypialnia małe",      "light",  "light",     0, 1, 0, 1};
mcp_out_config[4] = {"light_sypialnia2_mcp", "Sypialnia Duże",      "light",  "light",     0, 1, 0, 1};
mcp_out_config[5] = {"light_garderoba_mcp", "Garderoba",            "light",  "light",     0, 1, 0, 1};
mcp_out_config[6] = {"light_lazienka_pietro_mcp", "Łazienka Piętro","light",  "light",     0, 1, 0, 1};
mcp_out_config[7] = {"light_strych_mcp", "Strych",                  "light",  "light",     0, 1, 0, 1};
mcp_out_config[8] = {"light_korytarz_mcp", "Korytarz",              "light",  "light",     0, 1, 0, 1};
mcp_out_config[9] = {"light_schody_mcp", "Schody",                  "light",  "light",     0, 1, 1, 1};
mcp_out_config[10] = {"none", "none",                               "light",  "light",     0, 1, 0, 1};
mcp_out_config[11] = {"light_wiatrolap_mcp", "Wiatrołap",           "light",  "light",     0, 1, 0, 1};
mcp_out_config[12] = {"light_salon1_kom_mcp", "Salon Kom. Małe",    "light",  "light",     0, 1, 0, 1};
mcp_out_config[13] = {"light_salon2_mcp", "Salon kom. Duże",        "light",  "light",     0, 1, 0, 1};
mcp_out_config[14] = {"light_salon_gl_mcp", "Salon Główne",         "light",  "light",     0, 1, 0, 1};
mcp_out_config[15] = {"light_salon_wneka_mcp", "Salon Wnęka",       "light",  "light",     0, 1, 0, 1};
mcp_out_config[16] = {"light_lazienka_par_mcp", "Łazienka Parter",  "light",  "light",     0, 1, 0, 1};
mcp_out_config[17] = {"light_kuchnia_gl_mcp", "Kuchnia Główne",     "light",  "light",     0, 1, 0, 1};
mcp_out_config[18] = {"light_kuchnia_szafki_mcp", "Kuchnia Szafki", "light",  "light",     0, 1, 0, 1};
mcp_out_config[19] = {"light_kuchnia_okap_mcp", "Kuchnia Okap",     "light",  "light",     0, 1, 0, 1};
mcp_out_config[20] = {"light_spizarnia_mcp", "Spiżarnia",           "light",  "light",     0, 1, 0, 1};
mcp_out_config[21] = {"light_garaz_brama_mcp", "Garaż Przy Bramie", "light",  "light",     0, 1, 0, 1};
mcp_out_config[22] = {"light_garaz_lodowka_mcp", "Garaż Przy Kuchni","light",  "light",     0, 1, 0, 1};
mcp_out_config[23] = {"light_kotlownia_mcp", "Kotłownia",           "light",  "light",     0, 1, 0, 1};
mcp_out_config[24] = {"light_Piwnica_mcp", "Piwnica_1",             "light",  "light",     0, 1, 0, 1};
mcp_out_config[25] = {"light_Piwnica_2_mpc", "Piwnica_2",               "light",  "light",     0, 1, 0, 1};
mcp_out_config[26] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[27] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[28] = {"light_podbitka_tyl2_mcp", "Podbitka Tył dodatkowe",          "light",  "light",      0, 1, 0, 0};
mcp_out_config[29] = {"light_podbitka_przod2_mcp", "Podbitka Przód dodatkowe",      "light",  "light",      0, 1, 0, 0};
mcp_out_config[30] = {"light_podbitka_tyl1_mcp", "Podbitka Tył duże",               "light",  "light",      0, 1, 0, 0};
mcp_out_config[31] = {"light_podbitka_przod1_mcp", "podbitka Przód duże",           "light",  "light",      0, 1, 0, 0};
mcp_out_config[32] = {"outlet_goscinny_we_mcp", "Goscinny Ściana WE",               "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[33] = {"outlet_goscinny_ns_mcp", "Gościnny Ściana NS",               "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[34] = {"outlet_dzieciakow_n_mcp", "Dzieciakow Ściana N",             "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[35] = {"outlet_dzieciakow_ews_mcp", "Dzieciakow Ściana EWS",         "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[36] = {"outlet_dzienny_w_mcp", "Dzienny Ściana W",                   "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[37] = {"outlet_dzienny_s_mcp", "Dzienny Ściana S",                   "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[38] = {"outlet_dzienny_n_mcp", "Dzienny Ściana N",                   "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[39] = {"outlet_sypialnia_ssg_mcp", "Sypialnia Ściana S + Garderoba", "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[40] = {"outlet_sypialnia_wne_mcp", "Sypialnia Ściana WNE",           "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[41] = {"outlet_korytarz_mcp", "Korytarz",                            "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[42] = {"outlet_strych_mcp", "Strych",                                "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[43] = {"outlet_lazienka_parter_mcp", "Lazienka Parter",              "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[44] = {"outlet_lazienka_pietro_pralka_mcp", "Lazienka Pietro Pralka","outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[45] = {"outlet_lazienka_pietro_komin_mcp", "Lazienka Pietro Komin",  "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[46] = {"outlet_spizarnia_mcp", "Spiżarnia",                          "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[47] = {"outlet_kuchnia_przy_wyl_mcp", "Kuchnia Przy Włączinku",      "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[48] = {"outlet_kuchnia_nad_blat_mcp", "Kuchnia Pod Szafkami",        "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[49] = {"outlet_kuchnia_zmywarka_mcp", "Kuchnia Zmywarka",            "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[50] = {"outlet_kuchnia_mikrofala_mcp", "Kuchnia Mikrofala",          "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[51] = {"outlet_kuchnia_piekarnik_mcp", "Kuchnia Piekarnik",          "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[52] = {"outlet_salon_sw_mcp", "Salon SW",                            "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[53] = {"outlet_salon_nw_mcp", "Salon NW",                            "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[54] = {"outlet_salon_tv_mcp", "Salon TV",                            "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[55] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[56] = {"outlet_kuchnia_indukcja_l1_mcp", "Kuchnia Indukcja L1",      "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[57] = {"outlet_kuchnia_indukcja_l2_mcp", "Kuchnia Indukcja L2",      "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[58] = {"outlet_kuchnia_indukcja_l3_mcp", "Kuchnia Indukcja L3",      "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[59] = {"outlet_odkurzacz_centralny_switch", "Odkurzacz Centralny",   "switch", "switch",   0, 1, 0, 1};
mcp_out_config[60] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[61] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[62] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[63] = {"none", "none",        "none", "none",   0, 0, 0, 0};
mcp_out_config[64] = {"outlet_odkurzacz_centralny_zasilanie_switch", "Odkurzacz Centralny ",        "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[65] = {"outlet_zasilanie_switch_poe_garaz_switch", "Switch POE Garaz",               "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[66] = {"outlet_zasilanie_na_zewnatrz_przod_switch", "Zasilanie Na Zewnatrz Przód",   "outlet",  "switch",   0, 1, 0, 0};
mcp_out_config[67] = {"outlet_zasilanie_na_zewnatrz_tyl_switch", "Zasilanie Na Zewnatrz Tył",       "outlet",  "switch",   0, 1, 0, 0};
mcp_out_config[68] = {"outlet_gniazda_garaz_ont_internet_switch", "Garaż zasilanie ONT Internet",   "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[69] = {"outlet_zasilanie_brama_zewnetrza_switch", "Zasilanie Brama Zewnętrzna",      "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[70] = {"outlet_zasilanie_brama_garazowa_switch", "Zasilanie Brama Garażowa",         "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[71] = {"outlet_gniazda_piwnica_1_switch", "Piwnica 1",                               "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[72] = {"outlet_gniazda_piwnica_2_switch", "Piwnica 2",                               "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[73] = {"outlet_gniazda_rozdielnia_garaz_switch", "Rozdzielnia Garaż",                "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[74] = {"outlet_gniazda_garaz_sciana_switch", "Gniazda Na ścianie Garaż",             "outlet",  "switch",   1, 1, 0, 0};
mcp_out_config[75] = {"zraszacz_zawor_glowny_0", "Zraszacz Zawór Główny",                           "switch", "switch",   0, 1, 0, 0};
mcp_out_config[76] = {"zraszacz_sekcja_1", "Kroplownica Zachód",                                    "switch", "switch",   0, 1, 0, 0};
mcp_out_config[77] = {"zraszacz_sekcja_2", "Zraszacz Zachód",                                       "switch", "switch",   0, 1, 0, 0};
mcp_out_config[78] = {"zraszacz_sekcja_3", "Kroplownica Przy Bramce ",                              "switch", "switch",   0, 1, 0, 0};
mcp_out_config[79] = {"zraszacz_sekcja_4", "Zraszacz Wejście ",                                     "switch", "switch",   0, 1, 0, 0};
mcp_out_config[80] = {"zraszacz_sekcja_5", "Kroplownica Połódnie",                                  "switch", "switch",   0, 1, 0, 0};
mcp_out_config[81] = {"zraszacz_sekcja_6", "Zraszacz Połódnie",                                     "switch", "switch",   0, 1, 0, 0};
mcp_out_config[82] = {"zraszacz_sekcja_7", "Kroplownica Ogródek",                                   "switch", "switch",   0, 1, 0, 0};
mcp_out_config[83] = {"zraszacz_sekcja_8", "Zraszacz spare",                                        "switch", "switch",   0, 0, 0, 0};
mcp_out_config[84] = {"bramka_glowna", "Elektrozaczep Bramka Main",                                 "none", "lock",       0, 1, 0, 0};
mcp_out_config[85] = {"bramka_kojec", "Elektrozaczep Kojec na Śmieci",                              "none", "lock",       0, 1, 0, 0};
// mcp_out_config[86] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[87] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[88] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[89] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[90] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[91] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[92] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[93] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[94] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[95] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[96] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[97] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[98] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[99] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[100] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[101] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[102] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[103] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[104] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[105] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[106] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[107] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[108] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[109] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[110] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[111] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[112] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[113] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[114] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[115] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[116] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[117] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[118] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[119] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[120] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[121] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[122] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[123] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[124] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[125] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[126] = {"none", "none",        "none", "none",   0, 0, 0, 0};
// mcp_out_config[127] = {"none", "none",        "none", "none",   0, 0, 0, 0};

}

uint8_t MCP_CONFIG::get_input_len()
{
    return 64;
    // return 16;
}
uint8_t MCP_CONFIG::get_output_len()
{
    return 128;
    // return 16;
}

    
String MCP_CONFIG::get_out_name(uint8_t out)
{
    return mcp_out_config[out].name;
}
String MCP_CONFIG::get_out_unique_id(uint8_t out)     
{
    return mcp_out_config[out].unique_id;
}
String MCP_CONFIG::get_out_dev_class(uint8_t out)     
{
    return mcp_out_config[out].dev_class;
}
String MCP_CONFIG::get_out_dev_group(uint8_t out)     
{
    return mcp_out_config[out].dev_group;
}
bool MCP_CONFIG::get_out_define_state(uint8_t out)
{
    return mcp_out_config[out].define_state;
}
bool MCP_CONFIG::get_out_enabled(uint8_t out)
{
    return mcp_out_config[out].enabled;
}
bool MCP_CONFIG::get_out_bistable(uint8_t out)
{
    return mcp_out_config[out].bistable;
}
bool MCP_CONFIG::get_out_input_rel(uint8_t out)
{
    return mcp_out_config[out].input_related;
}

String MCP_CONFIG::get_in_name(uint8_t in)
{
    return mcp_in_config[in].name;
}
String MCP_CONFIG::get_in_unique_id(uint8_t in)
{
    return mcp_in_config[in].unique_id;
}
String MCP_CONFIG::get_in_dev_class(uint8_t in)
{
    return mcp_in_config[in].dev_class;
}
bool MCP_CONFIG::get_in_enabled(uint8_t in)
{
    return mcp_in_config[in].enabled;
}
bool MCP_CONFIG::get_in_enabledOutputRelated(uint8_t in)
{
    return mcp_in_config[in].enabled_output_related;
}
uint8_t MCP_CONFIG::get_in_output_related(uint8_t in)
{
    return mcp_in_config[in].output_number;
}
