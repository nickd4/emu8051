/*
 * instructions_8051.h
 *
 * Do not modify this file directly, as it was created by opcodes2c.pl
 * Any modifications made directly to this file will be lost.
 *
 * Copyright (C) 1999 Jonathan St-André
 * Copyright (C) 1999 Hugo Villeneuve <hugo.com>
 *
 * This file is released under the GPLv2
 */

#ifndef INSTRUCTIONS_8051_H
#define INSTRUCTIONS_8051_H 1


#define BANKPSW (mem_read_direct(_PSW_) & 0x18)

typedef int (*OPCODE_FP)(void);


int
cpu8051_OP_00(void);

int
cpu8051_OP_01(void);

int
cpu8051_OP_02(void);

int
cpu8051_OP_03(void);

int
cpu8051_OP_04(void);

int
cpu8051_OP_05(void);

int
cpu8051_OP_06(void);

int
cpu8051_OP_07(void);

int
cpu8051_OP_08(void);

int
cpu8051_OP_09(void);

int
cpu8051_OP_0A(void);

int
cpu8051_OP_0B(void);

int
cpu8051_OP_0C(void);

int
cpu8051_OP_0D(void);

int
cpu8051_OP_0E(void);

int
cpu8051_OP_0F(void);

int
cpu8051_OP_10(void);

int
cpu8051_OP_11(void);

int
cpu8051_OP_12(void);

int
cpu8051_OP_13(void);

int
cpu8051_OP_14(void);

int
cpu8051_OP_15(void);

int
cpu8051_OP_16(void);

int
cpu8051_OP_17(void);

int
cpu8051_OP_18(void);

int
cpu8051_OP_19(void);

int
cpu8051_OP_1A(void);

int
cpu8051_OP_1B(void);

int
cpu8051_OP_1C(void);

int
cpu8051_OP_1D(void);

int
cpu8051_OP_1E(void);

int
cpu8051_OP_1F(void);

int
cpu8051_OP_20(void);

int
cpu8051_OP_21(void);

int
cpu8051_OP_22(void);

int
cpu8051_OP_23(void);

int
cpu8051_OP_24(void);

int
cpu8051_OP_25(void);

int
cpu8051_OP_26(void);

int
cpu8051_OP_27(void);

int
cpu8051_OP_28(void);

int
cpu8051_OP_29(void);

int
cpu8051_OP_2A(void);

int
cpu8051_OP_2B(void);

int
cpu8051_OP_2C(void);

int
cpu8051_OP_2D(void);

int
cpu8051_OP_2E(void);

int
cpu8051_OP_2F(void);

int
cpu8051_OP_30(void);

int
cpu8051_OP_31(void);

int
cpu8051_OP_32(void);

int
cpu8051_OP_33(void);

int
cpu8051_OP_34(void);

int
cpu8051_OP_35(void);

int
cpu8051_OP_36(void);

int
cpu8051_OP_37(void);

int
cpu8051_OP_38(void);

int
cpu8051_OP_39(void);

int
cpu8051_OP_3A(void);

int
cpu8051_OP_3B(void);

int
cpu8051_OP_3C(void);

int
cpu8051_OP_3D(void);

int
cpu8051_OP_3E(void);

int
cpu8051_OP_3F(void);

int
cpu8051_OP_40(void);

int
cpu8051_OP_41(void);

int
cpu8051_OP_42(void);

int
cpu8051_OP_43(void);

int
cpu8051_OP_44(void);

int
cpu8051_OP_45(void);

int
cpu8051_OP_46(void);

int
cpu8051_OP_47(void);

int
cpu8051_OP_48(void);

int
cpu8051_OP_49(void);

int
cpu8051_OP_4A(void);

int
cpu8051_OP_4B(void);

int
cpu8051_OP_4C(void);

int
cpu8051_OP_4D(void);

int
cpu8051_OP_4E(void);

int
cpu8051_OP_4F(void);

int
cpu8051_OP_50(void);

int
cpu8051_OP_51(void);

int
cpu8051_OP_52(void);

int
cpu8051_OP_53(void);

