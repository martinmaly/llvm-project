#include "PropellerTargetMachine.h"
#include "TargetInfo/PropellerTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerTarget() {
  llvm::RegisterTargetMachine<llvm::PropellerTargetMachine> P(
      llvm::getThePropellerTarget());
}

namespace llvm {

PropellerTargetMachine::PropellerTargetMachine(
    const Target &T, const Triple &TT, StringRef CPU, StringRef FS,
    const TargetOptions &Options, std::optional<Reloc::Model> RM,
    std::optional<CodeModel::Model> CM, CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, TT.computeDataLayout(), TT, CPU, FS, Options,
                               Reloc::Static, CodeModel::Small, OL) {
  initAsmInfo();
}

PropellerTargetMachine::~PropellerTargetMachine() = default;

} // namespace llvm