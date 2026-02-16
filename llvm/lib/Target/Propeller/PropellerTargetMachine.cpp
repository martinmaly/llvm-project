#include "PropellerTargetMachine.h"
#include "Propeller.h"
#include "TargetInfo/PropellerTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerTarget() {
  llvm::RegisterTargetMachine<llvm::PropellerTargetMachine> P(
      llvm::getThePropellerTarget());
}

namespace {

/// Propeller Code Generator Pass Configuration Options.
class PropellerPassConfig : public llvm::TargetPassConfig {
public:
  PropellerPassConfig(llvm::TargetMachine &TM, llvm::PassManagerBase &PM);

  llvm::PropellerTargetMachine &getPropellerTargetMachine() const {
    return getTM<llvm::PropellerTargetMachine>();
  }

  bool addInstSelector() override;
};

} // namespace

PropellerPassConfig::PropellerPassConfig(llvm::TargetMachine &TM,
                                         llvm::PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

bool PropellerPassConfig::addInstSelector() {
  addPass(llvm::createPropellerISelDag(getPropellerTargetMachine()));
  return false;
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

TargetPassConfig *
PropellerTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new PropellerPassConfig(*this, PM);
}

} // namespace llvm