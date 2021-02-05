file(REMOVE_RECURSE
  "libsundials_sunlinsolband.3.7.0.dylib"
  "libsundials_sunlinsolband.dylib"
  "libsundials_sunlinsolband.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunlinsolband_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
