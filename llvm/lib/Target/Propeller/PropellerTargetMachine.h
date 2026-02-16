#ifndef LLVM_LIB_TARGET_PROPELLER_PROPELLERTARGETMACHINE_H
#define LLVM_LIB_TARGET_PROPELLER_PROPELLERTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

namespace llvm {

class PropellerTargetMachine final : public CodeGenTargetMachineImpl {
public:
  PropellerTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                         StringRef FS, const TargetOptions &Options,
                         std::optional<Reloc::Model> RM,
                         std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                         bool JIT);
  ~PropellerTargetMachine() override;

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};

} // namespace llvm

#endif
