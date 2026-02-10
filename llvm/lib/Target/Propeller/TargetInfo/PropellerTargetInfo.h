#ifndef LLVM_LIB_TARGET_PROPELLER_TARGETINFO_PROPELLERTARGETINFO_H
#define LLVM_LIB_TARGET_PROPELLER_TARGETINFO_PROPELLERTARGETINFO_H

namespace llvm {

class Target;

Target &getThePropellerTarget();

} // namespace llvm

#endif