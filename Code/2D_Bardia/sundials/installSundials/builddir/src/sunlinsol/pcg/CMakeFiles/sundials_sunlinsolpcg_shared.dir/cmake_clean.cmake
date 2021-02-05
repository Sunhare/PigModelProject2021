file(REMOVE_RECURSE
  "libsundials_sunlinsolpcg.3.7.0.dylib"
  "libsundials_sunlinsolpcg.dylib"
  "libsundials_sunlinsolpcg.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunlinsolpcg_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
