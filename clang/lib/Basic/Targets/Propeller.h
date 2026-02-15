#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_PROPELLER_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_PROPELLER_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/TargetParser/Triple.h"

namespace clang {
namespace targets {
class LLVM_LIBRARY_VISIBILITY PropellerTargetInfo : public TargetInfo {

public:
  PropellerTargetInfo(const llvm::Triple &Triple, const TargetOptions &);

  virtual void getTargetDefines(const LangOptions &Opts,
                                MacroBuilder &Builder) const override;
  virtual llvm::SmallVector<Builtin::InfosShard>
  getTargetBuiltins() const override;

  virtual BuiltinVaListKind getBuiltinVaListKind() const override;

  virtual bool
  validateAsmConstraint(const char *&Name,
                        TargetInfo::ConstraintInfo &info) const override;

  virtual std::string_view getClobbers() const override;

protected:
  virtual ArrayRef<const char *> getGCCRegNames() const override;
  virtual ArrayRef<GCCRegAlias> getGCCRegAliases() const override;
};
} // namespace targets
} // namespace clang

#endif
