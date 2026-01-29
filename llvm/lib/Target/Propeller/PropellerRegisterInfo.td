class PropellerRegister<string n, bits<9> enc> : Register<n> {
  let Namespace = "Propeller";
  let HWEncoding{8...0} = enc;
  int Address = enc;
}

class PropellerRegisterClass<list<ValueType> regTypes, dag regList>
      : RegisterClass<"Propeller", regTypes, 32, regList> {
  let Size = 32;

}

//---------------------------------------------------------------------------//
// General Purpose Registers
//---------------------------------------------------------------------------//
//
// Cog RAM contains 512 32-bit registers. Some of this memory is reserved
// for stack, variables. Some is reserved for compiler to use as registers.

defset list<PropellerRegister> GeneralPurposeRegisters = {
  foreach n = 0-15 in {
    def Reg#n : PropellerRegister<"Reg" # n, !add(0x1E0, n)>;
  }
}

def GPR: RegisterClass<"Propeller", [i32, f32], 32, (add GeneralPurposeRegisters)>;

//---------------------------------------------------------------------------//
// Special Purpose Registers
//---------------------------------------------------------------------------//

defset list<PropellerRegister> SpecialPurposeRegisters = {

  // Read Only Registers

  def PAR: PropellerRegister<"PAR", 0x1F0>; // Boot Parameter
  def CNT: PropellerRegister<"CNT", 0x1F1>; // System Counter
  def INA: PropellerRegister<"INA", 0x1F2>; // Input States for P31–P0
  def INB: PropellerRegister<"INB", 0x1F3>; // Input States for P63–P32

  // Read/Write Registers

  def OUTA: PropellerRegister<"OUTA", 0x1F4>; // Read/Write Output States for P31–P0
  def OUTB: PropellerRegister<"OUTB", 0x1F5>; // Read/Write Output States for P63–P32
  def DIRA: PropellerRegister<"DIRA", 0x1F6>; // Read/Write Direction States for P31–P0
  def DIRB: PropellerRegister<"DIRB", 0x1F7>; // Read/Write Direction States for P63–P32
  def CTRA: PropellerRegister<"CTRA", 0x1F8>; // Read/Write Counter A Control
  def CTRB: PropellerRegister<"CTRB", 0x1F9>; // Read/Write Counter B Control
  def FRQA: PropellerRegister<"FRQA", 0x1FA>; // Read/Write Counter A Frequency
  def FRQB: PropellerRegister<"FRQB", 0x1FB>; // Read/Write Counter B Frequency
  def PHSA: PropellerRegister<"PHSA", 0x1FC>; // Read/Write2 Counter A Phase
  def PHSB: PropellerRegister<"PHSB", 0x1FD>; // Read/Write2 Counter B Phase
  def VCFG: PropellerRegister<"VCFG", 0x1FE>; // Read/Write Video Configuration
  def VSCL: PropellerRegister<"VSCL", 0x1FF>; // Read/Write Video Scale

}

let isAllocatable = 0 in {
  def SPR: RegisterClass<"Propeller", [i32], 32, (add SpecialPurposeRegisters)>;
}

