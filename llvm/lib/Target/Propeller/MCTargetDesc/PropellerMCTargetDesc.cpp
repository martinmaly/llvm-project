#include "PropellerMCTargetDesc.h"
#include "PropellerMCAsmInfo.h"
#include "PropellerTargetStreamer.h"
#include "TargetInfo/PropellerTargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#define ENABLE_INSTR_PREDICATE_VERIFIER
#include "PropellerGenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "PropellerGenRegisterInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "PropellerGenSubtargetInfo.inc"

static MCAsmInfo *createPropellerMCAsmInfo(const MCRegisterInfo &MRI,
                                           const Triple &TT,
                                           const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new PropellerMCAsmInfo(TT);
  return MAI;
}

static MCInstrInfo *createPropellerMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitPropellerMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createPropellerMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitPropellerMCRegisterInfo(X, Propeller::Reg0);
  return X;
}

static MCSubtargetInfo *createPropellerMCSubtargetInfo(const Triple &TT,
                                                       StringRef CPU,
                                                       StringRef Features) {
  MCSubtargetInfo *STI =
      createPropellerMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, Features);
  return STI;
}

static MCTargetStreamer *
createObjectTargetStreamer(MCStreamer &S, const MCSubtargetInfo &STI) {
  return new PropellerTargetELFStreamer(S, STI);
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializePropellerTargetMC() {
  Target &T = getThePropellerTarget();
  RegisterMCAsmInfoFn X(T, createPropellerMCAsmInfo);

  TargetRegistry::RegisterMCInstrInfo(T, createPropellerMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createPropellerMCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createPropellerMCSubtargetInfo);
  TargetRegistry::RegisterMCCodeEmitter(T, createPropellerMCCodeEmitter);
  TargetRegistry::RegisterMCAsmBackend(T, createPropellerAsmBackend);
  TargetRegistry::RegisterObjectTargetStreamer(T, createObjectTargetStreamer);
}
