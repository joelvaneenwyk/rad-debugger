// Copyright (c) 2024 Epic Games Tools
// Licensed under the MIT license (https://opensource.org/license/mit/)

//- GENERATED CODE

internal String8
cv_string_from_numeric_kind(CV_NumericKind v)
{
String8 result = str8_lit("<Unknown CV_NumericKind>");
switch(v)
{
default:{}break;
case CV_NumericKind_CHAR:{result = str8_lit("CHAR");}break;
case CV_NumericKind_SHORT:{result = str8_lit("SHORT");}break;
case CV_NumericKind_USHORT:{result = str8_lit("USHORT");}break;
case CV_NumericKind_LONG:{result = str8_lit("LONG");}break;
case CV_NumericKind_ULONG:{result = str8_lit("ULONG");}break;
case CV_NumericKind_FLOAT32:{result = str8_lit("FLOAT32");}break;
case CV_NumericKind_FLOAT64:{result = str8_lit("FLOAT64");}break;
case CV_NumericKind_FLOAT80:{result = str8_lit("FLOAT80");}break;
case CV_NumericKind_FLOAT128:{result = str8_lit("FLOAT128");}break;
case CV_NumericKind_QUADWORD:{result = str8_lit("QUADWORD");}break;
case CV_NumericKind_UQUADWORD:{result = str8_lit("UQUADWORD");}break;
case CV_NumericKind_FLOAT48:{result = str8_lit("FLOAT48");}break;
case CV_NumericKind_COMPLEX32:{result = str8_lit("COMPLEX32");}break;
case CV_NumericKind_COMPLEX64:{result = str8_lit("COMPLEX64");}break;
case CV_NumericKind_COMPLEX80:{result = str8_lit("COMPLEX80");}break;
case CV_NumericKind_COMPLEX128:{result = str8_lit("COMPLEX128");}break;
case CV_NumericKind_VARSTRING:{result = str8_lit("VARSTRING");}break;
case CV_NumericKind_OCTWORD:{result = str8_lit("OCTWORD");}break;
case CV_NumericKind_UOCTWORD:{result = str8_lit("UOCTWORD");}break;
case CV_NumericKind_DECIMAL:{result = str8_lit("DECIMAL");}break;
case CV_NumericKind_DATE:{result = str8_lit("DATE");}break;
case CV_NumericKind_UTF8STRING:{result = str8_lit("UTF8STRING");}break;
case CV_NumericKind_FLOAT16:{result = str8_lit("FLOAT16");}break;
}
return result;
}

internal String8
cv_string_from_arch(CV_Arch v)
{
String8 result = str8_lit("<Unknown CV_Arch>");
switch(v)
{
default:{}break;
case CV_Arch_8080:{result = str8_lit("8080");}break;
case CV_Arch_8086:{result = str8_lit("8086");}break;
case CV_Arch_80286:{result = str8_lit("80286");}break;
case CV_Arch_80386:{result = str8_lit("80386");}break;
case CV_Arch_80486:{result = str8_lit("80486");}break;
case CV_Arch_PENTIUM:{result = str8_lit("PENTIUM");}break;
case CV_Arch_PENTIUMII:{result = str8_lit("PENTIUMII");}break;
case CV_Arch_PENTIUMIII:{result = str8_lit("PENTIUMIII");}break;
case CV_Arch_MIPS:{result = str8_lit("MIPS");}break;
case CV_Arch_MIPS16:{result = str8_lit("MIPS16");}break;
case CV_Arch_MIPS32:{result = str8_lit("MIPS32");}break;
case CV_Arch_MIPS64:{result = str8_lit("MIPS64");}break;
case CV_Arch_MIPSI:{result = str8_lit("MIPSI");}break;
case CV_Arch_MIPSII:{result = str8_lit("MIPSII");}break;
case CV_Arch_MIPSIII:{result = str8_lit("MIPSIII");}break;
case CV_Arch_MIPSIV:{result = str8_lit("MIPSIV");}break;
case CV_Arch_MIPSV:{result = str8_lit("MIPSV");}break;
case CV_Arch_M68000:{result = str8_lit("M68000");}break;
case CV_Arch_M68010:{result = str8_lit("M68010");}break;
case CV_Arch_M68020:{result = str8_lit("M68020");}break;
case CV_Arch_M68030:{result = str8_lit("M68030");}break;
case CV_Arch_M68040:{result = str8_lit("M68040");}break;
case CV_Arch_ALPHA:{result = str8_lit("ALPHA");}break;
case CV_Arch_ALPHA_21164:{result = str8_lit("ALPHA_21164");}break;
case CV_Arch_ALPHA_21164A:{result = str8_lit("ALPHA_21164A");}break;
case CV_Arch_ALPHA_21264:{result = str8_lit("ALPHA_21264");}break;
case CV_Arch_ALPHA_21364:{result = str8_lit("ALPHA_21364");}break;
case CV_Arch_PPC601:{result = str8_lit("PPC601");}break;
case CV_Arch_PPC603:{result = str8_lit("PPC603");}break;
case CV_Arch_PPC604:{result = str8_lit("PPC604");}break;
case CV_Arch_PPC620:{result = str8_lit("PPC620");}break;
case CV_Arch_PPCFP:{result = str8_lit("PPCFP");}break;
case CV_Arch_PPCBE:{result = str8_lit("PPCBE");}break;
case CV_Arch_SH3:{result = str8_lit("SH3");}break;
case CV_Arch_SH3E:{result = str8_lit("SH3E");}break;
case CV_Arch_SH3DSP:{result = str8_lit("SH3DSP");}break;
case CV_Arch_SH4:{result = str8_lit("SH4");}break;
case CV_Arch_SHMEDIA:{result = str8_lit("SHMEDIA");}break;
case CV_Arch_ARM3:{result = str8_lit("ARM3");}break;
case CV_Arch_ARM4:{result = str8_lit("ARM4");}break;
case CV_Arch_ARM4T:{result = str8_lit("ARM4T");}break;
case CV_Arch_ARM5:{result = str8_lit("ARM5");}break;
case CV_Arch_ARM5T:{result = str8_lit("ARM5T");}break;
case CV_Arch_ARM6:{result = str8_lit("ARM6");}break;
case CV_Arch_ARM_XMAC:{result = str8_lit("ARM_XMAC");}break;
case CV_Arch_ARM_WMMX:{result = str8_lit("ARM_WMMX");}break;
case CV_Arch_ARM7:{result = str8_lit("ARM7");}break;
case CV_Arch_OMNI:{result = str8_lit("OMNI");}break;
case CV_Arch_IA64_1:{result = str8_lit("IA64_1");}break;
case CV_Arch_IA64_2:{result = str8_lit("IA64_2");}break;
case CV_Arch_CEE:{result = str8_lit("CEE");}break;
case CV_Arch_AM33:{result = str8_lit("AM33");}break;
case CV_Arch_M32R:{result = str8_lit("M32R");}break;
case CV_Arch_TRICORE:{result = str8_lit("TRICORE");}break;
case CV_Arch_X64:{result = str8_lit("X64");}break;
case CV_Arch_EBC:{result = str8_lit("EBC");}break;
case CV_Arch_THUMB:{result = str8_lit("THUMB");}break;
case CV_Arch_ARMNT:{result = str8_lit("ARMNT");}break;
case CV_Arch_ARM64:{result = str8_lit("ARM64");}break;
case CV_Arch_D3D11_SHADER:{result = str8_lit("D3D11_SHADER");}break;
}
return result;
}

