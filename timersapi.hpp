#ifndef TIMERSAPI_H
#define TIMERSAPI_H

#include <Arduino.h>

// defines
#define UP_COUNT 1
#define DOWN_COUNT 0
#define TO_ZERO 0
#define BACK 1
/**
 * @brief Simple timers. 
 * 
 */
class timers
{
public:
    /**
     * @brief Construct a new timers object
     * 
     * @param _del Delay for timer
     */
    timers(unsigned int _del);
    /**
     * @brief Stop timer.
     * 
     */
    void stop();
    /**
     * @brief Start timer.
     * 
     */
    void start();
    /**
     * @brief Set the delay to timer.
     * 
     * @param _del Delay for timer.
     */
    void setDel(unsigned int _del);
    /**
     * @brief Get the delay from timer
     * 
     * @return unsigned int - timer delay 
     */
    unsigned int getDel();
    /**
     * @brief Get the timer ttick.
     * 
     * @return true - timer get to max
     * @return false - timer do not go to the max
     */
    bool getTick();
    /**
     * @brief Get the timer owerflow.
     * 
     * @return true - millis() for timer was overflowed
     * @return false - millis() for was not overflowed
     */
    bool getOverflow();
private:
    /**
     * @brief main Api
     * 
     */
    void tickApi();
    unsigned long tmr = 0;
    unsigned int del = 0;
    bool run;
    byte is = 0;
    bool overflow;
    bool offlag;
};

/**
 * @brief counter on timerr
 * 
 */
class counts
{
public:
    /**
     * @brief Construct a new counts object
     * 
     * @param _del delay for timer
     * @param _max max count number
     */
    counts(unsigned int _del, int _max);
    /**
     * @brief Construct a new counts object
     * 
     * @param _del delay for timer
     * @param _max max count number
     * @param _cnt starting cound value
     */
    counts(unsigned int _del, int _max, int _cnt);
    /**
     * @brief Stop counting
     * 
     */
    void stop();
    /**
     * @brief Start counting
     * 
     */
    void start();
    /**
     * @brief Set the mode of counter
     * 
     * @param _dir direction to counting, UP_COUNT/DOWN_COUNT
     * @param _ofmode overrflow mode, TO_ZERO (return to zero/max)/BACK (revers direction)
     */
    void setMode(int _dir, int _ofmode);
    /**
     * @brief Set the internal timer delay
     * 
     * @param _del delay
     */
    void setDel(unsigned int _del);
    /**
     * @brief Set the max to counter
     * 
     * @param _max max count value
     */
    void setMax(int _max);
    /**
     * @brief Set the counter.
     * 
     * @param _cnt counter value
     */
    void setCounter(int _cnt);
    /**
     * @brief Get the internal timer delay
     * 
     * @return unsigned int - delay
     */
    unsigned int getDel();
    /**
     * @brief Get the count value
     * 
     * @return int - counter
     */
    int getCounter();
private:
    /**
     * @brief counter Api
     * 
     */
    void counterApi();
    /**
     * @brief suport function for counting
     * 
     */
    void count();
    /**
     * @brief SSupport function for owerflow checks
     * 
     */
    void overflowCheck();
    int max;
    int counter;
    unsigned long tmr = 0;
    unsigned int del = 0;
    bool run;
    bool overflow;
    bool dir;
    bool ofmode;
    bool offlag;
};

/**
 * @brief Countdowns class
 * 
 */
class countdowns
{
    public:
        /**
         * @brief Construct a new countdowns object
         * 
         * @param _del delay for internal timer
         * @param _run run on start
         */
        countdowns(unsigned int _del, int _run);
        /**
         * @brief Restart countdowning
         * 
         */
        void start();
        /**
         * @brief Stop countdowning
         * 
         */
        void stop();
        /**
         * @brief Set the delay for internal timer
         * 
         * @param _del Delay for internal timer
         */
        void setDel(unsigned int _del);
        /**
         * @brief Return if countdown end
         * 
         * @return true - Countdowned
         * @return false - Not countdowned
         */
        bool counted();
        /**
         * @brief Get the internal timer delay object
         * 
         * @return unsigned int - timer delay
         */
        unsigned int getDel();
    private:
        /**
         * @brief Main countdown Api
         * 
         */
        void countedApi();
        unsigned int del;
        bool run;
        bool is = 0;
        unsigned long tmr = 0;
};

#endif // TIMERSAPI_H