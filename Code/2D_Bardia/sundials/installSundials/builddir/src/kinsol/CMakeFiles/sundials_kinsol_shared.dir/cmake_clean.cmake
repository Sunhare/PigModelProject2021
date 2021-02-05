file(REMOVE_RECURSE
  "libsundials_kinsol.5.7.0.dylib"
  "libsundials_kinsol.5.dylib"
  "libsundials_kinsol.dylib"
  "libsundials_kinsol.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_kinsol_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
