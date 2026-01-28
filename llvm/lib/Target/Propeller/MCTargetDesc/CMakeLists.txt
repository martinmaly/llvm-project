add_llvm_component_library(LLVMPropellerDesc
  PropellerMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Propeller
  )
