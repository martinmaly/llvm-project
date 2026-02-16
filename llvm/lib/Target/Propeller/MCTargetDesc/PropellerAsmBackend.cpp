#include "PropellerMCTargetDesc.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

namespace {

class PropellerAsmBackend : public MCAsmBackend {
  Triple::OSType OSType;

public:
  PropellerAsmBackend(const MCSubtargetInfo &STI, Triple::OSType OSType);

  virtual std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override;

  virtual void applyFixup(const MCFragment &, const MCFixup &,
                          const MCValue &Target, uint8_t *Data, uint64_t Value,
                          bool IsResolved) override;

  virtual bool writeNopData(raw_ostream &OS, uint64_t Count,
                            const MCSubtargetInfo *STI) const override;
};

} // end namespace

inline PropellerAsmBackend::PropellerAsmBackend(const MCSubtargetInfo &STI,
                                                Triple::OSType OSType)
    : MCAsmBackend(STI.getTargetTriple().isLittleEndian()
                       ? llvm::endianness::little
                       : llvm::endianness::big),
      OSType(OSType) {}

std::unique_ptr<MCObjectTargetWriter>
PropellerAsmBackend::createObjectTargetWriter() const {
  uint8_t OSABI = MCELFObjectTargetWriter::getOSABI(OSType);

  return createPropellerELFObjectWriter(OSABI);
}

void PropellerAsmBackend::applyFixup(const MCFragment &, const MCFixup &,
                                     const MCValue &Target, uint8_t *Data,
                                     uint64_t Value, bool IsResolved) {
  assert(false && "Not Implemented");
}

bool PropellerAsmBackend::writeNopData(raw_ostream &OS, uint64_t Count,
                                       const MCSubtargetInfo *STI) const {
  assert(false && "Not Implemented");
  return false;
}

MCAsmBackend *llvm::createPropellerAsmBackend(const Target &T,
                                              const MCSubtargetInfo &STI,
                                              const MCRegisterInfo &MRI,
                                              const MCTargetOptions &Options) {
  return new PropellerAsmBackend(STI, STI.getTargetTriple().getOS());
}