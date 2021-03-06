#include "stdafx.h"
#include "LibDG.hpp"
#include "Menu.hpp"
#include "MgsFunction.hpp"
#include "Actor_GameD.hpp"
#include "Psx.hpp"
#include "WinMain.hpp"
#include "LibDG.hpp"
#include "LibGV.hpp"
#include "Script.hpp"
#include "ResourceNameHash.hpp"
#include "Renderer.hpp"
#include "pcx.hpp"

#define MENU_IMPL true

struct MenuPrimBuffer
{
    BYTE* mFreeLocation;
    BYTE* mOt;
    BYTE* mOtEnd;
};

struct MenuMan;
using TMenuUpdateFn = void(CC*)(MenuMan*, int*);

#pragma pack(push)
#pragma pack(1)
struct MenuMan_MenuBars
{
    BYTE field_0_state;
    BYTE field_1_O2_hp;
    short int field_2_bar_x;
    short int field_4_bar_y;
    short int field_6_snake_hp;
    short int field_8;
    short int field_A_k10_decrement;
};
#pragma pack(pop)
MGS_ASSERT_SIZEOF(MenuMan_MenuBars, 0xc);

// TODO: Discover true size of structure/other data
struct MenuMan
{
    Actor mBase;
    MenuPrimBuffer* field_20_prim_buffer;
    ButtonStates* field_24_input;
    BYTE field_28_flags;
    BYTE field_29;
    BYTE field_2A_bSkipUpdateHpBars;
    BYTE field_2B;
    TMenuUpdateFn m7FnPtrs_field_2C[7];
    DR_ENV mDR_ENV_field_48[2];
    DR_ENV DR_ENV_field_C8;
    DWORD field_108;
    DWORD field_10C;
    DWORD field_110;
    DWORD field_114;
    DWORD field_118;
    DWORD field_11C;
    DWORD field_120;
    DWORD field_124;
    DWORD field_128;
    DWORD field_12C;
    DWORD field_130;
    DWORD field_134;
    DWORD field_138;
    DWORD field_13C;
    DWORD field_140;
    DWORD field_144;
    PSX_RECT field_148_rect;
    DR_ENV mDrEnvDst_field_150;
    DR_ENV mDrEnvDst_field_190;
    WORD field_1D0;
    WORD field_1D2;
    BYTE field_1D4;
    BYTE field_1D5;
    WORD field_1D6;
    DWORD field_1D8;
    DWORD field_1DC;
    DWORD field_1E0;
    DWORD field_1E4;
    DWORD field_1E8;
    DWORD field_1EC;
    DWORD field_1F0;
    DWORD field_1F4;
    DWORD field_1F8;
    DWORD field_1FC;
    MenuMan_MenuBars field_200_hp_bars_info;
    WORD field_20C_codec_state;
    WORD field_20E;
    DWORD field_210_size_19F2_q;
    DWORD field_214;
    DWORD field_218;
};
MGS_ASSERT_SIZEOF(MenuMan, 0x21C);


MGS_VAR(1, 0x722788, Texture_Record, gMenuTexture_A0BE_722788, {});
MGS_VAR(1, 0x725FC0, MenuMan, gMenuMan_stru_725FC0, {});

void CC Res_MenuMan_create_459A9A()
{
    Actor_PushBack_40A2AF(1, &gMenuMan_stru_725FC0.mBase, nullptr);
    Actor_Init_40A347(&gMenuMan_stru_725FC0.mBase, nullptr, nullptr, "C:\\mgs\\source\\Menu\\menuman.c");
}
MGS_FUNC_IMPLEX(0x00459A9A, Res_MenuMan_create_459A9A, MENU_IMPL);

MGS_FUNC_NOT_IMPL(0x462A3D, void __cdecl(MenuMan* pMenu, int* ot), Menu_update_helper_462A3D);
MGS_FUNC_NOT_IMPL(0x46B8CA, void __cdecl(char *pFileName), Menu_create_helper_item_file_46B8CA);

template<class T>
inline static T* PrimAlloc(MenuPrimBuffer* pPrimBuffer)
{
    T* pT = reinterpret_cast<T*>(pPrimBuffer->mFreeLocation);
    pPrimBuffer->mFreeLocation += sizeof(T);
    return pT;
}

TILE* CC Menu_render_rect_46B79F(MenuPrimBuffer* pPrimBuffer, __int16 x, __int16 y, __int16 w, __int16 h, int rgb)
{
    TILE* pTile = PrimAlloc<TILE>(pPrimBuffer);

    setTile(pTile);
    setRGB0(pTile, BYTE0(rgb), BYTE1(rgb), BYTE2(rgb));

    pTile->x0 = x;
    pTile->y0 = y;
    pTile->w = w;
    pTile->h = h;
    
   
    addPrim(pPrimBuffer->mOt, pTile);

    return pTile;
}
MGS_FUNC_IMPLEX(0x0046B79F, Menu_render_rect_46B79F, MENU_IMPL);

struct BarConfig
{
    const char* mText;
    BYTE mLeftRGB[3];
    BYTE mRightRGB[3];
    WORD mBarHeight;
};
MGS_ASSERT_SIZEOF(BarConfig, 0xC);

MGS_ARY(1, 0x733868, DWORD, 16, dword_733868, {});
MGS_ARY(1, 0x7338A8, DWORD, 16, dword_7338A8, {});

void CC sub_462E8D()
{
    int idx = 0;
    do
    {
        dword_733868[idx] = 0;
        dword_7338A8[idx] = 0;
        idx += 2; // TODO: Why are some elements skipped?
    } while (idx < 16);
}
MGS_FUNC_IMPLEX(0x00462E8D, sub_462E8D, MENU_IMPL);

MGS_VAR(1, 0x7265E0, MenuPrimBuffer, gMenuPrimBuffer_7265E0, {});
MGS_ARY(1, 0x7269F4, BYTE, 8192, gMenuPrimArray1_7269F4, {});
MGS_ARY(1, 0x7289F4, BYTE, 8192, gMenuPrimArray2_7289F4, {});
MGS_ARY(1, 0x7265EC, BYTE*, 2, gMenuPrimBufferArrays_7265EC, {});

MGS_FUNC_NOT_IMPL(0x463763, void __cdecl(MenuMan*, int*), Menu_codec_update_463763);


MGS_FUNC_NOT_IMPL(0x465B38, void __cdecl(), Menu_init_radar_helper_465B38);
MGS_FUNC_NOT_IMPL(0x465A01, void* __cdecl(int), sub_465A01);



MGS_VAR(1, 0x733950, DWORD, gFn_radar_dword_733950, 0);


MGS_FUNC_NOT_IMPL(0x468264, void __cdecl(MenuMan *pMenu, int buffer), Menu_radar_helper_468264);
MGS_FUNC_NOT_IMPL(0x465B4F, DWORD* __cdecl (MenuMan *pMenu, int *a2), Menu_radar_update_helper_465B4F);