internal String8
cv_string_from_sym_kind(CV_SymKind v)
{
String8 result = str8_lit("<Unknown CV_SymKind>");
switch(v)
{
default:{}break;
case CV_SymKind_COMPILE:{result = str8_lit("COMPILE");}break;
case CV_SymKind_REGISTER_16t:{result = str8_lit("REGISTER_16t");}break;
case CV_SymKind_CONSTANT_16t:{result = str8_lit("CONSTANT_16t");}break;
case CV_SymKind_UDT_16t:{result = str8_lit("UDT_16t");}break;
case CV_SymKind_SSEARCH:{result = str8_lit("SSEARCH");}break;
case CV_SymKind_END:{result = str8_lit("END");}break;
case CV_SymKind_SKIP:{result = str8_lit("SKIP");}break;
case CV_SymKind_CVRESERVE:{result = str8_lit("CVRESERVE");}break;
case CV_SymKind_OBJNAME_ST:{result = str8_lit("OBJNAME_ST");}break;
case CV_SymKind_ENDARG:{result = str8_lit("ENDARG");}break;
case CV_SymKind_COBOLUDT_16t:{result = str8_lit("COBOLUDT_16t");}break;
case CV_SymKind_MANYREG_16t:{result = str8_lit("MANYREG_16t");}break;
case CV_SymKind_RETURN:{result = str8_lit("RETURN");}break;
case CV_SymKind_ENTRYTHIS:{result = str8_lit("ENTRYTHIS");}break;
case CV_SymKind_BPREL16:{result = str8_lit("BPREL16");}break;
case CV_SymKind_LDATA16:{result = str8_lit("LDATA16");}break;
case CV_SymKind_GDATA16:{result = str8_lit("GDATA16");}break;
case CV_SymKind_PUB16:{result = str8_lit("PUB16");}break;
case CV_SymKind_LPROC16:{result = str8_lit("LPROC16");}break;
case CV_SymKind_GPROC16:{result = str8_lit("GPROC16");}break;
case CV_SymKind_THUNK16:{result = str8_lit("THUNK16");}break;
case CV_SymKind_BLOCK16:{result = str8_lit("BLOCK16");}break;
case CV_SymKind_WITH16:{result = str8_lit("WITH16");}break;
case CV_SymKind_LABEL16:{result = str8_lit("LABEL16");}break;
case CV_SymKind_CEXMODEL16:{result = str8_lit("CEXMODEL16");}break;
case CV_SymKind_VFTABLE16:{result = str8_lit("VFTABLE16");}break;
case CV_SymKind_REGREL16:{result = str8_lit("REGREL16");}break;
case CV_SymKind_BPREL32_16t:{result = str8_lit("BPREL32_16t");}break;
case CV_SymKind_LDATA32_16t:{result = str8_lit("LDATA32_16t");}break;
case CV_SymKind_GDATA32_16t:{result = str8_lit("GDATA32_16t");}break;
case CV_SymKind_PUB32_16t:{result = str8_lit("PUB32_16t");}break;
case CV_SymKind_LPROC32_16t:{result = str8_lit("LPROC32_16t");}break;
case CV_SymKind_GPROC32_16t:{result = str8_lit("GPROC32_16t");}break;
case CV_SymKind_THUNK32_ST:{result = str8_lit("THUNK32_ST");}break;
case CV_SymKind_BLOCK32_ST:{result = str8_lit("BLOCK32_ST");}break;
case CV_SymKind_WITH32_ST:{result = str8_lit("WITH32_ST");}break;
case CV_SymKind_LABEL32_ST:{result = str8_lit("LABEL32_ST");}break;
case CV_SymKind_CEXMODEL32:{result = str8_lit("CEXMODEL32");}break;
case CV_SymKind_VFTABLE32_16t:{result = str8_lit("VFTABLE32_16t");}break;
case CV_SymKind_REGREL32_16t:{result = str8_lit("REGREL32_16t");}break;
case CV_SymKind_LTHREAD32_16t:{result = str8_lit("LTHREAD32_16t");}break;
case CV_SymKind_GTHREAD32_16t:{result = str8_lit("GTHREAD32_16t");}break;
case CV_SymKind_SLINK32:{result = str8_lit("SLINK32");}break;
case CV_SymKind_LPROCMIPS_16t:{result = str8_lit("LPROCMIPS_16t");}break;
case CV_SymKind_GPROCMIPS_16t:{result = str8_lit("GPROCMIPS_16t");}break;
case CV_SymKind_PROCREF_ST:{result = str8_lit("PROCREF_ST");}break;
case CV_SymKind_DATAREF_ST:{result = str8_lit("DATAREF_ST");}break;
case CV_SymKind_ALIGN:{result = str8_lit("ALIGN");}break;
case CV_SymKind_LPROCREF_ST:{result = str8_lit("LPROCREF_ST");}break;
case CV_SymKind_OEM:{result = str8_lit("OEM");}break;
case CV_SymKind_TI16_MAX:{result = str8_lit("TI16_MAX");}break;
case CV_SymKind_CONSTANT_ST:{result = str8_lit("CONSTANT_ST");}break;
case CV_SymKind_UDT_ST:{result = str8_lit("UDT_ST");}break;
case CV_SymKind_COBOLUDT_ST:{result = str8_lit("COBOLUDT_ST");}break;
case CV_SymKind_MANYREG_ST:{result = str8_lit("MANYREG_ST");}break;
case CV_SymKind_BPREL32_ST:{result = str8_lit("BPREL32_ST");}break;
case CV_SymKind_LDATA32_ST:{result = str8_lit("LDATA32_ST");}break;
case CV_SymKind_GDATA32_ST:{result = str8_lit("GDATA32_ST");}break;
case CV_SymKind_PUB32_ST:{result = str8_lit("PUB32_ST");}break;
case CV_SymKind_LPROC32_ST:{result = str8_lit("LPROC32_ST");}break;
case CV_SymKind_GPROC32_ST:{result = str8_lit("GPROC32_ST");}break;
case CV_SymKind_VFTABLE32:{result = str8_lit("VFTABLE32");}break;
case CV_SymKind_REGREL32_ST:{result = str8_lit("REGREL32_ST");}break;
case CV_SymKind_LTHREAD32_ST:{result = str8_lit("LTHREAD32_ST");}break;
case CV_SymKind_GTHREAD32_ST:{result = str8_lit("GTHREAD32_ST");}break;
case CV_SymKind_LPROCMIPS_ST:{result = str8_lit("LPROCMIPS_ST");}break;
case CV_SymKind_GPROCMIPS_ST:{result = str8_lit("GPROCMIPS_ST");}break;
case CV_SymKind_FRAMEPROC:{result = str8_lit("FRAMEPROC");}break;
case CV_SymKind_COMPILE2_ST:{result = str8_lit("COMPILE2_ST");}break;
case CV_SymKind_MANYREG2_ST:{result = str8_lit("MANYREG2_ST");}break;
case CV_SymKind_LPROCIA64_ST:{result = str8_lit("LPROCIA64_ST");}break;
case CV_SymKind_GPROCIA64_ST:{result = str8_lit("GPROCIA64_ST");}break;
case CV_SymKind_LOCALSLOT_ST:{result = str8_lit("LOCALSLOT_ST");}break;
case CV_SymKind_PARAMSLOT_ST:{result = str8_lit("PARAMSLOT_ST");}break;
case CV_SymKind_ANNOTATION:{result = str8_lit("ANNOTATION");}break;
case CV_SymKind_GMANPROC_ST:{result = str8_lit("GMANPROC_ST");}break;
case CV_SymKind_LMANPROC_ST:{result = str8_lit("LMANPROC_ST");}break;
case CV_SymKind_RESERVED1:{result = str8_lit("RESERVED1");}break;
case CV_SymKind_RESERVED2:{result = str8_lit("RESERVED2");}break;
case CV_SymKind_RESERVED3:{result = str8_lit("RESERVED3");}break;
case CV_SymKind_RESERVED4:{result = str8_lit("RESERVED4");}break;
case CV_SymKind_LMANDATA_ST:{result = str8_lit("LMANDATA_ST");}break;
case CV_SymKind_GMANDATA_ST:{result = str8_lit("GMANDATA_ST");}break;
case CV_SymKind_MANFRAMEREL_ST:{result = str8_lit("MANFRAMEREL_ST");}break;
case CV_SymKind_MANREGISTER_ST:{result = str8_lit("MANREGISTER_ST");}break;
case CV_SymKind_MANSLOT_ST:{result = str8_lit("MANSLOT_ST");}break;
case CV_SymKind_MANMANYREG_ST:{result = str8_lit("MANMANYREG_ST");}break;
case CV_SymKind_MANREGREL_ST:{result = str8_lit("MANREGREL_ST");}break;
case CV_SymKind_MANMANYREG2_ST:{result = str8_lit("MANMANYREG2_ST");}break;
case CV_SymKind_MANTYPREF:{result = str8_lit("MANTYPREF");}break;
case CV_SymKind_UNAMESPACE_ST:{result = str8_lit("UNAMESPACE_ST");}break;
case CV_SymKind_ST_MAX:{result = str8_lit("ST_MAX");}break;
case CV_SymKind_OBJNAME:{result = str8_lit("OBJNAME");}break;
case CV_SymKind_THUNK32:{result = str8_lit("THUNK32");}break;
case CV_SymKind_BLOCK32:{result = str8_lit("BLOCK32");}break;
case CV_SymKind_WITH32:{result = str8_lit("WITH32");}break;
case CV_SymKind_LABEL32:{result = str8_lit("LABEL32");}break;
case CV_SymKind_REGISTER:{result = str8_lit("REGISTER");}break;
case CV_SymKind_CONSTANT:{result = str8_lit("CONSTANT");}break;
case CV_SymKind_UDT:{result = str8_lit("UDT");}break;
case CV_SymKind_COBOLUDT:{result = str8_lit("COBOLUDT");}break;
case CV_SymKind_MANYREG:{result = str8_lit("MANYREG");}break;
case CV_SymKind_BPREL32:{result = str8_lit("BPREL32");}break;
case CV_SymKind_LDATA32:{result = str8_lit("LDATA32");}break;
case CV_SymKind_GDATA32:{result = str8_lit("GDATA32");}break;
case CV_SymKind_PUB32:{result = str8_lit("PUB32");}break;
case CV_SymKind_LPROC32:{result = str8_lit("LPROC32");}break;
case CV_SymKind_GPROC32:{result = str8_lit("GPROC32");}break;
case CV_SymKind_REGREL32:{result = str8_lit("REGREL32");}break;
case CV_SymKind_LTHREAD32:{result = str8_lit("LTHREAD32");}break;
case CV_SymKind_GTHREAD32:{result = str8_lit("GTHREAD32");}break;
case CV_SymKind_LPROCMIPS:{result = str8_lit("LPROCMIPS");}break;
case CV_SymKind_GPROCMIPS:{result = str8_lit("GPROCMIPS");}break;
case CV_SymKind_COMPILE2:{result = str8_lit("COMPILE2");}break;
case CV_SymKind_MANYREG2:{result = str8_lit("MANYREG2");}break;
case CV_SymKind_LPROCIA64:{result = str8_lit("LPROCIA64");}break;
case CV_SymKind_GPROCIA64:{result = str8_lit("GPROCIA64");}break;
case CV_SymKind_LOCALSLOT:{result = str8_lit("LOCALSLOT");}break;
case CV_SymKind_PARAMSLOT:{result = str8_lit("PARAMSLOT");}break;
case CV_SymKind_LMANDATA:{result = str8_lit("LMANDATA");}break;
case CV_SymKind_GMANDATA:{result = str8_lit("GMANDATA");}break;
case CV_SymKind_MANFRAMEREL:{result = str8_lit("MANFRAMEREL");}break;
case CV_SymKind_MANREGISTER:{result = str8_lit("MANREGISTER");}break;
case CV_SymKind_MANSLOT:{result = str8_lit("MANSLOT");}break;
case CV_SymKind_MANMANYREG:{result = str8_lit("MANMANYREG");}break;
case CV_SymKind_MANREGREL:{result = str8_lit("MANREGREL");}break;
case CV_SymKind_MANMANYREG2:{result = str8_lit("MANMANYREG2");}break;
case CV_SymKind_UNAMESPACE:{result = str8_lit("UNAMESPACE");}break;
case CV_SymKind_PROCREF:{result = str8_lit("PROCREF");}break;
case CV_SymKind_DATAREF:{result = str8_lit("DATAREF");}break;
case CV_SymKind_LPROCREF:{result = str8_lit("LPROCREF");}break;
case CV_SymKind_ANNOTATIONREF:{result = str8_lit("ANNOTATIONREF");}break;
case CV_SymKind_TOKENREF:{result = str8_lit("TOKENREF");}break;
case CV_SymKind_GMANPROC:{result = str8_lit("GMANPROC");}break;
case CV_SymKind_LMANPROC:{result = str8_lit("LMANPROC");}break;
case CV_SymKind_TRAMPOLINE:{result = str8_lit("TRAMPOLINE");}break;
case CV_SymKind_MANCONSTANT:{result = str8_lit("MANCONSTANT");}break;
case CV_SymKind_ATTR_FRAMEREL:{result = str8_lit("ATTR_FRAMEREL");}break;
case CV_SymKind_ATTR_REGISTER:{result = str8_lit("ATTR_REGISTER");}break;
case CV_SymKind_ATTR_REGREL:{result = str8_lit("ATTR_REGREL");}break;
case CV_SymKind_ATTR_MANYREG:{result = str8_lit("ATTR_MANYREG");}break;
case CV_SymKind_SEPCODE:{result = str8_lit("SEPCODE");}break;
case CV_SymKind_DEFRANGE_2005:{result = str8_lit("DEFRANGE_2005");}break;
case CV_SymKind_DEFRANGE2_2005:{result = str8_lit("DEFRANGE2_2005");}break;
case CV_SymKind_SECTION:{result = str8_lit("SECTION");}break;
case CV_SymKind_COFFGROUP:{result = str8_lit("COFFGROUP");}break;
case CV_SymKind_EXPORT:{result = str8_lit("EXPORT");}break;
case CV_SymKind_CALLSITEINFO:{result = str8_lit("CALLSITEINFO");}break;
case CV_SymKind_FRAMECOOKIE:{result = str8_lit("FRAMECOOKIE");}break;
case CV_SymKind_DISCARDED:{result = str8_lit("DISCARDED");}break;
case CV_SymKind_COMPILE3:{result = str8_lit("COMPILE3");}break;
case CV_SymKind_ENVBLOCK:{result = str8_lit("ENVBLOCK");}break;
case CV_SymKind_LOCAL:{result = str8_lit("LOCAL");}break;
case CV_SymKind_DEFRANGE:{result = str8_lit("DEFRANGE");}break;
case CV_SymKind_DEFRANGE_SUBFIELD:{result = str8_lit("DEFRANGE_SUBFIELD");}break;
case CV_SymKind_DEFRANGE_REGISTER:{result = str8_lit("DEFRANGE_REGISTER");}break;
case CV_SymKind_DEFRANGE_FRAMEPOINTER_REL:{result = str8_lit("DEFRANGE_FRAMEPOINTER_REL");}break;
case CV_SymKind_DEFRANGE_SUBFIELD_REGISTER:{result = str8_lit("DEFRANGE_SUBFIELD_REGISTER");}break;
case CV_SymKind_DEFRANGE_FRAMEPOINTER_REL_FULL_SCOPE:{result = str8_lit("DEFRANGE_FRAMEPOINTER_REL_FULL_SCOPE");}break;
case CV_SymKind_DEFRANGE_REGISTER_REL:{result = str8_lit("DEFRANGE_REGISTER_REL");}break;
case CV_SymKind_LPROC32_ID:{result = str8_lit("LPROC32_ID");}break;
case CV_SymKind_GPROC32_ID:{result = str8_lit("GPROC32_ID");}break;
case CV_SymKind_LPROCMIPS_ID:{result = str8_lit("LPROCMIPS_ID");}break;
case CV_SymKind_GPROCMIPS_ID:{result = str8_lit("GPROCMIPS_ID");}break;
case CV_SymKind_LPROCIA64_ID:{result = str8_lit("LPROCIA64_ID");}break;
case CV_SymKind_GPROCIA64_ID:{result = str8_lit("GPROCIA64_ID");}break;
case CV_SymKind_BUILDINFO:{result = str8_lit("BUILDINFO");}break;
case CV_SymKind_INLINESITE:{result = str8_lit("INLINESITE");}break;
case CV_SymKind_INLINESITE_END:{result = str8_lit("INLINESITE_END");}break;
case CV_SymKind_PROC_ID_END:{result = str8_lit("PROC_ID_END");}break;
case CV_SymKind_DEFRANGE_HLSL:{result = str8_lit("DEFRANGE_HLSL");}break;
case CV_SymKind_GDATA_HLSL:{result = str8_lit("GDATA_HLSL");}break;
case CV_SymKind_LDATA_HLSL:{result = str8_lit("LDATA_HLSL");}break;
case CV_SymKind_FILESTATIC:{result = str8_lit("FILESTATIC");}break;
case CV_SymKind_LPROC32_DPC:{result = str8_lit("LPROC32_DPC");}break;
case CV_SymKind_LPROC32_DPC_ID:{result = str8_lit("LPROC32_DPC_ID");}break;
case CV_SymKind_DEFRANGE_DPC_PTR_TAG:{result = str8_lit("DEFRANGE_DPC_PTR_TAG");}break;
case CV_SymKind_DPC_SYM_TAG_MAP:{result = str8_lit("DPC_SYM_TAG_MAP");}break;
case CV_SymKind_ARMSWITCHTABLE:{result = str8_lit("ARMSWITCHTABLE");}break;
case CV_SymKind_CALLEES:{result = str8_lit("CALLEES");}break;
case CV_SymKind_CALLERS:{result = str8_lit("CALLERS");}break;
case CV_SymKind_POGODATA:{result = str8_lit("POGODATA");}break;
case CV_SymKind_INLINESITE2:{result = str8_lit("INLINESITE2");}break;
case CV_SymKind_HEAPALLOCSITE:{result = str8_lit("HEAPALLOCSITE");}break;
case CV_SymKind_MOD_TYPEREF:{result = str8_lit("MOD_TYPEREF");}break;
case CV_SymKind_REF_MINIPDB:{result = str8_lit("REF_MINIPDB");}break;
case CV_SymKind_PDBMAP:{result = str8_lit("PDBMAP");}break;
case CV_SymKind_GDATA_HLSL32:{result = str8_lit("GDATA_HLSL32");}break;
case CV_SymKind_LDATA_HLSL32:{result = str8_lit("LDATA_HLSL32");}break;
case CV_SymKind_GDATA_HLSL32_EX:{result = str8_lit("GDATA_HLSL32_EX");}break;
case CV_SymKind_LDATA_HLSL32_EX:{result = str8_lit("LDATA_HLSL32_EX");}break;
case CV_SymKind_FASTLINK:{result = str8_lit("FASTLINK");}break;
case CV_SymKind_INLINEES:{result = str8_lit("INLINEES");}break;
}
return result;
}

