file(REMOVE_RECURSE
  "libsundials_sunlinsolspfgmr.3.7.0.dylib"
  "libsundials_sunlinsolspfgmr.dylib"
  "libsundials_sunlinsolspfgmr.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunlinsolspfgmr_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
