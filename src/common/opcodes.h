/*
 * opcodes.h
 *
 * Do not modify this file directly, as it was created by opcodes2c.pl
 * Any modifications made directly to this file will be lost.
 *
 * Copyright (C) 1999 Jonathan St-André
 * Copyright (C) 1999 Hugo Villeneuve <hugo.com>
 *
 * This file is released under the GPLv2
 */

#ifndef OPCODES_H
#define OPCODES_H 1

int
opcodes_get_instr_size(uint8_t opcode);
char *
opcodes_get_instr_type_str(uint8_t opcode);
int
opcodes_get_instr_arg_type_id(unsigned int offset);
char *
opcodes_get_instr_arg_type_str(unsigned int offset);
#endif /* OPCODES_IMP */
