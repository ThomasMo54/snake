#ifndef SNAKE_ENERGY_HPP
#define SNAKE_ENERGY_HPP

class Energy {
public:
    explicit Energy(int initialValue): value(initialValue) {}

    inline const int* getValue() {
        return &value;
    }

    inline void add(int v) {
        value += v;
    }

    inline void remove(int v) {
        value -= v;
    }

    inline bool hasEnergyLeft() const {
        return value > 0;
    }

    inline void operator += (int v) {
        add(v);
    }

    inline void operator -= (int v) {
        remove(v);
    }

private:
    int value;
};

#endif //SNAKE_ENERGY_HPP