internal String8
cv_string_from_basic_type(CV_BasicType v)
{
String8 result = str8_lit("<Unknown CV_BasicType>");
switch(v)
{
default:{}break;
case CV_BasicType_NOTYPE:{result = str8_lit("NOTYPE");}break;
case CV_BasicType_ABS:{result = str8_lit("ABS");}break;
case CV_BasicType_SEGMENT:{result = str8_lit("SEGMENT");}break;
case CV_BasicType_VOID:{result = str8_lit("VOID");}break;
case CV_BasicType_CURRENCY:{result = str8_lit("CURRENCY");}break;
case CV_BasicType_NBASICSTR:{result = str8_lit("NBASICSTR");}break;
case CV_BasicType_FBASICSTR:{result = str8_lit("FBASICSTR");}break;
case CV_BasicType_NOTTRANS:{result = str8_lit("NOTTRANS");}break;
case CV_BasicType_HRESULT:{result = str8_lit("HRESULT");}break;
case CV_BasicType_CHAR:{result = str8_lit("CHAR");}break;
case CV_BasicType_SHORT:{result = str8_lit("SHORT");}break;
case CV_BasicType_LONG:{result = str8_lit("LONG");}break;
case CV_BasicType_QUAD:{result = str8_lit("QUAD");}break;
case CV_BasicType_OCT:{result = str8_lit("OCT");}break;
case CV_BasicType_UCHAR:{result = str8_lit("UCHAR");}break;
case CV_BasicType_USHORT:{result = str8_lit("USHORT");}break;
case CV_BasicType_ULONG:{result = str8_lit("ULONG");}break;
case CV_BasicType_UQUAD:{result = str8_lit("UQUAD");}break;
case CV_BasicType_UOCT:{result = str8_lit("UOCT");}break;
case CV_BasicType_BOOL8:{result = str8_lit("BOOL8");}break;
case CV_BasicType_BOOL16:{result = str8_lit("BOOL16");}break;
case CV_BasicType_BOOL32:{result = str8_lit("BOOL32");}break;
case CV_BasicType_BOOL64:{result = str8_lit("BOOL64");}break;
case CV_BasicType_FLOAT32:{result = str8_lit("FLOAT32");}break;
case CV_BasicType_FLOAT64:{result = str8_lit("FLOAT64");}break;
case CV_BasicType_FLOAT80:{result = str8_lit("FLOAT80");}break;
case CV_BasicType_FLOAT128:{result = str8_lit("FLOAT128");}break;
case CV_BasicType_FLOAT48:{result = str8_lit("FLOAT48");}break;
case CV_BasicType_FLOAT32PP:{result = str8_lit("FLOAT32PP");}break;
case CV_BasicType_FLOAT16:{result = str8_lit("FLOAT16");}break;
case CV_BasicType_COMPLEX32:{result = str8_lit("COMPLEX32");}break;
case CV_BasicType_COMPLEX64:{result = str8_lit("COMPLEX64");}break;
case CV_BasicType_COMPLEX80:{result = str8_lit("COMPLEX80");}break;
case CV_BasicType_COMPLEX128:{result = str8_lit("COMPLEX128");}break;
case CV_BasicType_BIT:{result = str8_lit("BIT");}break;
case CV_BasicType_PASCHAR:{result = str8_lit("PASCHAR");}break;
case CV_BasicType_BOOL32FF:{result = str8_lit("BOOL32FF");}break;
case CV_BasicType_INT8:{result = str8_lit("INT8");}break;
case CV_BasicType_UINT8:{result = str8_lit("UINT8");}break;
case CV_BasicType_RCHAR:{result = str8_lit("RCHAR");}break;
case CV_BasicType_WCHAR:{result = str8_lit("WCHAR");}break;
case CV_BasicType_INT16:{result = str8_lit("INT16");}break;
case CV_BasicType_UINT16:{result = str8_lit("UINT16");}break;
case CV_BasicType_INT32:{result = str8_lit("INT32");}break;
case CV_BasicType_UINT32:{result = str8_lit("UINT32");}break;
case CV_BasicType_INT64:{result = str8_lit("INT64");}break;
case CV_BasicType_UINT64:{result = str8_lit("UINT64");}break;
case CV_BasicType_INT128:{result = str8_lit("INT128");}break;
case CV_BasicType_UINT128:{result = str8_lit("UINT128");}break;
case CV_BasicType_CHAR16:{result = str8_lit("CHAR16");}break;
case CV_BasicType_CHAR32:{result = str8_lit("CHAR32");}break;
case CV_BasicType_CHAR8:{result = str8_lit("CHAR8");}break;
case CV_BasicType_PTR:{result = str8_lit("PTR");}break;
}
return result;
}

