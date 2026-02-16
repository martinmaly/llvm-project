#include "PropellerMCTargetDesc.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"

using namespace llvm;

namespace {

class PropellerMCCodeEmitter : public MCCodeEmitter {
  MCContext &Ctx;

public:
  PropellerMCCodeEmitter(const MCInstrInfo &II, MCContext &ctx);

  virtual void encodeInstruction(const MCInst &Inst, SmallVectorImpl<char> &CB,
                                 SmallVectorImpl<MCFixup> &Fixups,
                                 const MCSubtargetInfo &STI) const override;
};

} // end namespace

inline PropellerMCCodeEmitter::PropellerMCCodeEmitter(const MCInstrInfo &II,
                                                      MCContext &ctx)
    : Ctx(ctx) {}

void PropellerMCCodeEmitter::encodeInstruction(
    const MCInst &Inst, SmallVectorImpl<char> &CB,
    SmallVectorImpl<MCFixup> &Fixups, const MCSubtargetInfo &STI) const {
  assert(false && "Not Implemented");
}

MCCodeEmitter *llvm::createPropellerMCCodeEmitter(const MCInstrInfo &II,
                                                  MCContext &Ctx) {
  return new PropellerMCCodeEmitter(II, Ctx);
}