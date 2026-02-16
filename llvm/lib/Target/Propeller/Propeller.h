#ifndef LLVM_LIB_TARGET_PROPELLER_PROPELLER_H
#define LLVM_LIB_TARGET_PROPELLER_PROPELLER_H

#include "MCTargetDesc/PropellerMCTargetDesc.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class FunctionPass;
class PropellerTargetMachine;

FunctionPass *createPropellerISelDag(PropellerTargetMachine &TM);

} // namespace llvm

#endif