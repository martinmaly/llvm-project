include "llvm/Target/Target.td"

include "PropellerRegisterInfo.td"
include "PropellerInstrFormats.td"
include "PropellerInstrInfo.td"

//----------------------------------------------------------------------------//
// Dark Magic
//----------------------------------------------------------------------------//

defm : RemapAllTargetPseudoPointerOperands<GPR>;

//----------------------------------------------------------------------------//
// The Propeller Processor Supported
//----------------------------------------------------------------------------//

def : Processor<"propeller", NoItineraries, []>;

//----------------------------------------------------------------------------//
// The Propeller Target Definition
//----------------------------------------------------------------------------//

def PropellerInstrInfo : InstrInfo {
  let isLittleEndianEncoding = 1;
}

def Propeller : Target {
  let InstructionSet = PropellerInstrInfo;
}