void CC Menu_radar_update_468158(MenuMan* pMenu, int* ot)
{
    if (pMenu->field_1D4)
    {
        int field_1D2 = 0;
        if (!pMenu->field_2A_bSkipUpdateHpBars)
        {
            if (game_state_dword_72279C.flags & 0x200000)
            {
                field_1D2 = pMenu->field_1D2 - 16;
                if (field_1D2 <= -64)
                {
                    field_1D2 = -64;
                    game_state_dword_72279C.flags |= 0x400000u;
                    game_state_dword_72279C.flags &= 0xFFDFFFFF;
                }
            }
            else if (game_state_dword_72279C.flags & 0x100000)
            {
                field_1D2 = pMenu->field_1D2 + 16;
                game_state_dword_72279C.flags &= 0xFFBFFFFF;
                if (field_1D2 >= 0)
                {
                    field_1D2 = 0;
                    game_state_dword_72279C.flags &= 0xFFEFFFFF;
                }
            }
            else
            {
                field_1D2 = 0;
            }

            if (game_state_dword_72279C.flags & 0x400800)
            {
                pMenu->field_1D2 = static_cast<WORD>(-64);
            }
            else
            {
                pMenu->field_1D2 = static_cast<WORD>(field_1D2);
                Menu_radar_helper_468264(pMenu, gActiveBuffer_dword_791A08);
                Menu_radar_update_helper_465B4F(pMenu, ot);
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x00468158, Menu_radar_update_468158, MENU_IMPL);

void CC Menu_init_radar_468358(MenuMan* pMenu)
{
    pMenu->m7FnPtrs_field_2C[3] = Menu_radar_update_468158;
    pMenu->field_28_flags |= 8;
    pMenu->field_1D4 = 1;
    pMenu->field_1D0 = 0;
    pMenu->field_1D2 = 0;
    Menu_radar_helper_468264(pMenu, 0);
    Menu_radar_helper_468264(pMenu, 1);
    memcpy(&pMenu->mDrEnvDst_field_150, &pMenu->mDR_ENV_field_48[0], sizeof(pMenu->mDrEnvDst_field_150));
    memcpy(&pMenu->mDrEnvDst_field_190, &pMenu->mDR_ENV_field_48[1], sizeof(pMenu->mDrEnvDst_field_190));
    Menu_init_radar_helper_465B38();
    gFn_radar_dword_733950 = 0;
    sub_465A01(4096);
}
MGS_FUNC_IMPLEX(0x00468358, Menu_init_radar_468358, MENU_IMPL);

void CC Menu_init_codec_463746(MenuMan* pMenu)
{
    pMenu->m7FnPtrs_field_2C[4] = Menu_codec_update_463763.Ptr();
    pMenu->field_28_flags |= 0x10u;
}
MGS_FUNC_IMPLEX(0x00463746, Menu_init_codec_463746, MENU_IMPL);

using TMenuFn = void(CC*)(MenuMan*);

struct MenuMan_Inventory_14h_Unk
{
    BYTE* field_0_pixels;
    WORD* field_4_word_ptr_pixels;
    BYTE field_8_index;
    BYTE field_9_x;
    BYTE field_A_y;
    BYTE field_B;
    DWORD field_C_colour;
    WORD field_10_w;
    WORD field_12_h;
};
MGS_ASSERT_SIZEOF(MenuMan_Inventory_14h_Unk, 0x14);

MGS_FUNC_NOT_IMPL(0x46B92E, void __cdecl(MenuMan_Inventory_14h_Unk* pMenuUnk, int width, int height), Menu_get_item_file_item_46B92E);

MGS_VAR(1, 0x733978, SPRT, gMenu_sprt3_733978, {});

static void InitLargeFontTemplateSprite()
{
    setSprt(&gMenu_sprt3_733978);
    setRGB0(&gMenu_sprt3_733978, 0x80, 0x80, 0x80);
    gMenu_sprt3_733978.u0 = 0;
    gMenu_sprt3_733978.v0 = 242;
    gMenu_sprt3_733978.w = 8;
    gMenu_sprt3_733978.h = 6;
    gMenu_sprt3_733978.clut = 32765;
}

void CC Menu_init_num_res_font_helper_468A04()
{
    static PSX_RECT local_static_stru_6757E0 = { 960, 498, 0, 0 };

    MenuMan_Inventory_14h_Unk menu_unk = {};
    Menu_get_item_file_item_46B92E(&menu_unk, 45, 44);
    local_static_stru_6757E0.x2 = menu_unk.field_10_w / 4;
    local_static_stru_6757E0.y2 = menu_unk.field_12_h;
    g_Render_sub_41C640_ret_650D1A = Render_sub_41C640(
        &local_static_stru_6757E0,
        menu_unk.field_4_word_ptr_pixels,
        menu_unk.field_0_pixels,
        0,
        0,
        0,
        0);

    Render_sub_41C6B0(&local_static_stru_6757E0, menu_unk.field_0_pixels);

    InitLargeFontTemplateSprite();
}
MGS_FUNC_IMPLEX(0x00468A04, Menu_init_num_res_font_helper_468A04, MENU_IMPL);

struct Psx_Tim_Header
{
    DWORD field_0_magic;
    DWORD field_4_type;
    DWORD field_8_offset_to_image_data;
    WORD field_C_pal_xorg;
    WORD field_E_pal_yorg;
    WORD field_10_num_pal_colours;
    WORD field_12_num_pals;
};
MGS_ASSERT_SIZEOF(Psx_Tim_Header, 0x14);

MGS_VAR(1, 0x733960, SPRT, gMenu_sprt2_733960, {});
MGS_VAR(1, 0x7339C0, SPRT, gMenu_font1_template_sprite_7339C0, {});

static void InitSmallFontTemplateSprite()
{
    // TODO: SetSprt
    gMenu_sprt2_733960.tag = gMenu_sprt2_733960.tag & 0xFFFFFF | 0x4000000;
    gMenu_sprt2_733960.code = 0x64;

    // TODO: SetRGB0
    gMenu_sprt2_733960.r0 = 128;
    gMenu_sprt2_733960.g0 = 128;
    gMenu_sprt2_733960.b0 = 128;

    gMenu_sprt2_733960.u0 = 0;
    gMenu_sprt2_733960.v0 = 237;
    gMenu_sprt2_733960.w = 6;
    gMenu_sprt2_733960.h = 5;
    gMenu_sprt2_733960.clut = 32764;
}

void CC Menu_init_num_res_font_468406(MenuMan* /*pMenu*/)
{
    PSX_RECT rect;
    rect.x1 = 960;
    rect.y1 = 488;
    rect.x2 = 64;
    rect.y2 = 10;

    Psx_Tim_Header* pFileData = (Psx_Tim_Header *)LibGV_FindFile_40A603(HashFileName_40A5A2("num", 'r')); // num.res
    const unsigned int imageDataOffset = (unsigned int)pFileData->field_8_offset_to_image_data >> 1;
    BYTE* pImageHeader = (BYTE *)&pFileData[1] + 2 * imageDataOffset;
    WORD* pPalStart = (WORD*)&pFileData[1].field_0_magic;
    *pPalStart = 0;       // set first palt pixel to black?
    
    g_Render_sub_41C640_ret_650D1A = Render_sub_41C640(&rect, (WORD *)&pFileData[1], pImageHeader, 0, 0, 0, 0);
    Render_sub_41C6B0(&rect, pImageHeader);

    gMenu_font1_template_sprite_7339C0.tag = gMenu_font1_template_sprite_7339C0.tag & 0xFFFFFF | 0x4000000;
    gMenu_font1_template_sprite_7339C0.code = 0x64; // setSprt
    gMenu_font1_template_sprite_7339C0.r0 = 128;
    gMenu_font1_template_sprite_7339C0.g0 = 128;
    gMenu_font1_template_sprite_7339C0.b0 = 128;
    gMenu_font1_template_sprite_7339C0.u0 = 156;
    gMenu_font1_template_sprite_7339C0.v0 = 232;
    gMenu_font1_template_sprite_7339C0.w = 6;
    gMenu_font1_template_sprite_7339C0.h = 7;
    gMenu_font1_template_sprite_7339C0.clut = 32764;

    InitSmallFontTemplateSprite();


    Menu_init_num_res_font_helper_468A04();
}
MGS_FUNC_IMPLEX(0x00468406, Menu_init_num_res_font_468406, MENU_IMPL);


MGS_FUNC_NOT_IMPL(0x46AD91, void __cdecl(MenuMan*), Menu_init_fn0_46AD91);
MGS_FUNC_NOT_IMPL(0x469E77, void __cdecl(MenuMan*), Menu_init_inventory_left_469E77);
MGS_FUNC_NOT_IMPL(0x4694E4, void __cdecl(MenuMan*), Menu_init_inventory_right_4694E4);
MGS_FUNC_NOT_IMPL(0x462CFC, void __cdecl(MenuMan*), Menu_init_fn7_jimaku_font_buffer_size_sub_462CFC);

struct TextConfig
{
    DWORD gTextX_dword_66C4C0;
    DWORD gTextY_dword_66C4C4;
    DWORD gTextFlags_dword_66C4C8;
    DWORD gTextRGB_dword_66C4CC;
};
MGS_ASSERT_SIZEOF(TextConfig, 0x10);

template<class T>
static inline T UnSetPointerFlag(T ptr, bool& bWasFlagged)
{
    bWasFlagged = (reinterpret_cast<unsigned int>(ptr) & 0x40000000) ? true : false;
    return reinterpret_cast<T>(reinterpret_cast<unsigned int>(ptr) & 0xBFFFFFFF);
}

MGS_VAR(1, 0x66C4C0, TextConfig, gTextConfig_66C4C0, {});

struct SpecialChar
{
    char field_0_char;
    BYTE field_1_width;
};
MGS_ASSERT_SIZEOF(SpecialChar, 0x2);

/*
0x006757C0  2e 02 40 02 3a 02 5f 04 21 02 3f 06 2b 06 2d 06 2f 06 2a 06  ..@.:._.!.?.+.-./.*.
0x006757D4  7b 03 7d 03 00 00 00 00 00 00 00 00 c0 03 f2 01 36 00 0c 00  {.}.........�.�.6...
*/
/*
SpecialChar gSpecialChars_byte_6757C0[16] =
{
  { '.', 2 },
  { '@', 2 },
  { ':', 2 },
  { '_', 4 },
  { '!', 2 },
  { '?', 6 },
  { '+', 6 },
  { '-', 6 },
  { '/', 6 },
  { '*', 6 },
  { '{', 3 },
  { '}', 3 },
  { '\0', 0 },
  { '\0', 0 },
  { '\0', 0 },
  { '\0', 0 }
};
*/
MGS_ARY(1, 0x6757C0, SpecialChar, 16, gSpecialChars_byte_6757C0, {}); // TODO: Populate

int CC Render_Text_SetGlyphPositions_4687E8(SPRT* pFirstSprt, SPRT* pLastSprt, int updated_x, int xpos, DWORD flags)
{
    int result = updated_x;
    if (pFirstSprt && pFirstSprt < pLastSprt)
    {
        // Align all of the sprites for each number according to the alignment flags
        int adjustValue = 0;
        if ((flags & 0xF) == 1)
        {
            // Right aligned
            adjustValue = updated_x - xpos;
            result = updated_x - xpos;
        }
        else if ((flags & 0xF) == 2)
        {
            // Center aligned
            adjustValue = updated_x - xpos / 2;
            result = xpos;
        }
        else
        {
            // Left aligned
            adjustValue = updated_x;
            result = updated_x + xpos;
        }

        while(pFirstSprt < pLastSprt)
        {
            pFirstSprt->x0 += static_cast<short>(adjustValue);
            pFirstSprt++;
        }
    }

    return result;
}
MGS_FUNC_IMPLEX(0x4687E8, Render_Text_SetGlyphPositions_4687E8, MENU_IMPL);


const int kFontLineHeight = 8;

struct CharToFontAtlasIndex
{
    char mChar;
    char mIdx;
};

// TODO: Can't be used.. special table works in another way ?
const CharToFontAtlasIndex kFontCharMappings[] =
{
    { ':', 12 },  { '!', 14 }, { '?', 15 }, 
    { '+', 16 },  { '-', 17 }, { '/', 18 },
    { '*', 19 },  { '{', 20 }, { '}', 21 }
};

const char kFontSpacedChars[] = ".!:iI";

// 0-9 =      idx*6, 232 | idx*8, 248, h = 5
// a-z, A-Z = idx*6, 237 | idx*8, 242, h = 6
struct FontSettings
{
    BYTE mCharWidth;
    BYTE m0to9V;
    BYTE mAtoZV;
};

const FontSettings kFontSettings[] =
{
    { 8, 248, 242 }, // Large font
    { 6, 232, 237 }  // Small font
};

static void RenderTextHelper(MenuPrimBuffer* pPrimBuffer, TextConfig* pTextSettings, const char* pString, const FontSettings& fontSettings, const SPRT& templateSprite)
{
    if (!*pString)
    {
        return;
    }

    SPRT* firstSprt = nullptr;
    short xpos = 0;
    const char* iterChar = pString;
    while (*iterChar)
    {
        while (*iterChar == '\n')
        {
            Render_Text_SetGlyphPositions_4687E8(
                firstSprt,
                (SPRT *)pPrimBuffer->mFreeLocation,
                pTextSettings->gTextX_dword_66C4C0,
                xpos,
                pTextSettings->gTextFlags_dword_66C4C8);

            // Start again on the left
            xpos = 0;

            // Move future text down 1 line height
            pTextSettings->gTextY_dword_66C4C4 += kFontLineHeight;

            // Reset the "from" sprite for when we fix up the next line
            firstSprt = (SPRT *)pPrimBuffer->mFreeLocation;
            iterChar++;
            if (!*iterChar)
            {
                break;
            }
        }

        short advanceXBy =  fontSettings.mCharWidth + 1;
        BYTE char_u0 = 0;
        BYTE char_v0 = 0;
        bool valid = true;

        const char curChar = (*iterChar) | 0x20; // 0x20 is used to disable @ and some others?
        if (curChar >= '0' && curChar <= '9')
        {
            // 0-9 handling
            advanceXBy = fontSettings.mCharWidth + 1;
            char_u0 = fontSettings.mCharWidth * (curChar - '0');
            char_v0 = fontSettings.m0to9V;
        }
        else
        {
            if ((curChar >= 'a' && curChar <= 'z') || (curChar >= 'A' && curChar <= 'Z'))
            {
                if (curChar == 'i')
                {
                    xpos++;
                    advanceXBy = fontSettings.mCharWidth / 2;
                }
                char_u0 = fontSettings.mCharWidth * (toupper(curChar) - 'A');
                char_v0 = fontSettings.mAtoZV;
            }
            else
            {
                if (curChar == '#')
                {
                    if (fontSettings.mCharWidth != 8)
                    {
                        advanceXBy = fontSettings.mCharWidth;
                    }
                    else
                    {
                        iterChar++;
                        xpos += (*iterChar) - '0';
                        iterChar++;
                        char_u0 = fontSettings.mCharWidth * (*iterChar - '0');
                        char_v0 = fontSettings.m0to9V;
                    }
                }
                else if (curChar == ' ')
                {
                    advanceXBy = fontSettings.mCharWidth / 2;
                    valid = false;
                }
                else
                {
                    // Look up curChar in gSpecialChars_byte_6757C0
                    bool found = false;
                    for (int i = 0; i < 16; i++)
                    {
                        if (gSpecialChars_byte_6757C0[i].field_0_char == curChar)
                        {
                            found = true;

                            BYTE base = 80;
                            if (fontSettings.mCharWidth != 8)
                            {
                                base = 60;
                            }
                            char_u0 = static_cast<BYTE>((fontSettings.mCharWidth  * i) + base);
                            //char_u0 = fontSettings.mCharWidth * (curChar - '0');
                            char_v0 = fontSettings.m0to9V;

                            advanceXBy = gSpecialChars_byte_6757C0[i].field_1_width;
                            if (advanceXBy < 3)
                            {
                                ++xpos;
                                ++advanceXBy;
                                break;
                            }

                            if (advanceXBy != 6)
                            {
                                break;
                            }

                            advanceXBy = fontSettings.mCharWidth + 1;
                            break;
                        }
                    }

                    valid = found;
                    if (!valid)
                    {
                        // If we are not rendering a char then don't advance x pos
                        advanceXBy = 0;
                    }
                }
            }
        }

        if (valid)
        {
            SPRT* pTextSprt = PrimAlloc<SPRT>(pPrimBuffer);
            if (!firstSprt)
            {
                firstSprt = pTextSprt;
            }

            memcpy(pTextSprt, &templateSprite, sizeof(SPRT));

            setRGB0(pTextSprt,
                BYTE0(pTextSettings->gTextRGB_dword_66C4CC),
                BYTE1(pTextSettings->gTextRGB_dword_66C4CC),
                BYTE2(pTextSettings->gTextRGB_dword_66C4CC));

            pTextSprt->x0 = xpos;
            pTextSprt->y0 = static_cast<short>(pTextSettings->gTextY_dword_66C4C4);

            pTextSprt->v0 = char_v0;
            pTextSprt->u0 = char_u0;
            addPrim(pPrimBuffer->mOt, pTextSprt);
        }

        xpos += advanceXBy;
        iterChar++;
    }

    // Position the final line/batch
    Render_Text_SetGlyphPositions_4687E8(
        firstSprt,
        (SPRT *)pPrimBuffer->mFreeLocation,
        pTextSettings->gTextX_dword_66C4C0,
        xpos,
        pTextSettings->gTextFlags_dword_66C4C8);
}


void CC Render_Text_Large_font_468AAF(MenuPrimBuffer* pPrimBuffer, TextConfig* pTextSettings, const char* pString)
{
    RenderTextHelper(pPrimBuffer, pTextSettings, pString, kFontSettings[0], gMenu_sprt3_733978);
}
MGS_FUNC_IMPLEX(0x468AAF, Render_Text_Large_font_468AAF, true);

void CC Render_Text_Small_font_468642(MenuPrimBuffer* pPrimBuffer, TextConfig* pTextSettings, const char* pString)
{
    RenderTextHelper(pPrimBuffer, pTextSettings, pString, kFontSettings[1], gMenu_sprt2_733960);
}
MGS_FUNC_IMPLEX(0x468642, Render_Text_Small_font_468642, false); // TODO: Bugged

int CC TextSetRGB_459B27(int r, int g, int b)
{
    MGS_FORCE_ENOUGH_SPACE_FOR_A_DETOUR;
    return 0;
}
MGS_FUNC_IMPLEX(0x459B27, TextSetRGB_459B27, false);  // TODO

void CC Menu_DrawText_459B63(const char* pFormatStr, int formatArg1, int formatArg2, int formatArg3, int formatArg4)
{
    char formattedStr[64] = {};
    if (gMenuPrimBuffer_7265E0.mFreeLocation)
    {
        sprintf(formattedStr, pFormatStr, formatArg1, formatArg2, formatArg3, formatArg4);
        // Check there is enough space in the buffer for a SPRT per char, plus 2 extra
        if (gMenuPrimBuffer_7265E0.mOtEnd - gMenuPrimBuffer_7265E0.mFreeLocation >=
            static_cast<signed int>(sizeof(SPRT) * (strlen(formattedStr) + 2)))
        {
            if (gTextConfig_66C4C0.gTextFlags_dword_66C4C8 & 0x10)
            {
                Render_Text_Large_font_468AAF(&gMenuPrimBuffer_7265E0, &gTextConfig_66C4C0, formattedStr);
            }
            else
            {
                Render_Text_Small_font_468642(&gMenuPrimBuffer_7265E0, &gTextConfig_66C4C0, formattedStr);
            }
            Menu_Set_Text_BlendMode_459BE0();
        }
    }
}
MGS_FUNC_IMPLEX(0x459B63, Menu_DrawText_459B63, MENU_IMPL);

void CC Menu_render_life_bar_468DA6(MenuPrimBuffer* pPrimBuffer, short int xpos, short int ypos, short int redFillLength, short int normalFillLength, short int barLength, BarConfig* pMaybeFlaggedBarConfig)
{
    if (!(game_state_dword_72279C.flags & 0x80020400))
    {
        bool bDrawTextRed = false;
        BarConfig* pBarConfig = UnSetPointerFlag(pMaybeFlaggedBarConfig, bDrawTextRed);

        const short int barHeight = 5 - pBarConfig->mBarHeight;
        const short int scaledBarWidth = (barLength << 7) / 1024;

        TextConfig textConfig = {};
        textConfig.gTextFlags_dword_66C4C8 = 0;
        textConfig.gTextX_dword_66C4C0 = xpos + 4;
        textConfig.gTextY_dword_66C4C4 = ypos + 4;
        textConfig.gTextRGB_dword_66C4CC = bDrawTextRed ? 0x643030FF : 0x64FFFFFF;

        Render_Text_Small_font_468642(pPrimBuffer, &textConfig, pBarConfig->mText);
        TILE* pBarRectPrim = Menu_render_rect_46B79F(
            pPrimBuffer,
            xpos + 3,
            static_cast<__int16>(textConfig.gTextY_dword_66C4C4) - 1,
            static_cast<__int16>(textConfig.gTextX_dword_66C4C0) - (xpos + 4) + 2,
            7,
            0);

        // Rect is semi trans
        pBarRectPrim->code |= 2u;

        // "Damage" fill can't overflow the max bar length
        if (redFillLength > barLength)
        {
            redFillLength = barLength;
        }

        if (redFillLength > normalFillLength)
        {
            TILE* pTile = PrimAlloc<TILE>(pPrimBuffer);
            setTile(pTile);
            setRGB0(pTile, 200, 0, 0);
            pTile->x0 = xpos + (normalFillLength << 7) / 1024;
            pTile->y0 = ypos + 1;
            pTile->w = ((redFillLength - normalFillLength) << 7) / 1024;
            pTile->h = barHeight;
            addPrim(pPrimBuffer->mOt, pTile);
        }

        POLY_G4* pPolyG4 = PrimAlloc<POLY_G4>(pPrimBuffer);
        setPolyG4(pPolyG4);

        pPolyG4->x0 = xpos;
        pPolyG4->y0 = ypos + 1;

        pPolyG4->x2 = xpos;
        const __int16 x1 = ((normalFillLength + 7) << 7) / 1024 + xpos;
        pPolyG4->y1 = ypos + 1;

        const __int16 barBottom = barHeight + ypos + 1;
        pPolyG4->x1 = x1;
        pPolyG4->y2 = barBottom;

        pPolyG4->x3 = x1;
        pPolyG4->y3 = barBottom;
        
        setRGB0(pPolyG4, pBarConfig->mLeftRGB[0], pBarConfig->mLeftRGB[1], pBarConfig->mLeftRGB[2]);

        const int x1_m_xpos_1 = x1 - xpos;
        
        pPolyG4->r1 = static_cast<BYTE>(pBarConfig->mLeftRGB[0] + x1_m_xpos_1 * (pBarConfig->mRightRGB[0] - pBarConfig->mLeftRGB[0]) / 128);
        pPolyG4->g1 = static_cast<BYTE>(pBarConfig->mLeftRGB[1] + x1_m_xpos_1 * (pBarConfig->mRightRGB[1] - pBarConfig->mLeftRGB[1]) / 128);
        pPolyG4->b1 = static_cast<BYTE>(pBarConfig->mLeftRGB[2] + x1_m_xpos_1 * (pBarConfig->mRightRGB[2] - pBarConfig->mLeftRGB[2]) / 128);

        pPolyG4->r2 = pBarConfig->mLeftRGB[0];
        pPolyG4->g2 = pBarConfig->mLeftRGB[1];
        pPolyG4->b2 = pBarConfig->mLeftRGB[2];

        const int x1_m_xpos_2 = x1 - xpos;

        pPolyG4->r3 = static_cast<BYTE>(pBarConfig->mLeftRGB[0] + x1_m_xpos_2 * (pBarConfig->mRightRGB[0] - pBarConfig->mLeftRGB[0]) / 128);
        pPolyG4->g3 = static_cast<BYTE>(pBarConfig->mLeftRGB[1] + x1_m_xpos_2 * (pBarConfig->mRightRGB[1] - pBarConfig->mLeftRGB[1]) / 128);
        pPolyG4->b3 = static_cast<BYTE>(pBarConfig->mLeftRGB[2] + x1_m_xpos_2 * (pBarConfig->mRightRGB[2] - pBarConfig->mLeftRGB[2]) / 128);

        addPrim(pPrimBuffer->mOt, pPolyG4);

        TILE* pMenuBarBackgroundRect = Menu_render_rect_46B79F(pPrimBuffer, xpos, ypos + 1, scaledBarWidth, barHeight, 0x181800);
        // Set semi trans
        pMenuBarBackgroundRect->code |= 2u;

        Menu_render_rect_46B79F(pPrimBuffer, xpos - 1, ypos, 1, barHeight + 2, 0);
        Menu_render_rect_46B79F(pPrimBuffer, xpos, ypos, scaledBarWidth, 1, 0);
        Menu_render_rect_46B79F(pPrimBuffer, xpos, barHeight + ypos + 1, scaledBarWidth, 1, 0);
        Menu_render_rect_46B79F(pPrimBuffer, xpos + scaledBarWidth, ypos, 1, barHeight + 2, 0);
        
        DR_TPAGE* drTPage = PrimAlloc<DR_TPAGE>(pPrimBuffer);
        setDrawTPage(drTPage, 1, 1, 31);
        addPrim(pPrimBuffer->mOt, drTPage);
    }
}
MGS_FUNC_IMPLEX(0x468DA6, Menu_render_life_bar_468DA6, MENU_IMPL);

MGS_VAR(1, 0x78E7F6, WORD, gSnakeCurrentHealth_78E7F6, 0);

MGS_VAR(1, 0x7339D8, int, gTakeDamageCounter_dword_7339D8, 0);
MGS_VAR(1, 0x78E7F8, WORD, gSnakeMaxHealth_78E7F8, 0);
MGS_VAR(1, 0x995348, WORD, gSnakeCurrentO2_995348, 0);



signed int CC Menu_menu_bars_update_field200_46938A(MenuMan_MenuBars* pMenuBarsUnk)
{
    if (pMenuBarsUnk->field_6_snake_hp == gSnakeCurrentHealth_78E7F6)
    {
        pMenuBarsUnk->field_A_k10_decrement = 10;
        return 0;
    }

    if (pMenuBarsUnk->field_6_snake_hp > gSnakeCurrentHealth_78E7F6)
    {
        if (pMenuBarsUnk->field_A_k10_decrement)
        {
            pMenuBarsUnk->field_A_k10_decrement -= 1;
        }
        else
        {
            pMenuBarsUnk->field_6_snake_hp -= 64;
        }
    }

    if (pMenuBarsUnk->field_6_snake_hp < gSnakeCurrentHealth_78E7F6)
    {
        pMenuBarsUnk->field_6_snake_hp = gSnakeCurrentHealth_78E7F6;
    }
    return 1;
}
MGS_FUNC_IMPLEX(0x46938A, Menu_menu_bars_update_field200_46938A, MENU_IMPL);

MGS_VAR(1, 0x6757F0, BarConfig, gSnakeLifeBarConfig_6757F0, {}); // TODO: Populate
MGS_VAR(1, 0x675800, BarConfig, gSnakeO2BarConfig_675800, {}); // TODO: Populate
MGS_VAR(1, 0x7339D4, int, gSnakeLifeYPos_7339D4, 0);

template<class T>
static inline T SetPointerFlag(T ptr)
{
    return reinterpret_cast<T>(reinterpret_cast<unsigned int>(ptr) | 0x40000000);
}

void CC Menu_render_snake_life_bar_469194(MenuPrimBuffer* ot, short xpos, short ypos)
{
    game_state_dword_72279C.mParts.flags1 |= 0x80u;
    Menu_render_life_bar_468DA6(
        ot,
        xpos,
        ypos,
        gSnakeCurrentHealth_78E7F6,
        gSnakeCurrentHealth_78E7F6,
        gSnakeMaxHealth_78E7F8,
        &gSnakeLifeBarConfig_6757F0);
}
MGS_FUNC_IMPLEX(0x469194, Menu_render_snake_life_bar_469194, MENU_IMPL);

void CC Menu_render_auto_stacked_any_size_menu_bar_469160(MenuPrimBuffer* pPrimBuffer, short xpos, short ypos, short redFillLength, short normalFillLength, short barLength, BarConfig *pBarConfig)
{
    game_state_dword_72279C.mParts.flags1 |= 0x80u;
    Menu_render_life_bar_468DA6(
        pPrimBuffer,
        xpos,
        static_cast<short>(gSnakeLifeYPos_7339D4 + ypos - 16),
        redFillLength,
        normalFillLength,
        barLength,
        pBarConfig);
}
MGS_FUNC_IMPLEX(0x469160, Menu_render_auto_stacked_any_size_menu_bar_469160, MENU_IMPL);

void CC Menu_Set_Text_BlendMode_459BE0()
{
    DR_TPAGE* pDrTPage = PrimAlloc<DR_TPAGE>(&gMenuPrimBuffer_7265E0);
    int abr = ((gTextConfig_66C4C0.gTextFlags_dword_66C4C8 >> 8) & 3);
    setDrawTPage(pDrTPage, 1, 1, getTPage(0, abr, 960, 256));
    addPrim(gMenuPrimBuffer_7265E0.mOt, pDrTPage);
}
MGS_FUNC_IMPLEX(0x00459BE0, Menu_Set_Text_BlendMode_459BE0, MENU_IMPL);

void CC TextSetXYFlags_459B0B(int x, int y, int flags)
{
    // TODO: Create enum and replace call sites with enum flags
    // 0x1 = right align
    // 0x2 = center align
    // 0x10 = larger font size
    // 0x20 = semi transparent

    // other bits = left align/do nothing
    gTextConfig_66C4C0.gTextX_dword_66C4C0 = x;
    gTextConfig_66C4C0.gTextY_dword_66C4C4 = y;
    gTextConfig_66C4C0.gTextFlags_dword_66C4C8 = flags;
}
MGS_FUNC_IMPLEX(0x459B0B, TextSetXYFlags_459B0B, MENU_IMPL);

void CC Menu_render_auto_stacked_1024_size_menu_bar_459C6B(short xpos, short ypos, short redFillLength, short normalFillLength, BarConfig* pBarConfig)
{
    game_state_dword_72279C.mParts.flags1 |= 0x80u;
    Menu_render_auto_stacked_any_size_menu_bar_469160(
        &gMenuPrimBuffer_7265E0,
        xpos,
        ypos,
        redFillLength,
        normalFillLength,
        static_cast<short>(1024),
        pBarConfig);
    Menu_Set_Text_BlendMode_459BE0();
}
MGS_FUNC_IMPLEX(0x00459C6B, Menu_render_auto_stacked_1024_size_menu_bar_459C6B, MENU_IMPL);

void CC Menu_render_fixedx_auto_stacked_menu_bar_impl_46912D(MenuPrimBuffer* pPrimBuffer, short ypos, short redFill, short normalFill, short maxFill, BarConfig* pBarConfig)
{
    game_state_dword_72279C.mParts.flags1 |= 0x80u;
    Menu_render_life_bar_468DA6(pPrimBuffer, 16, static_cast<short>(gSnakeLifeYPos_7339D4 + ypos - 16), redFill, normalFill, maxFill, pBarConfig);
}
MGS_FUNC_IMPLEX(0x46912D, Menu_render_fixedx_auto_stacked_menu_bar_impl_46912D, MENU_IMPL);

void CC Menu_render_fixed_xpos_auto_stacked_menu_bar_459C9D(short ypos, short redFillLength, short normalFillLength, short barLength, BarConfig *pBarConfig)
{
    Menu_render_fixedx_auto_stacked_menu_bar_impl_46912D(
        &gMenuPrimBuffer_7265E0,
        ypos,
        redFillLength,
        normalFillLength,
        barLength,
        pBarConfig);
}
MGS_FUNC_IMPLEX(0x459C9D, Menu_render_fixed_xpos_auto_stacked_menu_bar_459C9D, MENU_IMPL);

void CC Menu_menu_bars_draw_snake_life_and_O2_4693D5(MenuPrimBuffer* ot, MenuMan_MenuBars *pField200)
{
    gSnakeLifeYPos_7339D4 = pField200->field_4_bar_y;

    BarConfig* pLifeBarText = &gSnakeLifeBarConfig_6757F0;

    if (game_state_dword_72279C.flags & 0x2000000)
    {
        // Sets hi byte
        game_state_dword_72279C.mParts.flags3 &= 0xFDu;
        gTakeDamageCounter_dword_7339D8 = 8;
    }

    if (gTakeDamageCounter_dword_7339D8 > 0)
    {
        --gTakeDamageCounter_dword_7339D8;
        // Flag causes MenuBar text to render in red
        pLifeBarText = SetPointerFlag(&gSnakeLifeBarConfig_6757F0);
    }

    Menu_render_life_bar_468DA6(
        ot,
        pField200->field_2_bar_x,
        pField200->field_4_bar_y,
        pField200->field_6_snake_hp,
        gSnakeCurrentHealth_78E7F6,
        gSnakeMaxHealth_78E7F8,
        pLifeBarText);

    if (pField200->field_1_O2_hp)
    {
        Menu_render_life_bar_468DA6(
            ot,
            pField200->field_2_bar_x,
            pField200->field_4_bar_y + 12,
            gSnakeCurrentO2_995348,
            gSnakeCurrentO2_995348,
            1024,
            &gSnakeO2BarConfig_675800);
    }
}
MGS_FUNC_IMPLEX(0x4693D5, Menu_menu_bars_draw_snake_life_and_O2_4693D5, MENU_IMPL);

void CC Menu_menu_bars_update_469215(MenuMan* pMenu, int* /*ot*/)
{
    MenuMan_MenuBars* pField_200 = &pMenu->field_200_hp_bars_info;
    signed int bHpChanged = Menu_menu_bars_update_field200_46938A(&pMenu->field_200_hp_bars_info);

    if (gSnakeCurrentO2_995348 < 1024)
    {
        pMenu->field_200_hp_bars_info.field_1_O2_hp = 150;
        bHpChanged = 1;
    }

    if (!pMenu->field_2A_bSkipUpdateHpBars)
    {
        if (game_state_dword_72279C.flags & 0x10000)
        {
            pField_200->field_0_state = 3;
        }

        const char state_copy = pField_200->field_0_state;
        if ((!pField_200->field_0_state || state_copy == 3)
            && (bHpChanged || game_state_dword_72279C.flags & 0x8000 || gSnakeCurrentHealth_78E7F6 <= gSnakeMaxHealth_78E7F8 / 2))
        {
            if (!state_copy)
            {
                pMenu->field_200_hp_bars_info.field_4_bar_y = -48;
            }
            pField_200->field_0_state = 1;
            gTakeDamageCounter_dword_7339D8 = 0;
        }
        if (pField_200->field_0_state)
        {
            if (pField_200->field_0_state == 1)     // animate in the life bar?
            {
                pMenu->field_200_hp_bars_info.field_4_bar_y += 8;
                if (pMenu->field_200_hp_bars_info.field_4_bar_y >= 16)
                {
                    pMenu->field_200_hp_bars_info.field_4_bar_y = 16;
                    pField_200->field_0_state = 2;
                    pMenu->field_200_hp_bars_info.field_8 = 150;
                }
                Menu_menu_bars_draw_snake_life_and_O2_4693D5(pMenu->field_20_prim_buffer, pField_200);
                return;
            }

            if (pField_200->field_0_state == 2)
            {
                if (bHpChanged || gSnakeCurrentHealth_78E7F6 <= gSnakeMaxHealth_78E7F8 / 2 || game_state_dword_72279C.flags & 0x8000)
                {
                    pMenu->field_200_hp_bars_info.field_8 = 150;
                    if (pMenu->field_200_hp_bars_info.field_1_O2_hp > 0)
                    {
                        pMenu->field_200_hp_bars_info.field_1_O2_hp -= 1;
                    }
                }
                else if (--pMenu->field_200_hp_bars_info.field_8 <= 0)
                {
                    pField_200->field_0_state = 3;
                }
                Menu_menu_bars_draw_snake_life_and_O2_4693D5(pMenu->field_20_prim_buffer, pField_200);
                return;
            }

            if (pField_200->field_0_state != 3)
            {
                if (pField_200->field_0_state == 4)
                {
                    pField_200->field_0_state = 0;
                    pMenu->field_200_hp_bars_info.field_4_bar_y = -48;
                }
                Menu_menu_bars_draw_snake_life_and_O2_4693D5(pMenu->field_20_prim_buffer, pField_200);
                return;
            }

            pMenu->field_200_hp_bars_info.field_4_bar_y -= 8;
            if (pMenu->field_200_hp_bars_info.field_4_bar_y > -48)
            {
                Menu_menu_bars_draw_snake_life_and_O2_4693D5(pMenu->field_20_prim_buffer, pField_200);
                return;
            }
            
            pField_200->field_0_state = 0;
            pMenu->field_200_hp_bars_info.field_4_bar_y = -48;
            
            if (game_state_dword_72279C.flags & 0x10000)
            {
                game_state_dword_72279C.flags = game_state_dword_72279C.flags & 0xFFFEFFFF | 0x20000;
            }

            if (gSnakeCurrentO2_995348 == 1024)
            {
                pMenu->field_200_hp_bars_info.field_1_O2_hp = 0;
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x469215, Menu_menu_bars_update_469215, MENU_IMPL);

void CC Menu_init_menu_bars_4691CE(MenuMan* pMenu)
{
    pMenu->field_28_flags |= 1u;
    pMenu->m7FnPtrs_field_2C[0] = Menu_menu_bars_update_469215;

    pMenu->field_200_hp_bars_info.field_0_state = 0;
    pMenu->field_200_hp_bars_info.field_1_O2_hp = 0;
    pMenu->field_200_hp_bars_info.field_6_snake_hp = gSnakeCurrentHealth_78E7F6;
    pMenu->field_200_hp_bars_info.field_A_k10_decrement = 10;
    pMenu->field_200_hp_bars_info.field_2_bar_x = 16;
    pMenu->field_200_hp_bars_info.field_4_bar_y = -48;

    gSnakeLifeYPos_7339D4 = -48;
}
MGS_FUNC_IMPLEX(0x4691CE, Menu_init_menu_bars_4691CE, MENU_IMPL);

MGS_ARY(1, 0x66C480, TMenuFn, 9, gMenuFuncs_inits_66C480,
{
    Menu_init_fn0_46AD91.Ptr(),
    Menu_init_radar_468358,
    Menu_init_codec_463746,
    Menu_init_inventory_left_469E77.Ptr(),
    Menu_init_inventory_right_4694E4.Ptr(),
    Menu_init_menu_bars_4691CE,
    Menu_init_num_res_font_468406,
    Menu_init_fn7_jimaku_font_buffer_size_sub_462CFC.Ptr(),
    nullptr
});

void CC Menu_TextReset_459ACE()
{
    gTextConfig_66C4C0.gTextFlags_dword_66C4C8 = 0;
    gTextConfig_66C4C0.gTextRGB_dword_66C4CC = 0x64808080;
    gMenuPrimBuffer_7265E0.mFreeLocation = gMenuPrimBufferArrays_7265EC[gActiveBuffer_dword_791A08];
    gMenuPrimBuffer_7265E0.mOtEnd = gMenuPrimBuffer_7265E0.mFreeLocation + 8192; // sizeof gMenuPrimArray1_7269F4/gMenuPrimArray2_7289F4
    gMenuPrimBuffer_7265E0.mOt = gLibGvStruct2_6BC558.mOrderingTables[gActiveBuffer_dword_791A08];
}
MGS_FUNC_IMPLEX(0x00459ACE, Menu_TextReset_459ACE, MENU_IMPL);

void CC Menu_create_helper_459991(MenuMan* pMenu)
{
    pMenu->field_2A_bSkipUpdateHpBars = 0;
    pMenu->field_29 = 0;
    pMenu->field_28_flags = 0;
    pMenu->field_20_prim_buffer = &gMenuPrimBuffer_7265E0;

    gMenuPrimBufferArrays_7265EC[0] = &gMenuPrimArray1_7269F4[0];
    gMenuPrimBufferArrays_7265EC[1] = &gMenuPrimArray2_7289F4[0];

    DRAWENV drEnv = {};
    Renderer_DRAWENV_Init_401888(&drEnv, 0, 0, 320, 224);
    drEnv.isbg = 0;
    drEnv.texturePage = 31;
    SetDrawEnv_40DDE0(&pMenu->mDR_ENV_field_48[0], &drEnv);
    
    Renderer_DRAWENV_Init_401888(&drEnv, 320, 0, 320, 224);
    drEnv.isbg = 0;
    drEnv.texturePage = 31;
    SetDrawEnv_40DDE0(&pMenu->mDR_ENV_field_48[1], &drEnv);

    Menu_create_helper_item_file_46B8CA("item");

    TMenuFn* fnPtr = &gMenuFuncs_inits_66C480[0];
    while (*fnPtr)
    {
        (*fnPtr)(pMenu);
        ++fnPtr;
    }
}
MGS_FUNC_IMPLEX(0x00459991, Menu_create_helper_459991, MENU_IMPL);

void CC TextSetDefaults_459B51()
{
    gTextConfig_66C4C0.gTextFlags_dword_66C4C8 = 0;
    gTextConfig_66C4C0.gTextRGB_dword_66C4CC = 0x64808080;
}
MGS_FUNC_IMPLEX(0x00459B51, TextSetDefaults_459B51, MENU_IMPL);

MGS_VAR(1, 0x733DD8, SPRT, gMenu_inventory_text_header_background_733DD8, {});

// TODO: Recover structure
struct Font
{

};
MGS_VAR(1, 0x733DF0, Font, gMenuFont_733DF0, {});
MGS_VAR(1, 0x676530, PSX_RECT, sMenu_rect_676530, {}); // TODO: Populate

MGS_FUNC_NOT_IMPL(0x45A70D, int __cdecl(Font *ptr, PSX_RECT *pRect, __int16 vramX, __int16 vramY), Font_45A70D);
MGS_FUNC_NOT_IMPL(0x45A796, int __cdecl (Font *pFont, int a2, int a3, int a4, int a5, int a6, int a7), Font_45A796);
MGS_FUNC_NOT_IMPL(0x45AA45, int __cdecl (Font *pFont), Font_CalcSize_45AA45);
MGS_FUNC_NOT_IMPL(0x45AAE9, int __cdecl (Font *pFont, void *pAllocated), Font_Set_Buffer_45AAE9);
MGS_FUNC_NOT_IMPL(0x45A89F, WORD *__cdecl (Font *pFont, signed int index, signed int colour1, signed int colour2), Font_ColourRelated_45A89F);
MGS_FUNC_NOT_IMPL(0x45C7F2, void *__cdecl (Font *pFont), Font_45C7F2);

struct uv_pair
{
    __int16 u;
    __int16 v;
};
MGS_ARY(1, 0x676538, uv_pair, 2, stru_676538, {}); // TODO: Populate

signed int CC Menu_inventory_common_update_helper_46B979(int idx)
{
    setSprt(&gMenu_inventory_text_header_background_733DD8);

    gMenu_inventory_text_header_background_733DD8.r0 = 128;
    gMenu_inventory_text_header_background_733DD8.g0 = 128;
    gMenu_inventory_text_header_background_733DD8.b0 = 128;

    gMenu_inventory_text_header_background_733DD8.v0 = static_cast<BYTE>(sMenu_rect_676530.y1);
    gMenu_inventory_text_header_background_733DD8.u0 = 0;

    gMenu_inventory_text_header_background_733DD8.w = 200;
    gMenu_inventory_text_header_background_733DD8.h = 80;

    const __int16 x0 = stru_676538[idx].u; // TODO: Actually POINT's?
    const __int16 y0 = stru_676538[idx].v;
    gMenu_inventory_text_header_background_733DD8.x0 = x0;
    gMenu_inventory_text_header_background_733DD8.y0 = y0;

    gMenu_inventory_text_header_background_733DD8.clut = 32700;
    ClearImage(&sMenu_rect_676530, 0, 0, 0);
    Font_45A70D(&gMenuFont_733DF0, &sMenu_rect_676530, 960, 510);
    Font_45A796(&gMenuFont_733DF0, -1, -1, 0, 6, 2, 0);
    const int sizeToAlloc = Font_CalcSize_45AA45(&gMenuFont_733DF0);
    void* pAllocated = System_2_zerod_allocate_memory_40B296(sizeToAlloc);
    if (!pAllocated)
    {
        return 0;
    }
    Font_Set_Buffer_45AAE9(&gMenuFont_733DF0, pAllocated);
    Font_ColourRelated_45A89F(&gMenuFont_733DF0, 0, 0x6739, 0);
    Font_45C7F2(&gMenuFont_733DF0);
    return 1;
}
MGS_FUNC_IMPLEX(0x46B979, Menu_inventory_common_update_helper_46B979, true);

void __cdecl Menu_inventory_draw_item_header_and_background_with_hp_bar_46BA95(MenuMan* pMenu, int* pOt, const char* pText)
{
    pMenu->field_2B |= 2u;

    SPRT* itemTextSprite = PrimAlloc<SPRT>(pMenu->field_20_prim_buffer);
    memcpy(itemTextSprite, &gMenu_inventory_text_header_background_733DD8, sizeof(SPRT));
    addPrim(pMenu->field_20_prim_buffer->mOt, itemTextSprite); // A texture with the item text on it ??

    const int textWidth = Menu_inventory_text_4689CB(
        pMenu,
        pOt,
        gMenu_inventory_text_header_background_733DD8.x0 - 10 + 2,
        gMenu_inventory_text_header_background_733DD8.y0 - 7,
        pText,
        0); // EQUIP or WEAPON/NO ITEM text

    Menu_render_snake_life_bar_469194(pMenu->field_20_prim_buffer, gMenu_inventory_text_header_background_733DD8.x0 - 10, 24); // HP bar
    
    const short int width = static_cast<short int>(textWidth + 2);
    for (int i=0; i<2; i++)
    {
        POLY_F4* pPolyFT4 = PrimAlloc<POLY_F4>(pMenu->field_20_prim_buffer); // Sloping header polygon that contains EQUIP/WEAPON text
        setPolyF4(pPolyFT4);
        setRGB0(pPolyFT4, 0, 0, 0);
        setSemiTrans(pPolyFT4, 1);
        pPolyFT4->x0 = gMenu_inventory_text_header_background_733DD8.x0 - 10;
        pPolyFT4->y0 = gMenu_inventory_text_header_background_733DD8.y0 - 9;
        pPolyFT4->x1 = width;
        pPolyFT4->x2 = gMenu_inventory_text_header_background_733DD8.x0 - 10;
        pPolyFT4->y1 = gMenu_inventory_text_header_background_733DD8.y0 - 9;
        pPolyFT4->x3 = width;
        pPolyFT4->y2 = gMenu_inventory_text_header_background_733DD8.y0;
        pPolyFT4->x3 = width + 10;
        pPolyFT4->y3 = gMenu_inventory_text_header_background_733DD8.y0;
        addPrim(pOt, pPolyFT4);

        TILE* pTile = PrimAlloc<TILE>(pMenu->field_20_prim_buffer); // Big square background for the item/weapon text
        setTile(pTile);
        setRGB0(pTile, 0, 0, 0);
        setSemiTrans(pTile, 1);
        pTile->x0 = gMenu_inventory_text_header_background_733DD8.x0 - 10;
        pTile->y0 = gMenu_inventory_text_header_background_733DD8.y0;
        pTile->w = gMenu_inventory_text_header_background_733DD8.w + 10;
        pTile->h = gMenu_inventory_text_header_background_733DD8.h;
        addPrim(pOt, pTile);
    }
}
MGS_FUNC_IMPLEX(0x46BA95, Menu_inventory_draw_item_header_and_background_with_hp_bar_46BA95, MENU_IMPL);

int CC Menu_inventory_text_4689CB(MenuMan* pMenu, int* /*ot*/, int xpos, int ypos, const char* pText, int textFlags)
{
    TextConfig textConfig = {};
    textConfig.gTextX_dword_66C4C0 = xpos;
    textConfig.gTextY_dword_66C4C4 = ypos;
    textConfig.gTextFlags_dword_66C4C8 = textFlags;
    textConfig.gTextRGB_dword_66C4CC = 0x64808080;
    Render_Text_Small_font_468642(pMenu->field_20_prim_buffer, &textConfig, pText);
    return textConfig.gTextX_dword_66C4C0;
}
MGS_FUNC_IMPLEX(0x4689CB, Menu_inventory_text_4689CB, MENU_IMPL);


const short kCharWidth = 6;

void CC Menu_render_number_as_string_468529(MenuPrimBuffer* pPrimBuffer, TextConfig* pTextConfig, signed int numberRemainder)
{
    int maxCount = 0;
    if (pTextConfig->gTextFlags_dword_66C4C8 & 0x40)
    {
        maxCount = pTextConfig->gTextFlags_dword_66C4C8 >> 8;
    }
    else
    {
        maxCount = 0;
    }

    short int xpos = 0;
    SPRT* pFirstSprt = nullptr;
    int numSprts = 0;
    for (;;)
    {
        xpos -= 6;
        const int currentNum = numberRemainder % 10;
        SPRT* pSprt = PrimAlloc<SPRT>(pPrimBuffer);
        numberRemainder /= 10;
        if (!pFirstSprt)
        {
            pFirstSprt = pSprt;
        }
        memcpy(pSprt, &gMenu_font1_template_sprite_7339C0, sizeof(SPRT));
        
        setRGB0(pSprt,
            BYTE0(pTextConfig->gTextRGB_dword_66C4CC),
            BYTE1(pTextConfig->gTextRGB_dword_66C4CC),
            BYTE2(pTextConfig->gTextRGB_dword_66C4CC));

        pSprt->x0 = xpos;
        pSprt->y0 = static_cast<short>(pTextConfig->gTextY_dword_66C4C4);
        pSprt->u0 = static_cast<BYTE>(kCharWidth * (currentNum + 26)); // the numbers are after the alphabet in the sprite sheet, hence + 26

        addPrim(pPrimBuffer->mOt, pSprt);
        numSprts++;

        --maxCount;
        if (numberRemainder <= 0 && maxCount <= 0)
        {
            break;
        }
    }

    // Similar to Render_Text_SetGlyphPositions_4687E8
    if (pFirstSprt)
    {
        // Align all of the sprites for each number according to the alignment flags
        int adjustValue = 0;
        if ((pTextConfig->gTextFlags_dword_66C4C8 & 0xF) == 1)
        {
            // Right aligned
            adjustValue = pTextConfig->gTextX_dword_66C4C0;
            pTextConfig->gTextX_dword_66C4C0 += xpos;
        }
        else if ((pTextConfig->gTextFlags_dword_66C4C8 & 0xF) == 2)
        {
            // Center aligned
            adjustValue = pTextConfig->gTextX_dword_66C4C0 - xpos / 2;
        }
        else
        {
            // Left aligned
            adjustValue = pTextConfig->gTextX_dword_66C4C0 - xpos;
            pTextConfig->gTextX_dword_66C4C0 = adjustValue;
        }

        for (int i = 0; i < numSprts; i++)
        {
            pFirstSprt[i].x0 += static_cast<short>(adjustValue);
        }
    }
}
MGS_FUNC_IMPLEX(0x00468529, Menu_render_number_as_string_468529, MENU_IMPL);

void CC Menu_render_number_as_string_with_flags_4688DC(MenuMan* pMenu, int /*ot*/, int textX, int textY, signed int number, int textFlags)
{
    TextConfig textConfig = {};
    textConfig.gTextX_dword_66C4C0 = textX;
    textConfig.gTextY_dword_66C4C4 = textY;
    textConfig.gTextFlags_dword_66C4C8 = textFlags;
    textConfig.gTextRGB_dword_66C4CC = 0x64808080;
    Menu_render_number_as_string_468529(pMenu->field_20_prim_buffer, &textConfig, number);
}
MGS_FUNC_IMPLEX(0x004688DC, Menu_render_number_as_string_with_flags_4688DC, MENU_IMPL);

void CC Menu_render_text_fractional_468915(MenuMan* pMenu, int x, int y, signed int currentValue, signed int maxValue)
{
    // Renders as text: "currentValue/maxValue"

    TextConfig textConfig = {};
    textConfig.gTextFlags_dword_66C4C8 = 0;
    textConfig.gTextX_dword_66C4C0 = x;
    textConfig.gTextY_dword_66C4C4 = y;
    textConfig.gTextRGB_dword_66C4CC = currentValue != 0 ? 0x64575757 : 0x64002080;

    // Render first number
    Menu_render_number_as_string_468529(pMenu->field_20_prim_buffer, &textConfig, currentValue);

    // Render dividing backslash
    SPRT* pSprt = PrimAlloc<SPRT>(pMenu->field_20_prim_buffer);
    memcpy(pSprt, &gMenu_font1_template_sprite_7339C0, sizeof(SPRT));

    setRGB0(pSprt,
        BYTE0(textConfig.gTextRGB_dword_66C4CC),
        BYTE1(textConfig.gTextRGB_dword_66C4CC),
        BYTE2(textConfig.gTextRGB_dword_66C4CC));

    pSprt->x0 = static_cast<short>(textConfig.gTextX_dword_66C4C0);
    pSprt->y0 = static_cast<short>(textConfig.gTextY_dword_66C4C4);
    pSprt->u0 = 224;
    addPrim(pMenu->field_20_prim_buffer->mOt, pSprt);
    textConfig.gTextX_dword_66C4C0 += kCharWidth;

    // Render 2nd number
    Menu_render_number_as_string_468529(pMenu->field_20_prim_buffer, &textConfig, maxValue);
}
MGS_FUNC_IMPLEX(0x00468915, Menu_render_text_fractional_468915, MENU_IMPL);

// Used when skipping/scrolling through codec text
void CC Menu_draw_blinking_arrow_463652(MenuMan* pMenu, BYTE* ot)
{
    if (g_lib_gv_stru_6BFEE0.gRenderedFramesCount_dword_6BFF00 % 16 >= 4)
    {
        POLY_F3* pPoly = PrimAlloc<POLY_F3>(pMenu->field_20_prim_buffer);

        setPolyF3(pPoly);
        setRGB0(pPoly, 0x80, 0x80, 0x80);

        pPoly->x1 = 288;
        pPoly->y1 = 210;
        pPoly->x0 = pPoly->x1 - 4;
        pPoly->x2 = pPoly->x1 + 4;
        pPoly->y2 = pPoly->y1 - 4;
        pPoly->y0 = pPoly->y2;

        addPrim(ot, pPoly);
    }
}
MGS_FUNC_IMPLEX(0x00463652, Menu_draw_blinking_arrow_463652, MENU_IMPL);

void CC Menu_update_4598BC(MenuMan* pMenu)
{
    int* pOtText1 = (int*)gMenuPrimBuffer_7265E0.mOt;
    int* pOtText2 = (int*)gMenuPrimBuffer_7265E0.mOt;
    pMenu->field_24_input = gpActiveButtons_995324 + 2;

    Menu_update_helper_462A3D(pMenu, pOtText2);

    if (!(gActorPauseFlags_dword_791A0C & 2)
        && gLoaderState_dword_9942B8 > 0
        && !script_cancel_non_zero_dword_7227A0
        && (game_state_dword_72279C.flags & 0x80000000) == 0)
    {
        const int field_28_flags = pMenu->field_28_flags;
        int flags = 1;
        for (int i = 0; i < 7; i++)
        {
            if (flags & field_28_flags)
            {
                // 0 = life bars
                // 1 = right side inventory
                // 2 = left side inventory
                // 3 = radar
                // 4 = enter/exit codec
                // 5/6 = not set by default
                pMenu->m7FnPtrs_field_2C[i](pMenu, pOtText1);
            }
            flags *= 2; // To the next bit
        }
    }

    // drawing environment change primitive
    addPrim(pOtText2, &pMenu->mDR_ENV_field_48[gActiveBuffer_dword_791A08]);
}
MGS_FUNC_IMPLEX(0x004598BC, Menu_update_4598BC, MENU_IMPL);

void CC Menu_shutdown_fn1_4683F3(MenuMan* pMenu)
{
    pMenu->field_28_flags &= 0xF7u;
}
MGS_FUNC_IMPLEX(0x004683F3, Menu_shutdown_fn1_4683F3, MENU_IMPL);

void CC Menu_shutdown_radar_4657E6(MenuMan *pMenu)
{
    pMenu->field_28_flags &= 0xEFu;
}
MGS_FUNC_IMPLEX(0x004657E6, Menu_shutdown_radar_4657E6, MENU_IMPL);

void CC Menu_shutdown_codec_46AD80(MenuMan *pMenu)
{
    pMenu->field_28_flags &= 0xFBu;
}
MGS_FUNC_IMPLEX(0x0046AD80, Menu_shutdown_codec_46AD80, MENU_IMPL);

void CC Menu_shutdown_fn4_469E26(MenuMan* pMenu)
{
    pMenu->field_28_flags &= 0xFDu;
}
MGS_FUNC_IMPLEX(0x00469E26, Menu_shutdown_fn4_469E26, MENU_IMPL);

void CC Menu_shutdown_fn5_469476(MenuMan* pMenu)
{
    pMenu->field_28_flags &= 0xFEu;
}
MGS_FUNC_IMPLEX(0x00469476, Menu_shutdown_fn5_469476, MENU_IMPL);

void Menu_shutdown_fn6_nullsub_131(MenuMan*)
{

}

MGS_ARY(1, 0x66C4A4, TMenuFn, 7, gMenuFuncs_shutdown_66C4A4,
{
    Menu_shutdown_fn1_4683F3,
    Menu_shutdown_radar_4657E6,
    Menu_shutdown_codec_46AD80,
    Menu_shutdown_fn4_469E26,
    Menu_shutdown_fn5_469476,
    Menu_shutdown_fn6_nullsub_131,
    nullptr
});

void Menu_shutdown_459971(MenuMan* pMenu)
{
    TMenuFn* fnPtr = &gMenuFuncs_shutdown_66C4A4[0];
    while (*fnPtr)
    {
        (*fnPtr)(pMenu);
    }
}
MGS_FUNC_IMPLEX(0x00459971, Menu_shutdown_459971, MENU_IMPL);

void CC Menu_create_459891()
{
    Actor_Init_40A347(&gMenuMan_stru_725FC0.mBase,
        (TActorFunction)Menu_update_4598BC,
        (TActorFunction)Menu_shutdown_459971,
        "C:\\mgs\\source\\Menu\\menuman.c");

    Menu_create_helper_459991(&gMenuMan_stru_725FC0);
    sub_462E8D();
}
MGS_FUNC_IMPLEX(0x00459891, Menu_create_459891, MENU_IMPL);

void CC MenuTextureLoad_44DEB3()
{
    Texture_Record* pFound = LibDG_FindTexture_4024A0(0xA0BE);

    gMenuTexture_A0BE_722788.mHashedName = pFound->mHashedName;
    gMenuTexture_A0BE_722788.mUsed = pFound->mUsed;
    gMenuTexture_A0BE_722788.mNumColours = pFound->mNumColours;

    gMenuTexture_A0BE_722788.mTPage = pFound->mTPage;
    gMenuTexture_A0BE_722788.mClut = pFound->mClut;

    gMenuTexture_A0BE_722788.u0 = pFound->u0;
    gMenuTexture_A0BE_722788.v0 = pFound->v0;
    gMenuTexture_A0BE_722788.u1 = pFound->u1;
    gMenuTexture_A0BE_722788.v1 = pFound->v1;

    gMenuTexture_A0BE_722788.mHashedName = 0;
}
MGS_FUNC_IMPLEX(0x44DEB3, MenuTextureLoad_44DEB3, MENU_IMPL);

//   Render_Text_Large_font_468AAF(&gMenuPrimBuffer_7265E0, &gTextConfig_66C4C0, formattedStr);

static void Test_Render_Text_Large_font_468AAF()
{
    BYTE backingBuffer[32 * sizeof(SPRT)] = {};
    MenuPrimBuffer buffer;
    buffer.mFreeLocation = backingBuffer;
    buffer.mOt = backingBuffer;
    buffer.mOtEnd = backingBuffer + sizeof(backingBuffer);

    TextConfig config;
    config.gTextX_dword_66C4C0 = 0;
    config.gTextY_dword_66C4C4 = 0;
    config.gTextFlags_dword_66C4C8 = 0;
    config.gTextRGB_dword_66C4CC = 0x64ffffff;

    InitLargeFontTemplateSprite();

    Render_Text_Large_font_468AAF(&buffer, &config, "i Hello\nwor l d \n1234#9567890\n.@:_!?+-/*{}");

    const SPRT expected[31] =
    {
        { 68759560, 255, 255, 255, 100, 1, 0, 64, 242, 32765, 8, 6 },
        { 68758960, 255, 255, 255, 100, 9, 0, 56, 242, 32765, 8, 6 },
        { 68758980, 255, 255, 255, 100, 18, 0, 32, 242, 32765, 8, 6 },
        { 68759000, 255, 255, 255, 100, 27, 0, 88, 242, 32765, 8, 6 },
        { 68759020, 255, 255, 255, 100, 36, 0, 88, 242, 32765, 8, 6 },
        { 68759040, 255, 255, 255, 100, 45, 0, 112, 242, 32765, 8, 6 },
        { 68759060, 255, 255, 255, 100, 0, 8, 176, 242, 32765, 8, 6 },
        { 68759080, 255, 255, 255, 100, 9, 8, 112, 242, 32765, 8, 6 },
        { 68759100, 255, 255, 255, 100, 18, 8, 136, 242, 32765, 8, 6 },
        { 68759120, 255, 255, 255, 100, 31, 8, 88, 242, 32765, 8, 6 },
        { 68759140, 255, 255, 255, 100, 44, 8, 24, 242, 32765, 8, 6 },
        { 68759160, 255, 255, 255, 100, 0, 16, 8, 248, 32765, 8, 6 },
        { 68759180, 255, 255, 255, 100, 9, 16, 16, 248, 32765, 8, 6 },
        { 68759200, 255, 255, 255, 100, 18, 16, 24, 248, 32765, 8, 6 },
        { 68759220, 255, 255, 255, 100, 27, 16, 32, 248, 32765, 8, 6 },
        { 68759240, 255, 255, 255, 100, 45, 16, 40, 248, 32765, 8, 6 },
        { 68759260, 255, 255, 255, 100, 54, 16, 48, 248, 32765, 8, 6 },
        { 68759280, 255, 255, 255, 100, 63, 16, 56, 248, 32765, 8, 6 },
        { 68759300, 255, 255, 255, 100, 72, 16, 64, 248, 32765, 8, 6 },
        { 68759320, 255, 255, 255, 100, 81, 16, 72, 248, 32765, 8, 6 },
        { 68759340, 255, 255, 255, 100, 90, 16, 0, 248, 32765, 8, 6 },
        { 68759360, 255, 255, 255, 100, 1, 24, 80, 248, 32765, 8, 6 },
        { 68759380, 255, 255, 255, 100, 5, 24, 96, 248, 32765, 8, 6 },
        { 68759400, 255, 255, 255, 100, 9, 24, 112, 248, 32765, 8, 6 },
        { 68759420, 255, 255, 255, 100, 12, 24, 120, 248, 32765, 8, 6 },
        { 68759440, 255, 255, 255, 100, 21, 24, 128, 248, 32765, 8, 6 },
        { 68759460, 255, 255, 255, 100, 30, 24, 136, 248, 32765, 8, 6 },
        { 68759480, 255, 255, 255, 100, 39, 24, 144, 248, 32765, 8, 6 },
        { 68759500, 255, 255, 255, 100, 48, 24, 152, 248, 32765, 8, 6 },
        { 68759520, 255, 255, 255, 100, 57, 24, 160, 248, 32765, 8, 6 },
        { 68759540, 255, 255, 255, 100, 60, 24, 168, 248, 32765, 8, 6 }
    };

    const SPRT* pExpectedSprt = &expected[0];
    const SPRT* pActualSprt = reinterpret_cast<SPRT*>(backingBuffer);
    int count = 0;
    while (pActualSprt->tag)
    {
        ASSERT_EQ(pActualSprt->code, pExpectedSprt->code);

        ASSERT_EQ(pActualSprt->r0, pExpectedSprt->r0);
        ASSERT_EQ(pActualSprt->g0, pExpectedSprt->g0);
        ASSERT_EQ(pActualSprt->b0, pExpectedSprt->b0);

        ASSERT_EQ(pActualSprt->x0, pExpectedSprt->x0);
        ASSERT_EQ(pActualSprt->y0, pExpectedSprt->y0);

        ASSERT_EQ(pActualSprt->w, pExpectedSprt->w);
        ASSERT_EQ(pActualSprt->h, pExpectedSprt->h);

        ASSERT_EQ(pActualSprt->u0, pExpectedSprt->u0);
        ASSERT_EQ(pActualSprt->v0, pExpectedSprt->v0);

        ASSERT_EQ(pActualSprt->clut, pExpectedSprt->clut);

        pActualSprt++;
        pExpectedSprt++;
        count++;
    }
    ASSERT_EQ(count, 31);
}

static void Test_Render_Text_Small_font_468642()
{
    BYTE backingBuffer[1024 * 50] = {};
    MenuPrimBuffer buffer;
    buffer.mFreeLocation = backingBuffer;
    buffer.mOt = backingBuffer;
    buffer.mOtEnd = backingBuffer + sizeof(backingBuffer);

    TextConfig config;
    config.gTextX_dword_66C4C0 = 0;
    config.gTextY_dword_66C4C4 = 0;
    config.gTextFlags_dword_66C4C8 = 0;

    InitSmallFontTemplateSprite();

    Render_Text_Small_font_468642(&buffer, &config, "i Hello\nwor l d \n1234#9567890\n.@:_!?+-/*{}");

    const SPRT expected[32] =
    {
        { 68759568, 204, 204, 204, 204, 1, 0, 48, 237, 32764, 6, 5 },
        { 68758948, 204, 204, 204, 204, 8, 0, 42, 237, 32764, 6, 5 },
        { 68758968, 204, 204, 204, 204, 14, 0, 24, 237, 32764, 6, 5 },
        { 68758988, 204, 204, 204, 204, 20, 0, 66, 237, 32764, 6, 5 },
        { 68759008, 204, 204, 204, 204, 26, 0, 66, 237, 32764, 6, 5 },
        { 68759028, 204, 204, 204, 204, 32, 0, 84, 237, 32764, 6, 5 },
        { 68759048, 204, 204, 204, 204, 0, 8, 132, 237, 32764, 6, 5 },
        { 68759068, 204, 204, 204, 204, 6, 8, 84, 237, 32764, 6, 5 },
        { 68759088, 204, 204, 204, 204, 12, 8, 102, 237, 32764, 6, 5 },
        { 68759108, 204, 204, 204, 204, 22, 8, 66, 237, 32764, 6, 5 },
        { 68759128, 204, 204, 204, 204, 32, 8, 18, 237, 32764, 6, 5 },
        { 68759148, 204, 204, 204, 204, 0, 16, 6, 232, 32764, 6, 5 },
        { 68759168, 204, 204, 204, 204, 6, 16, 12, 232, 32764, 6, 5 },
        { 68759188, 204, 204, 204, 204, 12, 16, 18, 232, 32764, 6, 5 },
        { 68759208, 204, 204, 204, 204, 18, 16, 24, 232, 32764, 6, 5 },
        { 68759228, 204, 204, 204, 204, 30, 16, 54, 232, 32764, 6, 5 },
        { 68759248, 204, 204, 204, 204, 36, 16, 30, 232, 32764, 6, 5 },
        { 68759268, 204, 204, 204, 204, 42, 16, 36, 232, 32764, 6, 5 },
        { 68759288, 204, 204, 204, 204, 48, 16, 42, 232, 32764, 6, 5 },
        { 68759308, 204, 204, 204, 204, 54, 16, 48, 232, 32764, 6, 5 },
        { 68759328, 204, 204, 204, 204, 60, 16, 54, 232, 32764, 6, 5 },
        { 68759348, 204, 204, 204, 204, 66, 16, 0, 232, 32764, 6, 5 },
        { 68759368, 204, 204, 204, 204, 1, 24, 60, 232, 32764, 6, 5 },
        { 68759388, 204, 204, 204, 204, 5, 24, 72, 232, 32764, 6, 5 },
        { 68759408, 204, 204, 204, 204, 9, 24, 84, 232, 32764, 6, 5 },
        { 68759428, 204, 204, 204, 204, 12, 24, 90, 232, 32764, 6, 5 },
        { 68759448, 204, 204, 204, 204, 18, 24, 96, 232, 32764, 6, 5 },
        { 68759468, 204, 204, 204, 204, 24, 24, 102, 232, 32764, 6, 5 },
        { 68759488, 204, 204, 204, 204, 30, 24, 108, 232, 32764, 6, 5 },
        { 68759508, 204, 204, 204, 204, 36, 24, 114, 232, 32764, 6, 5 },
        { 68759528, 204, 204, 204, 204, 42, 24, 120, 232, 32764, 6, 5 },
        { 68759548, 204, 204, 204, 204, 45, 24, 126, 232, 32764, 6, 5 }
    };

    const SPRT* pExpectedSprt = &expected[0];
    const SPRT* pActualSprt = reinterpret_cast<SPRT*>(backingBuffer);
    int count = 0;
    while (pActualSprt->tag)
    {
        //ASSERT_EQ(pActualSprt->code, pExpectedSprt->code);

        ASSERT_EQ(pActualSprt->r0, pExpectedSprt->r0);
        ASSERT_EQ(pActualSprt->g0, pExpectedSprt->g0);
        ASSERT_EQ(pActualSprt->b0, pExpectedSprt->b0);

        ASSERT_EQ(pActualSprt->x0, pExpectedSprt->x0);
        ASSERT_EQ(pActualSprt->y0, pExpectedSprt->y0);

        ASSERT_EQ(pActualSprt->w, pExpectedSprt->w);
        ASSERT_EQ(pActualSprt->h, pExpectedSprt->h);

        ASSERT_EQ(pActualSprt->u0, pExpectedSprt->u0);
        ASSERT_EQ(pActualSprt->v0, pExpectedSprt->v0);

        ASSERT_EQ(pActualSprt->clut, pExpectedSprt->clut);

        pActualSprt++;
        pExpectedSprt++;
        count++;
    }
    ASSERT_EQ(count, 32);
}

struct UvPair
{
    int s, u, v;

};
std::map<char, UvPair> gUvs;

static void UVCapture()
{
    InitSmallFontTemplateSprite();

    const char* inStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\n.@:_!?+-/*{}";
    const char* inStrIter = inStr;
    while (*inStrIter)
    {
        BYTE backingBuffer[sizeof(SPRT) * 200] = {};
        MenuPrimBuffer buffer;
        buffer.mFreeLocation = backingBuffer;
        buffer.mOt = backingBuffer;
        buffer.mOtEnd = backingBuffer + sizeof(backingBuffer);

        TextConfig config;
        config.gTextX_dword_66C4C0 = 0;
        config.gTextY_dword_66C4C4 = 0;
        config.gTextFlags_dword_66C4C8 = 0;

        char inBuffer[2] = {};
        inBuffer[0] = *inStrIter;
        Render_Text_Large_font_468AAF(&buffer, &config, inBuffer);

        const SPRT* pActualSprt = reinterpret_cast<SPRT*>(backingBuffer);
        if (pActualSprt->tag)
        {
            gUvs[inBuffer[0]] = { pActualSprt->x0, pActualSprt->u0 , pActualSprt->v0 };
        }
        else
        {
            printf("Nothing for %s\n", inBuffer);
        }

        inStrIter++;
    }

    printf("Done\n");

    for (auto& p : gUvs)
    {
        printf("{ '%c', %d, %d, %d },\n", p.first, p.second.s, p.second.u, p.second.v);
    }
    printf("Done\n");

}

void DoMenuTests()
{
    //UVCapture();
   // Test_Render_Text_Large_font_468AAF();
   // Test_Render_Text_Small_font_468642();
}
