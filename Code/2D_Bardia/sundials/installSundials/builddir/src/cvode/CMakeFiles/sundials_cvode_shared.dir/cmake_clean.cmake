file(REMOVE_RECURSE
  "libsundials_cvode.5.7.0.dylib"
  "libsundials_cvode.5.dylib"
  "libsundials_cvode.dylib"
  "libsundials_cvode.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_cvode_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
