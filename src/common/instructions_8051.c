/*
 * instructions_8051.c
 *
 * Do not modify this file directly, as it was created by opcodes2c.pl
 * Any modifications made directly to this file will be lost.
 *
 * Copyright (C) 1999 Jonathan St-André
 * Copyright (C) 1999 Hugo Villeneuve <hugo.com>
 *
 * This file is released under the GPLv2
 */

/* Define only here, for not having extern scope on local variables. */
#define INSTRUCTIONS_8051_M 1


#include "reg8051.h"
#include "cpu8051.h"
#include "memory.h"
#include "psw.h"
#include "operations.h"
#include "instructions_8051.h"


/*****************************************************************************
 * Instruction "NOP" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_00(void)
{
	return 1;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_01(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "LJMP addr16" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_02(void)
{
	uint16_t addr16 = pgm_read_addr16(cpu8051.pc);
	cpu8051.pc += 2;
	cpu8051.pc = addr16;
	return 2;
}

/*****************************************************************************
 * Instruction "RR A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_03(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination = ( destination >> 1 ) | ( destination << 7 );
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_04(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination++;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_05(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	destination++;
	mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC @R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_06(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination++;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC @R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_07(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination++;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_08(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	destination++;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_09(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	destination++;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_0A(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	destination++;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_0B(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	destination++;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_0C(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	destination++;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_0D(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	destination++;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_0E(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	destination++;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "INC R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_0F(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	destination++;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JBC bitaddr,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_10(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if ( destination == 1 ) { cpu8051.pc = source; destination = 0; }
	mem_write_bit( dstbitaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_11(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "LCALL addr16" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_12(void)
{
	uint16_t addr16 = pgm_read_addr16(cpu8051.pc);
	cpu8051.pc += 2;
	stack_push16(cpu8051.pc);
	cpu8051.pc = addr16;
	return 2;
}

/*****************************************************************************
 * Instruction "RRC A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_13(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char new_cy = destination & 0x01;
	destination = ( destination >> 1 ) | (psw_read_cy() << 7);
	psw_write_cy(new_cy);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_14(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination--;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_15(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	destination--;
	mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC @R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_16(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination--;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC @R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_17(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination--;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_18(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	destination--;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_19(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	destination--;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_1A(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	destination--;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_1B(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	destination--;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_1C(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	destination--;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_1D(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	destination--;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_1E(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	destination--;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DEC R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_1F(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	destination--;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JB bitaddr,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_20(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if ( destination == 1 ) { cpu8051.pc = source; }
	mem_write_bit( dstbitaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_21(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "RET" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_22(void)
{
	cpu8051.pc = stack_pop16();
	return 2;
}

/*****************************************************************************
 * Instruction "RL A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_23(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination = ( destination << 1 ) | ( destination >> 7 );
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_24(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_25(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_26(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_27(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_28(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_29(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_2A(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_2B(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_2C(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_2D(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_2E(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADD A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_2F(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	destination = addition(destination, source, 0);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JNB bitaddr,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_30(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if ( destination == 0 ) { cpu8051.pc = source; }
	mem_write_bit( dstbitaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_31(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "RETI" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_32(void)
{
	cpu8051.active_priority = -1;
	cpu8051.pc = stack_pop16();
	return 2;
}

/*****************************************************************************
 * Instruction "RLC A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_33(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char new_cy = destination & 0x80;
	destination = ( destination << 1 ) | psw_read_cy();
	psw_write_cy(new_cy);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_34(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_35(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_36(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_37(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_38(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_39(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_3A(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_3B(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_3C(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_3D(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_3E(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ADDC A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_3F(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	unsigned char carryflag = psw_read_cy();
	destination = addition(destination, source, carryflag);
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JC reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_40(void)
{
	cpu8051.pc++;
	unsigned int destination = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if (psw_read_cy()) { cpu8051.pc = destination; }
	return 2;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_41(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "ORL direct,A" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_42(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( _ACC_ );
	destination |= source;
	mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL direct,#data" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_43(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination |= source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "ORL A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_44(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_45(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_46(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_47(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_48(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_49(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_4A(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_4B(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_4C(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_4D(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_4E(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_4F(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	destination |= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JNC reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_50(void)
{
	cpu8051.pc++;
	unsigned int destination = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if (psw_read_cy() == 0) { cpu8051.pc = destination; }
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_51(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "ANL direct,A" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_52(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( _ACC_ );
	destination &= source;
	mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL direct,#data" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_53(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination &= source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "ANL A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_54(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_55(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_56(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_57(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_58(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_59(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_5A(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_5B(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_5C(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_5D(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_5E(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ANL A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_5F(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	destination &= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JZ reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_60(void)
{
	cpu8051.pc++;
	unsigned int destination = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if ( mem_read_direct( _ACC_ ) == 0 ) { cpu8051.pc = destination; }
	return 2;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_61(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "XRL direct,A" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_62(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( _ACC_ );
	destination ^= source;
	mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL direct,#data" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_63(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination ^= source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "XRL A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_64(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_65(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_66(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_67(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_68(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_69(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_6A(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_6B(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_6C(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_6D(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_6E(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XRL A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_6F(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	destination ^= source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "JNZ reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_70(void)
{
	cpu8051.pc++;
	unsigned int destination = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	if ( mem_read_direct( _ACC_ ) != 0 ) { cpu8051.pc = destination; }
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_71(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "ORL C,bitaddr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_72(void)
{
	unsigned char destination = psw_read_cy();
	unsigned char source, srcbitaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	source = mem_read_bit( srcbitaddr );
	destination |= source;
	psw_write_cy(destination);
	return 2;
}

/*****************************************************************************
 * Instruction "JMP @A+DPTR" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_73(void)
{
	unsigned int destination = mem_read_direct( _ACC_ ) + mem_sfr_read_dptr();
	cpu8051.pc = destination;
	return 2;
}

/*****************************************************************************
 * Instruction "MOV A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_74(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV direct,#data" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_75(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV @R0,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_76(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV @R1,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_77(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R0,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_78(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R1,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_79(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R2,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_7A(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R3,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_7B(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R4,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_7C(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R5,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_7D(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R6,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_7E(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R7,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_7F(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	destination = source;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SJMP reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_80(void)
{
	cpu8051.pc++;
	unsigned int destination = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	cpu8051.pc = destination;
	return 2;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_81(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "ANL C,bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_82(void)
{
	unsigned char destination = psw_read_cy();
	unsigned char source, srcbitaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	source = mem_read_bit( srcbitaddr );
	destination &= source;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "MOVC A,@A+PC" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_83(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, mem_read_direct( _ACC_ ) + ( ++cpu8051.pc ) );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DIV AB" takes 4 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_84(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( _B_ );
	psw_clr_cy();
	if (source != 0) {
	    mem_write_direct(_ACC_, destination/source);
	    mem_write_direct( _B_, destination%source);
	    psw_clr_ov();
	} else {
	    psw_set_ov();
	}
	return 4;
}

/*****************************************************************************
 * Instruction "MOV direct,direct" takes 1 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_85(void)
{
  unsigned char srcaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
  unsigned char source = mem_read_direct( srcaddr );
  unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
  unsigned char destination = mem_read_direct( destaddr );
  destination = source;
  mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV direct,@R0" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_86(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,@R1" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_87(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R0" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_88(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R1" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_89(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R2" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_8A(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R3" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_8B(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R4" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_8C(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R5" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_8D(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R6" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_8E(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV direct,R7" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_8F(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV DPTR,#data16" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_90(void)
{
	unsigned int destination = mem_sfr_read_dptr();
	uint16_t source = pgm_read_addr16(cpu8051.pc);
	cpu8051.pc += 2;
	destination = source;
	mem_sfr_write_dptr(destination);
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_91(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "MOV bitaddr,C" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_92(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	unsigned char source = psw_read_cy();
	destination = source;
	mem_write_bit( dstbitaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOVC A,@A+DPTR" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_93(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, mem_read_direct( _ACC_ ) + mem_sfr_read_dptr());
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "SUBB A,#data" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_94(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_95(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_96(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_97(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_98(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_99(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_9A(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_9B(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_9C(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_9D(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_9E(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SUBB A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_9F(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	unsigned char carryflag = psw_read_cy();
	psw_clr_cy();
	psw_clr_ac();
	psw_clr_ov();
	if ( destination < ( source + carryflag ) ) {
	  psw_set_cy();
	  if ((destination & 0x7F) > ((source + carryflag) & 0x7F))  psw_set_ov();
	} else if ((destination & 0x7F) < ((source + carryflag) & 0x7F))   psw_set_ov();
	if ((destination & 0x0F) < ((source + carryflag) & 0x0F))   psw_set_ac();
	destination -= source + carryflag;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "ORL C,/bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A0(void)
{
	unsigned char destination = psw_read_cy();
	unsigned char source, srcbitaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	source = ( mem_read_bit( srcbitaddr ) ^ 1 );
	destination |= source;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A1(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "MOV C,bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A2(void)
{
	unsigned char destination = psw_read_cy();
	unsigned char source, srcbitaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	source = mem_read_bit( srcbitaddr );
	destination = source;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "INC DPTR" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A3(void)
{
	unsigned int destination = mem_sfr_read_dptr();
	destination++;
	mem_sfr_write_dptr(destination);
	return 2;
}

/*****************************************************************************
 * Instruction "MUL AB" takes 4 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A4(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( _B_ );
	psw_clr_cy();
	mem_write_direct(_ACC_, destination * source);
	mem_write_direct(_B_, (destination * source) / 0x100);
	if (mem_read_direct(_B_) > 0)
	    psw_set_ov();
	else
	    psw_clr_ov();
	return 4;
}

/*****************************************************************************
 * Instruction "INVALID" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A5(void)
{
	return 1;
}

/*****************************************************************************
 * Instruction "MOV @R0,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A6(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV @R1,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A7(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R0,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A8(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R1,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_A9(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R2,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_AA(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R3,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_AB(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R4,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_AC(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R5,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_AD(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R6,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_AE(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOV R7,direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_AF(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "ANL C,/bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B0(void)
{
	unsigned char destination = psw_read_cy();
	unsigned char source, srcbitaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	source = ( mem_read_bit( srcbitaddr ) ^ 1 );
	destination &= source;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B1(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "CPL bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B2(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	destination ^= 0x01;
	mem_write_bit( dstbitaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "CPL C" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B3(void)
{
	unsigned char destination = psw_read_cy();
	destination ^= 0x01;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "CJNE A,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B4(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( _ACC_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE A,direct,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B5(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( _ACC_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE @R0,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B6(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE @R1,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B7(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R0,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B8(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R1,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_B9(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R2,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_BA(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R3,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_BB(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R4,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_BC(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R5,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_BD(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R6,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_BE(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CJNE R7,#data,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_BF(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	unsigned char source = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned int reladdr = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc)) + (cpu8051.pc + 1);
	psw_clr_cy();
	if ( destination < source ) psw_set_cy();
	if ( destination != source ) cpu8051.pc = reladdr; else cpu8051.pc++;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "PUSH direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C0(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	stack_push8(destination);
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C1(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "CLR bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C2(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	destination = 0;
	mem_write_bit( dstbitaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "CLR C" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C3(void)
{
	unsigned char destination = psw_read_cy();
	destination = 0;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "SWAP A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C4(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination = ( destination << 4 ) + ( destination >> 4 );
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C5(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( srcaddr, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C6(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C7(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C8(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R0_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_C9(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R1_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_CA(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R2_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_CB(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R3_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_CC(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R4_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_CD(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R5_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_CE(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R6_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCH A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_CF(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	unsigned char tmpval = destination;
	destination = source; source = tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_direct( BANKPSW + _R7_, source );
	return 1;
}

/*****************************************************************************
 * Instruction "POP direct" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D0(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	destination = stack_pop8();
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D1(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "SETB bitaddr" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D2(void)
{
	unsigned char destination, dstbitaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	destination = mem_read_bit( dstbitaddr );
	destination = 1;
	mem_write_bit( dstbitaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "SETB C" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D3(void)
{
	unsigned char destination = psw_read_cy();
	destination = 1;
	psw_write_cy(destination);
	return 1;
}

/*****************************************************************************
 * Instruction "DA A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D4(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	if (((destination & 0x0F) > 9) || psw_read_ac()) {
	   if ( ( destination + 6 ) > 0xFF)  psw_set_cy();
	   destination += 6;
	}
	if ( psw_read_cy() || ( ( destination & 0xF0 ) > 0x90 ) ) {
	   if ( ( destination + 0x60 ) > 0xFF ) psw_set_cy();
	   destination += 0x60;
	}
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "DJNZ direct,reladdr" takes 2 cycle(s) and 3 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D5(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( destaddr, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "XCHD A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D6(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char tmpval = ( destination & 0x0F );
	destination = ( destination & 0xF0 ) + ( source & 0x0F );
	source = ( source & 0xF0 ) + tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), source );
	return 1;
}

/*****************************************************************************
 * Instruction "XCHD A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D7(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char tmpval = ( destination & 0x0F );
	destination = ( destination & 0xF0 ) + ( source & 0x0F );
	source = ( source & 0xF0 ) + tmpval;
	mem_write_direct( _ACC_, destination );
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), source );
	return 1;
}

/*****************************************************************************
 * Instruction "DJNZ R0,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D8(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R1,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_D9(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R2,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_DA(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R3,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_DB(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R4,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_DC(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R5,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_DD(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R6,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_DE(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "DJNZ R7,reladdr" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_DF(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	(cpu8051.pc)++;
	unsigned int source = ((char) mem_read8(PGM_MEM_ID, cpu8051.pc - 1)) + cpu8051.pc;
	destination--;
	if ( destination != 0 ) cpu8051.pc = source;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOVX A,@DPTR" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E0(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect(mem_sfr_read_dptr());
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "AJMP addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E1(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "MOVX A,@R0" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E2(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOVX A,@R1" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E3(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CLR A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E4(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination = 0;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,direct" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E5(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char srcaddr = mem_read8( PGM_MEM_ID, (cpu8051.pc)++ );
	unsigned char source = mem_read_direct( srcaddr );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,@R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E6(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,@R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E7(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R0" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E8(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R0_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R1" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_E9(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R1_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R2" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_EA(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R2_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R3" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_EB(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R3_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R4" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_EC(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R4_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R5" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_ED(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R5_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R6" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_EE(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R6_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV A,R7" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_EF(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	unsigned char source = mem_read_direct( BANKPSW + _R7_ );
	destination = source;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOVX @DPTR,A" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F0(void)
{
	unsigned char destination = mem_read_indirect(mem_sfr_read_dptr());
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_indirect(mem_sfr_read_dptr(), destination);
	return 2;
}

/*****************************************************************************
 * Instruction "ACALL addr11" takes 2 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F1(void)
{
	unsigned int addr11 = ( ( mem_read8( PGM_MEM_ID, cpu8051.pc - 1 ) << 3 ) & 0xF00 ) + mem_read8( PGM_MEM_ID, cpu8051.pc );
	cpu8051.pc++;
	stack_push16(cpu8051.pc);
	cpu8051.pc = ( cpu8051.pc & 0xF800 ) | addr11;
	return 2;
}

/*****************************************************************************
 * Instruction "MOVX @R0,A" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F2(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 2;
}

/*****************************************************************************
 * Instruction "MOVX @R1,A" takes 2 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F3(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 2;
}

/*****************************************************************************
 * Instruction "CPL A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F4(void)
{
	unsigned char destination = mem_read_direct( _ACC_ );
	destination ^= 0xFF;
	mem_write_direct( _ACC_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV direct,A" takes 1 cycle(s) and 2 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F5(void)
{
	unsigned char destaddr = mem_read8( PGM_MEM_ID, cpu8051.pc++ );
	unsigned char destination = mem_read_direct( destaddr );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( destaddr, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV @R0,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F6(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R0_ ) );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R0_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV @R1,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F7(void)
{
	unsigned char destination = mem_read_indirect ( mem_read_direct( BANKPSW + _R1_ ) );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_indirect( mem_read_direct( BANKPSW + _R1_ ), destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R0,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F8(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R0_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R0_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R1,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_F9(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R1_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R1_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R2,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_FA(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R2_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R2_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R3,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_FB(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R3_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R3_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R4,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_FC(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R4_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R4_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R5,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_FD(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R5_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R5_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R6,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_FE(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R6_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R6_, destination );
	return 1;
}

/*****************************************************************************
 * Instruction "MOV R7,A" takes 1 cycle(s) and 1 byte(s).
 ****************************************************************************/
int
cpu8051_OP_FF(void)
{
	unsigned char destination = mem_read_direct( BANKPSW + _R7_ );
	unsigned char source = mem_read_direct( _ACC_ );
	destination = source;
	mem_write_direct( BANKPSW + _R7_, destination );
	return 1;
}

