/* @header@ */
#include <stdint.h>

#include "emu/emu_cpu.h"
#include "emu/emu_cpu_data.h"
#include "emu/emu_cpu_functions.h"
#include "emu/emu_memory.h"



int32_t instr_mov_88(struct emu_cpu *c, struct instruction *i)
{

	/* 88 /r  
	 * Move r8 to r/m8									
	 * MOV r/m8,r8      
	 */

	if( i->modrm.mod != 3 )
	{
		MEM_BYTE_WRITE(c, i->modrm.ea, *c->reg8[i->modrm.opc]);
	}
	else
	{
		*c->reg8[i->modrm.rm] = *c->reg8[i->modrm.opc];
	}

	return 0;
}

int32_t instr_mov_89(struct emu_cpu *c, struct instruction *i)
{

																		 
	/* 89 /r  
	 * Move r16 to r/m16                                
	 * MOV r/m16,r16    
	 */																		 

	/* 89 /r  
	 * Move r32 to r/m32                                
	 * MOV r/m32,r32    
	 */																		 

	if( i->prefixes & PREFIX_OPSIZE )
	{
		if( i->modrm.mod != 3 )
		{
			MEM_WORD_WRITE(c, i->modrm.ea, *c->reg16[i->modrm.opc]);
		}
		else
		{
			*c->reg16[i->modrm.rm] = *c->reg16[i->modrm.opc];
		}
	}
	else
	{
		if( i->modrm.mod != 3 )
		{
			MEM_DWORD_WRITE(c, i->modrm.ea, c->reg[i->modrm.opc]);
		}
		else
		{
			c->reg[i->modrm.rm] = c->reg[i->modrm.opc];
		}
	}

	return 0;
}

int32_t instr_mov_8a(struct emu_cpu *c, struct instruction *i)
{


	/* 8A /r  
	 * Move r/m8 to r8                                  
	 * MOV r8,r/m8      
	 */																		 

	if( i->modrm.mod != 3 )
	{
		MEM_BYTE_READ(c, i->modrm.ea, c->reg8[i->modrm.opc]);
	}
	else
	{
		*c->reg8[i->modrm.opc] = *c->reg8[i->modrm.rm];
	}

	return 0;
}

int32_t instr_mov_8b(struct emu_cpu *c, struct instruction *i)
{


	/* 8B /r  
	 * Move r/m16 to r16                                
	 * MOV r16,r/m16    
	 */																		 

	/* 8B /r  
	 * Move r/m32 to r32                                
	 * MOV r32,r/m32    
	 */																		 

	if( i->prefixes & PREFIX_OPSIZE )
	{
		if( i->modrm.mod != 3 )
		{
			MEM_WORD_READ(c, i->modrm.ea, c->reg16[i->modrm.opc]);
		}
		else
		{
			*c->reg16[i->modrm.opc] = *c->reg16[i->modrm.rm];
		}
	}
	else
	{
		if( i->modrm.mod != 3 )
		{
			MEM_DWORD_READ(c, i->modrm.ea, &c->reg[i->modrm.opc]);
		}
		else
		{
			c->reg[i->modrm.opc] = c->reg[i->modrm.rm];
		}
	}

	return 0;
}

int32_t instr_mov_8c(struct emu_cpu *c, struct instruction *i)
{


	/* 8C /r  
	 * Move segment register to r/m16                   
	 * MOV r/m16,Sreg** 
	 */																		 


	return 0;
}

int32_t instr_mov_8e(struct emu_cpu *c, struct instruction *i)
{


	/* 8E /r  
	 * Move r/m16 to segment register                   
	 * MOV Sreg,r/m16** 
	 */																		 


	return 0;
}

int32_t instr_mov_a0(struct emu_cpu *c, struct instruction *i)
{

																		 
	/* A0     
	 * Move byte at (seg:offset) to AL                  
	 * MOV AL,moffs8*   
	 */																		 


	return 0;
}

int32_t instr_mov_a1(struct emu_cpu *c, struct instruction *i)
{


	/* A1     
	 * Move word at (seg:offset) to AX                  
	 * MOV AX,moffs16*  
	 */																		 

	/* A1     
	 * Move doubleword at (seg:offset) to EAX           
	 * MOV EAX,moffs32* 
	 */


	return 0;
}

int32_t instr_mov_a2(struct emu_cpu *c, struct instruction *i)
{


	/* A2     
	 * Move AL to (seg:offset)                          
	 * MOV moffs8*,AL   
	 */																		 


	return 0;
}

int32_t instr_mov_a3(struct emu_cpu *c, struct instruction *i)
{


	/* A3     
	 * Move AX to (seg:offset)                          
	 * MOV moffs16*,AX  
	 */
	/* A3     
	 * Move EAX to (seg:offset)                         
	 * MOV moffs32*,EAX 
	 */																		 


	return 0;
}

int32_t instr_mov_bx_1(struct emu_cpu *c, struct instruction *i)
{
	/* B0+ rb 
	 * Move imm8 to r8                                  
	 * MOV r8,imm8      
	 */

	/* B8+ rw 
	 * Move imm16 to r16                                
	 * MOV r16,imm16    
	 */

	/* B8+ rd 
	 * Move imm32 to r32                                
	 * MOV r32,imm32    
	 */																		 

	*c->reg8[i->opc & 7] = *i->imm8;

	return 0;
}

int32_t instr_mov_bx_2(struct emu_cpu *c, struct instruction *i)
{
	/* B0+ rb 
	 * Move imm8 to r8                                  
	 * MOV r8,imm8      
	 */

	/* B8+ rw 
	 * Move imm16 to r16                                
	 * MOV r16,imm16    
	 */

	/* B8+ rd 
	 * Move imm32 to r32                                
	 * MOV r32,imm32    
	 */																		 

	if( i->prefixes & PREFIX_OPSIZE )
		*c->reg16[i->opc & 7] = *i->imm16;
	else
		c->reg[i->opc & 7] = i->imm;

	return 0;
}

int32_t instr_mov_c6(struct emu_cpu *c, struct instruction *i)
{


	/* C6 /0  
	 * Move imm8 to r/m8                                
	 * MOV r/m8,imm8    
	 */
	
	if( i->modrm.mod != 3 )
	{
		MEM_BYTE_WRITE(c, i->modrm.ea, *i->imm8);
	}
	else
	{
		*c->reg8[i->modrm.rm] = *i->imm8;
	}																	 

	return 0;
}

int32_t instr_mov_c7(struct emu_cpu *c, struct instruction *i)
{
	/* C7 /0  
	 * Move imm16 to r/m16                              
	 * MOV r/m16,imm16  
	 */																		 

	/* C7 /0  
	 * Move imm32 to r/m32                              
	 * MOV r/m32,imm32  
	 */

	if( i->prefixes & PREFIX_OPSIZE )
	{
		if( i->modrm.mod != 3 )
		{
			MEM_WORD_WRITE(c, i->modrm.ea, *i->imm16);
		}
		else
		{
			*c->reg16[i->modrm.rm] = *i->imm16;
		}																	 
	}
	else
	{
		if( i->modrm.mod != 3 )
		{
			MEM_DWORD_WRITE(c, i->modrm.ea, i->imm);
		}
		else
		{
			c->reg[i->modrm.rm] = i->imm;
		}																	 
	}

	return 0;
}