internal String8
cv_type_name_from_basic_type(CV_BasicType v)
{
String8 result = str8_lit("<Unknown CV_BasicType>");
switch(v)
{
default:{}break;
case CV_BasicType_NOTYPE:{result = str8_lit("");}break;
case CV_BasicType_ABS:{result = str8_lit("");}break;
case CV_BasicType_SEGMENT:{result = str8_lit("");}break;
case CV_BasicType_VOID:{result = str8_lit("void");}break;
case CV_BasicType_CURRENCY:{result = str8_lit("");}break;
case CV_BasicType_NBASICSTR:{result = str8_lit("");}break;
case CV_BasicType_FBASICSTR:{result = str8_lit("");}break;
case CV_BasicType_NOTTRANS:{result = str8_lit("");}break;
case CV_BasicType_HRESULT:{result = str8_lit("HRESULT");}break;
case CV_BasicType_CHAR:{result = str8_lit("char");}break;
case CV_BasicType_SHORT:{result = str8_lit("S16");}break;
case CV_BasicType_LONG:{result = str8_lit("S32");}break;
case CV_BasicType_QUAD:{result = str8_lit("S64");}break;
case CV_BasicType_OCT:{result = str8_lit("S128");}break;
case CV_BasicType_UCHAR:{result = str8_lit("UCHAR");}break;
case CV_BasicType_USHORT:{result = str8_lit("U16");}break;
case CV_BasicType_ULONG:{result = str8_lit("U32");}break;
case CV_BasicType_UQUAD:{result = str8_lit("U64");}break;
case CV_BasicType_UOCT:{result = str8_lit("U128");}break;
case CV_BasicType_BOOL8:{result = str8_lit("B8");}break;
case CV_BasicType_BOOL16:{result = str8_lit("B16");}break;
case CV_BasicType_BOOL32:{result = str8_lit("B32");}break;
case CV_BasicType_BOOL64:{result = str8_lit("B64");}break;
case CV_BasicType_FLOAT32:{result = str8_lit("F32");}break;
case CV_BasicType_FLOAT64:{result = str8_lit("F64");}break;
case CV_BasicType_FLOAT80:{result = str8_lit("F80");}break;
case CV_BasicType_FLOAT128:{result = str8_lit("F128");}break;
case CV_BasicType_FLOAT48:{result = str8_lit("F48");}break;
case CV_BasicType_FLOAT32PP:{result = str8_lit("F32PP");}break;
case CV_BasicType_FLOAT16:{result = str8_lit("F16");}break;
case CV_BasicType_COMPLEX32:{result = str8_lit("ComplexF32");}break;
case CV_BasicType_COMPLEX64:{result = str8_lit("ComplexF64");}break;
case CV_BasicType_COMPLEX80:{result = str8_lit("ComplexF80");}break;
case CV_BasicType_COMPLEX128:{result = str8_lit("ComplexF128");}break;
case CV_BasicType_BIT:{result = str8_lit("");}break;
case CV_BasicType_PASCHAR:{result = str8_lit("");}break;
case CV_BasicType_BOOL32FF:{result = str8_lit("B32FF");}break;
case CV_BasicType_INT8:{result = str8_lit("S8");}break;
case CV_BasicType_UINT8:{result = str8_lit("U8");}break;
case CV_BasicType_RCHAR:{result = str8_lit("char");}break;
case CV_BasicType_WCHAR:{result = str8_lit("WCHAR");}break;
case CV_BasicType_INT16:{result = str8_lit("S16");}break;
case CV_BasicType_UINT16:{result = str8_lit("U16");}break;
case CV_BasicType_INT32:{result = str8_lit("S32");}break;
case CV_BasicType_UINT32:{result = str8_lit("U32");}break;
case CV_BasicType_INT64:{result = str8_lit("S64");}break;
case CV_BasicType_UINT64:{result = str8_lit("U64");}break;
case CV_BasicType_INT128:{result = str8_lit("S128");}break;
case CV_BasicType_UINT128:{result = str8_lit("U128");}break;
case CV_BasicType_CHAR16:{result = str8_lit("CHAR16");}break;
case CV_BasicType_CHAR32:{result = str8_lit("CHAR32");}break;
case CV_BasicType_CHAR8:{result = str8_lit("char");}break;
case CV_BasicType_PTR:{result = str8_lit("PTR");}break;
}
return result;
}

