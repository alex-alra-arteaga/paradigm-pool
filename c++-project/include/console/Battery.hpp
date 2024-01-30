#ifndef BATTERY_HPP_
#define BATTERY_HPP_

class Battery {
  public:
    Battery() = default;
    ~Battery() = default;
    bool isCharging() const;
    int getPercentage() const;
};

#endif /* !BATTERY_HPP_ */
