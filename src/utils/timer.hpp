#ifndef RTAVIS_TIMER_HPP
#define RTAVIS_TIMER_HPP

#include <ctime>
#include <iostream>

class Timer {
    public:
        Timer() {
            std::clock_t start_time = std::clock();
        }

        inline std::clock_t get_start_time() const{
            return start_time;
        }

    private:
        std::clock_t start_time;
};

inline std::ostream& operator<<(std::ostream &out, const Timer& timer){
    double duration = ((double) (std::clock() - timer.get_start_time())) / CLOCKS_PER_SEC;
    return out << duration << " s";
}

#endif