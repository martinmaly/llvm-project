add_llvm_component_library(LLVMPropellerDesc
  PropellerAsmBackend.cpp
  PropellerELFObjectWriter.cpp
  PropellerMCAsmInfo.cpp
  PropellerMCCodeEmitter.cpp
  PropellerMCTargetDesc.cpp
  PropellerTargetStreamer.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Propeller
  )
