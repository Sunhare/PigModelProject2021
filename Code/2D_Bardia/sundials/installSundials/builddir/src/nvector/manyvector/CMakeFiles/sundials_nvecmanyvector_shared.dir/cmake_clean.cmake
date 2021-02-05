file(REMOVE_RECURSE
  "libsundials_nvecmanyvector.5.7.0.dylib"
  "libsundials_nvecmanyvector.5.dylib"
  "libsundials_nvecmanyvector.dylib"
  "libsundials_nvecmanyvector.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_nvecmanyvector_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
