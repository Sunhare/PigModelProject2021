file(REMOVE_RECURSE
  "libsundials_ida.5.7.0.dylib"
  "libsundials_ida.5.dylib"
  "libsundials_ida.dylib"
  "libsundials_ida.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/sundials_ida_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
