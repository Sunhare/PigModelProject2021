file(REMOVE_RECURSE
  "libsundials_sunmatrixband.3.7.0.dylib"
  "libsundials_sunmatrixband.3.dylib"
  "libsundials_sunmatrixband.dylib"
  "libsundials_sunmatrixband.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunmatrixband_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
