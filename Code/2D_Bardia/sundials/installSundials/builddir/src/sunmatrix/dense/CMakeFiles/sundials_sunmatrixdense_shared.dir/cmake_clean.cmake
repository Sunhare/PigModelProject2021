file(REMOVE_RECURSE
  "libsundials_sunmatrixdense.3.7.0.dylib"
  "libsundials_sunmatrixdense.3.dylib"
  "libsundials_sunmatrixdense.dylib"
  "libsundials_sunmatrixdense.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunmatrixdense_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
