/* Copyright (c) 2014-2017, ARM Limited and Contributors
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge,
 * to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef TIMER_H
#define TIMER_H

#include <cstdio>
#include <sys/time.h>

namespace AstcTextures
{
    /**
     * \brief Provides a platform independent high resolution timer.
     * \note The timer measures real time, not CPU time.
     */
    class Timer
    {
        private:
            int frameCount;

            float fps;
            float lastTime;
            float lastIntervalTime;
            float fpsTime;

            timeval startTime;
            timeval currentTime;

        public:
            /**
             * \brief Overloaded default constructor
             */
            Timer();

            /**
             * \brief Resets the timer to 0.0f.
             */
            void reset();

            /**
             * \brief Returns the time passed since object creation or since reset() was last called.
             * \return Float containing the current time.
             */
            float getTime();

            /**
             * \brief Tests if 'seconds' seconds have passed since reset() or this method was called.
             *
             * \param[in] seconds number of seconds passed default is 1.0
             * \return bool true if a 'seconds' seconds are passed and false otherwise.
             */
            bool isTimePassed(float seconds = 1.0f);
    };
}
#endif /* TIMER_H */