int
cpu8051_OP_54(void);

int
cpu8051_OP_55(void);

int
cpu8051_OP_56(void);

int
cpu8051_OP_57(void);

int
cpu8051_OP_58(void);

int
cpu8051_OP_59(void);

int
cpu8051_OP_5A(void);

int
cpu8051_OP_5B(void);

int
cpu8051_OP_5C(void);

int
cpu8051_OP_5D(void);

int
cpu8051_OP_5E(void);

int
cpu8051_OP_5F(void);

int
cpu8051_OP_60(void);

int
cpu8051_OP_61(void);

int
cpu8051_OP_62(void);

int
cpu8051_OP_63(void);

int
cpu8051_OP_64(void);

int
cpu8051_OP_65(void);

int
cpu8051_OP_66(void);

int
cpu8051_OP_67(void);

int
cpu8051_OP_68(void);

int
cpu8051_OP_69(void);

int
cpu8051_OP_6A(void);

int
cpu8051_OP_6B(void);

int
cpu8051_OP_6C(void);

int
cpu8051_OP_6D(void);

int
cpu8051_OP_6E(void);

int
cpu8051_OP_6F(void);

int
cpu8051_OP_70(void);

int
cpu8051_OP_71(void);

int
cpu8051_OP_72(void);

int
cpu8051_OP_73(void);

int
cpu8051_OP_74(void);

int
cpu8051_OP_75(void);

int
cpu8051_OP_76(void);

int
cpu8051_OP_77(void);

int
cpu8051_OP_78(void);

int
cpu8051_OP_79(void);

int
cpu8051_OP_7A(void);

int
cpu8051_OP_7B(void);

int
cpu8051_OP_7C(void);

int
cpu8051_OP_7D(void);

int
cpu8051_OP_7E(void);

int
cpu8051_OP_7F(void);

int
cpu8051_OP_80(void);

int
cpu8051_OP_81(void);

int
cpu8051_OP_82(void);

int
cpu8051_OP_83(void);

int
cpu8051_OP_84(void);

int
cpu8051_OP_85(void);

int
cpu8051_OP_86(void);

int
cpu8051_OP_87(void);

int
cpu8051_OP_88(void);

int
cpu8051_OP_89(void);

int
cpu8051_OP_8A(void);

int
cpu8051_OP_8B(void);

int
cpu8051_OP_8C(void);

int
cpu8051_OP_8D(void);

int
cpu8051_OP_8E(void);

int
cpu8051_OP_8F(void);

int
cpu8051_OP_90(void);

int
cpu8051_OP_91(void);

int
cpu8051_OP_92(void);

int
cpu8051_OP_93(void);

int
cpu8051_OP_94(void);

int
cpu8051_OP_95(void);

int
cpu8051_OP_96(void);

int
cpu8051_OP_97(void);

int
cpu8051_OP_98(void);

int
cpu8051_OP_99(void);

int
cpu8051_OP_9A(void);

int
cpu8051_OP_9B(void);

int
cpu8051_OP_9C(void);

int
cpu8051_OP_9D(void);

int
cpu8051_OP_9E(void);

int
cpu8051_OP_9F(void);

int
cpu8051_OP_A0(void);

int
cpu8051_OP_A1(void);

int
cpu8051_OP_A2(void);

int
cpu8051_OP_A3(void);

int
cpu8051_OP_A4(void);

int
cpu8051_OP_A5(void);

int
cpu8051_OP_A6(void);

int
cpu8051_OP_A7(void);

int
cpu8051_OP_A8(void);

int
cpu8051_OP_A9(void);

int
cpu8051_OP_AA(void);

int
cpu8051_OP_AB(void);

int
cpu8051_OP_AC(void);

int
cpu8051_OP_AD(void);

int
cpu8051_OP_AE(void);

int
cpu8051_OP_AF(void);

int
cpu8051_OP_B0(void);

int
cpu8051_OP_B1(void);

int
cpu8051_OP_B2(void);

int
cpu8051_OP_B3(void);

int
cpu8051_OP_B4(void);

int
cpu8051_OP_B5(void);

