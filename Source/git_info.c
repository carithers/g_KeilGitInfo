
#include "git_info.h"

#if GIT_COMMIT_HASH_HEX

#if GIT_IS_CLEAN != 1
#warning "git:有变更文件未提交!"
#endif

const git_info_t git_info __attribute__((used)) = {
    .hash = GIT_COMMIT_HASH_HEX,
    .commit_time = GIT_COMMIT_TIME,
    .commit_author = GIT_COMMIT_AUTHOR,
    .is_clean = GIT_IS_CLEAN,
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
 *         [  py RTE/GitInfo/git_info  ] has been added (and checked/ticked).
 * { doc: https://github.com/carithers/g_KeilGitInfo }
 */

#endif

