#ifndef LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERINSTPRINTER_H
#define LLVM_LIB_TARGET_PROPELLER_MCTARGETDESC_PROPELLERINSTPRINTER_H

#include "PropellerMCTargetDesc.h"
#include "llvm/MC/MCInstPrinter.h"

namespace llvm {

class PropellerInstPrinter : public MCInstPrinter {
public:
  PropellerInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                       const MCRegisterInfo &MRI);

  virtual std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override;

  virtual void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                         const MCSubtargetInfo &STI, raw_ostream &OS) override;
};

} // namespace llvm

#endif