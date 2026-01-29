class PropellerRegister<string n, bits<9> enc> : Register<n> {
  let HWEncoding{0...8} = enc;
}

//---------------------------------------------------------------------------//
// Special Purpose Registers
//---------------------------------------------------------------------------//

def PAR: PropellerRegister<"PAR", 0x1F0>;

def SPR: RegisterClass<"Propeller", [i32, f32], 32, (add PAR)>;

def GPR: RegisterClass<"Propeller", [i32], 32, (add PAR)>;