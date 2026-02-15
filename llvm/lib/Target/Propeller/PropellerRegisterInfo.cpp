#include "PropellerRegisterInfo.h"
#include "Propeller.h"
#include "PropellerFrameLowering.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_REGINFO_TARGET_DESC
#include "PropellerGenRegisterInfo.inc"
