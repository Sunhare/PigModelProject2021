file(REMOVE_RECURSE
  "libsundials_generic.5.7.0.dylib"
  "libsundials_generic.5.dylib"
  "libsundials_generic.dylib"
  "libsundials_generic.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_generic_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
