#ifndef ASSEMBLE_H
#define ASSEMBLE_H

typedef enum { PC, ACC, IN1, IN2, SP, BAF, CS, DS, NUM_REGISTERS } Register;

// mapping from regster to enum value

extern const char* register_name_to_code[];

typedef struct {
  char op[8];
  char opd1[23];
  char opd2[23];
  char opd3[23];
} Instruction;

typedef enum {
  ADDI,   // 0b0000000
  SUBI,   // 0b0000001
  MULTI,  // 0b0000010
  DIVI,   // 0b0000011
  MODI,   // 0b0000100
  OPLUSI, // 0b0000101
  ORI,    // 0b0000111
  ANDI,   // 0b0000111
  ADDR,   // 0b0001000
  SUBR,   // 0b0001001
  MULTR,  // 0b0001010
  DIVR,   // 0b0001011
  MODR,   // 0b0001100
  OPLUSR, // 0b0001101
  ORR,    // 0b0001110
  ANDR,   // 0b0001111
  ADDM,   // 0b0010000
  SUBM,   // 0b0010001
  MULTM,  // 0b0010010
  DIVM,   // 0b0010011
  MODM,   // 0b0010100
  OPLUSM, // 0b0010101
  ORM,    // 0b0010110
  ANDM,   // 0b0010111
  LOAD = 0b0100,
  LOADIN = 0b0101,
  LOADI = 0b0111,
  STORE = 0b100,
  STOREIN = 0b1001,
  MOVE = 0b1011,
  NOP = 0b1100000,
  INT = 0b1100001,
  RTI = 0b1100010,
  JUMPGT = 0b1100100,
  JUMPEQ = 0b1101000,
  JUMPGE = 0b1101100,
  JUMPLT = 0b1110000,
  JUMPNE = 0b1110100,
  JUMPLE = 0b1111000,
  JUMP = 0b1111100,
  UNKNOWN,
  NUM_Mnemonics
} Unique_Mnemonic;

typedef struct {
  const char *name;
  Unique_Mnemonic value;
} String_to_Mnemonic;

extern String_to_Mnemonic mnemonic_to_opcode[];

int get_register_code(const char *reg);
const char *get_register_name(int code);
unsigned int assembly_to_machine(Instruction *instruction);
void machine_to_assembly(unsigned int machine_instruction, char *assembly);

#endif // ASSEMBLE_H