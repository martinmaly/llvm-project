#include "PropellerMCTargetDesc.h"
#include "llvm/BinaryFormat/ELF.h"
#include "llvm/MC/MCELFObjectWriter.h"

using namespace llvm;

namespace {
class PropellerELFObjectWriter : public MCELFObjectTargetWriter {
public:
  explicit PropellerELFObjectWriter(uint8_t OSABI);

  virtual unsigned getRelocType(const MCFixup &Fixup, const MCValue &Target,
                                bool IsPCRel) const override;
};

} // namespace

inline PropellerELFObjectWriter::PropellerELFObjectWriter(uint8_t OSABI)
    : MCELFObjectTargetWriter(/*Is64Bit*/ false, OSABI,
                              /*EMachine*/ llvm::ELF::EM_NONE,
                              /*HasRelocationAddend*/ false) {}

unsigned PropellerELFObjectWriter::getRelocType(const MCFixup &Fixup,
                                                const MCValue &Target,
                                                bool IsPCRel) const {
  assert(false && "Not Implemente");
  return 0;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createPropellerELFObjectWriter(uint8_t OSABI) {
  return std::make_unique<PropellerELFObjectWriter>(OSABI);
}
