#include "stdafx.h"
#include "MgsFunction.hpp"
#include "logger.hpp"
#include "Task.hpp"
#include "Script.hpp"


MGS_VAR(1, 0x9942A8, WORD, byte1_flags_word_9942A8, 0);

MGS_VAR_EXTERN(DWORD, script_cancel_non_zero_dword_7227A0);

void ScriptCpp_ForceLink()
{

}

struct proc_struct_sub;

struct proc_struct
{
    proc_struct* pNext;
    DWORD mNumCommands;
    proc_struct_sub* pCommandsArray;
};

using proc_sub_ptr = int(__cdecl*)(char *);

struct proc_struct_sub
{
    WORD mId;
    WORD mUnknown;
    proc_sub_ptr mCommandFunction;
};

MGS_PTR(1, 0x6BFC6C, proc_struct**, gScriptCmdTable_dword_6BFC6C, 0);

proc_struct_sub *__cdecl Script_GetCommand(WORD cmdToFind)
{
    proc_struct* i = *gScriptCmdTable_dword_6BFC6C;
    while (i)
    {
        for (DWORD j = 0; j<i->mNumCommands; j++) // WARN: Real game does it backwards but can't see why
        {
            if (i->pCommandsArray[j].mId == cmdToFind)
            {
                return &i->pCommandsArray[j];
            }
        }
        i = i->pNext;
    }
    printf("command not found\n");
    return 0;
}
MSG_FUNC_IMPL(0x00409ACC, Script_GetCommand);


int __cdecl Script_InitCommandTable(proc_struct* pCmdTbl)
{
    pCmdTbl->pNext = *gScriptCmdTable_dword_6BFC6C;
    *gScriptCmdTable_dword_6BFC6C = pCmdTbl;
    proc_struct_sub* pItem = pCmdTbl->pCommandsArray;
    if (pCmdTbl->mNumCommands > 0)
    {
        DWORD cmdNum = pCmdTbl->mNumCommands;
        do
        {
            printf("COM %d ADR %X\n", pItem->mId, pItem->mCommandFunction);
            ++pItem;
            --cmdNum;
        } while (cmdNum);
    }
    return 0;
}
MSG_FUNC_IMPL(0x00409A4F, Script_InitCommandTable);