internal String8
cv_string_from_leaf_kind(CV_LeafKind v)
{
String8 result = str8_lit("<Unknown CV_LeafKind>");
switch(v)
{
default:{}break;
case CV_LeafKind_MODIFIER_16t:{result = str8_lit("MODIFIER_16t");}break;
case CV_LeafKind_POINTER_16t:{result = str8_lit("POINTER_16t");}break;
case CV_LeafKind_ARRAY_16t:{result = str8_lit("ARRAY_16t");}break;
case CV_LeafKind_CLASS_16t:{result = str8_lit("CLASS_16t");}break;
case CV_LeafKind_STRUCTURE_16t:{result = str8_lit("STRUCTURE_16t");}break;
case CV_LeafKind_UNION_16t:{result = str8_lit("UNION_16t");}break;
case CV_LeafKind_ENUM_16t:{result = str8_lit("ENUM_16t");}break;
case CV_LeafKind_PROCEDURE_16t:{result = str8_lit("PROCEDURE_16t");}break;
case CV_LeafKind_MFUNCTION_16t:{result = str8_lit("MFUNCTION_16t");}break;
case CV_LeafKind_VTSHAPE:{result = str8_lit("VTSHAPE");}break;
case CV_LeafKind_COBOL0_16t:{result = str8_lit("COBOL0_16t");}break;
case CV_LeafKind_COBOL1:{result = str8_lit("COBOL1");}break;
case CV_LeafKind_BARRAY_16t:{result = str8_lit("BARRAY_16t");}break;
case CV_LeafKind_LABEL:{result = str8_lit("LABEL");}break;
case CV_LeafKind_NULL:{result = str8_lit("NULL");}break;
case CV_LeafKind_NOTTRAN:{result = str8_lit("NOTTRAN");}break;
case CV_LeafKind_DIMARRAY_16t:{result = str8_lit("DIMARRAY_16t");}break;
case CV_LeafKind_VFTPATH_16t:{result = str8_lit("VFTPATH_16t");}break;
case CV_LeafKind_PRECOMP_16t:{result = str8_lit("PRECOMP_16t");}break;
case CV_LeafKind_ENDPRECOMP:{result = str8_lit("ENDPRECOMP");}break;
case CV_LeafKind_OEM_16t:{result = str8_lit("OEM_16t");}break;
case CV_LeafKind_TYPESERVER_ST:{result = str8_lit("TYPESERVER_ST");}break;
case CV_LeafKind_SKIP_16t:{result = str8_lit("SKIP_16t");}break;
case CV_LeafKind_ARGLIST_16t:{result = str8_lit("ARGLIST_16t");}break;
case CV_LeafKind_DEFARG_16t:{result = str8_lit("DEFARG_16t");}break;
case CV_LeafKind_LIST:{result = str8_lit("LIST");}break;
case CV_LeafKind_FIELDLIST_16t:{result = str8_lit("FIELDLIST_16t");}break;
case CV_LeafKind_DERIVED_16t:{result = str8_lit("DERIVED_16t");}break;
case CV_LeafKind_BITFIELD_16t:{result = str8_lit("BITFIELD_16t");}break;
case CV_LeafKind_METHODLIST_16t:{result = str8_lit("METHODLIST_16t");}break;
case CV_LeafKind_DIMCONU_16t:{result = str8_lit("DIMCONU_16t");}break;
case CV_LeafKind_DIMCONLU_16t:{result = str8_lit("DIMCONLU_16t");}break;
case CV_LeafKind_DIMVARU_16t:{result = str8_lit("DIMVARU_16t");}break;
case CV_LeafKind_DIMVARLU_16t:{result = str8_lit("DIMVARLU_16t");}break;
case CV_LeafKind_REFSYM:{result = str8_lit("REFSYM");}break;
case CV_LeafKind_BCLASS_16t:{result = str8_lit("BCLASS_16t");}break;
case CV_LeafKind_VBCLASS_16t:{result = str8_lit("VBCLASS_16t");}break;
case CV_LeafKind_IVBCLASS_16t:{result = str8_lit("IVBCLASS_16t");}break;
case CV_LeafKind_ENUMERATE_ST:{result = str8_lit("ENUMERATE_ST");}break;
case CV_LeafKind_FRIENDFCN_16t:{result = str8_lit("FRIENDFCN_16t");}break;
case CV_LeafKind_INDEX_16t:{result = str8_lit("INDEX_16t");}break;
case CV_LeafKind_MEMBER_16t:{result = str8_lit("MEMBER_16t");}break;
case CV_LeafKind_STMEMBER_16t:{result = str8_lit("STMEMBER_16t");}break;
case CV_LeafKind_METHOD_16t:{result = str8_lit("METHOD_16t");}break;
case CV_LeafKind_NESTTYPE_16t:{result = str8_lit("NESTTYPE_16t");}break;
case CV_LeafKind_VFUNCTAB_16t:{result = str8_lit("VFUNCTAB_16t");}break;
case CV_LeafKind_FRIENDCLS_16t:{result = str8_lit("FRIENDCLS_16t");}break;
case CV_LeafKind_ONEMETHOD_16t:{result = str8_lit("ONEMETHOD_16t");}break;
case CV_LeafKind_VFUNCOFF_16t:{result = str8_lit("VFUNCOFF_16t");}break;
case CV_LeafKind_TI16_MAX:{result = str8_lit("TI16_MAX");}break;
case CV_LeafKind_MODIFIER:{result = str8_lit("MODIFIER");}break;
case CV_LeafKind_POINTER:{result = str8_lit("POINTER");}break;
case CV_LeafKind_ARRAY_ST:{result = str8_lit("ARRAY_ST");}break;
case CV_LeafKind_CLASS_ST:{result = str8_lit("CLASS_ST");}break;
case CV_LeafKind_STRUCTURE_ST:{result = str8_lit("STRUCTURE_ST");}break;
case CV_LeafKind_UNION_ST:{result = str8_lit("UNION_ST");}break;
case CV_LeafKind_ENUM_ST:{result = str8_lit("ENUM_ST");}break;
case CV_LeafKind_PROCEDURE:{result = str8_lit("PROCEDURE");}break;
case CV_LeafKind_MFUNCTION:{result = str8_lit("MFUNCTION");}break;
case CV_LeafKind_COBOL0:{result = str8_lit("COBOL0");}break;
case CV_LeafKind_BARRAY:{result = str8_lit("BARRAY");}break;
case CV_LeafKind_DIMARRAY_ST:{result = str8_lit("DIMARRAY_ST");}break;
case CV_LeafKind_VFTPATH:{result = str8_lit("VFTPATH");}break;
case CV_LeafKind_PRECOMP_ST:{result = str8_lit("PRECOMP_ST");}break;
case CV_LeafKind_OEM:{result = str8_lit("OEM");}break;
case CV_LeafKind_ALIAS_ST:{result = str8_lit("ALIAS_ST");}break;
case CV_LeafKind_OEM2:{result = str8_lit("OEM2");}break;
case CV_LeafKind_SKIP:{result = str8_lit("SKIP");}break;
case CV_LeafKind_ARGLIST:{result = str8_lit("ARGLIST");}break;
case CV_LeafKind_DEFARG_ST:{result = str8_lit("DEFARG_ST");}break;
case CV_LeafKind_FIELDLIST:{result = str8_lit("FIELDLIST");}break;
case CV_LeafKind_DERIVED:{result = str8_lit("DERIVED");}break;
case CV_LeafKind_BITFIELD:{result = str8_lit("BITFIELD");}break;
case CV_LeafKind_METHODLIST:{result = str8_lit("METHODLIST");}break;
case CV_LeafKind_DIMCONU:{result = str8_lit("DIMCONU");}break;
case CV_LeafKind_DIMCONLU:{result = str8_lit("DIMCONLU");}break;
case CV_LeafKind_DIMVARU:{result = str8_lit("DIMVARU");}break;
case CV_LeafKind_DIMVARLU:{result = str8_lit("DIMVARLU");}break;
case CV_LeafKind_BCLASS:{result = str8_lit("BCLASS");}break;
case CV_LeafKind_VBCLASS:{result = str8_lit("VBCLASS");}break;
case CV_LeafKind_IVBCLASS:{result = str8_lit("IVBCLASS");}break;
case CV_LeafKind_FRIENDFCN_ST:{result = str8_lit("FRIENDFCN_ST");}break;
case CV_LeafKind_INDEX:{result = str8_lit("INDEX");}break;
case CV_LeafKind_MEMBER_ST:{result = str8_lit("MEMBER_ST");}break;
case CV_LeafKind_STMEMBER_ST:{result = str8_lit("STMEMBER_ST");}break;
case CV_LeafKind_METHOD_ST:{result = str8_lit("METHOD_ST");}break;
case CV_LeafKind_NESTTYPE_ST:{result = str8_lit("NESTTYPE_ST");}break;
case CV_LeafKind_VFUNCTAB:{result = str8_lit("VFUNCTAB");}break;
case CV_LeafKind_FRIENDCLS:{result = str8_lit("FRIENDCLS");}break;
case CV_LeafKind_ONEMETHOD_ST:{result = str8_lit("ONEMETHOD_ST");}break;
case CV_LeafKind_VFUNCOFF:{result = str8_lit("VFUNCOFF");}break;
case CV_LeafKind_NESTTYPEEX_ST:{result = str8_lit("NESTTYPEEX_ST");}break;
case CV_LeafKind_MEMBERMODIFY_ST:{result = str8_lit("MEMBERMODIFY_ST");}break;
case CV_LeafKind_MANAGED_ST:{result = str8_lit("MANAGED_ST");}break;
case CV_LeafKind_ST_MAX:{result = str8_lit("ST_MAX");}break;
case CV_LeafKind_TYPESERVER:{result = str8_lit("TYPESERVER");}break;
case CV_LeafKind_ENUMERATE:{result = str8_lit("ENUMERATE");}break;
case CV_LeafKind_ARRAY:{result = str8_lit("ARRAY");}break;
case CV_LeafKind_CLASS:{result = str8_lit("CLASS");}break;
case CV_LeafKind_STRUCTURE:{result = str8_lit("STRUCTURE");}break;
case CV_LeafKind_UNION:{result = str8_lit("UNION");}break;
case CV_LeafKind_ENUM:{result = str8_lit("ENUM");}break;
case CV_LeafKind_DIMARRAY:{result = str8_lit("DIMARRAY");}break;
case CV_LeafKind_PRECOMP:{result = str8_lit("PRECOMP");}break;
case CV_LeafKind_ALIAS:{result = str8_lit("ALIAS");}break;
case CV_LeafKind_DEFARG:{result = str8_lit("DEFARG");}break;
case CV_LeafKind_FRIENDFCN:{result = str8_lit("FRIENDFCN");}break;
case CV_LeafKind_MEMBER:{result = str8_lit("MEMBER");}break;
case CV_LeafKind_STMEMBER:{result = str8_lit("STMEMBER");}break;
case CV_LeafKind_METHOD:{result = str8_lit("METHOD");}break;
case CV_LeafKind_NESTTYPE:{result = str8_lit("NESTTYPE");}break;
case CV_LeafKind_ONEMETHOD:{result = str8_lit("ONEMETHOD");}break;
case CV_LeafKind_NESTTYPEEX:{result = str8_lit("NESTTYPEEX");}break;
case CV_LeafKind_MEMBERMODIFY:{result = str8_lit("MEMBERMODIFY");}break;
case CV_LeafKind_MANAGED:{result = str8_lit("MANAGED");}break;
case CV_LeafKind_TYPESERVER2:{result = str8_lit("TYPESERVER2");}break;
case CV_LeafKind_STRIDED_ARRAY:{result = str8_lit("STRIDED_ARRAY");}break;
case CV_LeafKind_HLSL:{result = str8_lit("HLSL");}break;
case CV_LeafKind_MODIFIER_EX:{result = str8_lit("MODIFIER_EX");}break;
case CV_LeafKind_INTERFACE:{result = str8_lit("INTERFACE");}break;
case CV_LeafKind_BINTERFACE:{result = str8_lit("BINTERFACE");}break;
case CV_LeafKind_VECTOR:{result = str8_lit("VECTOR");}break;
case CV_LeafKind_MATRIX:{result = str8_lit("MATRIX");}break;
case CV_LeafKind_VFTABLE:{result = str8_lit("VFTABLE");}break;
case CV_LeafKind_CLASS2:{result = str8_lit("CLASS2");}break;
case CV_LeafKind_STRUCT2:{result = str8_lit("STRUCT2");}break;
}
return result;
}

