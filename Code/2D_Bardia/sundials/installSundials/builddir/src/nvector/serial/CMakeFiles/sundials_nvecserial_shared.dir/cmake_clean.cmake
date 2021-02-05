file(REMOVE_RECURSE
  "libsundials_nvecserial.5.7.0.dylib"
  "libsundials_nvecserial.5.dylib"
  "libsundials_nvecserial.dylib"
  "libsundials_nvecserial.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_nvecserial_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
