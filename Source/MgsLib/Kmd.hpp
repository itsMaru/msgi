#pragma once

#include "MgsFunction.hpp"
#include "Psx.hpp"

void ForceLinkKmdCpp();

struct KmdHeader;

struct Prim_unknown_0x48
{
    PSX_MATRIX field_0_matrix;
    void* field_20;
    KmdHeader* field_24_pKmdFileData;
    DWORD field_28_flags_or_type;
    WORD field_2C_index;
    WORD field_2E_UnknownOrNumFaces;
    WORD field_30_size;
    WORD field_32;
    SVECTOR* field_34_pVec; // Or 2 words?
    DWORD field_38_size24b;
    DWORD field_3C;
    BYTE* field_40_pDataStart[2];
};
MGS_ASSERT_SIZEOF(Prim_unknown_0x48, 0x48);

struct Prim_unknown_0x54
{
    PSX_MATRIX field_0_matrix;
    void* field_20;
    KmdHeader* field_24_pKmdFileData;
    WORD field_28_flags_or_type;
    WORD field_2A_num_prims;
    WORD field_2C_gv_index;
    WORD field_2E_UnknownOrNumFaces;
    WORD field_30_prim_size;
    WORD field_32;
    WORD field_34; // Or 2 words?
    WORD field_36;
    DWORD field_38_size24b;
    DWORD field_3C;
    BYTE* field_40_pDataStart[2];
    // ^^^ BASE

    DWORD field_48;
    DWORD field_4C;
    DWORD field_50;
};
MGS_ASSERT_SIZEOF(Prim_unknown_0x54, 0x54);