int
cpu8051_OP_B6(void);

int
cpu8051_OP_B7(void);

int
cpu8051_OP_B8(void);

int
cpu8051_OP_B9(void);

int
cpu8051_OP_BA(void);

int
cpu8051_OP_BB(void);

int
cpu8051_OP_BC(void);

int
cpu8051_OP_BD(void);

int
cpu8051_OP_BE(void);

int
cpu8051_OP_BF(void);

int
cpu8051_OP_C0(void);

int
cpu8051_OP_C1(void);

int
cpu8051_OP_C2(void);

int
cpu8051_OP_C3(void);

int
cpu8051_OP_C4(void);

int
cpu8051_OP_C5(void);

int
cpu8051_OP_C6(void);

int
cpu8051_OP_C7(void);

int
cpu8051_OP_C8(void);

int
cpu8051_OP_C9(void);

int
cpu8051_OP_CA(void);

int
cpu8051_OP_CB(void);

int
cpu8051_OP_CC(void);

int
cpu8051_OP_CD(void);

int
cpu8051_OP_CE(void);

int
cpu8051_OP_CF(void);

int
cpu8051_OP_D0(void);

int
cpu8051_OP_D1(void);

int
cpu8051_OP_D2(void);

int
cpu8051_OP_D3(void);

int
cpu8051_OP_D4(void);

int
cpu8051_OP_D5(void);

int
cpu8051_OP_D6(void);

int
cpu8051_OP_D7(void);

int
cpu8051_OP_D8(void);

int
cpu8051_OP_D9(void);

int
cpu8051_OP_DA(void);

int
cpu8051_OP_DB(void);

int
cpu8051_OP_DC(void);

int
cpu8051_OP_DD(void);

int
cpu8051_OP_DE(void);

int
cpu8051_OP_DF(void);

int
cpu8051_OP_E0(void);

int
cpu8051_OP_E1(void);

int
cpu8051_OP_E2(void);

int
cpu8051_OP_E3(void);

int
cpu8051_OP_E4(void);

int
cpu8051_OP_E5(void);

int
cpu8051_OP_E6(void);

int
cpu8051_OP_E7(void);

int
cpu8051_OP_E8(void);

int
cpu8051_OP_E9(void);

int
cpu8051_OP_EA(void);

int
cpu8051_OP_EB(void);

int
cpu8051_OP_EC(void);

int
cpu8051_OP_ED(void);

int
cpu8051_OP_EE(void);

int
cpu8051_OP_EF(void);

int
cpu8051_OP_F0(void);

int
cpu8051_OP_F1(void);

int
cpu8051_OP_F2(void);

int
cpu8051_OP_F3(void);

int
cpu8051_OP_F4(void);

int
cpu8051_OP_F5(void);

int
cpu8051_OP_F6(void);

int
cpu8051_OP_F7(void);

int
cpu8051_OP_F8(void);

int
cpu8051_OP_F9(void);

int
cpu8051_OP_FA(void);

int
cpu8051_OP_FB(void);

int
cpu8051_OP_FC(void);

int
cpu8051_OP_FD(void);

int
cpu8051_OP_FE(void);

int
cpu8051_OP_FF(void);


