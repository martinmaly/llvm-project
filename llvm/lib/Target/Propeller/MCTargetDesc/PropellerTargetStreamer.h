#ifndef LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERTARGETSTREAMER_H
#define LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERTARGETSTREAMER_H

#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/FormattedStream.h"

namespace llvm {

class PropellerTargetStreamer : public MCTargetStreamer {
public:
  PropellerTargetStreamer(MCStreamer &S);
};

class PropellerTargetAsmStreamer : public PropellerTargetStreamer {
  formatted_raw_ostream &OS;

public:
  PropellerTargetAsmStreamer(MCStreamer &S, formatted_raw_ostream &OS);
};

class PropellerTargetELFStreamer : public PropellerTargetStreamer {
public:
  PropellerTargetELFStreamer(MCStreamer &S, const MCSubtargetInfo &STI);
};

} // namespace llvm

#endif