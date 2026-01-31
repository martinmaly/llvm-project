def i9 : VTInt<9>;  // 9-bit integer value

let OperandType = "OPERAND_IMMEDIATE" in {
  def i9imm : Operand<i9>;
}



def NOP: PropInst<0b000000, (outs), (ins)> {
  let zcri = 0b0000;
  let cond = 0b0000;
  let dest = 0;
  let src = 0;
}

defm ABS : Conditional;
defm ADD : Conditional, InstDS<0b100000>;
defm AND : InstDS<0b011000>, Conditional;

defm CMP : CInst<0b100001, (outs), (ins)>;

/*

Instruction -INSTR-ZCRI-COND-DESTINATI-SOURCE--- Z Result C Result Result Clocks

ABS    D, S 101010 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
ABSNEG D, S 101011 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
ADD    D, S 100000 001i 1111 ddddddddd sssssssss D + S = 0 Unsigned Carry Written 4
ADDABS D, S 100010 001i 1111 ddddddddd sssssssss D + |S| = 0 Unsigned Carry 3 Written 4
ADDS   D, S 110100 001i 1111 ddddddddd sssssssss D + S = 0 Signed Overflow Written 4
ADDSX  D, S 110110 001i 1111 ddddddddd sssssssss Z & (D+S+C = 0) Signed Overflow Written 4
ADDX   D, S 110010 001i 1111 ddddddddd sssssssss Z & (D+S+C = 0) Unsigned Carry Written 4
AND    D, S 011000 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4
ANDN   D, S 011001 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4

CALL     #S 010111 0011 1111 ????????? sssssssss Result = 0 --- Written 4

CLKSET D    000011 0001 1111 ddddddddd ------000 --- --- Not Written 8..23 1

CMP    D, S 100001 000i 1111 ddddddddd sssssssss D = S Unsigned (D < S) Not Written 4
CMPS   D, S 110000 000i 1111 ddddddddd sssssssss D = S Signed (D < S) Not Written 4
CMPSUB D, S 111000 001i 1111 ddddddddd sssssssss D = S Unsigned (D => S) Written 4
CMPSX  D, S 110001 000i 1111 ddddddddd sssssssss Z & (D = S+C) Signed (D < S+C) Not Written 4
CMPX   D, S 110011 000i 1111 ddddddddd sssssssss Z & (D = S+C) Unsigned (D < S+C) Not Written 4

COGID  D    000011 0011 1111 ddddddddd ------001 ID = 0 0 Written 8..23 1
COGINIT D   000011 0001 1111 ddddddddd ------010 ID = 0 No Cog Free Not Written 8..23 1
COGSTOP D   000011 0001 1111 ddddddddd ------011 Stopped ID = 0 No Cog Free Not Written 8..23 1

DJNZ   D, S 111001 001i 1111 ddddddddd sssssssss Result = 0 Unsigned Borrow Written 4 or 8 2
HUBOP  D, S 000011 000i 1111 ddddddddd sssssssss Result = 0 --- Not Written 8..23 1
JMP       S 010111 000i 1111 --------- sssssssss Result = 0 --- Not Written 4
JMPRET D, S 010111 001i 1111 ddddddddd sssssssss Result = 0 --- Written 4

LOCKCLR D   000011 0001 1111 ddddddddd ------111 ID = 0 Prior Lock State Not Written 8..23 1
LOCKNEW D   000011 0011 1111 ddddddddd ------100 ID = 0 No Lock Free Written 8..23 1
LOCKRET D   000011 0001 1111 ddddddddd ------101 ID = 0 No Lock Free Not Written 8..23 1
LOCKSET D   000011 0001 1111 ddddddddd ------110 ID = 0 Prior Lock State Not Written 8..23 1

MAX    D, S 010011 001i 1111 ddddddddd sssssssss S = 0 Unsigned (D < S) Written 4
MAXS   D, S 010001 001i 1111 ddddddddd sssssssss S = 0 Signed (D < S) Written 4
MIN    D, S 010010 001i 1111 ddddddddd sssssssss S = 0 Unsigned (D < S) Written 4
MINS   D, S 010000 001i 1111 ddddddddd sssssssss S = 0 Signed (D < S) Written 4
MOV    D, S 101000 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
MOVD   D, S 010101 001i 1111 ddddddddd sssssssss Result = 0 --- Written 4
MOVI   D, S 010110 001i 1111 ddddddddd sssssssss Result = 0 --- Written 4
MOVS   D, S 010100 001i 1111 ddddddddd sssssssss Result = 0 --- Written 4
MUXC   D, S 011100 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4
MUXNC  D, S 011101 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4
MUXNZ  D, S 011111 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4
MUXZ   D, S 011110 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4
NEG    D, S 101001 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
NEGC   D, S 101100 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
NEGNC  D, S 101101 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
NEGNZ  D, S 101111 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
NEGZ   D, S 101110 001i 1111 ddddddddd sssssssss Result = 0 S[31] Written 4
NOP         ------ ---- 0000 --------- --------- --- --- --- 4
OR     D, S 011010 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4
RCL    D, S 001101 001i 1111 ddddddddd sssssssss Result = 0 D[31] Written 4
RCR    D, S 001100 001i 1111 ddddddddd sssssssss Result = 0 D[0] Written 4
RDBYTE D, S 000000 001i 1111 ddddddddd sssssssss Result = 0 --- Written 8..23 1
RDLONG D, S 000010 001i 1111 ddddddddd sssssssss Result = 0 --- Written 8..23 1
RDWORD D, S 000001 001i 1111 ddddddddd sssssssss Result = 0 --- Written 8..23 1
RET         010111 0001 1111 --------- --------- Result = 0 --- Not Written 4
REV    D, S 001111 001i 1111 ddddddddd sssssssss Result = 0 D[0] Written 4
ROL    D, S 001001 001i 1111 ddddddddd sssssssss Result = 0 D[31] Written 4
ROR    D, S 001000 001i 1111 ddddddddd sssssssss Result = 0 D[0] Written 4
SAR    D, S 001110 001i 1111 ddddddddd sssssssss Result = 0 D[0] Written 4
SHL    D, S 001011 001i 1111 ddddddddd sssssssss Result = 0 D[31] Written 4
SHR    D, S 001010 001i 1111 ddddddddd sssssssss Result = 0 D[0] Written 4
SUB    D, S 100001 001i 1111 ddddddddd sssssssss D - S = 0 Unsigned Borrow Written 4
SUBABS D, S 100011 001i 1111 ddddddddd sssssssss D - |S| = 0 Unsigned Borrow 4 Written 4
SUBS   D, S 110101 001i 1111 ddddddddd sssssssss D - S = 0 Signed Overflow Written 4
SUBSX  D, S 110111 001i 1111 ddddddddd sssssssss Z & (D-(S+C) = 0) Signed Overflow Written 4
SUBX   D, S 110011 001i 1111 ddddddddd sssssssss Z & (D-(S+C) = 0) Unsigned Borrow Written 4
SUMC   D, S 100100 001i 1111 ddddddddd sssssssss D ± S = 0 Signed Overflow Written 4
SUMNC  D, S 100101 001i 1111 ddddddddd sssssssss D ± S = 0 Signed Overflow Written 4
SUMNZ  D, S 100111 001i 1111 ddddddddd sssssssss D ± S = 0 Signed Overflow Written 4
SUMZ   D, S 100110 001i 1111 ddddddddd sssssssss D ± S = 0 Signed Overflow Written 4
TEST   D, S 011000 000i 1111 ddddddddd sssssssss D = 0 Parity of Result Not Written 4
TESTN  D, S 011001 000i 1111 ddddddddd sssssssss D = 0 Parity of Result Not Written 4
TJNZ   D, S 111010 000i 1111 ddddddddd sssssssss D = 0 0 Not Written 4 or 8 2
TJZ    D, S 111011 000i 1111 ddddddddd sssssssss D = 0 0 Not Written 4 or 8 2
WAITCNT D, S 111110 001i 1111 ddddddddd sssssssss Result = 0 Unsigned Carry Written 6+
WAITPEQ D, S 111100 000i 1111 ddddddddd sssssssss Result = 0 --- Not Written 6+
WAITPNE D, S 111101 000i 1111 ddddddddd sssssssss Result = 0 --- Not Written 6+
WAITVID D, S 111111 000i 1111 ddddddddd sssssssss Result = 0 --- Not Written 4+ 5
WRBYTE D, S 000000 000i 1111 ddddddddd sssssssss --- --- Not Written 8..23 1
WRLONG D, S 000010 000i 1111 ddddddddd sssssssss --- --- Not Written 8..23 1
WRWORD D, S 000001 000i 1111 ddddddddd sssssssss --- --- Not Written 8..23 1
XOR    D, S 011011 001i 1111 ddddddddd sssssssss Result = 0 Parity of Result Written 4

*/