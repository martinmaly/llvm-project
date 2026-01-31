class PropInst<bits<6> op, dag ool, dag iol> : Instruction {
  bits<4> zcri;
  bits<4> cond;
  bits<9> dest;
  bits<9> src;

  field bits<32> Inst;
  let Namespace = "Prop";
  let Size = 4;

  let Inst{31...26} = op;
  let Inst{25...22} = zcri;
  let Inst{21...18} = cond;
  let Inst{17...9}  = dest;
  let Inst{8...0}   = src;

  let OutOperandList = ool;
  let InOperandList = iol;
}

def CogMem;

multiclass InstDS<bits<6> op> {
  def _r : PropInst<op, (outs), (ins)> {}
  def _i : PropInst<op, (outs), (ins)> {}
}

multiclass InstD<bits<6> op, bits<3> subop> {
  def NAME : PropInst<op, (outs), (ins)> {
    let src{2...0} = subop;
  }
}

multiclass InstS<Bits<6> op> : InstDS<op> {
  
}

class Condition<bits<4> c> {
  bits<4> cond = c;
}


def Condition_if_always    : Condition<0b1111> {} // always []
def Condition_if_never     : Condition<0b0000> {} // never []
def Condition_if_e         : Condition<0b1010> {} // if equal (Z = 1) [IF_Z]
def Condition_if_ne        : Condition<0b0101> {} // if not equal (Z = 0) [IF_NZ]
def Condition_if_a         : Condition<0b0001> {} // if above (!C & !Z = 1) [IF_NC_AND_NZ –and– IF_NZ_AND_NC]
def Condition_if_b         : Condition<0b1100> {} // if below (C = 1) [IF_C]
def Condition_if_ae        : Condition<0b0011> {} // if above or equal (C = 0) [IF_NC]
def Condition_if_be        : Condition<0b1110> {} // if below or equal (C | Z = 1) [IF_C_OR_Z –and– IF_Z_OR_C]
def Condition_if_c         : Condition<0b1100> {} // if C set [IF_B]
def Condition_if_nc        : Condition<0b0011> {} // if C clear [IF_AE]
def Condition_if_z         : Condition<0b1010> {} // if Z set [IF_E]
def Condition_if_nz        : Condition<0b0101> {} // if Z clear [IF_NE]
def Condition_if_c_eq_z    : Condition<0b1001> {} // if C equal to Z [IF_Z_EQ_C]
def Condition_if_c_ne_z    : Condition<0b0110> {} // if C not equal to Z [IF_Z_NE_C]
def Condition_if_c_and_z   : Condition<0b1000> {} // if C set and Z set [IF_Z_AND_C]
def Condition_if_c_and_nz  : Condition<0b0100> {} // if C set and Z clear [IF_NZ_AND_C]
def Condition_if_nc_and_z  : Condition<0b0010> {} // if C clear and Z set [IF_Z_AND_NC]
def Condition_if_nc_and_nz : Condition<0b0001> {} // if C clear and Z clear [IF_A –and– IF_NZ_AND_NC]
def Condition_if_c_or_z    : Condition<0b1110> {} // if C set or Z set [IF_BE –and– IF_Z_OR_C]
def Condition_if_c_or_nz   : Condition<0b1101> {} // if C set or Z clear [IF_NZ_OR_C]
def Condition_if_nc_or_z   : Condition<0b1011> {} // if C clear or Z set [IF_Z_OR_NC]
def Condition_if_nc_or_nz  : Condition<0b0111> {} // if C clear or Z clear [IF_NZ_OR_NC]
def Condition_if_z_eq_c    : Condition<0b1001> {} // if Z equal to C [IF_C_EQ_Z]
def Condition_if_z_ne_c    : Condition<0b0110> {} // if Z not equal to C [IF_C_NE_Z]
def Condition_if_z_and_c   : Condition<0b1000> {} // if Z set and C set [IF_C_AND_Z]
def Condition_if_z_and_nc  : Condition<0b0010> {} // if Z set and C clear [IF_NC_AND_Z]
def Condition_if_nz_and_c  : Condition<0b0100> {} // if Z clear and C set [IF_C_AND_NZ]
def Condition_if_nz_and_nc : Condition<0b0001> {} // if Z clear and C clear [IF_A –and– IF_NC_AND_NZ]
def Condition_if_z_or_c    : Condition<0b1110> {} // if Z set or C set [IF_BE –and– IF_C_OR_Z]
def Condition_if_z_or_nc   : Condition<0b1011> {} // if Z set or C clear [IF_NC_OR_Z]
def Condition_if_nz_or_c   : Condition<0b1101> {} // if Z clear or C set [IF_C_OR_NZ]
def Condition_if_nz_or_nc  : Condition<0b0111> {} // if Z clear or C clear [IF_NC_OR_NZ]

multiclass Conditional {
  def NAME {} // if_always
  def if_never_____ # NAME {}
  def if_e_________ # NAME {}
  def if_ne________ # NAME {}
  def if_a_________ # NAME {}
  def if_b_________ # NAME {}
  def if_ae________ # NAME {}
  def if_be________ # NAME {}
  def if_c_________ # NAME {}
  def if_nc________ # NAME {}
  def if_z_________ # NAME {}
  def if_nz________ # NAME {}
  def if_c_eq_z____ # NAME {}
  def if_c_ne_z____ # NAME {}
  def if_c_and_z___ # NAME {}
  def if_c_and_nz__ # NAME {}
  def if_nc_and_z__ # NAME {}
  def if_nc_and_nz_ # NAME {}
  def if_c_or_z____ # NAME {}
  def if_c_or_nz___ # NAME {}
  def if_nc_or_z___ # NAME {}
  def if_nc_or_nz__ # NAME {}
  def if_z_eq_c____ # NAME {}
  def if_z_ne_c____ # NAME {}
  def if_z_and_c___ # NAME {}
  def if_z_and_nc__ # NAME {}
  def if_nz_and_c__ # NAME {}
  def if_nz_and_nc_ # NAME {}
  def if_z_or_c____ # NAME {}
  def if_z_or_nc___ # NAME {}
  def if_nz_or_c___ # NAME {}
  def if_nz_or_nc__ # NAME {}
}

multiclass CInst<bits<6> op, dag ool, dag iol> : Conditional {
  def NAME : PropInst<op, ool, iol>{}
}