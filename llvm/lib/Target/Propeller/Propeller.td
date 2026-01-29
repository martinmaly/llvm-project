include "llvm/Target/Target.td"

include "PropellerRegisterInfo.td"
include "PropellerInstrInfo.td"

//----------------------------------------------------------------------------//
// Dark Magic
//----------------------------------------------------------------------------//

defm : RemapAllTargetPseudoPointerOperands<GPR>;

//----------------------------------------------------------------------------//
// The Propeller Target Definition
//----------------------------------------------------------------------------//

def PropellerInstrInfo : InstrInfo {
  let isLittleEndianEncoding = 1;
}

def Propeller : Target {
  let InstructionSet = PropellerInstrInfo;
}