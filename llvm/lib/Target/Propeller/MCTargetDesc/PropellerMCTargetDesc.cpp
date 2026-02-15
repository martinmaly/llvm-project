#include "PropellerMCTargetDesc.h"
#include "PropellerMCAsmInfo.h"
#include "TargetInfo/PropellerTargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

#define GET_INSTRINFO_MC_DESC
#define ENABLE_INSTR_PREDICATE_VERIFIER
#include "PropellerGenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "PropellerGenRegisterInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "PropellerGenSubtargetInfo.inc"

static llvm::MCAsmInfo *
createPropellerMCAsmInfo(const llvm::MCRegisterInfo &MRI,
                         const llvm::Triple &TT,
                         const llvm::MCTargetOptions &Options) {
  llvm::MCAsmInfo *MAI = new llvm::PropellerMCAsmInfo(TT);
  return MAI;
}

static llvm::MCInstrInfo *createPropellerMCInstrInfo() {
  llvm::MCInstrInfo *X = new llvm::MCInstrInfo();
  InitPropellerMCInstrInfo(X);
  return X;
}

static llvm::MCRegisterInfo *
createPropellerMCRegisterInfo(const llvm::Triple &TT) {
  llvm::MCRegisterInfo *X = new llvm::MCRegisterInfo();
  InitPropellerMCRegisterInfo(X, llvm::Propeller::Reg0);
  return X;
}

static llvm::MCSubtargetInfo *
createPropellerMCSubtargetInfo(const llvm::Triple &TT, llvm::StringRef CPU,
                               llvm::StringRef Features) {
  llvm::MCSubtargetInfo *STI =
      createPropellerMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, Features);
  return STI;
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerTargetMC() {
  llvm::Target &T = llvm::getThePropellerTarget();
  llvm::RegisterMCAsmInfoFn X(T, createPropellerMCAsmInfo);

  llvm::TargetRegistry::RegisterMCInstrInfo(T, createPropellerMCInstrInfo);
  llvm::TargetRegistry::RegisterMCRegInfo(T, createPropellerMCRegisterInfo);
  llvm::TargetRegistry::RegisterMCSubtargetInfo(T,
                                                createPropellerMCSubtargetInfo);
}
