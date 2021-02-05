file(REMOVE_RECURSE
  "libsundials_sunnonlinsolfixedpoint.2.7.0.dylib"
  "libsundials_sunnonlinsolfixedpoint.dylib"
  "libsundials_sunnonlinsolfixedpoint.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunnonlinsolfixedpoint_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
