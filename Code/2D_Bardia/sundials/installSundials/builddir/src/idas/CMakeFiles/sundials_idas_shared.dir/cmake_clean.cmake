file(REMOVE_RECURSE
  "libsundials_idas.4.7.0.dylib"
  "libsundials_idas.4.dylib"
  "libsundials_idas.dylib"
  "libsundials_idas.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_idas_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