MSG_FUNC_NOT_IMPL(0x00451A5E, int __cdecl(char*), Script_tbl_mesg_sub_451A5E);
MSG_FUNC_NOT_IMPL(0x00451688, int __cdecl(char*), Script_tbl_ntrap_removeQ_451688);
MSG_FUNC_NOT_IMPL(0x00451AC3, int __cdecl(char*), Script_tbl_chara_sub_451AC3);
MSG_FUNC_NOT_IMPL(0x0045151D, int __cdecl(char*), Script_tbl_map_sub_45151D);
MSG_FUNC_NOT_IMPL(0x00451673, int __cdecl(char*), Script_tbl_hzd_related_sub_451673);
MSG_FUNC_NOT_IMPL(0x004512E5, int __cdecl(char*), script_tbl_camera_sub_4512E5);
MSG_FUNC_NOT_IMPL(0x00451239, int __cdecl(char*), Script_tbl_light_sub_451239);
MSG_FUNC_NOT_IMPL(0x00451B0E, int __cdecl(char*), Script_tbl_start_sub_451B0E);
MSG_FUNC_NOT_IMPL(0x00451BBF, int __cdecl(char*), Script_tbl_load_451BBF);
MSG_FUNC_NOT_IMPL(0x00451D5C, int __cdecl(char*), Script_tbl_radio_sub_451D5C);
MSG_FUNC_NOT_IMPL(0x00451F22, int __cdecl(char*), Script_tbl_str_status_sub_451F22);
MSG_FUNC_NOT_IMPL(0x00452064, int __cdecl(char*), Script_tbl_demo_sub_452064);
MSG_FUNC_NOT_IMPL(0x00451778, int __cdecl(char*), Script_tbl_ntrap_451778);
MSG_FUNC_NOT_IMPL(0x004519C7, int __cdecl(char*), Script_tbl_Delay_sub_4519C7);
MSG_FUNC_NOT_IMPL(0x00452132, int __cdecl(char*), Script_tbl_pad_452132);
MSG_FUNC_NOT_IMPL(0x00451F89, int __cdecl(char*), Script_tbl_varsave_sub_451F89);
MSG_FUNC_NOT_IMPL(0x00451FE3, int __cdecl(char*), Script_tbl_system_sub_451FE3);
MSG_FUNC_NOT_IMPL(0x0045219B, int __cdecl(char*), Script_tbl_sound_45219B);
MSG_FUNC_NOT_IMPL(0x004521A7, int __cdecl(char*), Script_tbl_menu_sub_4521A7);
MSG_FUNC_NOT_IMPL(0x004523C7, int __cdecl(char*), Script_Tbl_rand_4523C7);
MSG_FUNC_NOT_IMPL(0x004523E7, int __cdecl(char*), Script_tbl_sub_4523E7);
MSG_FUNC_NOT_IMPL(0x0045256B, int __cdecl(char*), Script_tbl_print_sub_45256B);
MSG_FUNC_NOT_IMPL(0x004525D6, int __cdecl(char*), Script_tbl_jimaku_4525D6);
MGS_ARY(1, 0x66B000, proc_struct_sub, 24, script_funcs_tbl_66B000,
{
    { 0x22FF, 0x0, Script_tbl_mesg_sub_451A5E.Ptr() },
    { 0xD4CB, 0x0, Script_tbl_ntrap_removeQ_451688.Ptr() },
    { 0x9906, 0x0, Script_tbl_chara_sub_451AC3.Ptr() },
    { 0xC091, 0x0, Script_tbl_map_sub_45151D.Ptr() },
    { 0x7D50, 0x0, Script_tbl_hzd_related_sub_451673.Ptr() },
    { 0xEEE9, 0x0, script_tbl_camera_sub_4512E5.Ptr() },
    { 0x306A, 0x0, Script_tbl_light_sub_451239.Ptr() },
    { 0x9A1F, 0x0, Script_tbl_start_sub_451B0E.Ptr() },
    { 0xC8BB, 0x0, Script_tbl_load_451BBF.Ptr() },
    { 0x24E1, 0x0, Script_tbl_radio_sub_451D5C.Ptr() },
    { 0xE43C, 0x0, Script_tbl_str_status_sub_451F22.Ptr() },
    { 0xA242, 0x0, Script_tbl_demo_sub_452064.Ptr() },
    { 0xDBAB, 0x0, Script_tbl_ntrap_451778.Ptr() },
    { 0x430D, 0x0, Script_tbl_Delay_sub_4519C7.Ptr() },
    { 0xCC85, 0x0, Script_tbl_pad_452132.Ptr() },
    { 0x5C9E, 0x0, Script_tbl_varsave_sub_451F89.Ptr() },
    { 0x4AD9, 0x0, Script_tbl_system_sub_451FE3.Ptr() },
    { 0x698D, 0x0, Script_tbl_sound_45219B.Ptr() },
    { 0x226D, 0x0, Script_tbl_menu_sub_4521A7.Ptr() },
    { 0x925E, 0x0, Script_Tbl_rand_4523C7.Ptr() },
    { 0xE257, 0x0, Script_tbl_sub_4523E7.Ptr() },
    { 0xB96E, 0x0, Script_tbl_print_sub_45256B.Ptr() },
    { 0xEC9D, 0x0, Script_tbl_jimaku_4525D6.Ptr() }
});
MGS_ARY(1, 0x66B0B8, proc_struct, 1, gScriptBindFns_66B0B8, { nullptr, 23, script_funcs_tbl_66B000 }); // TODO: Not an array, only done this way so it compiles

MSG_FUNC_NOT_IMPL(0x004525E6, int __cdecl(), Script_binds_init_4525E6);

void CC Script_BindInits_452610()
{
    Script_binds_init_4525E6();
    Script_InitCommandTable(gScriptBindFns_66B0B8);
}
MSG_FUNC_IMPL(0x00452610, Script_BindInits_452610);

MSG_FUNC_NOT_IMPL(0x004090EA, int __cdecl(char*), Script_tbl_if_sub_4090EA);
MSG_FUNC_NOT_IMPL(0x0040915D, int __cdecl(char*), Script_tbl_eval_sub_40915D);
MSG_FUNC_NOT_IMPL(0x00409178, int __cdecl(char*), Script_tbl_unknown_loop_sub_409178);

signed int script_tbl_nop_sub_4091F6(char*)
{
    return 1;
}
//MSG_FUNC_IMPL(0x004091F6, script_tbl_nop_sub_4091F6); // Can't hook because func is too small


MGS_ARY(1, 0x6506E0, proc_struct_sub, 4, gEarlyScriptBinds_Tbl_6506E0,
{
    { 0x000D, 0x0, Script_tbl_if_sub_4090EA.Ptr() },
    { 0x64C0, 0x0, Script_tbl_eval_sub_40915D.Ptr() },
    { 0xCD3A, 0x0, script_tbl_nop_sub_4091F6 },
    { 0x7636, 0x0, Script_tbl_unknown_loop_sub_409178.Ptr() }
});
MGS_ARY(1, 0x650700, proc_struct, 1, gEarlyScriptBinds_650700, { nullptr, 4, gEarlyScriptBinds_Tbl_6506E0 }); // TODO: Not an array, only done this way so it compiles

void __cdecl Script_sub_4091FA()
{
    Script_InitCommandTable(gEarlyScriptBinds_650700);
}
MSG_FUNC_IMPL(0x004091FA, Script_sub_4091FA);

MSG_FUNC_NOT_IMPL(0x00409CAF, signed int __cdecl(BYTE* pScriptBytes, int numberOfArguments), Script_Run);

struct GCL_ProcInfo
{
    WORD mId;
    WORD mOffset;
};