internal U64
cv_header_struct_size_from_sym_kind(CV_SymKind v)
{
U64 result = 0;
switch(v)
{
default:{}break;
case CV_SymKind_COMPILE:{result = sizeof(CV_SymCompile);}break;
case CV_SymKind_SSEARCH:{result = sizeof(CV_SymStartSearch);}break;
case CV_SymKind_RETURN:{result = sizeof(CV_SymReturn);}break;
case CV_SymKind_SLINK32:{result = sizeof(CV_SymSLink32);}break;
case CV_SymKind_OEM:{result = sizeof(CV_SymOEM);}break;
case CV_SymKind_VFTABLE32:{result = sizeof(CV_SymVPath32);}break;
case CV_SymKind_FRAMEPROC:{result = sizeof(CV_SymFrameproc);}break;
case CV_SymKind_ANNOTATION:{result = sizeof(CV_SymAnnotation);}break;
case CV_SymKind_OBJNAME:{result = sizeof(CV_SymObjname);}break;
case CV_SymKind_THUNK32:{result = sizeof(CV_SymThunk32);}break;
case CV_SymKind_BLOCK32:{result = sizeof(CV_SymBlock32);}break;
case CV_SymKind_LABEL32:{result = sizeof(CV_SymLabel32);}break;
case CV_SymKind_REGISTER:{result = sizeof(CV_SymRegister);}break;
case CV_SymKind_CONSTANT:{result = sizeof(CV_SymConstant);}break;
case CV_SymKind_UDT:{result = sizeof(CV_SymUDT);}break;
case CV_SymKind_MANYREG:{result = sizeof(CV_SymManyreg);}break;
case CV_SymKind_BPREL32:{result = sizeof(CV_SymBPRel32);}break;
case CV_SymKind_LDATA32:{result = sizeof(CV_SymData32);}break;
case CV_SymKind_GDATA32:{result = sizeof(CV_SymData32);}break;
case CV_SymKind_PUB32:{result = sizeof(CV_SymPub32);}break;
case CV_SymKind_LPROC32:{result = sizeof(CV_SymProc32);}break;
case CV_SymKind_GPROC32:{result = sizeof(CV_SymProc32);}break;
case CV_SymKind_REGREL32:{result = sizeof(CV_SymRegrel32);}break;
case CV_SymKind_LTHREAD32:{result = sizeof(CV_SymThread32);}break;
case CV_SymKind_GTHREAD32:{result = sizeof(CV_SymThread32);}break;
case CV_SymKind_COMPILE2:{result = sizeof(CV_SymCompile2);}break;
case CV_SymKind_MANYREG2:{result = sizeof(CV_SymManyreg2);}break;
case CV_SymKind_LOCALSLOT:{result = sizeof(CV_SymSlot);}break;
case CV_SymKind_MANFRAMEREL:{result = sizeof(CV_SymAttrFrameRel);}break;
case CV_SymKind_MANREGISTER:{result = sizeof(CV_SymAttrReg);}break;
case CV_SymKind_MANMANYREG:{result = sizeof(CV_SymAttrManyReg);}break;
case CV_SymKind_MANREGREL:{result = sizeof(CV_SymAttrRegRel);}break;
case CV_SymKind_UNAMESPACE:{result = sizeof(CV_SymUNamespace);}break;
case CV_SymKind_PROCREF:{result = sizeof(CV_SymRef2);}break;
case CV_SymKind_DATAREF:{result = sizeof(CV_SymRef2);}break;
case CV_SymKind_LPROCREF:{result = sizeof(CV_SymRef2);}break;
case CV_SymKind_TRAMPOLINE:{result = sizeof(CV_SymTrampoline);}break;
case CV_SymKind_ATTR_FRAMEREL:{result = sizeof(CV_SymAttrFrameRel);}break;
case CV_SymKind_ATTR_REGISTER:{result = sizeof(CV_SymAttrReg);}break;
case CV_SymKind_ATTR_REGREL:{result = sizeof(CV_SymAttrRegRel);}break;
case CV_SymKind_ATTR_MANYREG:{result = sizeof(CV_SymAttrManyReg);}break;
case CV_SymKind_SEPCODE:{result = sizeof(CV_SymSepcode);}break;
case CV_SymKind_SECTION:{result = sizeof(CV_SymSection);}break;
case CV_SymKind_COFFGROUP:{result = sizeof(CV_SymCoffGroup);}break;
case CV_SymKind_EXPORT:{result = sizeof(CV_SymExport);}break;
case CV_SymKind_CALLSITEINFO:{result = sizeof(CV_SymCallSiteInfo);}break;
case CV_SymKind_FRAMECOOKIE:{result = sizeof(CV_SymFrameCookie);}break;
case CV_SymKind_DISCARDED:{result = sizeof(CV_SymDiscarded);}break;
case CV_SymKind_COMPILE3:{result = sizeof(CV_SymCompile3);}break;
case CV_SymKind_ENVBLOCK:{result = sizeof(CV_SymEnvBlock);}break;
case CV_SymKind_LOCAL:{result = sizeof(CV_SymLocal);}break;
case CV_SymKind_DEFRANGE_SUBFIELD:{result = sizeof(CV_SymDefrangeSubfield);}break;
case CV_SymKind_DEFRANGE_REGISTER:{result = sizeof(CV_SymDefrangeRegister);}break;
case CV_SymKind_DEFRANGE_FRAMEPOINTER_REL:{result = sizeof(CV_SymDefrangeFramepointerRel);}break;
case CV_SymKind_DEFRANGE_SUBFIELD_REGISTER:{result = sizeof(CV_SymDefrangeSubfieldRegister);}break;
case CV_SymKind_DEFRANGE_FRAMEPOINTER_REL_FULL_SCOPE:{result = sizeof(CV_SymDefrangeFramepointerRelFullScope);}break;
case CV_SymKind_DEFRANGE_REGISTER_REL:{result = sizeof(CV_SymDefrangeRegisterRel);}break;
case CV_SymKind_BUILDINFO:{result = sizeof(CV_SymBuildInfo);}break;
case CV_SymKind_INLINESITE:{result = sizeof(CV_SymInlineSite);}break;
case CV_SymKind_FILESTATIC:{result = sizeof(CV_SymFileStatic);}break;
case CV_SymKind_CALLEES:{result = sizeof(CV_SymFunctionList);}break;
case CV_SymKind_CALLERS:{result = sizeof(CV_SymFunctionList);}break;
case CV_SymKind_POGODATA:{result = sizeof(CV_SymPogoInfo);}break;
case CV_SymKind_INLINESITE2:{result = sizeof(CV_SymInlineSite2);}break;
case CV_SymKind_HEAPALLOCSITE:{result = sizeof(CV_SymHeapAllocSite);}break;
case CV_SymKind_MOD_TYPEREF:{result = sizeof(CV_SymModTypeRef);}break;
case CV_SymKind_REF_MINIPDB:{result = sizeof(CV_SymRefMiniPdb);}break;
case CV_SymKind_FASTLINK:{result = sizeof(CV_SymFastLink);}break;
case CV_SymKind_INLINEES:{result = sizeof(CV_SymInlinees);}break;
}
return result;
}
internal U64
cv_header_struct_size_from_leaf_kind(CV_LeafKind v)
{
U64 result = 0;
switch(v)
{
default:{}break;
case CV_LeafKind_VTSHAPE:{result = sizeof(CV_LeafVTShape);}break;
case CV_LeafKind_LABEL:{result = sizeof(CV_LeafLabel);}break;
case CV_LeafKind_MODIFIER:{result = sizeof(CV_LeafModifier);}break;
case CV_LeafKind_POINTER:{result = sizeof(CV_LeafPointer);}break;
case CV_LeafKind_PROCEDURE:{result = sizeof(CV_LeafProcedure);}break;
case CV_LeafKind_MFUNCTION:{result = sizeof(CV_LeafMFunction);}break;
case CV_LeafKind_VFTPATH:{result = sizeof(CV_LeafVFPath);}break;
case CV_LeafKind_SKIP:{result = sizeof(CV_LeafSkip);}break;
case CV_LeafKind_ARGLIST:{result = sizeof(CV_LeafArgList);}break;
case CV_LeafKind_BITFIELD:{result = sizeof(CV_LeafBitField);}break;
case CV_LeafKind_METHODLIST:{result = sizeof(CV_LeafMethodListMember);}break;
case CV_LeafKind_BCLASS:{result = sizeof(CV_LeafBClass);}break;
case CV_LeafKind_VBCLASS:{result = sizeof(CV_LeafVBClass);}break;
case CV_LeafKind_INDEX:{result = sizeof(CV_LeafIndex);}break;
case CV_LeafKind_VFUNCTAB:{result = sizeof(CV_LeafVFuncTab);}break;
case CV_LeafKind_VFUNCOFF:{result = sizeof(CV_LeafVFuncOff);}break;
case CV_LeafKind_TYPESERVER:{result = sizeof(CV_LeafTypeServer);}break;
case CV_LeafKind_ENUMERATE:{result = sizeof(CV_LeafEnumerate);}break;
case CV_LeafKind_ARRAY:{result = sizeof(CV_LeafArray);}break;
case CV_LeafKind_CLASS:{result = sizeof(CV_LeafStruct);}break;
case CV_LeafKind_STRUCTURE:{result = sizeof(CV_LeafStruct);}break;
case CV_LeafKind_UNION:{result = sizeof(CV_LeafUnion);}break;
case CV_LeafKind_ENUM:{result = sizeof(CV_LeafEnum);}break;
case CV_LeafKind_PRECOMP:{result = sizeof(CV_LeafPreComp);}break;
case CV_LeafKind_ALIAS:{result = sizeof(CV_LeafAlias);}break;
case CV_LeafKind_MEMBER:{result = sizeof(CV_LeafMember);}break;
case CV_LeafKind_STMEMBER:{result = sizeof(CV_LeafStMember);}break;
case CV_LeafKind_METHOD:{result = sizeof(CV_LeafMethod);}break;
case CV_LeafKind_NESTTYPE:{result = sizeof(CV_LeafNestType);}break;
case CV_LeafKind_ONEMETHOD:{result = sizeof(CV_LeafOneMethod);}break;
case CV_LeafKind_NESTTYPEEX:{result = sizeof(CV_LeafNestTypeEx);}break;
case CV_LeafKind_TYPESERVER2:{result = sizeof(CV_LeafTypeServer2);}break;
case CV_LeafKind_INTERFACE:{result = sizeof(CV_LeafStruct);}break;
case CV_LeafKind_CLASS2:{result = sizeof(CV_LeafStruct2);}break;
case CV_LeafKind_STRUCT2:{result = sizeof(CV_LeafStruct2);}break;
}
return result;
}
C_LINKAGE_BEGIN
C_LINKAGE_END

