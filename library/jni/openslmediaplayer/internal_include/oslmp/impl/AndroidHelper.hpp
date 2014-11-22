//
//    Copyright (C) 2014 Haruki Hasegawa
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#ifndef ANDROID_HELPER_HPP_
#define ANDROID_HELPER_HPP_

#include <jni.h>
#include <unistd.h>

namespace oslmp {
namespace impl {

class AndroidHelper {

    AndroidHelper() = delete;

public:
    static bool setThreadPriority(JavaVM *vm, pid_t tid, int prio) noexcept;
    static bool setCurrentThreadName(const char *name) noexcept;
};

// sync. with android.os.Process
enum AndroidThreadPriority {
    ANDROID_THREAD_PRIORITY_LOWEST = 19,
    ANDROID_THREAD_PRIORITY_BACKGROUND = 10,
    ANDROID_THREAD_PRIORITY_DEFAULT = 0,
    ANDROID_THREAD_PRIORITY_MORE_FAVORABLE = -1,
    ANDROID_THREAD_PRIORITY_LESS_FAVORABLE = -2,
    ANDROID_THREAD_PRIORITY_FOREGROUND = -4,
    ANDROID_THREAD_PRIORITY_URGENT_DISPLAY = -8,
    ANDROID_THREAD_PRIORITY_AUDIO = -16,
    ANDROID_THREAD_PRIORITY_URGENT_AUDIO = -19
};

} // namespace impl
} // namespace oslmp

#endif // ANDROID_HELPER_HPP_
