#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

namespace llvm {

Target &getThePropellerTarget() {
  static Target ThePropellerTarget;
  return ThePropellerTarget;
}

} // namespace llvm

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerTargetInfo() {
  llvm::RegisterTarget<llvm::Triple::propeller, /*HasJIT=*/false> X(
      llvm::getThePropellerTarget(), "propeller", "Parallax Propeller", "Propeller");
}