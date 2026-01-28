add_llvm_component_group(Propeller)

set(LLVM_TARGET_DEFINITIONS Propeller.td)

add_llvm_target(PropellerCodeGen
  PropellerTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Target

  ADD_TO_COMPONENT
  Propeller
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)