file(REMOVE_RECURSE
  "libsundials_arkode.4.7.0.dylib"
  "libsundials_arkode.4.dylib"
  "libsundials_arkode.dylib"
  "libsundials_arkode.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_arkode_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
