file(REMOVE_RECURSE
  "libsundials_sunmatrixsparse.3.7.0.dylib"
  "libsundials_sunmatrixsparse.3.dylib"
  "libsundials_sunmatrixsparse.dylib"
  "libsundials_sunmatrixsparse.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_sunmatrixsparse_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
