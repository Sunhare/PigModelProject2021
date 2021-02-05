file(REMOVE_RECURSE
  "libsundials_cvodes.5.7.0.dylib"
  "libsundials_cvodes.5.dylib"
  "libsundials_cvodes.dylib"
  "libsundials_cvodes.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_cvodes_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
