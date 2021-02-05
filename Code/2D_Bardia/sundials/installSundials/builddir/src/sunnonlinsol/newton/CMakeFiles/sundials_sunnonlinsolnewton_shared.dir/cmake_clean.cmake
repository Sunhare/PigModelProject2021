file(REMOVE_RECURSE
  "libsundials_sunnonlinsolnewton.2.7.0.dylib"
  "libsundials_sunnonlinsolnewton.dylib"
  "libsundials_sunnonlinsolnewton.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunnonlinsolnewton_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
