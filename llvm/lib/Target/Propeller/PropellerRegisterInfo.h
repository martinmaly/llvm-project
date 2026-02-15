#ifndef LLVM_LIB_TARGET_PROPELLER_PROPELLERREGISTERINFO_H
#define LLVM_LIB_TARGET_PROPELLER_PROPELLERREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "PropellerGenRegisterInfo.inc"

namespace llvm {

struct PropellerRegisterInfo : public PropellerGenRegisterInfo {};

} // namespace llvm

#endif