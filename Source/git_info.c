
#include "git_info"

#if GIT_COMMIT_HASH_HEX > 0

#if GIT_IS_CLEAN != 1
#warning "git: Uncommitted changes!"
#endif

const git_info_t git_info __attribute__((used)) = {
    .hash = GIT_COMMIT_HASH_HEX,
    .is_clean = GIT_IS_CLEAN,
    .commit_time = GIT_COMMIT_TIME,
    .commit_author = GIT_COMMIT_AUTHOR,
    .build_author = BUILD_AUTHOR,
    .build_time = BUILD_EXECUTION_TIME
};

#else

#error " GitInfo configuration error! "
/* 1. Please ensure that git and Python are installed.
 * 2. Please ensure that GitInfo(https://github.com/carithers/g_KeilGitInfo/release) is installed.
 * 3. Please ensure that the project is tracked with git.
 * 4. Please ensure that in
 *     Keil -> Options for Target (magic wand) -> User -> Before Build/Rebuild,
 *         [  cmd /Q /c "ren .\RTE\GitInfo\git_info git_info.bat & .\RTE\GitInfo\git_info.bat & ren .\RTE\GitInfo\git_info.bat git_info" ] has been added (and checked/ticked).
 * 5. git init
 * 6. git add .
 * 7. git commit -m init
 * { doc: https://github.com/carithers/g_KeilGitInfo }
 */

#endif

