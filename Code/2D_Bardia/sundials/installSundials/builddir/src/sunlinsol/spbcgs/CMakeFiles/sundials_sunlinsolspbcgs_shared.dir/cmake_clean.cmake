file(REMOVE_RECURSE
  "libsundials_sunlinsolspbcgs.3.7.0.dylib"
  "libsundials_sunlinsolspbcgs.dylib"
  "libsundials_sunlinsolspbcgs.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunlinsolspbcgs_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
