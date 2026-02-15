#ifndef LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERMCASMINFO_H
#define LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class PropellerMCAsmInfo : public MCAsmInfoELF {

public:
  explicit PropellerMCAsmInfo(const Triple &TT);
};

} // namespace llvm

#endif