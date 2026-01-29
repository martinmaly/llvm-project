#include "PropellerRegisterInfo.h"
#include "Propeller.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "PropellerFrameLowering.h"

#define GET_REGINFO_TARGET_DESC
#include "PropellerRegisterInfo.inc"
