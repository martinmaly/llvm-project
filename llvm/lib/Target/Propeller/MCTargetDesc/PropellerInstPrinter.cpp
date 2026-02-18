#include "PropellerInstPrinter.h"

using namespace llvm;

PropellerInstPrinter::PropellerInstPrinter(const MCAsmInfo &MAI,
                                           const MCInstrInfo &MII,
                                           const MCRegisterInfo &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

std::pair<const char *, uint64_t>
PropellerInstPrinter::getMnemonic(const MCInst &MI) const {
  assert(false && "Not Implemented");
  return std::pair<const char *, uint64_t>("Hello", 0LL);
}

void PropellerInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                                     StringRef Annot,
                                     const MCSubtargetInfo &STI,
                                     raw_ostream &OS) {
  assert(false && "Not Implemented");
}