/* Exported variables. */
#ifdef INSTRUCTIONS_8051_M
OPCODE_FP opcode_table[256] = {
	cpu8051_OP_00,
	cpu8051_OP_01,
	cpu8051_OP_02,
	cpu8051_OP_03,
	cpu8051_OP_04,
	cpu8051_OP_05,
	cpu8051_OP_06,
	cpu8051_OP_07,
	cpu8051_OP_08,
	cpu8051_OP_09,
	cpu8051_OP_0A,
	cpu8051_OP_0B,
	cpu8051_OP_0C,
	cpu8051_OP_0D,
	cpu8051_OP_0E,
	cpu8051_OP_0F,
	cpu8051_OP_10,
	cpu8051_OP_11,
	cpu8051_OP_12,
	cpu8051_OP_13,
	cpu8051_OP_14,
	cpu8051_OP_15,
	cpu8051_OP_16,
	cpu8051_OP_17,
	cpu8051_OP_18,
	cpu8051_OP_19,
	cpu8051_OP_1A,
	cpu8051_OP_1B,
	cpu8051_OP_1C,
	cpu8051_OP_1D,
	cpu8051_OP_1E,
	cpu8051_OP_1F,
	cpu8051_OP_20,
	cpu8051_OP_21,
	cpu8051_OP_22,
	cpu8051_OP_23,
	cpu8051_OP_24,
	cpu8051_OP_25,
	cpu8051_OP_26,
	cpu8051_OP_27,
	cpu8051_OP_28,
	cpu8051_OP_29,
	cpu8051_OP_2A,
	cpu8051_OP_2B,
	cpu8051_OP_2C,
	cpu8051_OP_2D,
	cpu8051_OP_2E,
	cpu8051_OP_2F,
	cpu8051_OP_30,
	cpu8051_OP_31,
	cpu8051_OP_32,
	cpu8051_OP_33,
	cpu8051_OP_34,
	cpu8051_OP_35,
	cpu8051_OP_36,
	cpu8051_OP_37,
	cpu8051_OP_38,
	cpu8051_OP_39,
	cpu8051_OP_3A,
	cpu8051_OP_3B,
	cpu8051_OP_3C,
	cpu8051_OP_3D,
	cpu8051_OP_3E,
	cpu8051_OP_3F,
	cpu8051_OP_40,
	cpu8051_OP_41,
	cpu8051_OP_42,
	cpu8051_OP_43,
	cpu8051_OP_44,
	cpu8051_OP_45,
	cpu8051_OP_46,
	cpu8051_OP_47,
	cpu8051_OP_48,
	cpu8051_OP_49,
	cpu8051_OP_4A,
	cpu8051_OP_4B,
	cpu8051_OP_4C,
	cpu8051_OP_4D,
	cpu8051_OP_4E,
	cpu8051_OP_4F,
	cpu8051_OP_50,
	cpu8051_OP_51,
	cpu8051_OP_52,
	cpu8051_OP_53,
	cpu8051_OP_54,
	cpu8051_OP_55,
	cpu8051_OP_56,
	cpu8051_OP_57,
	cpu8051_OP_58,
	cpu8051_OP_59,
	cpu8051_OP_5A,
	cpu8051_OP_5B,
	cpu8051_OP_5C,
	cpu8051_OP_5D,
	cpu8051_OP_5E,
	cpu8051_OP_5F,
	cpu8051_OP_60,
	cpu8051_OP_61,
	cpu8051_OP_62,
	cpu8051_OP_63,
	cpu8051_OP_64,
	cpu8051_OP_65,
	cpu8051_OP_66,
	cpu8051_OP_67,
	cpu8051_OP_68,
	cpu8051_OP_69,
	cpu8051_OP_6A,
	cpu8051_OP_6B,
	cpu8051_OP_6C,
	cpu8051_OP_6D,
	cpu8051_OP_6E,
	cpu8051_OP_6F,
	cpu8051_OP_70,
	cpu8051_OP_71,
	cpu8051_OP_72,
	cpu8051_OP_73,
	cpu8051_OP_74,
	cpu8051_OP_75,
	cpu8051_OP_76,
	cpu8051_OP_77,
	cpu8051_OP_78,
	cpu8051_OP_79,
	cpu8051_OP_7A,
	cpu8051_OP_7B,
	cpu8051_OP_7C,
	cpu8051_OP_7D,
	cpu8051_OP_7E,
	cpu8051_OP_7F,
	cpu8051_OP_80,
	cpu8051_OP_81,
	cpu8051_OP_82,
	cpu8051_OP_83,
	cpu8051_OP_84,
	cpu8051_OP_85,
	cpu8051_OP_86,
	cpu8051_OP_87,
	cpu8051_OP_88,
	cpu8051_OP_89,
	cpu8051_OP_8A,
	cpu8051_OP_8B,
	cpu8051_OP_8C,
	cpu8051_OP_8D,
	cpu8051_OP_8E,
	cpu8051_OP_8F,
	cpu8051_OP_90,
	cpu8051_OP_91,
	cpu8051_OP_92,
	cpu8051_OP_93,
	cpu8051_OP_94,
	cpu8051_OP_95,
	cpu8051_OP_96,
	cpu8051_OP_97,
	cpu8051_OP_98,
	cpu8051_OP_99,
	cpu8051_OP_9A,
	cpu8051_OP_9B,
	cpu8051_OP_9C,
	cpu8051_OP_9D,
	cpu8051_OP_9E,
	cpu8051_OP_9F,
	cpu8051_OP_A0,
	cpu8051_OP_A1,
	cpu8051_OP_A2,
	cpu8051_OP_A3,
	cpu8051_OP_A4,
	cpu8051_OP_A5,
	cpu8051_OP_A6,
	cpu8051_OP_A7,
	cpu8051_OP_A8,
	cpu8051_OP_A9,
	cpu8051_OP_AA,
	cpu8051_OP_AB,
	cpu8051_OP_AC,
	cpu8051_OP_AD,
	cpu8051_OP_AE,
	cpu8051_OP_AF,
	cpu8051_OP_B0,
	cpu8051_OP_B1,
	cpu8051_OP_B2,
	cpu8051_OP_B3,
	cpu8051_OP_B4,
	cpu8051_OP_B5,
	cpu8051_OP_B6,
	cpu8051_OP_B7,
	cpu8051_OP_B8,
	cpu8051_OP_B9,
	cpu8051_OP_BA,
	cpu8051_OP_BB,
	cpu8051_OP_BC,
	cpu8051_OP_BD,
	cpu8051_OP_BE,
	cpu8051_OP_BF,
	cpu8051_OP_C0,
	cpu8051_OP_C1,
	cpu8051_OP_C2,
	cpu8051_OP_C3,
	cpu8051_OP_C4,
	cpu8051_OP_C5,
	cpu8051_OP_C6,
	cpu8051_OP_C7,
	cpu8051_OP_C8,
	cpu8051_OP_C9,
	cpu8051_OP_CA,
	cpu8051_OP_CB,
	cpu8051_OP_CC,
	cpu8051_OP_CD,
	cpu8051_OP_CE,
	cpu8051_OP_CF,
	cpu8051_OP_D0,
	cpu8051_OP_D1,
	cpu8051_OP_D2,
	cpu8051_OP_D3,
	cpu8051_OP_D4,
	cpu8051_OP_D5,
	cpu8051_OP_D6,
	cpu8051_OP_D7,
	cpu8051_OP_D8,
	cpu8051_OP_D9,
	cpu8051_OP_DA,
	cpu8051_OP_DB,
	cpu8051_OP_DC,
	cpu8051_OP_DD,
	cpu8051_OP_DE,
	cpu8051_OP_DF,
	cpu8051_OP_E0,
	cpu8051_OP_E1,
	cpu8051_OP_E2,
	cpu8051_OP_E3,
	cpu8051_OP_E4,
	cpu8051_OP_E5,
	cpu8051_OP_E6,
	cpu8051_OP_E7,
	cpu8051_OP_E8,
	cpu8051_OP_E9,
	cpu8051_OP_EA,
	cpu8051_OP_EB,
	cpu8051_OP_EC,
	cpu8051_OP_ED,
	cpu8051_OP_EE,
	cpu8051_OP_EF,
	cpu8051_OP_F0,
	cpu8051_OP_F1,
	cpu8051_OP_F2,
	cpu8051_OP_F3,
	cpu8051_OP_F4,
	cpu8051_OP_F5,
	cpu8051_OP_F6,
	cpu8051_OP_F7,
	cpu8051_OP_F8,
	cpu8051_OP_F9,
	cpu8051_OP_FA,
	cpu8051_OP_FB,
	cpu8051_OP_FC,
	cpu8051_OP_FD,
	cpu8051_OP_FE,
	cpu8051_OP_FF,
};
#else
extern OPCODE_FP opcode_table[256];
#endif


#endif /* INSTRUCTIONS_8051_H */
