#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

static llvm::Target &getThePropellerTarget() {
  static llvm::Target ThePropellerTarget;
  return ThePropellerTarget;
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerTargetInfo() {
  llvm::RegisterTarget<llvm::Triple::propeller, /*HasJIT=*/false> X(
      getThePropellerTarget(), "propeller", "Parallax Propeller", "Propeller");
}