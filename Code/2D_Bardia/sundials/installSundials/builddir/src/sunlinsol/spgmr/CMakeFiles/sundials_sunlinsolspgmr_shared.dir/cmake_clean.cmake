file(REMOVE_RECURSE
  "libsundials_sunlinsolspgmr.3.7.0.dylib"
  "libsundials_sunlinsolspgmr.dylib"
  "libsundials_sunlinsolspgmr.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunlinsolspgmr_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