MGS_PTR(1, 0x006BFC60, GCL_ProcInfo**, gProcInfos, nullptr);
MGS_PTR(1, 0x006BFC64, BYTE**, dword_6BFC64, 0);

static DWORD ToDWORD(const BYTE* ptr)
{
    return (ptr[3]) | (ptr[2] << 8) | (ptr[1] << 16) | (ptr[0] << 24);
}

BYTE* __cdecl Script_InitProcTables_sub_409C87(BYTE* pScript)
{
    // pScript skips the first 4 bytes of the script
    for (;;)
    {
        // Reverse the GCL_ProcInfo data
        std::swap(pScript[0], pScript[1]);
        std::swap(pScript[2], pScript[3]);
        pScript += 4;

        // 4 NULL bytes is the end of the table
        if (pScript[0] == 0 && pScript[1] == 0 && pScript[2] == 0 && pScript[3] == 0)
        {
            break;
        }
    }

    return pScript + 4;
}
MSG_FUNC_IMPL(0x00409C87, Script_InitProcTables_sub_409C87);

MGS_PTR(1, 0x6BFC68, BYTE**, gScriptMainProc_dword_6BFC68, 0);

MSG_FUNC_NOT_IMPL(0x45A6F6, int __cdecl(int a1, void* a2), sub_45A6F6);

int __cdecl Script_Init_sub_409C19(BYTE* pScript)
{
    DWORD offset = ToDWORD(pScript);
    *gProcInfos = reinterpret_cast<GCL_ProcInfo*>(pScript + 4);
    *dword_6BFC64 = Script_InitProcTables_sub_409C87(pScript + 4);

    *gScriptMainProc_dword_6BFC68 = (pScript + 4 + offset + 4);

    DWORD mainScriptLen = ToDWORD((*gScriptMainProc_dword_6BFC68)-4);
    BYTE* pEndOfScriptData = (*gScriptMainProc_dword_6BFC68) + mainScriptLen + 4;

    sub_45A6F6(2, pEndOfScriptData);

    return 0;
}
MSG_FUNC_IMPL(0x00409C19, Script_Init_sub_409C19);


BYTE* __cdecl Script_FindProc(WORD procId)
{
    for (GCL_ProcInfo* pProcInfo = *gProcInfos; pProcInfo->mId; ++pProcInfo)
    {
        if (pProcInfo->mId == procId)
        {
            return (*dword_6BFC64) + pProcInfo->mOffset;
        }
    }
    printf("PROC %X NOT FOUND\n", procId);
    return nullptr;
}
MSG_FUNC_IMPL(0x00409B1D, Script_FindProc);

signed int __cdecl Script_Run_Proc_sub_409B03(WORD procId, int numArgs)
{
    BYTE* pScriptProc = Script_FindProc(procId);
    return Script_Run(pScriptProc + 3, numArgs);
}
MSG_FUNC_IMPL(0x409B03, Script_Run_Proc_sub_409B03);

signed int __cdecl Script_ProcCancelOrRun(WORD id, int numArgs)
{
    if (script_cancel_non_zero_dword_7227A0 || BYTE1(byte1_flags_word_9942A8) & 0x20)
    {
        printf("proc %d cancel\n", id);
        return 0;
    }
    else
    {
        // stage\init\scenerio.gcx @ 0x5FA
        // 40 00 08 70 04 21 51 00 00 40 08 
        // 24 70 04 C8 CF 00 60 00 12 64 C0
        BYTE* scriptProc = Script_FindProc(id); // For id = 26069 / 0x000065d5
        return Script_Run(scriptProc + 3, numArgs);
    }
}
MSG_FUNC_IMPL(0x00409B53, Script_ProcCancelOrRun);


int __cdecl Script_Operator_Evaluate(int operation, int v1, int v2)
{
    int result = 0;
    switch (operation)
    {
    case 1:
        result = -v2;
        break;
    case 2:
        result = v2 == 0;
        break;
    case 3:
        result = ~v2;
        break;
    case 4:
        result = v2 + v1;
        break;
    case 5:
        result = v1 - v2;
        break;
    case 6:
        result = v2 * v1;
        break;
    case 7:
        result = v1 / v2;
        break;
    case 8:
        result = v1 % v2;
        break;
    case 9:
        result = v1 == v2;
        break;
    case 10:
        result = v1 != v2;
        break;
    case 11:
        result = v1 < v2;
        break;
    case 12:
        result = v1 <= v2;
        break;
    case 13:
        result = v1 > v2;
        break;
    case 14:
        result = v1 >= v2;
        break;
    case 15:
        result = v2 | v1;
        break;
    case 16:
        result = v2 & v1;
        break;
    case 17:
        result = v2 ^ v1;
        break;
    case 18:
        result = v1 >= 0 && v2 >= 0; // TODO Check this is correct __PAIR__(v2, v1) != 0;
        printf("Check me\n");
        break;
    case 19:
        result = v1 && v2;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
MSG_FUNC_IMPL(0x00409E7C, Script_Operator_Evaluate);