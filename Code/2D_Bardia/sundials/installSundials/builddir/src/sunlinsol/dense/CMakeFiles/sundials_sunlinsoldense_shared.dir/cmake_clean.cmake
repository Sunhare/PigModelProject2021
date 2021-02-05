file(REMOVE_RECURSE
  "libsundials_sunlinsoldense.3.7.0.dylib"
  "libsundials_sunlinsoldense.dylib"
  "libsundials_sunlinsoldense.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunlinsoldense_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
