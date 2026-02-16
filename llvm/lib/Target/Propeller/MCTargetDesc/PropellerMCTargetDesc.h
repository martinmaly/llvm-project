#ifndef LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERMCTARGETDESC_H
#define LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERMCTARGETDESC_H

#include "llvm/MC/MCObjectWriter.h"
#include "llvm/Support/DataTypes.h"
#include <memory>

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createPropellerMCCodeEmitter(const MCInstrInfo &II,
                                            MCContext &Ctx);
MCAsmBackend *createPropellerAsmBackend(const Target &T,
                                        const MCSubtargetInfo &STI,
                                        const MCRegisterInfo &MRI,
                                        const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter>
createPropellerELFObjectWriter(uint8_t OSABI);

} // end namespace llvm

#define GET_REGINFO_ENUM
#include "PropellerGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "PropellerGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "PropellerGenSubtargetInfo.inc"

#endif
